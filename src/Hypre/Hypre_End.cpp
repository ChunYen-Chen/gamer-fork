#include "GAMER.h"




#ifdef SUPPORT_HYPRE
//-------------------------------------------------------------------------------------------------------
// Function    :  Hypre_End
// Description :  Free the resources used by the Hypre
//
// Note        :  1. Invoked by End_GAMER()
//
// Parameter   :  None
//
// Return      :  None
//-------------------------------------------------------------------------------------------------------
void Hypre_End()
{

   int hypre_ierr;
// free memory
   hypre_ierr = HYPRE_SStructGridDestroy( Hypre_grid );
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructGraphDestroy( Hypre_graph );
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructStencilDestroy( Hypre_stencil );
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructMatrixDestroy( Hypre_A );
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructVectorDestroy( Hypre_b );
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   hypre_ierr = HYPRE_SStructVectorDestroy( Hypre_x );
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );
   // HYPRE_SStructPCGDestroy( Hypre_solver );

// finalize Hypre
   hypre_ierr = HYPRE_Finalize();
         if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );


} // FUNCTION : End_HYPRE
#endif // #ifdef SUPPORT_HYPRE
