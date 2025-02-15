#include "GAMER.h"




#ifdef SUPPORT_HYPRE
void Hypre_InitialGuess();
void Hypre_SetA();
void Hypre_Solve();


// TODO : for debugging
// if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );

void Hypre_Main()
{

   const int NParts      = MAX_LEVEL+1; // number of AMR levels
   const int NVars       = 1;  // One var, potential?
   const int NDim        = 3;
   const int NEntries    = 2*NDim + 1;
   const int var         = 0; // TODO: not sure what is this
   const int object_type = HYPRE_SSTRUCT; // or this HYPRE_PARCSR // TODO: check which one should I use
   int hypre_ierr;
   int Offsets[NEntries][NDim] = { {  0,  0,  0 },
                                   { -1,  0,  0 }, // -x
                                   {  1,  0,  0 }, // +x
                                   {  0, -1,  0 }, // -y
                                   {  0,  1,  0 }, // +y
                                   {  0,  0, -1 }, // -z
                                   {  0,  0,  1 }, // +z
                                 }; // TODO: need to be checked

// create grid object
#  ifdef LOAD_BALANCE
   hypre_ierr = HYPRE_SStructGridCreate( MPI_COMM_WORLD, NDim, NParts, &Hypre_grid );
#  else
   hypre_ierr = HYPRE_SStructGridCreate( NULL, NDim, NParts, &Hypre_grid );
#  endif

// set each patch
   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         hypre_ierr = HYPRE_SStructGridSetExtents( Hypre_grid, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR );
      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

// solve one cell-centered variables
   HYPRE_SStructVariable vartypes[] = { HYPRE_SSTRUCT_VARIABLE_CELL };

   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      hypre_ierr = HYPRE_SStructGridSetVariables( Hypre_grid, lv, NVars, vartypes );
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

// assamble grid
   hypre_ierr = HYPRE_SStructGridAssemble( Hypre_grid );

// create stencils
   hypre_ierr = HYPRE_SStructStencilCreate( NDim, NEntries, &Hypre_stencil );

// set entries
   for (int e=0; e<NEntries; e++)
   {
      hypre_ierr = HYPRE_SStructStencilSetEntry( Hypre_stencil, e, Offsets[e], var );
   }

#  ifdef LOAD_BALANCE
   hypre_ierr = HYPRE_SStructGraphCreate( MPI_COMM_WORLD, Hypre_grid, &Hypre_graph );
#  else
   hypre_ierr = HYPRE_SStructGraphCreate( NULL, Hypre_grid, &Hypre_graph );
#  endif

   hypre_ierr = HYPRE_SStructGraphSetObjectType( Hypre_graph, object_type );

   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      hypre_ierr = HYPRE_SStructGraphSetStencil( Hypre_graph, lv, var, Hypre_stencil );
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

   hypre_ierr = HYPRE_SStructGraphAssemble( Hypre_graph );

// TODO: link the neighbor

#  ifdef LOAD_BALANCE
   hypre_ierr = HYPRE_SStructMatrixCreate( MPI_COMM_WORLD, Hypre_graph, &Hypre_A );
   hypre_ierr = HYPRE_SStructVectorCreate( MPI_COMM_WORLD, Hypre_grid,  &Hypre_b );
   hypre_ierr = HYPRE_SStructVectorCreate( MPI_COMM_WORLD, Hypre_grid,  &Hypre_x );
#  else
   hypre_ierr = HYPRE_SStructMatrixCreate( NULL, Hypre_graph, &Hypre_A );
   hypre_ierr = HYPRE_SStructVectorCreate( NULL, Hypre_grid,  &Hypre_b );
   hypre_ierr = HYPRE_SStructVectorCreate( NULL, Hypre_grid,  &Hypre_x );
#  endif

   hypre_ierr = HYPRE_SStructMatrixSetObjectType( Hypre_A, object_type );
   hypre_ierr = HYPRE_SStructVectorSetObjectType( Hypre_b, object_type );
   hypre_ierr = HYPRE_SStructVectorSetObjectType( Hypre_x, object_type );

   hypre_ierr = HYPRE_SStructMatrixInitialize( Hypre_A );
   hypre_ierr = HYPRE_SStructVectorInitialize( Hypre_b );
   hypre_ierr = HYPRE_SStructVectorInitialize( Hypre_x );

} // FUNCTION : Hypre_Main



void Hypre_SolvePoisson()
{

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s ...\n", __FUNCTION__ );

   int hypre_ierr;
   int iFactorB = 1;
   int var      = 0;  // var iterator.

// set each patch
   real *dens = new real [CUBE(PS1)];

   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         for (int k=0; k<PS1; k++)
         for (int j=0; j<PS1; j++)
         for (int i=0; i<PS1; i++)
         {
            // TODO: check the data structure
            const int  idx   = k*SQR(PS1) + j*PS1 + i;
            const real coeff = -4.0*M_PI*NEWTON_G;
            dens[idx] = coeff * amr->patch[ amr->FluSg[lv] ][lv][PID]->fluid[DENS][k][j][i];

         }

         hypre_ierr = HYPRE_SStructVectorSetBoxValues( Hypre_b, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, dens );

      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

   delete [] dens;

  hypre_ierr = HYPRE_SStructVectorAssemble( Hypre_b );

// initial guess
   printf("Initialize guess\n");
   Hypre_InitialGuess();

// Compute A in AX=B
   printf("Set A\n");
   Hypre_SetA();

// setup solver and solve
   printf("Solve AX=B\n");
   Hypre_Solve();

   printf("Collect potential\n");
// collect the potential
   hypre_ierr = HYPRE_SStructVectorGather( Hypre_x );

// update GAMER array
   printf("Update GAMER array\n");
   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      printf("lv %d\n", lv);
      real *pote = new real [CUBE(PS1)];
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         // NOTE: By FLASH: Use GetBoxValues more efficient then GetValues.
         hypre_ierr = HYPRE_SStructVectorGetBoxValues( Hypre_x, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, pote );

         for (int k=0; k<PS1; k++)
         for (int j=0; j<PS1; j++)
         for (int i=0; i<PS1; i++)
         {
            // TODO: check the data structure
            const int idx = k*SQR(PS1) + j*PS1 + i;
            // amr->patch[ amr->PotSg[lv] ][lv][PID]->pot[k][j][i] = pote[idx];
            amr->patch[ 0 ][lv][PID]->pot[k][j][i] = pote[idx];
            amr->patch[ 1 ][lv][PID]->pot[k][j][i] = pote[idx];
            // TODO: apply the floor value here
         } // i, j, k
      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      printf("lv %d done\n", lv);

      delete [] pote;
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

// clean b array
   printf("Clean b array\n");

   real *dens = new real [CUBE(PS1)];
   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         for (int k=0; k<PS1; k++)
         for (int j=0; j<PS1; j++)
         for (int i=0; i<PS1; i++)
         {
            // TODO: check the data structure
            const int idx = i*SQR(PS1) + j*PS1 + k;
            dens[idx] = 0.0;
         }

         hypre_ierr = HYPRE_SStructVectorSetBoxValues( Hypre_b, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, dens );

      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)

   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)
   delete [] dens;

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s ... done\n", __FUNCTION__ );

} // FUNCTION : Hypre_SolvePoisson



void Hypre_InitialGuess()
{

   int hypre_ierr;
   int var = 0;

   real *pote = new real [CUBE(PS1)];
   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         for (int k=0; k<PS1; k++)
         for (int j=0; j<PS1; j++)
         for (int i=0; i<PS1; i++)
         {
            // TODO: check the data structure
            const int idx = k*SQR(PS1) + j*PS1 + i;
            pote[idx] = 0.0;
         }

         hypre_ierr = HYPRE_SStructVectorSetBoxValues( Hypre_x, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, pote );

      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)

   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)
   delete [] pote;

   hypre_ierr = HYPRE_SStructVectorAssemble( Hypre_x );

} // FUNCTION : Hypre_InitialGuess



void Hypre_SetA()
{

   const int NDim     = 3;
   const int NEntries = 2*NDim + 1;
   const int var      = 0; // TODO: not sure what is this

   int hypre_ierr;
   int bcCornerL[3], bcCornerR[3];
   int stencil_indices[NEntries];

   for (int i=0; i<NEntries; i++)  stencil_indices[i] = i;

   real *boxVal = new real [NEntries*CUBE(PS1)];
   real *bcVal  = new real [SQR(PS1)];

   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         for (int k=0; k<PS1; k++)
         for (int j=0; j<PS1; j++)
         for (int i=0; i<PS1; i++)
         {
            const int idx = (k*SQR(PS1) + j*PS1 + i) * NEntries;
//          \nabla matrix
            boxVal[idx+0] =  6; // i,   j,   k
            boxVal[idx+1] = -1; // i-1, j,   k
            boxVal[idx+2] = -1; // i+1, j,   k
            boxVal[idx+3] = -1; // i,   j-1, k
            boxVal[idx+4] = -1; // i,   j+1, k
            boxVal[idx+5] = -1; // i,   j,   k-1
            boxVal[idx+6] = -1; // i,   j,   k+1
         }

         hypre_ierr = HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR,
                                                       var, NEntries, stencil_indices, boxVal );

//       set BC
         if ( amr->patch[0][lv][PID]->EdgeL[0] == 0.0 )
         {
            int stencil_index[1] = {1};
            bcCornerL[0] = amr->patch[0][lv][PID]->cornerL[0];
            bcCornerL[1] = amr->patch[0][lv][PID]->cornerL[1];
            bcCornerL[2] = amr->patch[0][lv][PID]->cornerL[2];
            bcCornerR[0] = amr->patch[0][lv][PID]->cornerL[0];
            bcCornerR[1] = amr->patch[0][lv][PID]->cornerR[1];
            bcCornerR[2] = amr->patch[0][lv][PID]->cornerR[2];

            for (int j=0; j<PS1; j++)
            for (int i=0; i<PS1; i++)
            {
               const int idx = j*PS1 + i;
               bcVal[idx] = 0;
            }

            hypre_ierr = HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, bcCornerL, bcCornerR, var, 1, stencil_index, boxVal );
         }

         if ( amr->patch[0][lv][PID]->EdgeR[0] == amr->BoxSize[0] )
         {
            int stencil_index[1] = {2};
            bcCornerL[0] = amr->patch[0][lv][PID]->cornerR[0];
            bcCornerL[1] = amr->patch[0][lv][PID]->cornerL[1];
            bcCornerL[2] = amr->patch[0][lv][PID]->cornerL[2];
            bcCornerR[0] = amr->patch[0][lv][PID]->cornerR[0];
            bcCornerR[1] = amr->patch[0][lv][PID]->cornerR[1];
            bcCornerR[2] = amr->patch[0][lv][PID]->cornerR[2];

            for (int j=0; j<PS1; j++)
            for (int i=0; i<PS1; i++)
            {
               const int idx = j*PS1 + i;
               bcVal[idx] = 0;
            }

            hypre_ierr = HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, bcCornerL, bcCornerR, var, 1, stencil_index, boxVal );
         }

         if ( amr->patch[0][lv][PID]->EdgeL[1] == 0.0 )
         {
            int stencil_index[1] = {3};
            bcCornerL[0] = amr->patch[0][lv][PID]->cornerL[0];
            bcCornerL[1] = amr->patch[0][lv][PID]->cornerL[1];
            bcCornerL[2] = amr->patch[0][lv][PID]->cornerL[2];
            bcCornerR[0] = amr->patch[0][lv][PID]->cornerR[0];
            bcCornerR[1] = amr->patch[0][lv][PID]->cornerL[1];
            bcCornerR[2] = amr->patch[0][lv][PID]->cornerR[2];

            for (int j=0; j<PS1; j++)
            for (int i=0; i<PS1; i++)
            {
               const int idx = j*PS1 + i;
               bcVal[idx] = 0;
            }

            hypre_ierr = HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, bcCornerL, bcCornerR, var, 1, stencil_index, boxVal );
         }

         if ( amr->patch[0][lv][PID]->EdgeR[1] == amr->BoxSize[1] )
         {
            int stencil_index[1] = {4};
            bcCornerL[0] = amr->patch[0][lv][PID]->cornerL[0];
            bcCornerL[1] = amr->patch[0][lv][PID]->cornerR[1];
            bcCornerL[2] = amr->patch[0][lv][PID]->cornerL[2];
            bcCornerR[0] = amr->patch[0][lv][PID]->cornerR[0];
            bcCornerR[1] = amr->patch[0][lv][PID]->cornerR[1];
            bcCornerR[2] = amr->patch[0][lv][PID]->cornerR[2];

            for (int j=0; j<PS1; j++)
            for (int i=0; i<PS1; i++)
            {
               const int idx = j*PS1 + i;
               bcVal[idx] = 0;
            }

            hypre_ierr = HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, bcCornerL, bcCornerR, var, 1, stencil_index, boxVal );
         }

         if ( amr->patch[0][lv][PID]->EdgeL[2] == 0.0 )
         {
            int stencil_index[1] = {5};
            bcCornerL[0] = amr->patch[0][lv][PID]->cornerL[0];
            bcCornerL[1] = amr->patch[0][lv][PID]->cornerL[1];
            bcCornerL[2] = amr->patch[0][lv][PID]->cornerL[2];
            bcCornerR[0] = amr->patch[0][lv][PID]->cornerR[0];
            bcCornerR[1] = amr->patch[0][lv][PID]->cornerR[1];
            bcCornerR[2] = amr->patch[0][lv][PID]->cornerL[2];

            for (int j=0; j<PS1; j++)
            for (int i=0; i<PS1; i++)
            {
               const int idx = j*PS1 + i;
               bcVal[idx] = 0;
            }

            hypre_ierr = HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, bcCornerL, bcCornerR, var, 1, stencil_index, boxVal );
         }

         if ( amr->patch[0][lv][PID]->EdgeR[2] == amr->BoxSize[2] )
         {
            int stencil_index[1] = {6};
            bcCornerL[0] = amr->patch[0][lv][PID]->cornerL[0];
            bcCornerL[1] = amr->patch[0][lv][PID]->cornerL[1];
            bcCornerL[2] = amr->patch[0][lv][PID]->cornerR[2];
            bcCornerR[0] = amr->patch[0][lv][PID]->cornerR[0];
            bcCornerR[1] = amr->patch[0][lv][PID]->cornerR[1];
            bcCornerR[2] = amr->patch[0][lv][PID]->cornerR[2];

            for (int j=0; j<PS1; j++)
            for (int i=0; i<PS1; i++)
            {
               const int idx = j*PS1 + i;
               bcVal[idx] = 0;
            }

            hypre_ierr = HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, bcCornerL, bcCornerR, var, 1, stencil_index, boxVal );
         }

      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

   delete [] boxVal;
   delete [] bcVal;

   hypre_ierr = HYPRE_SStructMatrixAssemble( Hypre_A );

} // FUNCTION : Hypre_SetA



void Hypre_FillVector( HYPRE_SStructVector Hypre_vector, const int field_idx, const real factor )
{

   int hypre_ierr;
   int var = 0;

   real *field = new real [CUBE(PS1)];
   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         for (int k=0; k<PS1; k++)
         for (int j=0; j<PS1; j++)
         for (int i=0; i<PS1; i++)
         {
            // TODO: check the data structure
            const int idx = k*SQR(PS1) + j*PS1 + i;
            field[idx] = factor * amr->patch[ amr->FluSg[lv] ][lv][PID]->fluid[field_idx][k][j][i];
         }

         hypre_ierr = HYPRE_SStructVectorSetBoxValues( Hypre_vector, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, field );
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );

      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

   delete [] field;

} // FUNCTION : Hypre_FillVector
#endif // #ifdef SUPPORT_HYPRE
