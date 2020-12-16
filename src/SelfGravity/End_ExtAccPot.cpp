#include "GAMER.h"

#ifdef GRAVITY


// prototypes of built-in ExtPot
#ifdef GREP
void End_ExtPot_GREP();
#endif

// these function pointers can be set by a test problem initializer
void (*End_ExtAcc_Ptr)() = NULL;
void (*End_ExtPot_Ptr)() = NULL;




//-------------------------------------------------------------------------------------------------------
// Function    :  End_ExtAccPot
// Description :  Terminate external acceleration and potential
//
// Note        :  1. Invoked by End_GAMER()
//                2. Function pointers End_ExtAcc_Ptr and End_ExtPot_Ptr can be set by a test problem initializer
//
// Parameter   :  None
//
// Return      :  None
//-------------------------------------------------------------------------------------------------------
void End_ExtAccPot()
{

   if ( MPI_Rank == 0 )    Aux_Message( stdout, "%s ...\n", __FUNCTION__ );


// external acceleration
   if ( OPT__EXT_ACC )
   {
      if ( End_ExtAcc_Ptr != NULL )    End_ExtAcc_Ptr();
   }

// external potential
   if ( OPT__EXT_POT )
   {
//    set the default function pointer of the built-in external potential
#     ifdef GREP
      if ( OPT__EXT_POT == EXT_POT_GREP )    End_ExtPot_Ptr = End_ExtPot_GREP;
#     endif

      if ( End_ExtPot_Ptr != NULL )    End_ExtPot_Ptr();
   }


   if ( MPI_Rank == 0 )    Aux_Message( stdout, "%s ... done\n", __FUNCTION__ );

} // FUNCTION : End_ExtAccPot



#endif // #ifdef GRAVITY
