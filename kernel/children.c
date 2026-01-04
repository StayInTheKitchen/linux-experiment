#include <linux/sched.h>
#include <linux/syscalls.h>

int sys_children(void)
{
	return 1818;
}

SYSCALL_DEFINE0(children)
{
	return sys_children();
}

