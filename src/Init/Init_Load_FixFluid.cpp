#include "GAMER.h"




//-------------------------------------------------------------------------------------------------------
// Function    :  Init_Load_FixFluid
// Description :  Load the dump table from the file "Input__FixFluid"
//-------------------------------------------------------------------------------------------------------
void Init_Load_FixFluid()
{

   if ( MPI_Rank == 0 )    Aux_Message( stdout, "Init_Load_FixFluid ...\n" );


   const char FileName[] = "Input__FixFluid";

   if ( !Aux_CheckFileExist(FileName) )   Aux_Error( ERROR_INFO, "file \"%s\" does not exist !!\n", FileName );

   FILE *File = fopen( FileName, "r" );

   const int MaxLine = 10000;
   char *input_line = NULL;
   size_t len = 0;
   int Trash, line, n;
   int fluidType, fixOrNot;


// TODO
// allocate the dump table, and initialized with 0(not fix)
   FixFlu.FixSwitch = new int [MaxLine];
   for (line=0; line<MaxLine; line++) FixFlu.FixSwitch[line] = 0;


// skip the header
   getline( &input_line, &len, File );

// begin to read
   for (line=0; line<MaxLine; line++)
   {
      n = getline( &input_line, &len, File );
      Aux_Message( stdout, "line: %d, Rank: %d, n: %d\n", line, MPI_Rank, n );

//    check
      if ( n <= 1 )
         Aux_Error( ERROR_INFO, "incorrect reading at line %d of the file <%s> !!\n", line+2, FileName );

      sscanf( input_line, "%d%d", &fluidType, &fixOrNot );
      Aux_Message( stdout, "line: %d, Rank: %d, n: %d, fluidType: %d, fixOrNot: %d\n", line, MPI_Rank, n, fluidType, fixOrNot );
      
//    stop the reading
//    TODO: Should I put in here?
      if ( input_line[0] == 42 )   break;   // '*' == 42

      FixFlu.FixSwitch[fluidType] = fixOrNot;

   } // for (line=0; line<MaxLine; line++)


   if ( line == MaxLine )
      Aux_Error( ERROR_INFO, "please prepare a symbol * in the end of the file <%s> !!\n", FileName );


   fclose( File );

   if ( input_line != NULL )     free( input_line );

   #ifdef GPU
   CUAPI_SetConstMemory_FixFluid();
   #else
   FixFlu.FixSwitchPtr = FixFlu.FixSwitch;
   #endif


   if ( MPI_Rank == 0 )    Aux_Message( stdout, "Init_Load_FixFluid ... done\n" );

} // FUNCTION : Init_Load_FixFluid
