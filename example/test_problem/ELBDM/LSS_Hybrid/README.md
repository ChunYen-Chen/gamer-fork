# Compilation flags
- Must enable
   - [[MODEL=ELBDM | Installation: Simulation-Options#MODEL]]
   - [[ELBDM_SCHEME=ELBDM_HYBRID | Installation: Simulation-Options#ELBDM_SCHEME]]
   - [[GRAVITY | Installation: Simulation-Options#GRAVITY]]
   - [[COMOVING | Installation: Simulation-Options#COMOVING]]
- Must disable
   - [[PARTICLE | Installation: Simulation-Options#PARTICLE]]
- Available options
   - [[Miscellaneous Options | Installation: Simulation-Options#miscellaneous-options]]


# Default setup
1. Cosmological constants
   | Parameter name | value              |
   |---             |---                 |
   | ELBDM_MASS     | 2.0e-23            |
   | A_INIT         | 9.900990099e-3     |
   | OMEGA_M0       | 0.3158230904284232 |
   | HUBBLE0        | 0.6732117          |

2. Simulation
   | Parameter name         | value |
   |---                     |---    |
   | BOX_SIZE               | 2.8   |
   | MAX_LEVEL              | 6     |
   | OPT__FLAG_SPECTRAL     | 1     |
   | OPT__FLAG_INTERFERENCE | 1     |

3. Flag tables
   * `Input__Flag_Rho`:           `example/input/Input__Flag_Rho8`
   * `Input__Flag_Spectral`:      `example/input/Input__Flag_Spectral`
   * `Input__Flag_Interference`:  `example/input/Input__Flag_Interference`


Note:
========================================
1. Cosmological large-scale structure simulations using hybrid scheme

2. Quickstart:
   1. Download the IC file
   ```bash
   sh download_light_halo_ic.sh
   ```
   or
   ```bash
   sh download_heavy_halo_ic.sh
   ```
   2. For spectral interpolation:
      -  Download spectral interpolation tables
         ```bash
         sh download_spectral_interpolation_tables.sh
         ```
      -  Set [[OPT__FLU_INT_SCHEME | ]] and [[OPT__REF_FLU_INT_SCHEME | ]] to 8
   3. Compile GAMER and run simulation to redshift 0 with default settings.

4. Explanation:
   1. IC

      The wave IC consisting of two blocks of real and imaginary parts are converted to hybrid IC
      consisting of two blocks with the density and phase fields using the Python script `elbdm_wave_to_hybrid_IC.py`

      It can be used as follows:
      ```bash
      python elbdm_wave_to_hybrid_IC.py -resolution 256 -input UM_IC_wave -output UM_IC_hybrid
      ```
      to convert the input file `UM_IC_wave` with a resolution of 256 points in each dimension to the output hybrid IC `UM_IC_hybrid`. Optionally, it accepts the keyword -float8 for double precision input data.
      The conversion is only well-defined if the IC do not contain vortices, i.e. at high redshift for cosmological IC.

      In a second step, the initial conditions can be rescaled using the Python script `elbdm_rescale_periodic_ic.py`.
      It can be used as follows:
      ```bash
      python elbdm_rescale_periodic_ic.py -n_in 256 -n_out 64 -input UM_IC_high_resolution -output UM_IC_low_resolution
      ```
      and supports up- and downscaling periodic wave and hybrid IC. Optionally, it accepts the keyword -float8 for double precision input data.
   2. Interpolation tables

      The tables can be recreated by calling
      ```bash
      mpirun -n 16 python3 tool/table_maker/GramFE/compute_interpolation_tables.py
      ```
      `INT_SPEC_TABLE_PATH` (default = "./") must be set to a folder containing the folders `interpolation_tables` and `boundary2extension_tables`

3. The simulation uses a low base-level resolution of 2.8 Mpc/h / 64 ~ 44 kpc/h (comoving).
   This corresponds to a maximum wave vector k ~ 72 h/Mpc well above the cutoff power in the initial conditions for m = 2.0e-23 eV. This initial resolution has shown very good agreement with higher resolution wave initial conditions.

4. The simulation uses the fluid solver on levels 0 - 3 and switches to the wave solver in regions of interference on level 4.
   The corresponding runtime parameter [[ELBDM_FIRST_WAVE_LEVEL | ELBDM#ELBDM_FIRST_WAVE_LEVEL]] is set to 4.

   The resolution for the first level using the wave solver is 2.8 Mpc/h /(64*2^4) ~ 2.75 kpc/h (comoving) with these settings.
   This resolution has shown to be a good compromise for the starting resolution of the wave solver.
   Note that increasing [[ELBDM_FIRST_WAVE_LEVEL | ELBDM#ELBDM_FIRST_WAVE_LEVEL]] will affect performance since it will likely lead to overrefinement. However, it should increase the accuracy of the hybrid scheme.
   On the contrary, decreasing [[ELBDM_FIRST_WAVE_LEVEL | ELBDM#ELBDM_FIRST_WAVE_LEVEL]] will lead to a lower-resolution at the wave-fluid boundary (regardless of [[MAX_LEVEL | Runtime-Parameters:-Refinement#MAX_LEVEL]] and [[REFINE_NLEVEL | Runtime-Parameters:-Refinement#REFINE_NLEVEL]]) and will negatively affect the accuracy of the solver.

3. Default maximum resolution is low
   --> Only 2.8/(64*2^6) ~ 0.7 kpc/h (comoving)
   --> Can only marginally resolve a central soliton

4. Some yt visualization scripts are put in `plot_script`