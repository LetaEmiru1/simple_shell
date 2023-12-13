#include "main.h"
/**
 *main- simple shell implementor
 *Return: 0 on success
 */
int main(void)
{
	extern char **environ;
	char input[MAX_INPUT];
	char *args[MAX_ARGS];
	pid_t child_pid;
	int waitstatus;
	ssize_t read_char;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		fflush(stdout);
		read_char = read(STDIN_FILENO, input, sizeof(input));
		if (read_char == 0)
		{
			write(STDOUT_FILENO, "End of file reached.\n", 21);
			exit(EXIT_SUCCESS);
		}
		if (read_char > 0 && input[read_char - 1] == '\n')
		{
			input[read_char - 1] = '\0';
		}
		tokenize_input(input, args);
		if (access(input, X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error forking.");
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				execve(args[0], args, environ);
				perror("Error executing command");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(child_pid, &waitstatus, 0);
			}
		}
		else
		{
			perror("Access error");
		}
	}
	return (0);
}
