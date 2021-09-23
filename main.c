#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/*int main()
{
	char *file = "hhgttg.txt";
	char *s;
	int fd = open(file, O_RDONLY);
	int i = 0;
	while (i++ < 15) {
		s = get_next_line(fd);
		*s ? printf("l %02d: %s", i, s) : printf("l: (null)\n");
	}
	//system("leaks -q a.out");
	printf("FINISH");
}*/
int main()
{
	char *file = "hhgttg.txt";
	char *s;
	int fd = open(file, O_RDONLY);
	int i = 1;
	//perror("open");
	s = get_next_line(fd);
	printf("l %d: %s", i++, s);
	while (s) {
		s = get_next_line(fd);
		printf("l %d: %s", i++, s);
	}
	printf("FINISH");
}
