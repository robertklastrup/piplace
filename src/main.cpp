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

    unsigned char kommando[] = { 0x00, 0xAF };
    ssize_t n = write(fd, kommando, 2);

    if (n != 2) {
        perror("write");
        close(fd);
        return 1;
    }
    printf("Sendte %zd bytes til OLED\n", n);

    printf("Forbundet til OLED\n");
    close(fd);
}