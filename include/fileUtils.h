#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>

FILE* file_open(char *file_name);
int file_close(FILE* fptr);
char* file_read(FILE* fptr);
int file_write(FILE* fptr, const char* data);

#endif
