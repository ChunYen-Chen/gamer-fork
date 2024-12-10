> [!TIP]
> Try to search `(Ctrl+f)` for the keyword you want!

### Running out of GPU memory
* **Description**:
<pre>
ERROR : CUDA ERROR : out of memory !!
</pre>
* **Solution**: Reduce [[NSTREAM | GPU#NSTREAM]] until the issue is resolved.

* * *

### Instability with MHD
* **Description**: See this [issue](https://github.com/gamer-project/gamer/issues/80#issuecomment-1030177067) report.
* **Solution**: Update `CUDA` to 11.3 or higher.

* * *

### Inconsistent magnetic field between patches
* **Description**:
<pre>
"DIAGNOSIS" : &lt;MHD_Aux_Check_InterfaceB&gt; FAILED, Time = 2.8550051e-03, Step = 16!!
</pre>
* **Solutions**:
   1. Set `MINMOD_MAX_ITER` to `0` in `Input__Parameter`
   1. Enable `OPT__SAME_INTERFACE_B` in `Input__Parameter`

* * *