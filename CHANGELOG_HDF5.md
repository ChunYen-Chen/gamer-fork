# Changelog of GAMER HDF5 output data

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).


## [Unreleased] - YYYY-MM-DD

### Added
- Nothing

### Changed
- Nothing

### Deprecated
- Nothing

### Removed
- Nothing

### Fixed
- Nothing


## [2478] - 2024-04-09

### Added
- ANGMOM_ORIGIN_X
- ANGMOM_ORIGIN_Y
- ANGMOM_ORIGIN_Z


## [2477] - 2024-04-05

### Added
- OPT__RECORD_CENTER
- COM_CEN_X
- COM_CEN_Y
- COM_CEN_Z
- COM_MAX_R
- COM_MIN_RHO
- COM_TOLERR_R
- COM_MAX_ITER


## [2476] - 2024-03-31

### Added
- particle attribute with assigned precision set by FLOAT8_PAR in Makefile
- record value of FLOAT8_PAR as Makefile.Float8_Par and KeyInfo.Float8_Par


## [2475] - 2024-03-28

### Added
- YT_JUPYTER_USE_CONNECTION_FILE
- LIBYT_RELOAD
- LIBYT_INTERACTIVE
- LIBYT_JUPYTER


## [2474] - 2023-11-22

### Added
- OPT__UM_IC_FLOAT8
- PAR_IC_FLOAT8


## [2473] - 2023-11-29

### Added
- SRHD options and fields


## [2472] - 2023-11-11

### Added
- FixUpVar_Flux
- FixUpVar_Restrict


## [2471] - 2023-11-09

### Added
- cosmic-ray options


## [2470] - 2023-10-16

### Added
- OPT__OUTPUT_TEXT_FORMAT_FLT


## [2469] - 2023-09-09

### Added
- MHM_CHECK_PREDICT


## [2468] - 2023-06-24

### Added
- OPT__SORT_PATCH_BY_LBIDX


## [2467] - 2023-05-18

### Changed
- OPT__INIT_BFIELD_BYFILE -> OPT__INIT_BFIELD_BYVECPOT


## [2466] - 2023-05-08

### Added
- OPT__FFTW_STARTUP


## [2465] - 2023-04-29

### Added
- MU_NORM


## [2464] - 2023-04-27

### Added
- LIBYT_INTERACTIVE


## [2463] - 2023-03-20

### Added
- FB_SEP_FLUOUT


## [2462] - 2023-03-19

### Added
- FB_GHOST_SIZE
- FB_NXT


## [2461] - 2023-01-28

### Added
- OPT__RESET_FLUID_INIT


## [2460] - 2022-12-15

### Added
- SUPPORT_FFTW


## [2459] - 2022-11-04

### Added
- REFINE_NLEVEL


## [2458] - 2022-10-24

### Added
- AUTO_REDUCE_MINMOD_FACTOR
- AUTO_REDUCE_MINMOD_MIN
- AUTO_REDUCE_INT_MONO_FACTOR
- AUTO_REDUCE_INT_MONO_MIN
- INT_MONO_COEFF_B


## [2457] - 2022-10-20

### Added
- RSOLVER_RESCUE


## [2456] - 2022-10-17

### Added
- INTERP_MASK
- OPT__CK_INPUT_FLUID


## [2455] - 2022-10-10

### Added
- OPT__SAME_INTERFACE_B


## [2454] - 2022-07-13

### Added
- OPT__INT_PRIM


## [2453] - 2022-07-08

### Added
- OPT__OUTPUT_RESTART


## [2452] - 2021-04-03

### Added
- FB_RSEED


## [2451] - 2021-04-02

### Added
- FB_SNE
- FB_USER


## [2450] - 2021-03-21

### Added
- FB_LEVEL


## [2449] - 2021-03-21

### Added
- FEEDBACK


## [2448] - 2022-05-18

### Added
- PAR_IC_TYPE


## [2447] - 2022-05-11

### Added
- MASSIVE_PARTICLES
- TRACER
- PAR_NTYPE
- GhostSizeTracer


## [2446] - 2022-05-10

### Added
- SUPPORT_LIBYT
- LIBYT_USE_PATCH_GROUP


## [2445] - 2022-03-25

### Added
- OPT__OUTPUT_ENTR


## [2444] - 2022-03-16

### Added
- OPT__FLAG_LOHNER_ENTR and MIN_ENTR


## [2443] - 2022-01-30

### Added
- MINMOD_MAX_ITER
- MONO_MAX_ITER


## [2442] - 2022-01-22

### Added
- OPT__FREEZE_PAR


## [2441] - 2021-10-20

### Added
- OPT__FREEZE_FLUID


## [2440] - 2021-06-17

### Added
- NFieldStored
- NMagStored
- NFieldStoredMax


## [2439] - 2021-06-05

### Added
- UniqueDataID


## [2438] - 2021-06-05

### Added
- git information


## [2437] - 2021-05-12

### Added
- OPT__CHECK_PRES_AFTER_FLU


## [2436] - 2021-04-06

### Added
- UM_IC_RefineRegion


## [2435] - 2021-04-06

### Added
- OPT__UM_IC_NLEVEL


## [2434] - 2021-03-12

### Added
- OPT__INT_FRAC_PASSIVE_LR
- PassiveIntFrac_NVar
- PassiveIntFrac_VarIdx


## [2433] - 2021-02-14

### Added
- MIN_TEMP


## [2432] - 2021-02-13

### Added
- OPT__OUTPUT_* of various derived fields


## [2431] - 2021-02-13

### Added
- DER_GHOST_SIZE
- DER_NXT
- DER_NOUT_MAX
- SRC_NXT


## [2430] - 2021-02-05

### Added
- EXT_POT_NGENE_MAX


## [2429] - 2021-01-26

### Added
- SRC_DLEP_PROF_NVAR
- SRC_DLEP_PROF_NBINMAX


## [2428] - 2020-12-27

### Added
- SRC_NAUX_DLEP
- SRC_NAUX_USER


## [2427] - 2020-12-26

### Added
- SRC_BLOCK_SIZE
- SRC_GHOST_SIZE


## [2426] - 2020-12-24

### Added
- FLU_NIN_S
- FLU_NOUT_S
- SRC_GPU_NPGROUP


## [2425] - 2020-12-24

### Added
- SRC_DELEPTONIZATION


## [2424] - 2020-12-22

### Added
- SRC_USER


## [2423] - 2020-11-01

### Added
- EOS_NTABLE_MAX


## [2422] - 2020-10-29

### Added
- the parameters of external potential table


## [2421] - 2020-10-26

### Added
- COSMIC_RAY


## [2420] - 2020-10-12

### Added
- OPT__FLAG_USER_NUM and use variable-length datatype for FlagTable_User


## [2419] - 2020-09-25

### Added
- EXTPOT_BLOCK_SIZE


## [2418] - 2020-09-21

### Changed
- OPT__GRAVITY_TYPE -> OPT__SELF_GRAVITY
- OPT__EXTERNAL_POT -> OPT__EXT_ACC and OPT__EXT_POT


## [2417] - 2020-09-09

### Added
- ISO_TEMP


## [2416] - 2020-09-08

### Added
- BAROTROPIC_EOS


## [2415] - 2020-09-08

### Added
- OPT__LAST_RESORT_FLOOR


## [2414] - 2020-09-06

### Added
- INT_OPP_SIGN_0TH_ORDER


## [2413] - 2020-08-23

### Added
- HLLD_WAVESPEED


## [2412] - 2020-08-17

### Added
- FLU_NIN_T


## [2411] - 2020-08-11

### Added
- LR_EINT


## [2410] - 2020-07-31

### Added
- HLLE_WAVESPEED


## [2409] - 2020-07-05

### Added
- HLLC_WAVESPEED


## [2408] - 2020-05-10

### Added
- EOS_NAUX_MAX


## [2407] - 2020-02-27

### Added
- MIN_EINT


## [2406] - 2020-02-26

### Added
- EOS


## [2405] - 2019-12-29

### Added
- GRACKLE_THREE_BODY_RATE
- GRACKLE_CIE_COOLING
- GRACKLE_H2_OPA_APPROX


## [2404] - 2019-10-16

### Added
- DT__MAX


## [2403] - 2019-09-20

### Added
- BIT_REP_FLUX defined in CUFLU.h
- BIT_REP_ELECTRIC defined in CUFLU.h


## [2402] - 2019-07-17

### Changed
- USG_GhostSize -> USG_GhostSizeF and USG_GhostSizeG


## [2401] - 2019-06-30

### Added
- OPT__FLAG_CURRENT
- FlagTable_Current


## [2400] - 2019-06-08

### Added
- magnetic field for MHD


## [2312] - 2019-05-31

### Added
- OPT__GRAVITY_EXTRA_MASS


## [2311] - 2019-05-22

### Added
- OPT__CK_DIVERGENCE_B


## [2310] - 2019-04-20

### Added
- OPT__CK_INTERFACE_B


## [2309] - 2019-03-27

### Added
- OPT__FIXUP_ELECTRIC


## [2308] - 2019-03-14

### Added
- OPT__RECORD_NOTE and OPT__RECORD_UNPHY


## [2307] - 2018-12-27

### Changed
- GRA_BLOCK_SIZE_Z -> GRA_BLOCK_SIZE


## [2306] - 2018-12-25

### Changed
- DT_GRA_BLOCK_SIZE_Z -> DT_GRA_BLOCK_SIZE


## [2305] - 2018-12-15

### Removed
- variables related to the WAF scheme


## [2304] - 2018-12-10

### Removed
- EP_Coeff that no longer exists


## [2303] - 2018-10-04

### Added
- set "CodeVersion" to VERSION defined in Macro.h


## [2302] - 2018-07-24

### Changed
- GRACKLE_MODE -> GRACKLE_ACTIVATE


## [2301] - 2018-07-24

### Added
- OPT__UM_IC_FORMAT
- PAR_IC_FORMAT
- PAR_IC_MASS


## [2300] - 2018-07-15

### Changed
- PAR_NVAR and PAR_NPASSIVE -> PAR_NATT_STORED and PAR_NATT_USER
- use the new infrastructure for adding user-defined grid fields and particle attributes
  --> imcompatible with version 2266 for the data with user-defined grid fields and particle attributes as their labels may have changed


## [2266] - 2018-05-11

### Added
- OPT__UM_IC_LOAD_NRANK


## [2265] - 2018-04-02

### Added
- OPT__NO_FLAG_NEAR_BOUNDARY


## [2264] - 2018-02-28

### Added
- RANDOM_NUMBER


## [2263] - 2017-12-27

### Added
- OPT__RESTART_HEADER


## [2262] - 2017-12-27

### Changed
- rename all UM variables


## [2261] - 2017-12-05

### Removed
- no longer define INTEL


## [2259] - 2017-10-10

### Added
- OPT__INIT_GRID_WITH_OMP


## [2258] - 2017-09-21

### Added
- OPT__MINIMIZE_MPI_BARRIER


## [2257] - 2017-09-17

### Added
- OPT__OPTIMIZE_AGGRESSIVE


## [2256] - 2017-09-10

### Added
- FLAG_BUFFER_SIZE_MAXM2_LV


## [2254] - 2017-08-29

### Added
- star formation parameters


## [2253] - 2017-08-27

### Added
- STAR_FORMATION


## [2252] - 2017-08-17

### Added
- GRACKLE_PE_HEATING
- GRACKLE_PE_HEATING_RATE


## [2255] - 2017-09-01

### Added
- SF_CREATION_STAR_DET_RANDOM


## [2251] - 2017-08-12

### Added
- OPT__RESTART_RESET


## [2250] - 2017-08-09

### Added
- dTime_AllLv[]


## [2242] - 2017-08-09

### Added
- DT__SYNC_PARENT_LV
- DT__SYNC_CHILDREN_LV

### Removed
- DT__FLEXIBLE_RANGE


## [2241] - 2017-08-05

### Added
- FLAG_BUFFER_SIZE_MAXM1_LV


## [2240] - 2017-07-26

### Added
- AUTO_REDUCE_DT*


## [2239] - 2017-07-25

### Added
- JEANS_MIN_PRES
- JEANS_MIN_PRES_LEVEL
- JEANS_MIN_PRES_NCELL


## [2238] - 2017-07-19

### Added
- DT_GRA_BLOCK_SIZE_Z
- DT_FLU_USE_SHUFFLE


## [2237] - 2017-07-17

### Added
- DT__FLEXIBLE_RANGE


## [2236] - 2017-07-16

### Added
- DT_FLU_BLOCK_SIZE
- DT_FLU_USE_SHUFFLE


## [2235] - 2017-07-11

### Changed
- IndividualDt and Opt__AdaptiveDt -> Opt__DtLevel


## [2234] - 2017-06-25

### Added
- Grackle variables


## [2233] - 2017-06-13

### Changed
- Opt__Output_TestError -> Opt__Output_User


## [2232] - 2017-06-13

### Added
- TESTPROB_ID


## [2231] - 2017-05-08

### Added
- OPT__FLAG_JEANS
- FlagTable_Jeans


## [2230] - 2017-05-08

### Added
- OPT__FLAG_PAR_MASS_CELL
- FlagTable_ParMassCell


## [2229] - 2017-04-06

### Added
- DUAL_ENERGY
- DUAL_ENERGY_SWITCH


## [2228] - 2017-03-21

### Added
- NCOMP_FLUID in KeyInfo_t
- NCOMP_PASSIVE in KeyInfo_t
- PAR_NPASSIVE in KeyInfo_t


## [2227] - 2017-03-21

### Added
- PassiveFieldName_Grid
- PassiveFieldName_Par


## [2226] - 2017-03-03

### Added
- Opt__RecordLoadBalance


## [2225] - 2017-03-01

### Added
- LB_Par_Weight

### Changed
- LB_Input__WLI_Max -> LB_WLI_Max


## [2224] - 2017-02-25

### Added
- OPT__CK_NORMALIZE_PASSIVE


## [2223] - 2017-02-22

### Added
- NormalizePassive_NVar
- NormalizePassive_VarIdx


## [2222] - 2017-02-20

### Added
- OPT__NORMALIZE_PASSIVE


## [2221] - 2017-02-20

### Added
- TINY_NUMBER
- HUGE_NUMBER


## [2220] - 2017-02-14

### Added
- passive grid
- particle variables


## [2218] - 2017-01-28

### Added
- OPT__FLAG_VORTICITY and the corresponding flag table


## [2217] - 2017-01-25

### Added
- RESTART_LOAD_NRANK, set CodeVersion to "gamer"


## [2216] - 2016-11-27

### Added
- OPT__FLAG_LOHNER_TEMP


## [2210] - 2016-10-03

### Added
- HUBBLE0
- OPT__UNIT
- UNIT_L/M/T/V/D/E
- MOLECULAR_WEIGHT
