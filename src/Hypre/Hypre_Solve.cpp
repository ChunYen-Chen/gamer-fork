#include "GAMER.h"




#ifdef SUPPORT_HYPRE
static void Hypre_Solve_SStructSysPFMG();



void Hypre_Solve()
{

   switch ( HYPRE_SOLVER )
   {
      case HYPRE_SOLVER_SSTRUCT_SYS_PFMG: Hypre_Solve_SStructSysPFMG(); break;
      default: Aux_Error( ERROR_INFO, "Unknown HYPRE_SOLVER: %d !!\n", HYPRE_SOLVER );
   } // switch ( HYPRE_SOLVER )

} // FUNCTION : Hypre_Solve



void Hypre_Solve_SStructSysPFMG()
{

   const int  n_pre   = 1;
   const int  n_post  = 1;
   const int  MaxIter = 50;
   const real RelTol  = 1.e-6;
   int hypre_ierr;

#  ifdef LOAD_BALANCE
   hypre_ierr = HYPRE_SStructSysPFMGCreate( MPI_COMM_WORLD, &Hypre_solver );
#  else
   hypre_ierr = HYPRE_SStructSysPFMGCreate( NULL, &Hypre_solver );
#  endif

// Set sysPFMG parameters
   hypre_ierr = HYPRE_SStructSysPFMGSetTol( Hypre_solver, RelTol );
   hypre_ierr = HYPRE_SStructSysPFMGSetMaxIter( Hypre_solver, MaxIter );
   hypre_ierr = HYPRE_SStructSysPFMGSetNumPreRelax( Hypre_solver, n_pre );
   hypre_ierr = HYPRE_SStructSysPFMGSetNumPostRelax( Hypre_solver, n_post );
   hypre_ierr = HYPRE_SStructSysPFMGSetPrintLevel( Hypre_solver, 0 );
   hypre_ierr = HYPRE_SStructSysPFMGSetLogging( Hypre_solver, 1 );

// do the setup
   hypre_ierr = HYPRE_SStructSysPFMGSetup( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );

// do the solve
   hypre_ierr = HYPRE_SStructSysPFMGSolve( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );

// get some info
   // HYPRE_SStructSysPFMGGetFinalRelativeResidualNorm( Hypre_solver, &final_res_norm );
   // HYPRE_SStructSysPFMGGetNumIterations( Hypre_solver, &its );

// clean up
   hypre_ierr = HYPRE_SStructSysPFMGDestroy( Hypre_solver );

} // FUNCTION : Hypre_Solve_SStructSysPFMG



void Hypre_Solve_SStructSplit()
{

   const int  MaxIter = 10;
   const real RelTol  = 1.e-6;
   int hypre_ierr;

   hypre_ierr = HYPRE_SStructSplitCreate( MPI_COMM_WORLD, &Hypre_solver );

   // HYPRE_SStructSplitSetStructSolver( Hypre_solver, ... ); // HYPRE_SMG or HYPRE_PFMG
   hypre_ierr = HYPRE_SStructSplitSetMaxIter( Hypre_solver, MaxIter );
   hypre_ierr = HYPRE_SStructSplitSetTol( Hypre_solver, RelTol );

   hypre_ierr = HYPRE_SStructSplitSetup( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );

   hypre_ierr = HYPRE_SStructSplitSolve( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );

   hypre_ierr = HYPRE_SStructSplitDestroy( Hypre_solver );

} // FUNCTION : Hypre_Solve
#endif // #ifdef SUPPORT_HYPRE
