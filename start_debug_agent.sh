export HSA_TOOLS_LIB=/opt/rocm/lib/librocr_debug_agent64.so
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/rocm/lib/
export PATH=/opt/rocm/opencl/bin/x86_64/:$PATH
export ROCM_DEBUG_ENABLE_AGENTLOG=stdout
export ROCM_DEBUG_WAVE_STATE_DUMP=file
#export ROCM_DEBUG_WAVE_STATE_DUMP=stdout
#export ROCM_DEBUG_ENABLE_AGENTLOG=stdout
#unset ROCM_DEBUG_WAVE_STATE_DUMP
export ROCM_DEBUG_ENABLE_LINUX_SIGNALS=1
#export ROCM_DEBUG_SAVE_CODE_OBJECT=/opt/hpc/nodequal/bin/
export ROCM_DEBUG_SAVE_CODE_OBJECT=/root/yuanxiong/myworks/helloworld-hipasm/
#unset ROCM_DEBUG_SAVE_CODE_OBJECT