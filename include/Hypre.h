#ifndef __HYPRE_H__
#define __HYPRE_H__



#include "HYPRE_config.h"
#include "HYPRE_sstruct_ls.h"
#include "HYPRE_sstruct_mv.h"
#include "HYPRE_struct_ls.h"
#include "HYPRE_struct_mv.h"
#if ( defined GPU  &&  HYPRE_USING_CUDA == 1 )
#include <cuda_runtime.h>
#endif

#ifdef GAMER_DEBUG
#  define DEBUG_HYPRE
#endif

#if ( defined GPU  &&  HYPRE_USING_CUDA == 1 )
#  define GPU_HYPRE
#endif

#ifndef SERIAL
#define HYPRE_MPI_COMM   MPI_COMM_WORLD
#else
#define HYPRE_MPI_COMM   NULL_INT
#endif


// macro for checking Hypre function return
#ifdef DEBUG_HYPRE

#  define HYPRE_CHECK_FUNC( call )                                         \
   {                                                                       \
      int hypre_ierr = call;                                               \
                                                                           \
      if ( hypre_ierr )                                                    \
         Aux_Error( ERROR_INFO, "hypre error code: %d !!\n", hypre_ierr ); \
   }

#else

#  define HYPRE_CHECK_FUNC( call ) call

#endif



#endif // #ifndef __HYPRE_H__
