#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

int serial_open(char* serialDevice)
{
	int fd; /* Store the file descriptor of the port that we open */

	fd = open(serialDevice, O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1)
	{
		// A file descriptor 0f -1 indicates that an error occurred.
		fprintf(stderr, "open_Serial: Unable to open %s - ", serialDevice);
		perror("");
	}
	else
	{
		fcntl(fd, F_SETFL, 0);
	}

	return fd;
}

int serial_close(int fd)
{
	return close(fd);
}

int serial_write(int fd, const unsigned char *data, size_t length)
{
	ssize_t written = write(fd, data, length);
	if (written < 0)
	{
		perror("Error writing to serial port - ");
		return -1;
	}
	return written;
}

int serial_read()
{
	//TODO
	return 0;
}

