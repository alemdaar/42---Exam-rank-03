#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main ()
{
    char buffer[2];
    ssize_t r;
    int i;
    int fd = open ("file",O_RDWR);
    if (fd == -1)
    {
        printf ("fd == -1");
        return -1;
    }
    while (1)
    {
        printf ("....\n");
        write (fd, "2", 1);
        i = 0;
        while (i < 999999998)
        {
            i++;
        }
        r = read(fd, buffer, 1);
        if (r == -1)
        {
            printf ("r == -1\n");
            return 1;
        }
        else if (r == 0)
        {
            printf ("r didnt read anything\n");
            return 0;
        }
        buffer[r] = 0;
        printf ("buffer : %s\n", buffer);
    }
}
