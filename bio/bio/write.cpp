#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main()
{
    int fd;
    char *buffer;
    const int SIZE = 4096;
    //char buf[4096];
    //sleep(30); //run ./funtion.sh to trace vfs_read of this process
    system("./function.sh");
    //fd = open("/etc/passwd", O_RDONLY);
    if(0 != posix_memalign((void**)&buffer, 4096, 4096)){
       printf("Errori in posix_memalign\n");
    }
    memset(buffer, 0x41, SIZE);
    fd = open("./test.txt", O_WRONLY|O_CREAT|O_DIRECT);
    //fd = open("./test.txt", O_WRONLY|O_CREAT);
    write(fd, buffer, 4096);
    close(fd);
    return 0;
}
