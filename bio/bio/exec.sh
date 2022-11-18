#tracefs=`sed -ne 's/^tracefs \(.*\) tracefs.*/\1/p' /proc/mounts`
tracefs=/sys/kernel/debug
echo nop > $tracefs/tracing/current_tracer
echo 0 > $tracefs/tracing/tracing_on
echo $$
echo $$ > $tracefs/tracing/set_ftrace_pid
echo function > $tracefs/tracing/current_tracer
echo 1 > $tracefs/tracing/tracing_on
exec "$@"

