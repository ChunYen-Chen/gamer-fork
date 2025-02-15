#include "GAMER.h"




#ifdef SUPPORT_HYPRE
//-------------------------------------------------------------------------------------------------------
// Function    :  Hypre_Init
// Description :  Initialize Hypre
//
// Note        :  1. Invoked by Init_GAMER()
//
// Parameter   :  None
//
// Return      :  None
//-------------------------------------------------------------------------------------------------------
void Hypre_Init()
{

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s ...\n", __FUNCTION__ );

   if ( MAX_LEVEL != 0 )   Aux_Error( ERROR_INFO, "HYPRE: not support AMR yet\n" );

   int hypre_ierr;
// initialize Hypre
   hypre_ierr = HYPRE_Initialize();

   if ( hypre_ierr )
      Aux_Error( ERROR_INFO, "Hypre error: %d\n !!\n", hypre_ierr );

   Hypre_Main();

   if ( MPI_Rank == 0 )   Aux_Message( stdout, "%s ... done\n", __FUNCTION__ );

} // FUNCTION : HYPRE_Init
#endif // #ifdef SUPPORT_HYPRE
