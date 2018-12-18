#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <native/task.h>
#include <rtdk.h>

/*
A task can be made periodic by two more steps:
step1: rt_task_set_periodic()
	arg1: task desc -- NULL -- current task
	arg2: when to schedule/start the task for first time -- TM_NOW
	arg3: task period in ns.
	returns: 0 on success

step2: rt_task_wait_period()
	arg1: NULL
	returns: 0 on success
*/

#define DELAY_NS	1000000000

// empty signal handler
void sigint_handler(int sig)
{
}

// task function implementation
void periodic_task(void *param)
{
	RT_TASK_INFO info;
	int i, ret;
	// get info about current task
	rt_task_inquire(NULL, &info);
	// make the current task as periodic
	ret = rt_task_set_periodic(NULL, TM_NOW, DELAY_NS);
	if(ret != 0)
	{
		rt_task_delete(NULL);
		return;
	}

	for(i=0; i<10; i++)
	{
		rt_printf("%s : %d\n", info.name, i);
		// wait for completion of the period.
		rt_task_wait_period(NULL);
	}
	// destroy current task -- NULL
	rt_task_delete(NULL);
}

int main()
{
	RT_TASK t1;
	int ret;
	struct sigaction sa;

	// all pages of current process become logical
	// i.e. they will not be swapped out/in
	// ensures no delay in execution of task due to paging activity.
	ret = mlockall(MCL_CURRENT | MCL_FUTURE);

	// registering SIGINT signal handler
	// ensure that process is not terminated due to ctrl+C
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);

	// create a background task that flush rt_printf's buffer periodically
	// on current terminal -- period is 1 ms (arg).
	rt_print_auto_init(1);
	rt_printf("main() started.\n");
	
	// create a task
	ret = rt_task_create(&t1, "Task1", 0, 50, T_CPU(0)); 
	if(ret != 0)
	{
		rt_printf("rt_task_create() failed.\n");
		_exit(1);
	}

	// begin execution of task
	ret = rt_task_start(&t1, periodic_task, NULL);
	if(ret != 0)
	{
		rt_printf("rt_task_start() failed.\n");
		_exit(1);
	}

	// wait for any signal to arrive
	// then signal handler is executed and
	// execution progresses further
	pause();

	rt_printf("main() completed.\n");
	return 0;
}

