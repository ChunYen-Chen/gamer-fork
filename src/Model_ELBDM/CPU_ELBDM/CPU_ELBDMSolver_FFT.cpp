#include "GAMER.h"

#if ( MODEL == ELBDM  &&  defined SUPPORT_FFTW )



static void Psi_Advance_FFT( real *PsiR, real *PsiI, const int j_start, const int dj, const int PsiK_Size, const real dt );

#ifdef SERIAL
extern fftwnd_plan     FFTW_Plan_Psi, FFTW_Plan_Psi_Inv;
#else
extern fftwnd_mpi_plan FFTW_Plan_Psi, FFTW_Plan_Psi_Inv;
#endif




//-------------------------------------------------------------------------------------------------------
// Function    :  Psi_Advance_FFT
// Description :  Use FFT to advance the wave function by the kinetic operator (the pseudo-spectral method)
//
// Note        :  1. Invoked by CPU_ELBDMSolver_FFT()
//                2. Advance wave function by exp( -i*dt*k^2/(2*ELBDM_ETA) ) in the k-space
//
// Parameter   :  PsiR     : Array storing the real part of wave function (input and output)
//                PsiI     : Array storing the imag part of wave function (input and output)
//                j_start  : Starting j index
//                dj       : Size of array in the j (y) direction after the forward FFT
//                PsiK_Size: Size of the array "PsiK"
//                dt       : Time interval to advance solution
//-------------------------------------------------------------------------------------------------------
void Psi_Advance_FFT( real *PsiR, real *PsiI, const int j_start, const int dj, const int PsiK_Size, const real dt )
{

   const int Nx        = NX0_TOT[0];
   const int Ny        = NX0_TOT[1];
   const int Nz        = NX0_TOT[2];
   const real dh       = amr->dh[0];
   const real Dt_2Eta  = (real)0.5*dt/ELBDM_ETA;
   real PsiKR, PsiKI, DtKK_2Eta;
   fftw_complex *PsiK;
   PsiK = (fftw_complex*) malloc( PsiK_Size * sizeof(fftw_complex) );

   for (int t=0; t<PsiK_Size; t++)
   {
      PsiK[t].re = PsiR[t];
      PsiK[t].im = PsiI[t];
   }


// forward FFT
#  ifdef SERIAL
   fftwnd_one( FFTW_Plan_Psi, PsiK, NULL );
#  else
   fftwnd_mpi( FFTW_Plan_Psi, 1, PsiK, NULL, FFTW_TRANSPOSED_ORDER );
#  endif


// set up the dimensional wave number
// and the k-space evolution phase (K_i*K_i)*dt/(2*ELBDM_ETA), where i=x,y,z
   real Kx[Nx], Ky[Ny], Kz[Nz];
   real DtKxKx_2Eta[Nx], DtKyKy_2Eta[Ny], DtKzKz_2Eta[Nz];

   for (int i=0; i<Nx; i++)
   {
      Kx[i]          = ( i <= Nx/2 ) ? 2.0*M_PI/(Nx*dh)*i : 2.0*M_PI/(Nx*dh)*(i-Nx);
      DtKxKx_2Eta[i] = SQR(Kx[i])*Dt_2Eta;
   }
   for (int j=0; j<Ny; j++)
   {
      Ky[j]          = ( j <= Ny/2 ) ? 2.0*M_PI/(Ny*dh)*j : 2.0*M_PI/(Ny*dh)*(j-Ny);
      DtKyKy_2Eta[j] = SQR(Ky[j])*Dt_2Eta;
   }
   for (int k=0; k<Nz; k++)
   {
      Kz[k]          = ( k <= Nz/2 ) ? 2.0*M_PI/(Nz*dh)*k : 2.0*M_PI/(Nz*dh)*(k-Nz);
      DtKzKz_2Eta[k] = SQR(Kz[k])*Dt_2Eta;
   }


// multiply the wave function by exp( -i*dt*k^2/(2*ELBDM_ETA) ) in the k-space
#  ifdef SERIAL // serial mode

#  pragma omp parallel for schedule( runtime )
   for (int k=0; k<Nz; k++)
   {
      for (int j=0; j<Ny; j++)
      for (int i=0; i<Nx; i++)
      {
         long ID = ((long)k*Ny + j)*Nx + i;

#  else // parallel mode

#  pragma omp parallel for schedule( runtime )
   for (int jj=0; jj<dj; jj++)
   {
      int j = j_start + jj;

      for (int k=0; k<Nz; k++)
      for (int i=0; i<Nx; i++)
      {
         long ID = ((long)jj*Nz + k)*Nx + i;

#  endif // #ifdef SERIAL ... else ...

         const real PsiKR = PsiK[ID].re;
         const real PsiKI = PsiK[ID].im;
         const real DtKK_2Eta = DtKxKx_2Eta[i] + DtKyKy_2Eta[j] + DtKzKz_2Eta[k];

         PsiK[ID].re =  PsiKR * COS(DtKK_2Eta) + PsiKI * SIN(DtKK_2Eta);
         PsiK[ID].im =  PsiKI * COS(DtKK_2Eta) - PsiKR * SIN(DtKK_2Eta);

      } // i,j,k
   } // i,j,k


// backward FFT
#  ifdef SERIAL
   fftwnd_one( FFTW_Plan_Psi_Inv, PsiK, NULL );
#  else
   fftwnd_mpi( FFTW_Plan_Psi_Inv, 1, PsiK, NULL, FFTW_TRANSPOSED_ORDER );
#  endif

// normalization
   const real norm = 1.0 / ( (real)Nx*Ny*Nz );

   for (int t=0; t<PsiK_Size; t++)
   {
      PsiR[t] = PsiK[t].re * norm;
      PsiI[t] = PsiK[t].im * norm;
   }

   free( PsiK );

} // FUNCTION : Psi_Advance_FFT



//-------------------------------------------------------------------------------------------------------
// Function    :  CPU_ELBDMSolver_FFT
// Description :  CPU ELBDM kinetic solver of base-level wave function using FFT (the pseudo-spectral method)
//
// Note        :  1. Work with the option ELBDM_BASE_SPECTRAL
//                2. Invoked by Flu_AdvanceDt()
//
// Parameter   :  dt       : Time interval to advance solution
//                PrepTime : Physical time for preparing the wave function
//                SaveSg   : Sandglass to store the updated data
//-------------------------------------------------------------------------------------------------------
void CPU_ELBDMSolver_FFT( const real dt, const double PrepTime, const int SaveSg )
{
// determine the FFT size
   const int FFT_Size[3] = { NX0_TOT[0], NX0_TOT[1], NX0_TOT[2] };


// get the array indices using by FFTW
   int local_nz, local_z_start, local_ny_after_transpose, local_y_start_after_transpose, total_local_size;

#  ifdef SERIAL
   local_nz                      = FFT_Size[2];
   local_z_start                 = 0;
   local_ny_after_transpose      = NULL_INT;
   local_y_start_after_transpose = NULL_INT;
   total_local_size              = FFT_Size[0]*FFT_Size[1]*FFT_Size[2];
#  else
   fftwnd_mpi_local_sizes( FFTW_Plan_Psi, &local_nz, &local_z_start, &local_ny_after_transpose,
                           &local_y_start_after_transpose, &total_local_size );
#  endif


// collect "local_nz" from all ranks and set the corresponding list "List_z_start"
   int List_nz     [MPI_NRank  ];   // slab thickness of each rank in the FFTW slab decomposition
   int List_z_start[MPI_NRank+1];   // starting z coordinate of each rank in the FFTW slab decomposition

   MPI_Allgather( &local_nz, 1, MPI_INT, List_nz, 1, MPI_INT, MPI_COMM_WORLD );

   List_z_start[0] = 0;
   for (int r=0; r<MPI_NRank; r++)  List_z_start[r+1] = List_z_start[r] + List_nz[r];

   if ( List_z_start[MPI_NRank] != FFT_Size[2] )
      Aux_Error( ERROR_INFO, "List_z_start[%d] (%d) != expectation (%d) !!\n",
                 MPI_NRank, List_z_start[MPI_NRank], FFT_Size[2] );


// allocate memory
   const int NRecvSlice = MIN( List_z_start[MPI_Rank]+local_nz, NX0_TOT[2] ) - MIN( List_z_start[MPI_Rank], NX0_TOT[2] );

   real *PsiR         = new real [ total_local_size ];                           // array storing the real part of wave function
   real *PsiI         = new real [ total_local_size ];                           // array storing the imag part of wave function
   real *SendBuf      = new real [ amr->NPatchComma[0][1]*CUBE(PS1) ];           // MPI send buffer
   real *RecvBuf      = new real [ NX0_TOT[0]*NX0_TOT[1]*NRecvSlice ];           // MPI recv buffer
   long *SendBuf_SIdx = new long [ amr->NPatchComma[0][1]*PS1 ];                 // MPI send buffer for 1D coordinate in slab
   long *RecvBuf_SIdx = new long [ NX0_TOT[0]*NX0_TOT[1]*NRecvSlice/SQR(PS1) ];  // MPI recv buffer for 1D coordinate in slab

   int  *List_PID_R  [MPI_NRank];   // PID of each patch slice sent to each rank for the real part
   int  *List_k_R    [MPI_NRank];   // local z coordinate of each patch slice sent to each rank for the real part
   int  *List_PID_I  [MPI_NRank];   // PID of each patch slice sent to each rank for the imag part
   int  *List_k_I    [MPI_NRank];   // local z coordinate of each patch slice sent to each rank for the imag part
   int   List_NSend  [MPI_NRank];   // size of data sent to each rank
   int   List_NRecv  [MPI_NRank];   // size of data received from each rank
   const bool InPlacePad_No = false;   // not pad the array for in-place real-to-complex FFT
   const bool ForPoisson_No = false;   // not for the Poisson solver


// rearrange data from patch to slab
   Patch2Slab( PsiR, SendBuf, RecvBuf, SendBuf_SIdx, RecvBuf_SIdx, List_PID_R, List_k_R, List_NSend, List_NRecv, List_z_start,
               local_nz, FFT_Size, NRecvSlice, PrepTime, _REAL, InPlacePad_No, ForPoisson_No, false );
   Patch2Slab( PsiI, SendBuf, RecvBuf, SendBuf_SIdx, RecvBuf_SIdx, List_PID_I, List_k_I, List_NSend, List_NRecv, List_z_start,
               local_nz, FFT_Size, NRecvSlice, PrepTime, _IMAG, InPlacePad_No, ForPoisson_No, false );


// advance wave function by exp( -i*dt*k^2/(2*ELBDM_ETA) ) in the k-space using FFT
   Psi_Advance_FFT( PsiR, PsiI, local_y_start_after_transpose, local_ny_after_transpose, total_local_size , dt );


// rearrange data from slab back to patch
   Slab2Patch( PsiR, RecvBuf, SendBuf, SaveSg, RecvBuf_SIdx, List_PID_R, List_k_R, List_NRecv, List_NSend,
               local_nz, FFT_Size, NRecvSlice, _REAL, InPlacePad_No );
   Slab2Patch( PsiI, RecvBuf, SendBuf, SaveSg, RecvBuf_SIdx, List_PID_I, List_k_I, List_NRecv, List_NSend,
               local_nz, FFT_Size, NRecvSlice, _IMAG, InPlacePad_No );


// update density according to the updated wave function
#  pragma omp parallel for schedule( runtime )
   for (int PID=0; PID<amr->NPatchComma[0][1]; PID++)
   for (int k=0; k<PS1; k++)
   for (int j=0; j<PS1; j++)
   for (int i=0; i<PS1; i++)
   {
      const real NewReal = amr->patch[SaveSg][0][PID]->fluid[REAL][k][j][i];
      const real NewImag = amr->patch[SaveSg][0][PID]->fluid[IMAG][k][j][i];
      const real NewDens = SQR( NewReal ) + SQR( NewImag );

      amr->patch[SaveSg][0][PID]->fluid[DENS][k][j][i] = NewDens;
   } // PID,i,j,k


   // free memory
   delete [] PsiR;
   delete [] PsiI;
   delete [] SendBuf;
   delete [] RecvBuf;
   delete [] SendBuf_SIdx;
   delete [] RecvBuf_SIdx;

} // FUNCTION : CPU_ELBDMSolver_FFT



#endif // #if ( MODEL == ELBDM  &&  defined SUPPORT_FFTW )
