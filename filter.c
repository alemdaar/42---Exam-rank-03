#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int mystrlen(char *str)
{
	if (str == NULL)
		return 0;
	int i = 0;
	while (str[i])
		i++;
	return i;
}
int main (int ac, char **av)
{
	if (ac != 2)
		return 1;
	if (!av[1][0])
		return 1;
	char *readd = NULL;
	char *buffer = NULL;
	char *tmp;
	ssize_t r;
	int i = 0;
	int j = 0;
	while (1)
	{
		readd = malloc (5);
		if (!readd)
		{
			perror("readd: ");
			return 1;
		}
		readd[0] = 0;
		while (1)
		{
			r = read (0, readd, 4);
			if (r == -1)
			{
				perror ("read: ");
				return 1;
			}
			if (r == 0)
			{
				int debug_file = open ("close_stdin", O_CREAT | O_RDWR, 0777);
				if (debug_file == -1)
				{
					perror("debug_file: ");
					return 1;
				}
				break;
			}
			readd[r] = 0;
			tmp = buffer;
			buffer = malloc (mystrlen(readd) + mystrlen(tmp) + 1);
			if (!buffer)
			{
				printf ("buffer allocation failed\n");
				return 1;
			}
			i = 0;
			j = 0;
			while ()
			if (tmp)
				free(tmp);
		}
		if (r == 0 && !buffer)
			return 0;
		readd[r] = 0;
		i = 0;
		while(readd[i])
			i++;
		buffer = malloc (i + 1);
		if (!buffer)
		{
			perror ("malloc: ");
			return 1;
		}
		i = 0;
		while (readd[i])
		{
			buffer[i] = readd[i];
			i++;
		}
		buffer[i] = 0;
		printf ("buffer before : %s", buffer);
		i = 0;
		int j = 0;
		int k = 0;
		while (buffer[i])
		{
			j = 0;
			k = i;
			while (buffer[k] == av[1][j])
			{
				k++;
				j++;
			}
			if (!av[1][j])
			{
				j = 0;
				while (av[1][j]) {
					printf("*");
					i ++;
					j ++;
				}
			}
			else{
				printf("%c", buffer[i++]);
			}
		}
		free(buffer);
	}
}
