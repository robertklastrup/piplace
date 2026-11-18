#include <fcntl.h>    // open()
#include <unistd.h>   // write(), close()
#include <cstdio>     // perror()
#include <sys/ioctl.h>      // ioctl()
#include <linux/i2c-dev.h>

bool send_command(int fd, unsigned char cmd) {
    unsigned char buf[] = { 0x00, cmd };
    ssize_t n = write(fd, buf, 2);
    return n == 2;
}

int main() {
    // 1. Åbn I2C-bussen
    int fd = open("/dev/i2c-1", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 2. Vælg OLED'en (adresse 0x3c)
    if (ioctl(fd, I2C_SLAVE, 0x3c) < 0) {
        perror("ioctl");
        close(fd);
        return 1;
    }
    printf("Forbundet til OLED\n");

    // 3. Tænd skærmen: charge pump til + display on
    if (!send_command(fd, 0x8D) ||
        !send_command(fd, 0x14) ||
        !send_command(fd, 0xAF)) {
        perror("send_command");
        close(fd);
        return 1;
    }
    printf("Skærmen er tændt\n");

    // 4. Ryd op
    close(fd);
    return 0;
}