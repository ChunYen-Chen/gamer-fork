#include "GAMER.h"




//-------------------------------------------------------------------------------------------------------
// Function    :  CPU_ComputeGREP
// Description :  Construct the effective GR potential
//
// Note        :  1. Enabled if macro GRAVITY and GREP are set
//                2. Invoked by Poi_UserWorkBeforePoisson_GREP()
//                3. The profile EffPot stores the value of -Phi_NW(r) + Phi_TOV(r) at the bin center
//                4. Ref: Marek et al., 2006, A&A, 445, 273 (arXiv: 0502161), sec. 2, case A
//
// Parameter   :  lv      : Current AMR level
//                Time    : Current physical time at the refinement level=lv
//                DensAve : Profile_t object storing the spherically averaged profile of density
//                EngyAve : Profile_t object storing the spherically averaged profile of internal energy density
//                VrAve   : Profile_t object storing the spherically averaged profile of radial velocity
//                PresAve : Profile_t object storing the spherically averaged profile of pressure
//                EffPot  : Profile_t object storing the effective GR potential
//
// Return      :  EffPot
//-------------------------------------------------------------------------------------------------------
void CPU_ComputeGREP( const int lv, const double Time, const Profile_t *DensAve, const Profile_t *EngyAve,
                      const Profile_t *VrAve, const Profile_t *PresAve, Profile_t *EffPot )
{

   const double c2          = SQR( Const_c / UNIT_V );
   const double _c2         = 1.0 / c2;
   const double FourPI      = 4.0 * M_PI;
   const double FourThirdPI = FourPI / 3.0;
   const double Tolerance   = 1.0e-5;

   int     NIter     = 0;
   int     NBin      = DensAve->NBin;
   double *Radius    = DensAve->Radius;
   double  MaxRadius = DensAve->MaxRadius;
   double *Dens      = DensAve->Data;
   double *Engy      = EngyAve->Data;
   double *Vr        = VrAve  ->Data;
   double *Pres      = PresAve->Data;

   double *Mass_NW      = new double [NBin];  // enclosed Newtonian mass for \bar_Phi(r)     in Eq. (7)
   double *Mass_TOV     = new double [NBin];  // enclosed TOV mass       for \bar_Phi(r)_TOV in Eq. (7)
   double *Mass_TOV_USG = new double [NBin];  // enclosed TOV mass in the previous iteration
   double *Dens_TOV     = new double [NBin];  // empirical TOV density                          Eq. (4)
   double *Gamma_TOV    = new double [NBin];  // metric function                                Eq. (5)
   double *dVol         = new double [NBin];  // volume    of each bin
   double *EdgeL        = new double [NBin];  // left edge of each bin

   for (int i=0; i<NBin;   i++)   Mass_TOV_USG[i] = 0.0;
   for (int i=0; i<NBin;   i++)   Gamma_TOV   [i] = 1.0;

                                  EdgeL       [0] = 0.0;
   for (int i=1; i<NBin;   i++)   EdgeL       [i] = ( GREP_LOGBIN ) ? sqrt( Radius[i-1] * Radius[i] )
                                                                    : 0.5*( Radius[i-1] + Radius[i] );

   for (int i=0; i<NBin-1; i++)   dVol        [i] = FourThirdPI * ( CUBE( EdgeL[i+1] ) - CUBE( EdgeL[i]      ) );
                                  dVol   [NBin-1] = FourThirdPI * ( CUBE( MaxRadius  ) - CUBE( EdgeL[NBin-1] ) );


// 1. compute Mass_NW at the outer edge of each bin
                                  Mass_NW     [0] = dVol     [0] * Dens[0];
   for (int i=1; i<NBin-1; i++)   Mass_NW     [i] = dVol     [i] * ( 0.5 * Dens[i] + 0.25 * ( Dens[i-1] + Dens[i+1] ) );
                                  Mass_NW[NBin-1] = dVol[NBin-1] * Dens[NBin-1];

   for (int i=1; i<NBin;   i++)   Mass_NW[i] += Mass_NW[i-1];


// 2. iteratively compute Mass_TOV and Gamma_TOV at the outer edge of each bin
   bool IsConverged = false;

   while ( ! IsConverged  &&  ( NIter++ < GREP_MAXITER ) )
   {
//    update Mass_TOV
      for (int i=0; i<NBin;   i++)   Dens_TOV[i] = Gamma_TOV[i] * ( Dens[i] + Engy[i] * _c2 );

                                     Mass_TOV     [0] = dVol     [0] * Dens_TOV[0];
      for (int i=1; i<NBin-1; i++)   Mass_TOV     [i] = dVol     [i] * ( 0.5 * Dens_TOV[i] + 0.25 * ( Dens_TOV[i-1] + Dens_TOV[i+1] ) );
                                     Mass_TOV[NBin-1] = dVol[NBin-1] * Dens_TOV[NBin-1];

      for (int i=1; i<NBin  ; i++)   Mass_TOV[i] += Mass_TOV[i-1];

//    update Gamma_TOV
      for (int i=0; i<NBin-1; i++)   Gamma_TOV     [i] = 1.0 + ( 0.25 * SQR( Vr[i] + Vr[i+1] )
                                                               - 2.0  * NEWTON_G * Mass_TOV[i]      / EdgeL[i+1]  ) * _c2;
                                     Gamma_TOV[NBin-1] = 1.0 + (        SQR( Vr[NBin-1] )
                                                               - 2.0  * NEWTON_G * Mass_TOV[NBin-1] / MaxRadius   ) * _c2;

      for (int i=0; i<NBin;   i++)   Gamma_TOV[i] = sqrt( MAX( TINY_NUMBER, Gamma_TOV[i] ) );

//    check whether the Mass_TOV is converged
      IsConverged = true;

      for (int i=0; i<NBin; i++)
      {
         double RelErr = fabs( Mass_TOV_USG[i] - Mass_TOV[i] ) / Mass_TOV[i];

         if ( RelErr > Tolerance )
         {
            IsConverged = false;
            break;
         }
      }

//    backup the old Mass_TOV if not converged yet
      if ( ! IsConverged )
         for (int i=0; i<NBin; i++)   Mass_TOV_USG[i] = Mass_TOV[i];
   } // while ( ! IsConverged  &&  ( NIter++ < GREP_MAXITER ) )


// troubleshooting information in case convergent solutions cannot be found.
   if ( ! IsConverged )
   {
      if ( MPI_Rank == 0 )
      {
         char FileName[MAX_STRING];

         sprintf( FileName, "GREP_Lv%02d_FailedTOVProfile", lv );
         FILE *File = fopen( FileName, "w" );

//       metadata
         fprintf( File, "# Step               : %ld\n",                  Step );
         fprintf( File, "# Time               : %.7e\n",                 Time );
         fprintf( File, "# GREP_CENTER_METHOD : %d\n",                   GREP_CENTER_METHOD );
         fprintf( File, "# Center             : %13.7e %13.7e %13.7e\n", DensAve->Center[0], DensAve->Center[1], DensAve->Center[2] );
         fprintf( File, "# Maximum Radius     : %13.7e\n",               DensAve->MaxRadius );
         fprintf( File, "# LogBin             : %d\n",                   DensAve->LogBin );
         fprintf( File, "# LogBinRatio        : %13.7e\n",               DensAve->LogBinRatio );
         fprintf( File, "# NBin               : %d\n",                   NBin );
         fprintf( File, "# Maximum Iteration  : %d\n",                   GREP_MAXITER );
         fprintf( File, "# Tolerance          : %13.7e\n",               Tolerance );
         fprintf( File, "------------------------------------------------------\n" );
         fprintf( File, "%5s %9s %22s %22s %22s %22s %22s %22s %22s %22s %22s %22s\n",
                        "# Bin", "NCell", "Radius", "Density", "Energy", "Vr", "Pressure",
                        "Mass_NW", "Mass_TOV", "Mass_TOV_Usg", "Gamma_TOV", "Rel_Err (Mass_TOV)");

//       data
         for (int i=0; i<NBin; i++)
         fprintf( File, "%5d %9ld %22.15e %22.15e %22.15e %22.15e %22.15e %22.15e %22.15e %22.15e %22.15e %22.15e\n",
                        i, DensAve->NCell[i], Radius[i], Dens[i], Engy[i], Vr[i], Pres[i],
                        Mass_NW[i], Mass_TOV[i], Mass_TOV_USG[i], Gamma_TOV[i],
                        fabs( Mass_TOV_USG[i] - Mass_TOV[i] ) / Mass_TOV[i] );

         fclose( File );

//       terminate the program
         Aux_Error( ERROR_INFO, "the solutions for Mass_TOV and Gamma_TOV are not converging !!\n" );
      }
   } // if ( ! IsConverged )


// 3. compute the effective GR potential at the bin center
   EffPot->NBin        = DensAve->NBin;
   EffPot->LogBin      = DensAve->LogBin;
   EffPot->LogBinRatio = DensAve->LogBinRatio;
   EffPot->MaxRadius   = DensAve->MaxRadius;
   EffPot->AllocateMemory();

   for (int d=0; d<3;    d++)   EffPot->Center[d] = DensAve->Center[d];
   for (int b=0; b<NBin; b++)   EffPot->Radius[b] = DensAve->Radius[b];

// set the outer boundary condition of the potential to -G * M_out / r_out
   EffPot->Data[NBin-1] = -NEWTON_G * ( Mass_TOV[NBin-1] - Mass_NW[NBin-1] ) / Radius[NBin-1];

   for (int i=NBin-2; i>0; i--)
   {
      double dr         = Radius[i] - Radius[i+1];
      double Mass_NW_C  = 0.5 * ( Mass_NW[i] + Mass_NW[i-1] );
      double Mass_TOV_C = ( 0.5 * ( Mass_TOV[i] + Mass_TOV[i-1] ) + FourPI * CUBE( Radius[i] ) * Pres[i] * _c2 )
                        * ( 1.0 + ( Engy[i] + Pres[i] ) / ( Dens[i] * c2 ) )
                        / SQR( 0.5 * ( Gamma_TOV[i] + Gamma_TOV[i-1] ) );

      EffPot->Data[i] = EffPot->Data[i+1] - dr * NEWTON_G * ( Mass_NW_C - Mass_TOV_C ) / SQR( Radius[i] );
   }

   double dr         = Radius[0] - Radius[1];
   double Mass_NW_C  = Mass_NW[0];
   double Mass_TOV_C = ( Mass_TOV[0] + FourPI * CUBE( Radius[0] ) * Pres[0] * _c2 )
                     * ( 1.0 + ( Engy[0] + Pres[0] ) / ( Dens[0] * c2 ) )
                     / SQR( Gamma_TOV[0] );

   EffPot->Data[0] = EffPot->Data[1] - dr * NEWTON_G * ( Mass_NW_C - Mass_TOV_C ) / SQR( Radius[0] ) ;


// troubleshooting information
#  ifdef GAMER_DEBUG
   if ( MPI_Rank == 0 )
   {
      char FileName[MAX_STRING];

      sprintf( FileName, "GREP_Lv%02d", lv );
      FILE *File = fopen( FileName, "w" );

//    metadata
      fprintf( File, "# Step                 : %ld\n",                  Step );
      fprintf( File, "# Time                 : %.7e\n",                 Time );
      fprintf( File, "# GREP_CENTER_METHOD   : %d\n",                   GREP_CENTER_METHOD );
      fprintf( File, "# Center               : %13.7e %13.7e %13.7e\n", EffPot->Center[0], EffPot->Center[1], EffPot->Center[2] );
      fprintf( File, "# Maximum Radius       : %13.7e\n",               EffPot->MaxRadius );
      fprintf( File, "# LogBin               : %d\n",                   EffPot->LogBin );
      fprintf( File, "# LogBinRatio          : %13.7e\n",               EffPot->LogBinRatio );
      fprintf( File, "# Number of Iterations : %d\n",                   NIter );
      fprintf( File, "# NBin                 : %d\n",                   NBin );
      fprintf( File, "# -------------------------------------------------\n" );
      fprintf( File, "%5s %9s %22s %22s %22s %22s %22s %22s %22s %22s %23s\n",
                     "# Bin", "NCell", "Radius", "Density", "Energy", "Vr", "Pressure",
                     "Mass_NW", "Mass_TOV", "Gamma_TOV", "Eff_Pot");

//    data
      for (int i=0; i<NBin; i++)
      fprintf( File, "%5d %9ld %22.15e %22.15e %22.15e %22.15e %22.15e %22.15e %22.15e %22.15e %23.15e\n",
                     i, DensAve->NCell[i], Radius[i], Dens[i], Engy[i], Vr[i], Pres[i],
                     Mass_NW[i], Mass_TOV[i], Gamma_TOV[i], EffPot->Data[i] );

      fclose( File );
   }
#  endif


// free memory
   delete [] Mass_NW;
   delete [] Mass_TOV;
   delete [] Mass_TOV_USG;
   delete [] Dens_TOV;
   delete [] Gamma_TOV;
   delete [] dVol;
   delete [] EdgeL;

} // FUNCTION : CPU_ComputeGREP
