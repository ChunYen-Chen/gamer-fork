#include "GAMER.h"
#include "ReadPara.h"




//-------------------------------------------------------------------------------------------------------
// Function    :  Init_Load_FixFluid
// Description :  Load the dump table from the file "Input__FixFluid"
//-------------------------------------------------------------------------------------------------------
void Init_Load_FixFluid()
{

   if ( MPI_Rank == 0 )    Aux_Message( stdout, "Init_Load_FixFluid ...\n" );

   FixFlu.FixSwitch = new int [NCOMP_TOTAL+NCOMP_MAG];
   
   if ( OPT__FIX_FLUID ) {
      #ifdef ELBDM
      Aux_Error( ERROR_INFO, "WARNING : Fix fluid is not supported for ELBDM!\n");
      #endif

      #ifdef GRAVITY
      Aux_Error( ERROR_INFO, "WARNING : Fix fluid is not supported for GRAVITY!\n");
      #endif

      #ifdef PARTICLE
      Aux_Error( ERROR_INFO, "WARNING : Fix fluid is not supported for PARTICLE!\n");
      #endif 

      #ifdef SUPPORT_GRACKLE
      Aux_Error( ERROR_INFO, "WARNING : Fix fluid is not supported for SUPPORT_GRACKLE!\n");
      #endif

      const char FileName[] = "Input__FixFluid";

      if ( !Aux_CheckFileExist(FileName) )   Aux_Error( ERROR_INFO, "file \"%s\" does not exist !!\n", FileName );

      ReadPara_t *ReadFix = new ReadPara_t;

//    add parameters in the following format:
//    --> note that VARIABLE, DEFAULT, MIN, and MAX must have the same data type
//    --> some handy constants (e.g., NoMin_int, Eps_float, ...) are defined in "ReadPara.h"
//    ************************************************************************************************************
//    ReadFix->Add( "FLUID_TYPE_IN_TABLE",     &VARIABLE,                             DEFAULT,     MIN,     MAX );
//    ************************************************************************************************************
      ReadFix->Add( "FIX_DENS",                &FixFlu.FixSwitch[DENS],               0,           0,       1   );
      ReadFix->Add( "FIX_MOMX",                &FixFlu.FixSwitch[MOMX],               0,           0,       1   );
      ReadFix->Add( "FIX_MOMY",                &FixFlu.FixSwitch[MOMY],               0,           0,       1   );
      ReadFix->Add( "FIX_MOMZ",                &FixFlu.FixSwitch[MOMZ],               0,           0,       1   );
      ReadFix->Add( "FIX_ENGY",                &FixFlu.FixSwitch[ENGY],               0,           0,       1   );

      #ifdef MHD
      ReadFix->Add( "FIX_MAGX",                &FixFlu.FixSwitch[NCOMP_TOTAL+MAGX],   0,           0,       1   );
      ReadFix->Add( "FIX_MAGY",                &FixFlu.FixSwitch[NCOMP_TOTAL+MAGY],   0,           0,       1   );
      ReadFix->Add( "FIX_MAGZ",                &FixFlu.FixSwitch[NCOMP_TOTAL+MAGZ],   0,           0,       1   );
      #endif

      #ifdef DUAL_ENERGY
      ReadFix->Add( "FIX_DUAL",                &FixFlu.FixSwitch[DUAL],               0,           0,       1   );
      #endif
      
      #ifdef COSMIC_RAY
      ReadFix->Add( "FIX_CRAY",                &FixFlu.FixSwitch[CRAY],               0,           0,       1   );
      #endif

//    load fix variable switch
//    ************************************************************************************************************
      ReadFix->Read( FileName );
//    ************************************************************************************************************

      delete ReadFix;
   } else {
      for ( int v=0; v<NCOMP_TOTAL+NCOMP_MAG; v++ ) FixFlu.FixSwitch[v] = 0;
   }

   #ifdef GPU
   CUAPI_SetConstMemory_FixFluid();
   #else
   FixFlu.FixSwitchPtr = FixFlu.FixSwitch;
   #endif

   if ( MPI_Rank == 0 )    Aux_Message( stdout, "Init_Load_FixFluid ... done\n" );

} // FUNCTION : Init_Load_FixFluid
