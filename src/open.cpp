#include <fcntl.h>    // open()
#include <unistd.h>   // write(), close()
#include <cstdio>     // perror()
#include <sys/ioctl.h>      // ioctl()
#include <linux/i2c-dev.h>

int main (){
    int fd = open("/dev/i2c-1", O_RDWR);

    if(fd == -1){
        perror("open");
        return 1;
    }
    if(ioctl(fd, I2C_SLAVE, 0x3c) < 0){
        perror("ioctl");
        close(fd);
        return 1;
    }

    printf("Forbundet til OLED\n");
    close(fd);
}