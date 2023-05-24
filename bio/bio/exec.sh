debugfs=/sys/kernel/debug
echo nop > $debugfs/tracing/current_tracer
echo 0 > $debugfs/tracing/tracing_on
echo $$
echo $$ > $debugfs/tracing/set_ftrace_pid
#echo function > $tracefs/tracing/current_tracer
echo function_graph > $debugfs/tracing/current_tracer
echo 'vfs_read:traceoff:1' > set_ftrace_filter
echo vfs_read > $debugfs/tracing/set_graph_function
echo 1 > $debugfs/tracing/tracing_on
exec $@

