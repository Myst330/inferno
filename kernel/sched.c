/*
 * 'sched.c' is the main kernel file. It contains scheduling primitives
 * (sleep_on, wakeup, schedule etc) as well as a number of simple system
 * call functions (type getpid(), which just extracts a field from
 * current-task
 */

#include <inferno/sched.h>
#include <inferno/kernel.h>
#include <signal.h>
#include <inferno/sys.h>
#include <asm/system
