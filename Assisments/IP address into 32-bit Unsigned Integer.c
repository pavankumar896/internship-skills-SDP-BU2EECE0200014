#include <stdio.h>

unsigned int packIP(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
    return (a << 24) | (b << 16) | (c << 8) | d;
}

int main() {
    unsigned char a, b, c, d;
    char ip_address[16];
    printf("Enter the IP address (format: 172.22.208.98): ");
    scanf("%15s", ip_address);
    sscanf(ip_address, "%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    unsigned int packedIP = packIP(a, b, c, d);
    printf("Packed IP address: 0x%X\n", packedIP);
    return 0;
}