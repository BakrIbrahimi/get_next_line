#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *file = "hhgttg.txt";
	char *s;
	int fd = open(file, O_RDONLY);
	int i = 0;
	while (i++ < 16) {
		s = get_next_line(fd);
		*s ? printf("l: %s", s) : printf("l: (null)\n");
	}
	*s ? printf("l: %s", s) : printf("l: (null)\n");
	system("leaks -q a.out");
	printf("FINISH");
}
