#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#define MAX_INPUT 1024
#define MAX_ARG_SIZE 128
#define MAX_ARGS 32
int path_finder(int ac, char **av);
char* tokenize_input(char* input, char* args[]);
pid_t parent_pid();

#endif
