#include "GAMER.h"




#ifdef SUPPORT_HYPRE
void Hypre_InitialGuess();
void Hypre_SetA();
void Hypre_SetBC( const int entry, int *stencil_indices, const int var, const int lv, const int *cornerL, const int *cornerR );
void Hypre_Solve();
void Hypre_SetGraph();


void Hypre_Main()
{

   const int NParts      = MAX_LEVEL+1; // number of AMR levels
   const int NVars       = 1;  // One var, potential?
   const int NDim        = 3;
   const int NEntries    = 2*NDim + 1;
   const int var         = 0; // TODO: not sure what is this
   const int object_type = HYPRE_SSTRUCT; // or this HYPRE_PARCSR // TODO: check which one should I use
   int Offsets[NEntries][NDim] = { {  0,  0,  0 },
                                   { -1,  0,  0 }, // -x
                                   {  1,  0,  0 }, // +x
                                   {  0, -1,  0 }, // -y
                                   {  0,  1,  0 }, // +y
                                   {  0,  0, -1 }, // -z
                                   {  0,  0,  1 }, // +z
                                 }; // TODO: need to be checked

// create grid object
#  ifndef SERIAL
   HYPRE_CHECK_FUNC(   HYPRE_SStructGridCreate( MPI_COMM_WORLD, NDim, NParts, &Hypre_grid )   );
#  else
   HYPRE_CHECK_FUNC(   HYPRE_SStructGridCreate( NULL,           NDim, NParts, &Hypre_grid )   );
#  endif

// set each patch
   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
#        ifdef DEBUG_HYPRE
         if ( amr->patch[0][lv][PID]->cornerR[0] - amr->patch[0][lv][PID]->cornerL[0] != PS1-1 ) Aux_Error( ERROR_INFO, "cornerR[0]-cornerL[0] != PS1-1 !!\n" );
         if ( amr->patch[0][lv][PID]->cornerR[1] - amr->patch[0][lv][PID]->cornerL[1] != PS1-1 ) Aux_Error( ERROR_INFO, "cornerR[1]-cornerL[1] != PS1-1 !!\n" );
         if ( amr->patch[0][lv][PID]->cornerR[2] - amr->patch[0][lv][PID]->cornerL[2] != PS1-1 ) Aux_Error( ERROR_INFO, "cornerR[2]-cornerL[2] != PS1-1 !!\n" );
#        endif
         // if ( amr->patch[0][lv][PID]->son >= 0 ) Aux_Error( ERROR_INFO, "PID %05d lv %02d has son !!\n", PID, lv );

         HYPRE_CHECK_FUNC(   HYPRE_SStructGridSetExtents( Hypre_grid, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR )   );
      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

// solve one cell-centered variables
   HYPRE_SStructVariable vartypes[] = { HYPRE_SSTRUCT_VARIABLE_CELL };

   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      HYPRE_CHECK_FUNC(   HYPRE_SStructGridSetVariables( Hypre_grid, lv, NVars, vartypes )   );
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

// set periodic for lv 0
// TODO: need to check what if lv 1 periodic
   if ( OPT__BC_POT != BC_POT_ISOLATED )
   {
      int periodicity[3] = { NX0_TOT[0], NX0_TOT[1], NX0_TOT[2] };
      HYPRE_CHECK_FUNC(   HYPRE_SStructGridSetPeriodic( Hypre_grid, 0, periodicity )   );
   }

// assamble grid
   HYPRE_CHECK_FUNC(   HYPRE_SStructGridAssemble( Hypre_grid )   );

// create stencils
   HYPRE_CHECK_FUNC(   HYPRE_SStructStencilCreate( NDim, NEntries, &Hypre_stencil )   );

// set entries
   for (int e=0; e<NEntries; e++)
   {
      HYPRE_CHECK_FUNC(   HYPRE_SStructStencilSetEntry( Hypre_stencil, e, Offsets[e], var )   );
   }

#  ifndef SERIAL
   HYPRE_CHECK_FUNC(   HYPRE_SStructGraphCreate( MPI_COMM_WORLD, Hypre_grid, &Hypre_graph )   );
#  else
   HYPRE_CHECK_FUNC(   HYPRE_SStructGraphCreate( NULL,           Hypre_grid, &Hypre_graph )   );
#  endif

   HYPRE_CHECK_FUNC(   HYPRE_SStructGraphSetObjectType( Hypre_graph, object_type )   );

   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      HYPRE_CHECK_FUNC(   HYPRE_SStructGraphSetStencil( Hypre_graph, lv, var, Hypre_stencil )   );
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)


// TODO: link the neighbor
   bool NLvHasPatch = false; // AMR not available now
   if ( NLvHasPatch )   Hypre_SetGraph();

   HYPRE_CHECK_FUNC(   HYPRE_SStructGraphAssemble( Hypre_graph )   );

#  ifndef SERIAL
   HYPRE_CHECK_FUNC(   HYPRE_SStructMatrixCreate( MPI_COMM_WORLD, Hypre_graph, &Hypre_A )   );
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorCreate( MPI_COMM_WORLD, Hypre_grid,  &Hypre_b )   );
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorCreate( MPI_COMM_WORLD, Hypre_grid,  &Hypre_x )   );
#  else
   HYPRE_CHECK_FUNC(   HYPRE_SStructMatrixCreate( NULL,           Hypre_graph, &Hypre_A )   );
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorCreate( NULL,           Hypre_grid,  &Hypre_b )   );
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorCreate( NULL,           Hypre_grid,  &Hypre_x )   );
#  endif

   HYPRE_CHECK_FUNC(   HYPRE_SStructMatrixSetObjectType( Hypre_A, object_type )   );
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorSetObjectType( Hypre_b, object_type )   );
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorSetObjectType( Hypre_x, object_type )   );

   HYPRE_CHECK_FUNC(   HYPRE_SStructMatrixInitialize( Hypre_A )   );
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorInitialize( Hypre_b )   );
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorInitialize( Hypre_x )   );

} // FUNCTION : Hypre_Main


void Hypre_SolvePoisson( const int SaveSg_Pot )
{

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s ...\n", __FUNCTION__ );

   int iFactorB = 1;
   int var      = 0;  // var iterator.

// set each patch
   real *dens = new real [CUBE(PS1)];

   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      const real dh2   = SQR( amr->dh[lv] );
      const real coeff = -4.0 * M_PI * NEWTON_G * dh2;
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         for (int k=0; k<PS1; k++)
         for (int j=0; j<PS1; j++)
         for (int i=0; i<PS1; i++)
         {
            const int idx = k*SQR(PS1) + j*PS1 + i;
            dens[idx] = coeff * amr->patch[ amr->FluSg[lv] ][lv][PID]->fluid[DENS][k][j][i];
         }

         HYPRE_CHECK_FUNC(   HYPRE_SStructVectorSetBoxValues( Hypre_b, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, dens )   );

      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

   delete [] dens;

   // HYPRE_CHECK_FUNC(   HYPRE_SStructVectorAssemble( Hypre_b )   );

// initial guess
   printf("Initialize guess\n");
   Hypre_InitialGuess();

// Compute A in AX=B
   printf("Set A\n");
   Hypre_SetA();
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorAssemble( Hypre_b )   );

// setup solver and solve
   printf("Solve AX=B\n");
   Hypre_Solve();

   printf("Collect potential\n");
// collect the potential
   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorGather( Hypre_x )   );

// update GAMER array
   for (int lv=0; lv<MAX_LEVEL+1; lv++)
   {
      real *pote = new real [CUBE(PS1)];
      for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
      {
         // NOTE: By FLASH: Use GetBoxValues more efficient then GetValues.
         HYPRE_CHECK_FUNC(   HYPRE_SStructVectorGetBoxValues( Hypre_x, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, pote )   );

         for (int k=0; k<PS1; k++)
         for (int j=0; j<PS1; j++)
         for (int i=0; i<PS1; i++)
         {
            // TODO: check the data structure
            const int idx = k*SQR(PS1) + j*PS1 + i;
            amr->patch[ SaveSg_Pot ][lv][PID]->pot[k][j][i] = pote[idx];
            // TODO: apply the floor value here
         } // i, j, k
      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)

      delete [] pote;
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

// clean b array
   printf("Clean b array\n");

   dens = new real [CUBE(PS1)];
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

         HYPRE_CHECK_FUNC(   HYPRE_SStructVectorSetBoxValues( Hypre_b, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, dens )   );

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

         HYPRE_CHECK_FUNC(   HYPRE_SStructVectorSetBoxValues( Hypre_x, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, pote )   );

      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)

   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)
   delete [] pote;

   HYPRE_CHECK_FUNC(   HYPRE_SStructVectorAssemble( Hypre_x )   );

} // FUNCTION : Hypre_InitialGuess



void Hypre_SetA()
{

   const int NDim     = 3;
   const int NEntries = 2*NDim + 1;
   const int var      = 0; // TODO: not sure what is this
   const bool fix_one_cell_sol = ( OPT__BC_POT != BC_POT_ISOLATED );

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

         HYPRE_CHECK_FUNC(   HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR,
                                                              var, NEntries, stencil_indices, boxVal )   );

//       set BC
         if ( amr->patch[0][lv][PID]->EdgeL[0] == 0.0             )   Hypre_SetBC( 1, stencil_indices, var, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR );
         if ( amr->patch[0][lv][PID]->EdgeR[0] == amr->BoxSize[0] )   Hypre_SetBC( 2, stencil_indices, var, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR );
         if ( amr->patch[0][lv][PID]->EdgeL[1] == 0.0             )   Hypre_SetBC( 3, stencil_indices, var, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR );
         if ( amr->patch[0][lv][PID]->EdgeR[1] == amr->BoxSize[1] )   Hypre_SetBC( 4, stencil_indices, var, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR );
         if ( amr->patch[0][lv][PID]->EdgeL[2] == 0.0             )   Hypre_SetBC( 5, stencil_indices, var, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR );
         if ( amr->patch[0][lv][PID]->EdgeR[2] == amr->BoxSize[2] )   Hypre_SetBC( 6, stencil_indices, var, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR );
      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

   delete [] boxVal;
   delete [] bcVal;

   HYPRE_CHECK_FUNC(   HYPRE_SStructMatrixAssemble( Hypre_A )   );

} // FUNCTION : Hypre_SetA


// dir: 1~6 -> 1:-x, 2:+x, 3:-y, 4:+y, 5:-z, 6:+z
void Hypre_SetBC( const int entry, int *stencil_indices, const int var, const int lv, const int *cornerL, const int *cornerR )
{

   int hypre_ierr;
   int bcCornerL[3], bcCornerR[3];

   for (int d=0; d<3; d++)
   {
      bcCornerL[d] = cornerL[d];
      bcCornerR[d] = cornerR[d];
   }

   switch ( entry )
   {
      case 1: bcCornerR[0] = cornerL[0];  break;
      case 2: bcCornerL[0] = cornerR[0];  break;
      case 3: bcCornerR[1] = cornerL[1];  break;
      case 4: bcCornerL[1] = cornerR[1];  break;
      case 5: bcCornerR[2] = cornerL[2];  break;
      case 6: bcCornerL[2] = cornerR[2];  break;
      default:  Aux_Error( ERROR_INFO, "Incorrect entry (1~6)\n" ); break;
   }

   real *bcVal  = new real [SQR(PS1)];

   if ( OPT__BC_POT == BC_POT_ISOLATED )
   {
      for (int j=0; j<PS1; j++)
      for (int i=0; i<PS1; i++)
      {
         const int idx = j*PS1 + i;
         bcVal[idx] = 0;
      }

      HYPRE_CHECK_FUNC(   HYPRE_SStructMatrixSetBoxValues( Hypre_A, lv, bcCornerL, bcCornerR, var, 1, stencil_indices+entry, bcVal )   );
   }

   delete [] bcVal;

} // FUNCITON : Hypre_SetBC



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

         HYPRE_CHECK_FUNC(   HYPRE_SStructVectorSetBoxValues( Hypre_vector, lv, amr->patch[0][lv][PID]->cornerL, amr->patch[0][lv][PID]->cornerR, var, field )   );
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );

      } // for (int PID=0; PID<amr->NPatchComma[lv][1]; PID++)
   } // for (int lv=0; lv<MAX_LEVEL+1; lv++)

   delete [] field;

} // FUNCTION : Hypre_FillVector
#endif // #ifdef SUPPORT_HYPRE
