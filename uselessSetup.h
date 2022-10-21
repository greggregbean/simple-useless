#ifndef USELESS_SETUP_H
#define USELESS_SETUP_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXBUFSIZE 1000
#define MAXNAMESIZE 20
#define MAXNUMSIZE 20

void space_skip(int* iter, char* buf);
int read_num(int* iter, char* buf);
char* read_name(int* iter, char* buf);

#endif