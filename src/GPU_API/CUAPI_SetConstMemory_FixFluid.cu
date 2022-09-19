#include "CUAPI.h"
#include "CUDA_ConstMemory.h"

#if ( defined GPU )

//-------------------------------------------------------------------------------------------------------
// Function    :  CUAPI_SetConstMemory_FixFluid
// Description :  Set the fix fluid constant memory variables on GPU
//
// Note        :  1. Adopt the suggested approach for CUDA version >= 5.0
//                2. Invoked by Init_Load_FixFluid()
//
// Parameter   :  None
//
// Return      :  c_FixSwitch[]
//                FixFlu.FixSwitchPtr
//---------------------------------------------------------------------------------------------------
void CUAPI_SetConstMemory_FixFluid()
{

// copy data to constant memory
   CUDA_CHECK_ERROR(  cudaMemcpyToSymbol( c_FixSwitch, FixFlu.FixSwitch, (NCOMP_TOTAL+NCOMP_MAG)*sizeof(int   ) )  );

// obtain the constant-memory pointers
   CUDA_CHECK_ERROR(  cudaGetSymbolAddress( (void **)&FixFlu.FixSwitchPtr, c_FixSwitch )   );

} // FUNCTION : CUAPI_SetConstMemory_FixFluid



#endif // #if ( defined GPU )
