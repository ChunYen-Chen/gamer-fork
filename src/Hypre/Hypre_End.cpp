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

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s ...\n", __FUNCTION__ );

   int hypre_ierr;

// free memory
   hypre_ierr = HYPRE_SStructGridDestroy( Hypre_grid );
   hypre_ierr = HYPRE_SStructGraphDestroy( Hypre_graph );
   hypre_ierr = HYPRE_SStructStencilDestroy( Hypre_stencil );
   hypre_ierr = HYPRE_SStructMatrixDestroy( Hypre_A );
   hypre_ierr = HYPRE_SStructVectorDestroy( Hypre_b );
   hypre_ierr = HYPRE_SStructVectorDestroy( Hypre_x );

// finalize Hypre
   hypre_ierr = HYPRE_Finalize();
   if ( hypre_ierr ) Aux_Error( ERROR_INFO, "hypre error: %d !!\n", hypre_ierr );

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s ... done\n", __FUNCTION__ );

} // FUNCTION : End_HYPRE
#endif // #ifdef SUPPORT_HYPRE
