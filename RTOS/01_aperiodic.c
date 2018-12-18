#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <native/task.h>
#include <rtdk.h>

/*
Xenomai Aperiodic Task:
	step1: Implement task function -- function to be executed by the task.
		prototype: void func(void *param);
	step2: Call rt_task_create() to create the RT task.
		arg1: addr of task desc (out param) -- RT_TASK*
		arg2: name of task -- char*
		arg3: stack size -- 0 for default stack size
		arg4: priority -- 0(min) to 99(max)
		arg5: flags -- cpu affinity: T_CPU(cpuno), fpu: T_FPU, init suspended: T_SUSP, ...
		returns: 0 on success.
	step3: Call rt_task_start() to begin execution of the task.
		arg1: addr of task desc -- RT_TASK*
		arg2: addr of task function
		arg3: param for task function
		returns: 0 on success.
	
	step4: Call rt_task_delete()
		arg1: addr of task desc -- RT_TASK* -- NULL for current task.	
		returns: 0 on success.
*/

// empty signal handler
void sigint_handler(int sig)
{
}

// task function implementation
void aperiodic_task(void *param)
{
	RT_TASK_INFO info;
	// get info about current task
	rt_task_inquire(NULL, &info);
	rt_printf("hello xenomai task.\n");
	rt_printf("task name : %s.\n", info.name);
	rt_printf("task cur prio/base prio : %d/%d.\n", info.cprio, info.bprio);
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
	ret = rt_task_start(&t1, aperiodic_task, NULL);
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

// compiling & executing without Makefile
//	CFLAGS	-->		/usr/xenomai/bin/xeno-config --skin=native --cflags
//	LDFLAGS	-->		/usr/xenomai/bin/xeno-config --skin=native --ldflags

//	gcc -o 01_aperiodic `/usr/xenomai/bin/xeno-config --skin=native --cflags --ldflags` 01_aperiodic.c

//	sudo LD_LIBRARY_PATH=/usr/xenomai/lib ./01_aperiodic

// documentation:
//	/usr/xenomai/share/doc/xenomai/html/api/index.html
