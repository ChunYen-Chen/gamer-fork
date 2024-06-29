| Name                                     |         Default |             Min |             Max | Description |
| :---                                     |            :--- |            :--- |            :--- | :--- |
| ANGMOM_ORIGIN_X                          |            -1.0 |    NoMin_double |    NoMax_double | x coordinate of the origin for angular momentum (<0=auto -> BoxCenter) [-1.0] |
| ANGMOM_ORIGIN_Y                          |            -1.0 |    NoMin_double |    NoMax_double | y coordinate of the origin for angular momentum (<0=auto -> BoxCenter) [-1.0] |
| ANGMOM_ORIGIN_Z                          |            -1.0 |    NoMin_double |    NoMax_double | z coordinate of the origin for angular momentum (<0=auto -> BoxCenter) [-1.0] |
| AUTO_REDUCE_DT                           |            true |    Useless_bool |    Useless_bool | reduce dt automatically when the program fails (for OPT__DT_LEVEL==3 only) [1] |
| AUTO_REDUCE_DT_FACTOR                    |             1.0 |      Eps_double |             1.0 | reduce dt by a factor of AUTO_REDUCE_DT_FACTOR when the program fails [1.0] |
| AUTO_REDUCE_DT_FACTOR_MIN                |             0.1 |             0.0 |             1.0 | minimum allowed AUTO_REDUCE_DT_FACTOR after consecutive failures [0.1] |
| AUTO_REDUCE_INT_MONO_FACTOR              |             0.8 |      Eps_double |             1.0 | reduce INT_MONO_COEFF(_B) by this factor together with AUTO_REDUCE_DT (1.0=off) [0.8] |
| AUTO_REDUCE_INT_MONO_MIN                 |          1.0e-2 |             0.0 |    NoMax_double | minimum allowed INT_MONO_COEFF(_B) after consecutive failures [1.0e-2] |
| AUTO_REDUCE_MINMOD_FACTOR                |             0.8 |      Eps_double |             1.0 | reduce MINMOD_COEFF by this factor together with AUTO_REDUCE_DT (1.0=off) [0.8] ##HYDRO ONLY## |
| AUTO_REDUCE_MINMOD_MIN                   |          1.0e-2 |             0.0 |    NoMax_double | minimum allowed MINMOD_COEFF after consecutive failures [1.0e-2] ##HYDRO ONLY## |
| A_INIT                                   |            -1.0 |      Eps_double |    NoMax_double | initial scale factor |
| BOX_SIZE                                 |            -1.0 |      Eps_double |    NoMax_double | box size along the longest side (in Mpc/h if COMOVING is adopted) |
| CHE_GPU_NPGROUP                          |              -1 |       NoMin_int |       NoMax_int | number of patch groups sent into the CPU/GPU Grackle solver (<=0=auto) [-1] |
| COM_CEN_X                                |            -1.0 |    NoMin_double |    NoMax_double | x coordinate as an initial guess for determining center of mass (if one of COM_CEN_X/Y/Z < 0 -> peak density position x) [-1.0] |
| COM_CEN_Y                                |            -1.0 |    NoMin_double |    NoMax_double | y coordinate as an initial guess for determining center of mass (if one of COM_CEN_X/Y/Z < 0 -> peak density position y) [-1.0] |
| COM_CEN_Z                                |            -1.0 |    NoMin_double |    NoMax_double | z coordinate as an initial guess for determining center of mass (if one of COM_CEN_X/Y/Z < 0 -> peak density position z) [-1.0] |
| COM_MAX_ITER                             |              10 |               1 |       NoMax_int | maximum number of iterations for determining the center of mass (must >= 1) [10] |
| COM_MAX_R                                |            -1.0 |    NoMin_double |    NoMax_double | maximum radius for determining center of mass (<0=auto -> __FLT_MAX__) [-1.0] |
| COM_MIN_RHO                              |             0.0 |             0.0 |    NoMax_double | minimum density for determining center of mass (must >= 0.0) [0.0] |
| COM_TOLERR_R                             |            -1.0 |    NoMin_double |    NoMax_double | maximum tolerated error of deviation in radius during the iterations of determining the center of mass (<0=auto -> amr->dh[MAX_LEVEL]) [-1.0] |
| CR_DIFF_MIN_B                            |             0.0 |    NoMin_double |    NoMax_double | disable diffusion locally when B field amplitude is smaller than this threshold (<=0=off) [0.0] ##CR_DIFFUSION only## |
| CR_DIFF_PARA                             |             0.0 |             0.0 |    NoMax_double | cosmic-ray diffusion coefficients parallel/perpendicular to the |
| CR_DIFF_PERP                             |             0.0 |             0.0 |    NoMax_double | magnetic field [0.0] ##CR_DIFFUSION only## |
| DT__CR_DIFFUSION                         |          3.0e-1 |             0.0 |    NoMax_double | dt criterion: cosmic-ray diffusion CFL factor [0.3] ##CR_DIFFUSION only## |
| DT__FLUID                                |            -1.0 |    NoMin_double |    NoMax_double | dt criterion: fluid solver CFL factor (<0=auto) [-1.0] |
| DT__FLUID_INIT                           |            -1.0 |    NoMin_double |    NoMax_double | dt criterion: DT__FLUID at the first step (<0=auto) [-1.0] |
| DT__GRAVITY                              |            -1.0 |    NoMin_double |    NoMax_double | dt criterion: gravity solver safety factor (<0=auto) [-1.0] |
| DT__MAX                                  |            -1.0 |    NoMin_double |    NoMax_double | dt criterion: maximum allowed dt (<0=off) [-1.0] |
| DT__MAX_DELTA_A                          |            0.01 |             0.0 |    NoMax_double | dt criterion: maximum variation of the cosmic scale factor [0.01] |
| DT__PARACC                               |             0.5 |             0.0 |    NoMax_double | dt criterion: particle acceleration safety factor (0=off) [0.5] ##STORE_PAR_ACC ONLY## |
| DT__PARVEL                               |             0.5 |             0.0 |    NoMax_double | dt criterion: particle velocity safety factor [0.5] |
| DT__PARVEL_MAX                           |            -1.0 |    NoMin_double |    NoMax_double | dt criterion: maximum allowed dt from particle velocity (<0=off) [-1.0] |
| DT__PHASE                                |             0.0 |             0.0 |    NoMax_double | dt criterion: phase rotation safety factor (0=off) [0.0] ##ELBDM ONLY## |
| DT__SPEED_OF_LIGHT                       |           false |    Useless_bool |    Useless_bool | dt criterion: speed of light [0] ##SRHD ONLY## |
| DT__SYNC_CHILDREN_LV                     |             0.1 |             0.0 |             1.0 | dt criterion: allow dt to adjust by (1.0-DT__SYNC_CHILDREN) in order to synchronize with the children level (for OPT__DT_LEVEL==3 only; 0=off) [0.1] |
| DT__SYNC_PARENT_LV                       |             0.1 |             0.0 |    NoMax_double | dt criterion: allow dt to adjust by (1.0+DT__SYNC_PARENT) in order to synchronize with the parent level (for OPT__DT_LEVEL==3 only) [0.1] |
| DUAL_ENERGY_SWITCH                       |          2.0e-2 |             0.0 |    NoMax_double | apply dual-energy if E_int/E_kin < DUAL_ENERGY_SWITCH [2.0e-2] ##DUAL_ENERGY ONLY## |
| ELBDM_LAMBDA                             |             1.0 |    NoMin_double |    NoMax_double | quartic self-interaction coefficient [1.0] ##QUARTIC_SELF_INTERACTION ONLY## |
| ELBDM_MASS                               |            -1.0 |      Eps_double |    NoMax_double | particle mass in ev/c^2 (input unit is fixed even when OPT__UNIT or COMOVING is on) |
| ELBDM_PLANCK_CONST                       |            -1.0 |    NoMin_double |    NoMax_double | reduced Planck constant (will be overwritten if OPT__UNIT or COMOVING is on) |
| ELBDM_TAYLOR3_AUTO                       |            true |    Useless_bool |    Useless_bool | Optimize ELBDM_TAYLOR3_COEFF automatically to minimize the damping at kmax [1] |
| ELBDM_TAYLOR3_COEFF                      |         1.0/6.0 |    NoMin_double |    NoMax_double | 3rd Taylor expansion coefficient [1.0/6.0] ##USELESS if ELBDM_TAYLOR3_AUTO is on## |
| END_STEP                                 |             -1L |      NoMin_long |      NoMax_long | end step (<0=auto -> must be set by test problems or restart) [-1] |
| END_T                                    |            -1.0 |    NoMin_double |    NoMax_double | end physical time (<0=auto -> must be set by test problems or restart) [-1.0] |
| EXT_POT_TABLE_DH_X                       |            -1.0 |    NoMin_double |    NoMax_double | ... : spatial interval between adjacent data points |
| EXT_POT_TABLE_DH_Y                       |            -1.0 |    NoMin_double |    NoMax_double |  |
| EXT_POT_TABLE_DH_Z                       |            -1.0 |    NoMin_double |    NoMax_double |  |
| EXT_POT_TABLE_EDGEL_X                    |    NoDef_double |    NoMin_double |    NoMax_double | ... : starting x/y/z coordinates |
| EXT_POT_TABLE_EDGEL_Y                    |    NoDef_double |    NoMin_double |    NoMax_double |  |
| EXT_POT_TABLE_EDGEL_Z                    |    NoDef_double |    NoMin_double |    NoMax_double |  |
| EXT_POT_TABLE_FLOAT8                     |              -1 |              -1 |              -1 | ... : double precision (<0=auto -> FLOAT8, 0=off, 1=on) [-1] --> not supported yet; use -1 for now |
| EXT_POT_TABLE_NAME                       |       NoDef_str |     Useless_str |     Useless_str | external potential table: filename |
| EXT_POT_TABLE_NPOINT_X                   |              -1 |       NoMin_int |       NoMax_int | ... : table size (i.e., number of data points) along x/y/z |
| EXT_POT_TABLE_NPOINT_Y                   |              -1 |       NoMin_int |       NoMax_int |  |
| EXT_POT_TABLE_NPOINT_Z                   |              -1 |       NoMin_int |       NoMax_int |  |
| FB_LEVEL                                 |              -1 |       NoMin_int |       TOP_LEVEL | AMR level to apply feedback (must be MAX_LEVEL for now; <0=auto -> MAX_LEVEL) [-1] |
| FB_RSEED                                 |             456 |               0 |       NoMax_int | random seed [456] |
| FB_SNE                                   |           false |    Useless_bool |    Useless_bool | supernova explosion feedback [0] |
| FB_USER                                  |           false |    Useless_bool |    Useless_bool | user-defined feedback [0] |
| FLAG_BUFFER_SIZE                         |              -1 |       NoMin_int |             PS1 | number of buffer cells for the flag operation (0~PATCH_SIZE; <0=auto -> PATCH_SIZE) [-1] |
| FLAG_BUFFER_SIZE_MAXM1_LV                |              -1 |       NoMin_int |             PS1 | FLAG_BUFFER_SIZE at the level MAX_LEVEL-1 (<0=auto -> REGRID_COUNT) [-1] |
| FLAG_BUFFER_SIZE_MAXM2_LV                |              -1 |       NoMin_int |             PS1 | FLAG_BUFFER_SIZE at the level MAX_LEVEL-2 (<0=auto) [-1] |
| FLU_GPU_NPGROUP                          |              -1 |       NoMin_int |       NoMax_int | number of patch groups sent into the CPU/GPU fluid solver (<=0=auto) [-1] |
| GAMMA                                    |     __DBL_MAX__ |    NoMin_double |    NoMax_double | ratio of specific heats (i.e., adiabatic index) [5.0/3.0] ##EOS_GAMMA ONLY## |
| GAMMA_CR                                 |         4.0/3.0 |             1.0 |    NoMax_double | effective adiabatic index of cosmic rays [4.0/3.0] |
| GFUNC_COEFF0                             |            -1.0 |    NoMin_double |    NoMax_double | Green's function coefficient at the origin for the isolated BC (<0=auto) [-1.0] |
| GPU_NSTREAM                              |              -1 |       NoMin_int |       NoMax_int | number of CUDA streams for the asynchronous memory copy in GPU (<=0=auto) [-1] |
| GRACKLE_ACTIVATE                         |            true |    Useless_bool |    Useless_bool | enable Grackle [1] |
| GRACKLE_CIE_COOLING                      |           false |    Useless_bool |    Useless_bool | 0: off; 1:on |
| GRACKLE_CLOUDY_TABLE                     |       NoDef_str |     Useless_str |     Useless_str | "grackle_data_file" |
| GRACKLE_CMB_FLOOR                        |            true |    Useless_bool |    Useless_bool | ... "cmb_temperature_floor" [1] |
| GRACKLE_COOLING                          |            true |    Useless_bool |    Useless_bool | ... "with_radiative_cooling" [1] |
| GRACKLE_H2_OPA_APPROX                    |               0 |               0 |               1 | H2 opacity from Ripamonti+04; 0:off, 1:Ripomonti+04 |
| GRACKLE_METAL                            |           false |    Useless_bool |    Useless_bool | ... "metal_cooling" (must increase NCOMP_PASSIVE_USER by 1) [0] |
| GRACKLE_PE_HEATING                       |           false |    Useless_bool |    Useless_bool | ... "photoelectric_heating" [0] |
| GRACKLE_PE_HEATING_RATE                  |         8.5e-26 |             0.0 |    NoMax_double | ... "photoelectric_heating_rate (in erg/cm^3/s)" [8.5e-26] |
| GRACKLE_PRIMORDIAL                       |               0 |               0 |               3 | ... "primordial_chemistry" (0=Cloudy, 1/2/3=6-/9-/12-species) [0] (must increase NCOMP_PASSIVE_USER by 6/9/12, respectively) |
| GRACKLE_THREE_BODY_RATE                  |               0 |               0 |               5 | used Glover+08 rate |
| GRACKLE_UV                               |           false |    Useless_bool |    Useless_bool | ... "UVbackground" [0] |
| GRACKLE_VERBOSE                          |            true |    Useless_bool |    Useless_bool | map to "grackle_verbose" [1] |
| HUBBLE0                                  |            -1.0 |      Eps_double |             1.0 | dimensionless Hubble parameter (currently only for converting ELBDM_MASS to code units) |
| INIT_DUMPID                              |              -1 |       NoMin_int |       NoMax_int | set the first dump ID (<0=auto) [-1] |
| INIT_SUBSAMPLING_NCELL                   |               0 |               0 |       NoMax_int | perform sub-sampling during initialization: (0=off, >0=# of sub-sampling cells) [0] |
| INT_MONO_COEFF                           |             2.0 |             1.0 |             4.0 | coefficient for ensuring the interpolation monotonicity (1.0~4.0) [2.0] |
| INT_MONO_COEFF_B                         |             2.0 |             1.0 |             4.0 | coefficient for ensuring the interpolation monotonicity of B field (1.0~4.0) [2.0] ##MHD ONLY## |
| INT_OPP_SIGN_0TH_ORDER                   |           false |    Useless_bool |    Useless_bool | switch to 0th-order interpolation if adjacent values change signs [HYDRO:1; ELBDM:0] |
| ISO_TEMP                                 |     __DBL_MAX__ |    NoMin_double |    NoMax_double | isothermal temperature in kelvin ##EOS_ISOTHERMAL ONLY## |
| JEANS_MIN_PRES                           |           false |    Useless_bool |    Useless_bool | minimum pressure estimated from the Jeans length [0] ##HYDRO/MHD and GRAVITY ONLY## |
| JEANS_MIN_PRES_LEVEL                     |              -1 |       NoMin_int |        NLEVEL-1 | for JEANS_MIN_PRES; ensure Jeans length is resolved by JEANS_MIN_PRES_NCELL*dh[JEANS_MIN_PRES_LEVEL] (<0=auto -> MAX_LEVEL) [-1] |
| JEANS_MIN_PRES_NCELL                     |               4 |               1 |       NoMax_int | for JEANS_MIN_PRES; see JEANS_MIN_PRES_LEVEL [4] |
| LB_INPUT__PAR_WEIGHT                     |             0.0 |             0.0 |    NoMax_double | load-balance weighting of one particle over one cell [0.0] |
| LB_INPUT__WLI_MAX                        |             0.1 |             0.0 |    NoMax_double | weighted-load-imbalance (WLI) threshold for redistributing all patches [0.1] |
| MAX_LEVEL                                |       TOP_LEVEL |               0 |       TOP_LEVEL | maximum refinement level (0~NLEVEL-1) [NLEVEL-1] |
| MG_MAX_ITER                              |              -1 |       NoMin_int |       NoMax_int | maximum number of iterations in multigrid: (<0=auto) [-1] |
| MG_NPOST_SMOOTH                          |              -1 |       NoMin_int |       NoMax_int | number of post-smoothing steps in multigrid: (<0=auto) [-1] |
| MG_NPRE_SMOOTH                           |              -1 |       NoMin_int |       NoMax_int | number of pre-smoothing steps in multigrid: (<0=auto) [-1] |
| MG_TOLERATED_ERROR                       |            -1.0 |    NoMin_double |    NoMax_double | maximum tolerated error in multigrid (<0=auto) [-1.0] |
| MINMOD_COEFF                             |             1.5 |             1.0 |             2.0 | coefficient of the generalized MinMod limiter (1.0~2.0) [1.5] |
| MINMOD_MAX_ITER                          |               0 |               0 |       NoMax_int | maximum number of iterations to reduce MINMOD_COEFF when data reconstruction fails (0=off) [0] |
| MIN_DENS                                 |             0.0 |             0.0 |    NoMax_double | minimum mass density (must >= 0.0) [0.0] ##HYDRO, MHD, and ELBDM ONLY## |
| MIN_EINT                                 |             0.0 |             0.0 |    NoMax_double | minimum internal energy (must >= 0.0) [0.0] ##HYDRO and MHD ONLY## |
| MIN_ENTR                                 |             0.0 |             0.0 |    NoMax_double | minimum entropy (must >= 0.0) [0.0] ##HYDRO and MHD ONLY## |
| MIN_PRES                                 |             0.0 |             0.0 |    NoMax_double | minimum pressure (must >= 0.0) [0.0] ##HYDRO and MHD ONLY## |
| MIN_TEMP                                 |             0.0 |             0.0 |    NoMax_double | minimum temperature in K (must >= 0.0) [0.0] ##HYDRO and MHD ONLY## |
| MOLECULAR_WEIGHT                         |             0.6 |      Eps_double |    NoMax_double | mean molecular weight [0.6] |
| MONO_MAX_ITER                            |              10 |               0 |       NoMax_int | maximum number of iterations to reduce INT_MONO_COEFF when interpolation fails (0=off) [10] |
| MU_NORM                                  |            -1.0 |    NoMin_double |    NoMax_double | normalization of MOLECULAR_WEIGHT (<0=m_H, 0=amu, >0=input manually) [-1.0] |
| NEWTON_G                                 |            -1.0 |    NoMin_double |    NoMax_double | gravitational constant (will be overwritten if OPT__UNIT or COMOVING is on) |
| NX0_TOT_X                                |              -1 |             PS2 |       NoMax_int | number of base-level cells along x |
| NX0_TOT_Y                                |              -1 |             PS2 |       NoMax_int | number of base-level cells along y |
| NX0_TOT_Z                                |              -1 |             PS2 |       NoMax_int | number of base-level cells along z |
| OMEGA_M0                                 |            -1.0 |             0.0 |             1.0 | omega matter at the present time |
| OMP_NTHREAD                              |              -1 |       NoMin_int |       NoMax_int | number of OpenMP threads (<=0=auto) [-1] ##OPENMP ONLY## |
| OPT__1ST_FLUX_CORR                       |              -1 |       NoMin_int |               2 | correct unphysical results (defined by MIN_DENS/PRES) by the 1st-order fluxes: (<0=auto, 0=off, 1=3D, 2=3D+1D) [-1] ##MHM/MHM_RP/CTU ONLY## |
| OPT__1ST_FLUX_CORR_SCHEME                | RSOLVER_1ST_DEFAULT |              -1 |               3 | Riemann solver for OPT__1ST_FLUX_CORR (-1=auto, 0=none, 1=Roe, 2=HLLC, 3=HLLE, 4=HLLD) [-1] |
| OPT__BC_FLU_XM                           |              -1 |               1 |               5 | fluid boundary condition at the -x face: (1=periodic, 2=outflow, 3=reflecting, 4=user, 5=diode) ##2/3/5 for HYDRO ONLY## |
| OPT__BC_FLU_XP                           |              -1 |               1 |               5 | fluid boundary condition at the +x face: (1=periodic, 2=outflow, 3=reflecting, 4=user, 5=diode) ##2/3/5 for HYDRO ONLY## |
| OPT__BC_FLU_YM                           |              -1 |               1 |               5 | fluid boundary condition at the -y face: (1=periodic, 2=outflow, 3=reflecting, 4=user, 5=diode) ##2/3/5 for HYDRO ONLY## |
| OPT__BC_FLU_YP                           |              -1 |               1 |               5 | fluid boundary condition at the +y face: (1=periodic, 2=outflow, 3=reflecting, 4=user, 5=diode) ##2/3/5 for HYDRO ONLY## |
| OPT__BC_FLU_ZM                           |              -1 |               1 |               5 | fluid boundary condition at the -z face: (1=periodic, 2=outflow, 3=reflecting, 4=user, 5=diode) ##2/3/5 for HYDRO ONLY## |
| OPT__BC_FLU_ZP                           |              -1 |               1 |               5 | fluid boundary condition at the +z face: (1=periodic, 2=outflow, 3=reflecting, 4=user, 5=diode) ##2/3/5 for HYDRO ONLY## |
| OPT__BC_POT                              |              -1 |               1 |               2 | gravity boundary condition: (1=periodic, 2=isolated) |
| OPT__CHECK_PRES_AFTER_FLU                |              -1 |       NoMin_int |               1 | check unphysical pressure at the end of the fluid solver (<0=auto) [-1] |
| OPT__CK_CONSERVATION                     |           false |    Useless_bool |    Useless_bool | check the conservation law [0] |
| OPT__CK_DIVERGENCE_B                     |               0 |               0 |               2 | check the divergence-free constraint on B field (0=off, 1=on, 2=on+verbose) [0] ##MHD ONLY## |
| OPT__CK_FINITE                           |           false |    Useless_bool |    Useless_bool | check if all variables are finite [0] |
| OPT__CK_FLUX_ALLOCATE                    |           false |    Useless_bool |    Useless_bool | check if all flux arrays are properly allocated [0] ##HYDRO and ELBDM ONLY## |
| OPT__CK_INPUT_FLUID                      |           false |    Useless_bool |    Useless_bool | check the input data of the fluid solver [0] |
| OPT__CK_INTERFACE_B                      |           false |    Useless_bool |    Useless_bool | check the consistency of patch interface B field [0] ##MHD ONLY## |
| OPT__CK_MEMFREE                          |             1.0 |             0.0 |    NoMax_double | check the free memory in GB (0=off, >0=threshold) [1.0] |
| OPT__CK_NEGATIVE                         |               0 |               0 |               3 | check the negative values: (0=off, 1=density, 2=pressure and entropy, 3=both) [0] ##HYDRO ONLY## |
| OPT__CK_NORMALIZE_PASSIVE                |           false |    Useless_bool |    Useless_bool | check the normalization of passive scalars [0] ##OPT__NORMALIZE_PASSIVE ONLY## |
| OPT__CK_PARTICLE                         |           false |    Useless_bool |    Useless_bool | check the particle allocation [0] |
| OPT__CK_PATCH_ALLOCATE                   |           false |    Useless_bool |    Useless_bool | check if all patches are properly allocated [0] |
| OPT__CK_PROPER_NESTING                   |           false |    Useless_bool |    Useless_bool | check the proper-nesting condition [0] |
| OPT__CK_REFINE                           |           false |    Useless_bool |    Useless_bool | check the grid refinement [0] |
| OPT__CK_RESTRICT                         |           false |    Useless_bool |    Useless_bool | check the data restriction [0] |
| OPT__CORR_AFTER_ALL_SYNC                 |              -1 |       NoMin_int |       NoMax_int | apply various corrections after all levels are synchronized (see "Flu_CorrAfterAllSync"): (-1=auto, 0=off, 1=every step, 2=before dump) [-1] |
| OPT__DT_LEVEL                            |               3 |               1 |               3 | dt at different AMR levels (1=shared, 2=differ by two, 3=flexible) [3] |
| OPT__DT_USER                             |           false |    Useless_bool |    Useless_bool | dt criterion: user-defined -> edit "Mis_GetTimeStep_UserCriteria.cpp" [0] |
| OPT__EXT_ACC                             |               0 |               0 |               1 | add external acceleration (0=off, 1=function, 2=table) [0] ##HYDRO ONLY## --> 2 (table) is not supported yet |
| OPT__EXT_POT                             |               0 |               0 |               2 | add external potential (0=off, 1=function, 2=table) [0] --> for 2 (table), edit the corresponding parameters below too |
| OPT__FFTW_STARTUP                        | FFTW_STARTUP_DEFAULT | FFTW_STARTUP_DEFAULT | FFTW_STARTUP_PATIENT | initialise fftw plans: (-1=auto, 0=ESTIMATE, 1=MEASURE, 2=PATIENT (only FFTW3)) [-1] |
| OPT__FIXUP_ELECTRIC                      |            true |    Useless_bool |    Useless_bool | correct coarse grids by the fine-grid boundary electric field [1] ##MHD ONLY## |
| OPT__FIXUP_FLUX                          |            true |    Useless_bool |    Useless_bool | correct coarse grids by the fine-grid boundary fluxes [1] ##HYDRO and ELBDM ONLY## |
| OPT__FIXUP_RESTRICT                      |            true |    Useless_bool |    Useless_bool | correct coarse grids by averaging the fine-grid data [1] |
| OPT__FLAG_CRAY                           |           false |    Useless_bool |    Useless_bool | flag: cosmic-ray energy (Input__Flag_CRay) [0] ##COSMIC_RAY ONLY## |
| OPT__FLAG_CURRENT                        |           false |    Useless_bool |    Useless_bool | flag: current density in MHD (Input__Flag_Current) [0] ##MHD ONLY## |
| OPT__FLAG_ENGY_DENSITY                   |           false |    Useless_bool |    Useless_bool | flag: energy density (Input_Flag_EngyDensity) [0] ##ELBDM ONLY## |
| OPT__FLAG_JEANS                          |           false |    Useless_bool |    Useless_bool | flag: Jeans length (Input__Flag_Jeans) [0] ##HYDRO ONLY## |
| OPT__FLAG_LOHNER_CRAY                    |           false |    Useless_bool |    Useless_bool | flag: Lohner for cosmic-ray energy (Input__Flag_Lohner) [0] ##COSMIC_RAY ONLY## |
| OPT__FLAG_LOHNER_DENS                    |           false |    Useless_bool |    Useless_bool | flag: Lohner for mass density (Input__Flag_Lohner) [0] ##BOTH HYDRO AND ELBDM## |
| OPT__FLAG_LOHNER_ENGY                    |           false |    Useless_bool |    Useless_bool | flag: Lohner for energy density (Input__Flag_Lohner) [0] ##HYDRO ONLY## |
| OPT__FLAG_LOHNER_ENTR                    |           false |    Useless_bool |    Useless_bool | flag: Lohner for entropy (Input__Flag_Lohner) [0] ##HYDRO ONLY## |
| OPT__FLAG_LOHNER_FORM                    |   LOHNER_FLASH2 |               1 |               4 | form of Lohner: (1=FLASH-1, 2=FLASH-2, 3=form-invariant-1, 4=form-invariant-2) [2] |
| OPT__FLAG_LOHNER_PRES                    |           false |    Useless_bool |    Useless_bool | flag: Lohner for pressure (Input__Flag_Lohner) [0] ##HYDRO ONLY## |
| OPT__FLAG_LOHNER_TEMP                    |           false |    Useless_bool |    Useless_bool | flag: Lohner for temperature (Input__Flag_Lohner) [0] ##HYDRO ONLY## |
| OPT__FLAG_LRTZ_GRADIENT                  |           false |    Useless_bool |    Useless_bool | flag: Lorentz factor gradient (Input__Flag_LrtzGradient) [0] ##SRHD ONLY## |
| OPT__FLAG_NPAR_CELL                      |           false |    Useless_bool |    Useless_bool | flag: # of particles per cell (Input__Flag_NParCell) [0] |
| OPT__FLAG_NPAR_PATCH                     |               0 |               0 |               2 | flag: # of particles per patch (Input__Flag_NParPatch): (0=off, 1=itself, 2=itself+siblings) [0] |
| OPT__FLAG_PAR_MASS_CELL                  |           false |    Useless_bool |    Useless_bool | flag: total particle mass per cell (Input__Flag_ParMassCell) [0] |
| OPT__FLAG_PRES_GRADIENT                  |           false |    Useless_bool |    Useless_bool | flag: pressure gradient (Input__Flag_PresGradient) [0] ##HYDRO ONLY## |
| OPT__FLAG_REGION                         |           false |    Useless_bool |    Useless_bool | flag: specify the regions **allowed** to be refined -> edit "Flag_Region.cpp" [0] |
| OPT__FLAG_RHO                            |           false |    Useless_bool |    Useless_bool | flag: density (Input__Flag_Rho) [0] |
| OPT__FLAG_RHO_GRADIENT                   |           false |    Useless_bool |    Useless_bool | flag: density gradient (Input__Flag_RhoGradient) [0] |
| OPT__FLAG_USER                           |           false |    Useless_bool |    Useless_bool | flag: user-defined (Input__Flag_User) -> edit "Flag_User.cpp" [0] |
| OPT__FLAG_USER_NUM                       |               1 |               1 |       NoMax_int | number of threshold values in user-defined table (Input__Flag_User) [1] |
| OPT__FLAG_VORTICITY                      |           false |    Useless_bool |    Useless_bool | flag: vorticity (Input__Flag_Vorticity) [0] ##HYDRO ONLY## |
| OPT__FLU_INT_SCHEME                      |     INT_DEFAULT |       NoMin_int |       NoMax_int | ghost-zone fluid variables for the fluid solver [-1] |
| OPT__FREEZE_FLUID                        |           false |    Useless_bool |    Useless_bool | do not evolve fluid at all [0] |
| OPT__FREEZE_PAR                          |           false |    Useless_bool |    Useless_bool | do not update particles (except for tracers) [0] |
| OPT__GPUID_SELECT                        |              -1 |              -3 |       NoMax_int | GPU ID selection mode: (-3=Laohu, -2=CUDA, -1=MPI rank, >=0=input) [-1] |
| OPT__GRAVITY_EXTRA_MASS                  |           false |    Useless_bool |    Useless_bool | add extra mass source when computing gravity [0] |
| OPT__GRA_INT_SCHEME                      |       INT_CQUAD |               1 |               7 | ghost-zone potential for the gravity solver (for UNSPLIT_GRAVITY as well) [4] |
| OPT__GRA_P5_GRADIENT                     |           false |    Useless_bool |    Useless_bool | 5-points gradient in the Gravity solver (must have GRA/USG_GHOST_SIZE_G>=2) [0] |
| OPT__INIT                                |              -1 |               1 |               3 | initialization option: (1=FUNCTION, 2=RESTART, 3=FILE->"UM_IC") |
| OPT__INIT_BFIELD_BYVECPOT                | INIT_MAG_BYVECPOT_NONE |               0 |               2 | initialize the magnetic field from vector potential (0=off, 1=external disk file named "B_IC", see tool/inits/gen_vec_pot.py for example, 2=function) [0] ##MHD ONLY## |
| OPT__INIT_GRID_WITH_OMP                  |            true |    Useless_bool |    Useless_bool | enable OpenMP when assigning the initial condition of each grid patch [1] |
| OPT__INIT_RESTRICT                       |            true |    Useless_bool |    Useless_bool | restrict all data during the initialization [1] |
| OPT__INT_FRAC_PASSIVE_LR                 |            true |    Useless_bool |    Useless_bool | convert specified passive scalars to mass fraction during data reconstruction [1] |
| OPT__INT_PHASE                           |            true |    Useless_bool |    Useless_bool | interpolation on phase (does not support MinMod-1D) [1] ##ELBDM ONLY## |
| OPT__INT_PRIM                            |            true |    Useless_bool |    Useless_bool | switch to primitive variables when the interpolation on conserved variables fails [1] ##HYDRO ONLY## |
| OPT__INT_TIME                            |            true |    Useless_bool |    Useless_bool | perform "temporal" interpolation for OPT__DT_LEVEL == 2/3 [1] |
| OPT__LAST_RESORT_FLOOR                   |            true |    Useless_bool |    Useless_bool | apply floor values as the last resort when the fluid solver fails [1] ##HYDRO and MHD ONLY## |
| OPT__LR_LIMITER                          | LR_LIMITER_DEFAULT |              -1 |               7 | slope limiter of data reconstruction in the MHM/MHM_RP/CTU schemes: (-1=auto, 0=none, 1=vanLeer, 2=generalized MinMod, 3=vanAlbada, 4=vanLeer+generalized MinMod, 6=central, 7=Athena) [-1] |
| OPT__MAG_INT_SCHEME                      |       INT_CQUAD |       NoMin_int |       NoMax_int | ghost-zone magnetic field for the MHD solver (2,3,4,6 only) [4] |
| OPT__MANUAL_CONTROL                      |            true |    Useless_bool |    Useless_bool | support manually dump data, stop run, or pause run during the runtime (by generating the file DUMP_GAMER_DUMP, STOP_GAMER_STOP, PAUSE_GAMER_PAUSE, respectively) [1] |
| OPT__MEMORY_POOL                         |           false |    Useless_bool |    Useless_bool | preallocate patches for OPT__REUSE_MEMORY=1/2 (Input__MemoryPool) [0] |
| OPT__MINIMIZE_MPI_BARRIER                |           false |    Useless_bool |    Useless_bool | minimize MPI barriers to improve load balance, especially with particles [0] (STORE_POT_GHOST, PAR_IMPROVE_ACC=1, OPT__TIMING_BARRIER=0 only; recommend AUTO_REDUCE_DT=0) |
| OPT__NORMALIZE_PASSIVE                   |            true |    Useless_bool |    Useless_bool | ensure "sum(passive_scalar_density) == gas_density" [1] |
| OPT__NO_FLAG_NEAR_BOUNDARY               |           false |    Useless_bool |    Useless_bool | flag: disallow refinement near the boundaries [0] |
| OPT__OPTIMIZE_AGGRESSIVE                 |           false |    Useless_bool |    Useless_bool | apply aggressive optimizations (experimental) [0] |
| OPT__OUTPUT_3VELOCITY                    |           false |    Useless_bool |    Useless_bool | output 3-velocities [0] ##SRHD ONLY## |
| OPT__OUTPUT_BASE                         |           false |    Useless_bool |    Useless_bool | only output the base-level data [0] ##OPT__OUTPUT_PART ONLY## |
| OPT__OUTPUT_BASEPS                       |           false |    Useless_bool |    Useless_bool | output the base-level power spectrum [0] |
| OPT__OUTPUT_CC_MAG                       |            true |    Useless_bool |    Useless_bool | output **cell-centered** magnetic field (necessary for yt analysis) [1] ##MHD ONLY## |
| OPT__OUTPUT_CS                           |           false |    Useless_bool |    Useless_bool | output sound speed [0] ##HYDRO ONLY## |
| OPT__OUTPUT_DIVMAG                       |           false |    Useless_bool |    Useless_bool | output |divergence(B)*dh/|B|| [0] ##MHD ONLY## |
| OPT__OUTPUT_DIVVEL                       |           false |    Useless_bool |    Useless_bool | output divergence(velocity) [0] ##HYDRO ONLY## |
| OPT__OUTPUT_ENTHALPY                     |            true |    Useless_bool |    Useless_bool | output reduced enthalpy [1] ##SRHD ONLY## |
| OPT__OUTPUT_ENTR                         |           false |    Useless_bool |    Useless_bool | output gas entropy [0] ##HYDRO ONLY## |
| OPT__OUTPUT_LORENTZ                      |           false |    Useless_bool |    Useless_bool | output Lorentz factor [0] ##SRHD ONLY## |
| OPT__OUTPUT_MACH                         |           false |    Useless_bool |    Useless_bool | output mach number [0] ##HYDRO ONLY## |
| OPT__OUTPUT_MODE                         |              -1 |               1 |               3 | (1=const step, 2=const dt, 3=dump table) -> edit "Input__DumpTable" for 3 |
| OPT__OUTPUT_PART                         |               0 |               0 |               7 | output a single line or slice: (0=off, 1=xy, 2=yz, 3=xz, 4=x, 5=y, 6=z, 7=diag) [0] |
| OPT__OUTPUT_PAR_DENS                     | PAR_OUTPUT_DENS_PAR_ONLY |               0 |               2 | output the particle or total mass density on grids: (0=off, 1=particle mass density, 2=total mass density) [1] ##OPT__OUTPUT_TOTAL ONLY## |
| OPT__OUTPUT_PAR_MODE                     |               0 |               0 |               2 | output the particle data: (0=off, 1=text-file, 2=C-binary) [0] ##PARTICLE ONLY## |
| OPT__OUTPUT_POT                          |            true |    Useless_bool |    Useless_bool | output gravitational potential [1] ##OPT__OUTPUT_TOTAL ONLY## |
| OPT__OUTPUT_PRES                         |           false |    Useless_bool |    Useless_bool | output gas pressure [0] ##HYDRO ONLY## |
| OPT__OUTPUT_RESTART                      |           false |    Useless_bool |    Useless_bool | output data immediately after restart [0] |
| OPT__OUTPUT_TEMP                         |  OutTempDefault |    Useless_bool |    Useless_bool | output gas temperature [0 (HD) or 1 (SRHD)] ##HYDRO ONLY## |
| OPT__OUTPUT_TEXT_FORMAT_FLT              |       "%24.16e" |     Useless_str |     Useless_str | string format of output text files [%24.16e] |
| OPT__OUTPUT_TOTAL                        |               1 |               0 |               2 | output the simulation snapshot: (0=off, 1=HDF5, 2=C-binary) [1] |
| OPT__OUTPUT_USER                         |           false |    Useless_bool |    Useless_bool | output the user-specified data -> edit "Output_User.cpp" [0] |
| OPT__OUTPUT_USER_FIELD                   |           false |    Useless_bool |    Useless_bool | output user-defined derived fields [0] -> edit "Flu_DerivedField_User.cpp" |
| OPT__OVERLAP_MPI                         |           false |    Useless_bool |    Useless_bool | overlap MPI communication with CPU/GPU computations [0] ##NOT SUPPORTED YET## |
| OPT__PARTICLE_COUNT                      |               1 |               0 |               2 | record the # of particles at each level: (0=off, 1=every step, 2=every sub-step) [1] |
| OPT__PATCH_COUNT                         |               1 |               0 |               2 | record the # of patches at each level: (0=off, 1=every step, 2=every sub-step) [1] |
| OPT__POT_INT_SCHEME                      |       INT_CQUAD |               4 |               5 | ghost-zone potential for the Poisson solver (only supports 4 & 5) [4] |
| OPT__RECORD_CENTER                       |           false |    Useless_bool |    Useless_bool | record the position of maximum density, minimum potential, and center of mass [0] |
| OPT__RECORD_DT                           |            true |    Useless_bool |    Useless_bool | record info of the dt determination [1] |
| OPT__RECORD_LOAD_BALANCE                 |            true |    Useless_bool |    Useless_bool | record the load-balance info [1] |
| OPT__RECORD_MEMORY                       |            true |    Useless_bool |    Useless_bool | record the memory consumption [1] |
| OPT__RECORD_NOTE                         |            true |    Useless_bool |    Useless_bool | take notes for the general simulation info [1] |
| OPT__RECORD_PERFORMANCE                  |            true |    Useless_bool |    Useless_bool | record the code performance [1] |
| OPT__RECORD_UNPHY                        |            true |    Useless_bool |    Useless_bool | record the number of cells with unphysical results being corrected [1] |
| OPT__RECORD_USER                         |           false |    Useless_bool |    Useless_bool | record the user-specified info -> edit "Aux_Record_User.cpp" [0] |
| OPT__REF_FLU_INT_SCHEME                  |     INT_DEFAULT |       NoMin_int |       NoMax_int | newly allocated fluid variables during grid refinement [-1] |
| OPT__REF_MAG_INT_SCHEME                  |       INT_CQUAD |       NoMin_int |       NoMax_int | newly allocated magnetic field during grid refinement (2,3,4,6 only) [4] |
| OPT__REF_POT_INT_SCHEME                  |       INT_CQUAD |               1 |               7 | newly allocated potential during grid refinement [4] |
| OPT__RESET_FLUID                         |           false |    Useless_bool |    Useless_bool | reset fluid variables after each update -> edit "Flu_ResetByUser.cpp" [0] |
| OPT__RESET_FLUID_INIT                    |              -1 |       NoMin_int |       NoMax_int | reset fluid variables during initialization (<0=auto -> OPT__RESET_FLUID, 0=off, 1=on) [-1] |
| OPT__RESTART_RESET                       |           false |    Useless_bool |    Useless_bool | reset some simulation status parameters (e.g., current step and time) during restart [0] |
| OPT__REUSE_MEMORY                        |               2 |               0 |               2 | reuse patch memory to reduce memory fragmentation: (0=off, 1=on, 2=aggressive) [2] |
| OPT__RHO_INT_SCHEME                      |       INT_CQUAD |               1 |               7 | ghost-zone mass density for the Poisson solver [4] |
| OPT__SAME_INTERFACE_B                    |           false |    Useless_bool |    Useless_bool | ensure B field consistency on the shared interfaces between sibling patches (for debugging) [0] ##MHD ONLY## |
| OPT__SELF_GRAVITY                        |            true |    Useless_bool |    Useless_bool | add self-gravity [1] |
| OPT__SORT_PATCH_BY_LBIDX                 |           false |    Useless_bool |    Useless_bool | sort patches to improve bitwise reproducibility [SERIAL:0, LOAD_BALACNE:1] |
| OPT__TIMING_BALANCE                      |           false |    Useless_bool |    Useless_bool | record the max/min elapsed time in various code sections for checking load balance [0] |
| OPT__TIMING_BARRIER                      |              -1 |       NoMin_int |       NoMax_int | synchronize before timing -> more accurate, but may slow down the run (<0=auto) [-1] |
| OPT__TIMING_MPI                          |           false |    Useless_bool |    Useless_bool | record the MPI bandwidth achieved in various code sections [0] ##LOAD_BALANCE ONLY## |
| OPT__UM_IC_DOWNGRADE                     |            true |    Useless_bool |    Useless_bool | downgrade UM_IC from level OPT__UM_IC_LEVEL to 0 [1] |
| OPT__UM_IC_FLOAT8                        |              -1 |       NoMin_int |               1 | floating-point precision for UM_IC (<0: default, 0: single, 1: double) [default: same as FLOAT8] |
| OPT__UM_IC_FORMAT                        | UM_IC_FORMAT_VZYX |               1 |               2 | data format of UM_IC: (1=vzyx, 2=zyxv; row-major and v=field) [1] |
| OPT__UM_IC_LEVEL                         |               0 |               0 |       TOP_LEVEL | starting AMR level in UM_IC [0] |
| OPT__UM_IC_LOAD_NRANK                    |               1 |               1 |       NoMax_int | number of parallel I/O (i.e., number of MPI ranks) for loading UM_IC [1] |
| OPT__UM_IC_NLEVEL                        |               1 |               1 |       NoMax_int | number of AMR levels UM_IC [1] --> edit "Input__UM_IC_RefineRegion" if >1 |
| OPT__UM_IC_NVAR                          |              -1 |       NoMin_int |     NCOMP_TOTAL | number of variables in UM_IC: (1~NCOMP_TOTAL; <=0=auto) [HYDRO=5+passive/ELBDM=2] |
| OPT__UM_IC_REFINE                        |            true |    Useless_bool |    Useless_bool | refine UM_IC from level OPT__UM_IC_LEVEL to MAX_LEVEL [1] |
| OPT__UNIT                                |           false |    Useless_bool |    Useless_bool | specify code units -> must set exactly 3 basic units below [0] ##USELESS FOR COMOVING## |
| OPT__VERBOSE                             |           false |    Useless_bool |    Useless_bool | output the simulation progress in detail [0] |
| OUTPUT_DT                                |            -1.0 |    NoMin_double |    NoMax_double | output data every OUTPUT_DT time interval ##OPT__OUTPUT_MODE==2 ONLY## |
| OUTPUT_PART_X                            |            -1.0 |    NoMin_double |    NoMax_double | x coordinate for OPT__OUTPUT_PART [-1.0] |
| OUTPUT_PART_Y                            |            -1.0 |    NoMin_double |    NoMax_double | y coordinate for OPT__OUTPUT_PART [-1.0] |
| OUTPUT_PART_Z                            |            -1.0 |    NoMin_double |    NoMax_double | z coordinate for OPT__OUTPUT_PART [-1.0] |
| OUTPUT_STEP                              |              -1 |       NoMin_int |       NoMax_int | output data every OUTPUT_STEP step ##OPT__OUTPUT_MODE==1 ONLY## |
| OUTPUT_WALLTIME                          |            -1.0 |    NoMin_double |    NoMax_double | output data every OUTPUT_WALLTIME walltime (<=0.0=off) [-1.0] |
| OUTPUT_WALLTIME_UNIT                     |               0 |               0 |               3 | unit of OUTPUT_WALLTIME (0=second, 1=minute, 2=hour, 3=day) [0] |
| PAR_IC_FLOAT8                            |              -1 |       NoMin_int |               1 | floating-point precision for PAR_IC (<0: default, 0: single, 1: double) [default: same as FLOAT8_PAR] |
| PAR_IC_FORMAT                            | PAR_IC_FORMAT_ATT_ID |               1 |               2 | data format of PAR_IC: (1=[attribute][id], 2=[id][attribute]; row-major) [1] |
| PAR_IC_MASS                              |            -1.0 |    NoMin_double |    NoMax_double | mass of all particles for PAR_INIT==3 (<0=off) [-1.0] |
| PAR_IC_TYPE                              |              -1 |       NoMin_int |     PAR_NTYPE-1 | type of all particles for PAR_INIT==3 (<0=off) [-1] |
| PAR_IMPROVE_ACC                          |            true |    Useless_bool |    Useless_bool | improve force accuracy at patch boundaries [1] ##STORE_POT_GHOST and PAR_INTERP=2/3 ONLY## |
| PAR_INIT                                 |              -1 |               1 |               3 | initialization option for particles: (1=FUNCTION, 2=RESTART, 3=FILE->"PAR_IC") |
| PAR_INTEG                                |   PAR_INTEG_KDK |               1 |               2 | particle integration scheme: (1=Euler, 2=KDK) [2] |
| PAR_INTERP                               |  PAR_INTERP_CIC |               1 |               3 | particle interpolation scheme: (1=NGP, 2=CIC, 3=TSC) [2] |
| PAR_NPAR                                 |             -1L |      NoMin_long |      NoMax_long | total number of particles (must be set for PAR_INIT==1/3; must be an integer) |
| PAR_PREDICT_POS                          |            true |    Useless_bool |    Useless_bool | predict particle position during mass assignment [1] |
| PAR_REMOVE_CELL                          |            -1.0 |    NoMin_double |    NoMax_double | remove particles X-root-cells from the boundaries (non-periodic BC only; <0=auto) [-1.0] |
| PAR_TR_INTEG                             | TRACER_INTEG_RK2 |               1 |               2 | tracer particle integration scheme: (1=Euler, 2=RK2) [2] |
| PAR_TR_INTERP                            |  PAR_INTERP_TSC |               1 |               3 | tracer particle interpolation scheme: (1=NGP, 2=CIC, 3=TSC) [3] |
| PAR_TR_VEL_CORR                          |           false |    Useless_bool |    Useless_bool | correct tracer particle velocities in regions of discontinuous flow [0] |
| POT_GPU_NPGROUP                          |              -1 |       NoMin_int |       NoMax_int | number of patch groups sent into the CPU/GPU Poisson solver (<=0=auto) [-1] |
| REFINE_NLEVEL                            |               1 |               1 |       NoMax_int | number of new AMR levels to be created at once during refinement [1] |
| REGRID_COUNT                             |               4 |               1 |       NoMax_int | refine every REGRID_COUNT sub-step [4] |
| RESTART_LOAD_NRANK                       |               1 |               1 |       NoMax_int | number of parallel I/O (i.e., number of MPI ranks) for restart [1] |
| SF_CREATE_STAR_DET_RANDOM                |              -1 |       NoMin_int |       NoMax_int | make random numbers deterministic (i.e., independent of OpenMP and MPI, <0=auto) [-1] |
| SF_CREATE_STAR_MASS_EFF                  |          1.0e-2 |      Eps_double |             1.0 | Gas-to-star mass conversion efficiency [1.0e-2] |
| SF_CREATE_STAR_MAX_STAR_MFRAC            |             0.5 |      Eps_double |             1.0 | maximum gas mass fraction allowed to convert to stars per substep [0.5] |
| SF_CREATE_STAR_MIN_GAS_DENS              |           1.0e1 |             0.0 |    NoMax_double | minimum gas density allowed to form stars (in HI count/cm^3) [1.0e1] |
| SF_CREATE_STAR_MIN_LEVEL                 |               0 |       NoMin_int |       TOP_LEVEL | minimum AMR level allowed to form stars (<0=auto -> MAX_LEVEL) [0] |
| SF_CREATE_STAR_MIN_STAR_MASS             |             0.0 |             0.0 |    NoMax_double | minimum star particle mass for the stochastical star formation (in Msun) [0.0] |
| SF_CREATE_STAR_RSEED                     |             123 |               0 |       NoMax_int | random seed [123] |
| SF_CREATE_STAR_SCHEME                    |               0 |               0 |               1 | star formation schemes (0=off, 1=AGORA) [0] |
| SOR_MAX_ITER                             |              -1 |       NoMin_int |       NoMax_int | maximum number of iterations in SOR: (<0=auto) [-1] |
| SOR_MIN_ITER                             |              -1 |       NoMin_int |       NoMax_int | minimum number of iterations in SOR: (<0=auto) [-1] |
| SOR_OMEGA                                |            -1.0 |    NoMin_double |    NoMax_double | over-relaxation parameter in SOR: (<0=auto) [-1.0] |
| SRC_DELEPTONIZATION                      |           false |    Useless_bool |    Useless_bool | deleptonization (for simulations of stellar core collapse) [0] ##HYDRO ONLY## |
| SRC_GPU_NPGROUP                          |              -1 |       NoMin_int |       NoMax_int | number of patch groups sent into the CPU/GPU source-term solver (<=0=auto) [-1] |
| SRC_USER                                 |           false |    Useless_bool |    Useless_bool | user-defined source terms -> edit "Src_User.cpp" [0] |
| TESTPROB_ID                              |               0 |               0 |       NoMax_int | test problem ID [0] 0: none 1: HYDRO blast wave [+MHD] 2: HYDRO acoustic wave 3: HYDRO Bondi accretion (+GRAVITY) 4: HYDRO cluster merger vs. Flash (+GRAVITY & PARTICLE) 5: HYDRO AGORA isolated galaxy (+GRAVITY & PARTICLE & STAR_FORMATION & GRACKLE) 6: HYDRO caustic wave 7: HYDRO spherical collapse (+GRAVITY & COMOVING) 8: HYDRO Kelvin Helmholtz instability 9: HYDRO Riemann problems [+MHD] 10: HYDRO jet(s) 11: HYDRO Plummer cloud(s) (+GRAVITY & PARTICLE) 12: HYDRO gravity (+GRAVITY) 13: HYDRO MHD Arnold-Beltrami-Childress (ABC) flow (+MHD) 14: HYDRO MHD Orszag-Tang vortex (+MHD) 15: HYDRO MHD linear wave (+MHD) 16: HYDRO Jeans instability (+GRAVITY) [+MHD] 17: HYDRO particle in equilibrium (+GRAVITY & PARTICLE) 19: HYDRO energy power spectrum 20: HYDRO MHD Cosmic Ray Soundwave 21: HYDRO MHD Cosmic Ray Shocktube 23: HYDRO MHD Cosmic Ray Diffusion 100: HYDRO CDM cosmological simulation (+GRAVITY & COMOVING & PARTICLE) 101: HYDRO Zeldovich pancake collapse (+GRAVITY & COMOVING & PARTICLE) 1000: ELBDM external potential (+GRAVITY) |
| UNIT_D                                   |            -1.0 |    NoMin_double |    NoMax_double | mass density unit (<=0 -> set to UNIT_M/UNIT_L^3) [-1.0] |
| UNIT_L                                   |            -1.0 |    NoMin_double |    NoMax_double | length unit (<=0 -> set to UNIT_V*UNIT_T or (UNIT_M/UNIT_D)^(1/3)) [-1.0] |
| UNIT_M                                   |            -1.0 |    NoMin_double |    NoMax_double | mass unit (<=0 -> set to UNIT_D*UNIT_L^3) [-1.0] |
| UNIT_T                                   |            -1.0 |    NoMin_double |    NoMax_double | time unit (<=0 -> set to UNIT_L/UNIT_V) [-1.0] |
| UNIT_V                                   |            -1.0 |    NoMin_double |    NoMax_double | velocity unit (<=0 -> set to UNIT_L/UNIT_T) [-1.0] |
| YT_FIG_BASENAME                          |       NoDef_str |     Useless_str |     Useless_str | figure basename [Fig] |
| YT_JUPYTER_USE_CONNECTION_FILE           |           false |    Useless_bool |    Useless_bool | use user-provided connection file when using libyt Jupyter UI [0] |
| YT_SCRIPT                                |       NoDef_str |     Useless_str |     Useless_str | yt inline analysis script (do not include the ".py" file extension) |
| YT_VERBOSE                               |               1 |               0 |               3 | verbose level of yt (0=off, 1=info, 2=warning, 3=debug) [1] |
