#include "GAMER.h"




#ifdef SUPPORT_HYPRE

static void Hypre_Solve_SStructSysPFMG();

// void Hypre_Solve()
// {
//    // HYPRE_SStructVectorAssemble( Hypre_b );
// 
// // setup solver (Split solver)
//    const int  MaxIter = 10;
//    const real RelTol  = 1.e-6;
//    int hypre_ierr;
// 
//    printf("Create\n");
//    hypre_ierr = HYPRE_SStructSplitCreate( MPI_COMM_WORLD, &Hypre_solver );
//          if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
// 
//    // HYPRE_SStructSplitSetStructSolver( Hypre_solver, ... ); // HYPRE_SMG or HYPRE_PFMG
//    HYPRE_SStructSplitSetMaxIter( Hypre_solver, MaxIter );
//    HYPRE_SStructSplitSetTol( Hypre_solver, RelTol );
// 
//    printf("Setup\n");
//    hypre_ierr = HYPRE_SStructSplitSetup( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );
//          if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
// 
//    printf("Solve\n");
//    hypre_ierr = HYPRE_SStructSplitSolve( Hypre_solver, Hypre_A, Hypre_b, Hypre_x );
//          if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
// 
//    printf("Destory\n");
//    hypre_ierr = HYPRE_SStructSplitDestroy( Hypre_solver );
//          if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
// 
// } // FUNCTION : Hypre_Solve



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
   // HYPRE_SStructVectorAssemble( Hypre_b );

// setup solver (Split solver)
   const int  MaxIter = 1000;
   const real RelTol  = 1.e-6;
   int hypre_ierr;

   const int n_pre = 1, n_post = 1;

   printf("create\n");
#  ifdef LOAD_BALANCE
   hypre_ierr = HYPRE_SStructSysPFMGCreate(MPI_COMM_WORLD, &Hypre_solver);
#  else
   hypre_ierr = HYPRE_SStructSysPFMGCreate(NULL, &Hypre_solver);
#  endif
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );

   /* Set sysPFMG parameters */
   printf("minor setup\n");
   hypre_ierr = HYPRE_SStructSysPFMGSetTol(Hypre_solver, 1.0e-6);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructSysPFMGSetMaxIter(Hypre_solver, 50);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructSysPFMGSetNumPreRelax(Hypre_solver, n_pre);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructSysPFMGSetNumPostRelax(Hypre_solver, n_post);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructSysPFMGSetPrintLevel(Hypre_solver, 0);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructSysPFMGSetLogging(Hypre_solver, 1);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );

   /* do the setup */
   printf("setup\n");
   hypre_ierr = HYPRE_SStructSysPFMGSetup(Hypre_solver, Hypre_A, Hypre_b, Hypre_x);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );

   /* do the solve */
   printf("solve\n");
   hypre_ierr = HYPRE_SStructSysPFMGSolve(Hypre_solver, Hypre_A, Hypre_b, Hypre_x);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );

   /* get some info */
   // HYPRE_SStructSysPFMGGetFinalRelativeResidualNorm(Hypre_solver,
   //                                                  &final_res_norm);
   // HYPRE_SStructSysPFMGGetNumIterations(Hypre_solver, &its);

   /* clean up */
   printf("Destory\n");
   hypre_ierr = HYPRE_SStructSysPFMGDestroy(Hypre_solver);
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
} // FUNCTION : Hypre_Solve_SStructSysPFMG
#endif// #ifdef SUPPORT_HYPRE
