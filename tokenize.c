#include "main.h"

char* tokenize_input(char* input, char* args[])
{
	char* token = strtok(input, " \t\n");
	int i = 0;
	args[i++] = token;

	while (token != NULL && i < MAX_ARG_SIZE-1)
	{
	        write(STDOUT_FILENO, token, strlen(token));
	        write(STDOUT_FILENO, " \n", 2);
	        token = strtok(NULL, " \t\n");
	        args[i++] = token;
	}

	args[i] = NULL;
	return (token);
}
