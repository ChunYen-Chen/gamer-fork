#include "GAMER.h"




#ifdef SUPPORT_HYPRE
static void Hypre_Solve_SStructSysPFMG();
static void Hypre_Solve_SStructSplit();



void Hypre_Solve()
{

   switch ( HYPRE_SOLVER )
   {
      case HYPRE_SOLVER_SSTRUCT_SYS_PFMG: Hypre_Solve_SStructSysPFMG(); break;
      case HYPRE_SOLVER_SSTRUCT_SPLIT:    Hypre_Solve_SStructSplit();   break;
      default: Aux_Error( ERROR_INFO, "Unknown HYPRE_SOLVER: %d !!\n", HYPRE_SOLVER );
   } // switch ( HYPRE_SOLVER )

} // FUNCTION : Hypre_Solve



void Hypre_Solve_SStructSysPFMG()
{

   int hypre_ierr;

#  ifdef LOAD_BALANCE
   hypre_ierr = HYPRE_SStructSysPFMGCreate( MPI_COMM_WORLD, &Hypre_solver );
#  else
   hypre_ierr = HYPRE_SStructSysPFMGCreate( NULL,           &Hypre_solver );
#  endif

   hypre_ierr = HYPRE_SStructSysPFMGSetPrintLevel( Hypre_solver, HYPRE_PRINT_LEVEL );
   hypre_ierr = HYPRE_SStructSysPFMGSetLogging( Hypre_solver, HYPRE_ENABLE_LOGGING );

   hypre_ierr = HYPRE_SStructSysPFMGSetZeroGuess( Hypre_solver );

// Set sysPFMG parameters
   hypre_ierr = HYPRE_SStructSysPFMGSetTol( Hypre_solver, HYPRE_REL_TOL );
   hypre_ierr = HYPRE_SStructSysPFMGSetMaxIter( Hypre_solver, HYPRE_MAX_ITER );
   hypre_ierr = HYPRE_SStructSysPFMGSetNumPreRelax( Hypre_solver, HYPRE_NPRE_RELAX );
   hypre_ierr = HYPRE_SStructSysPFMGSetNumPostRelax( Hypre_solver, HYPRE_NPOST_RELAX );

// do the setup
   hypre_ierr = HYPRE_SStructSysPFMGSetup( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );

// do the solve
   hypre_ierr = HYPRE_SStructSysPFMGSolve( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );

// get some info
   int its;
   real final_res_norm;
   HYPRE_SStructSysPFMGGetFinalRelativeResidualNorm( Hypre_solver, &final_res_norm );
   HYPRE_SStructSysPFMGGetNumIterations( Hypre_solver, &its );

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s: Iteration: %d, Residual norm: %24.16e\n", __FUNCTION__, its, final_res_norm );

// clean up
   hypre_ierr = HYPRE_SStructSysPFMGDestroy( Hypre_solver );

} // FUNCTION : Hypre_Solve_SStructSysPFMG



void Hypre_Solve_SStructSplit()
{

   int hypre_ierr;

#  ifdef LOAD_BALANCE
   hypre_ierr = HYPRE_SStructSplitCreate( MPI_COMM_WORLD, &Hypre_solver );
#  else
   hypre_ierr = HYPRE_SStructSplitCreate( NULL,           &Hypre_solver );
#  endif

   hypre_ierr = HYPRE_SStructSplitSetZeroGuess( Hypre_solver );

   // HYPRE_SStructSplitSetStructSolver( Hypre_solver, ... ); // HYPRE_SMG or HYPRE_PFMG
   hypre_ierr = HYPRE_SStructSplitSetMaxIter( Hypre_solver, HYPRE_MAX_ITER );
   hypre_ierr = HYPRE_SStructSplitSetTol( Hypre_solver, HYPRE_REL_TOL );

   hypre_ierr = HYPRE_SStructSplitSetup( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );

   hypre_ierr = HYPRE_SStructSplitSolve( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );

   int its;
   real final_res_norm;
   HYPRE_SStructSplitGetFinalRelativeResidualNorm( Hypre_solver, &final_res_norm );
   HYPRE_SStructSplitGetNumIterations( Hypre_solver, &its );

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s: Iteration: %d, Residual norm: %24.16e\n", __FUNCTION__, its, final_res_norm );

   hypre_ierr = HYPRE_SStructSplitDestroy( Hypre_solver );

} // FUNCTION : Hypre_Solve
#endif // #ifdef SUPPORT_HYPRE
