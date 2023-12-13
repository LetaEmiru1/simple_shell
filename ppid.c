#include "main.h"
/**
 *parent_pid- prints pid of a parent process
 *Return: 0 on success
 */
pid_t parent_pid()
{
	ssize_t parent;
	parent = getppid();
	printf("%ld\n", parent);
}
