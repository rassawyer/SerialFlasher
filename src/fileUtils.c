#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "fileUtils.h"

FILE* file_open(char *file_name)
{
	FILE* fptr;

	fptr = fopen(file_name, "r");

	if (fptr == NULL)
	{
		fprintf(stderr, "Failed to open %s", file_name);
		perror("");
	}
	return fptr;
}

int file_close(FILE* fptr)
{
	int status = fclose(fptr);

	if(status < 0)
	{
		fprintf(stderr, "Failed to close file: - ");
		perror("");
	}

	return status;
}

char* file_read(FILE* fptr)
{
	//TODO
	return 0;
}

int file_write(FILE* fptr, const char* data)
{
	//TODO
	return 0;
}
