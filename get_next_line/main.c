#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int fd;
	char *line;

	fd = open("fd.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
}
