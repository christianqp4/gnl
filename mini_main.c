# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

int main()
{
	int fd = open ("file.txt", O_RDONLY);
	//int fd = -1;
  	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	//printf("---nul");
}