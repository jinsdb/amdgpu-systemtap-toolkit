#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd;
    char buf[4096];
    //sleep(30); //run ./funtion.sh to trace vfs_read of this process
    //system("./function.sh");
    fd = open("/etc/passwd", O_RDONLY|O_DIRECT);
    read(fd, buf, 4096);
    read(fd, buf, 4096);
    close(fd);
    return 0;
}
