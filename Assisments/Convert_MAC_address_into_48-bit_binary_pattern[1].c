#include <stdio.h>

void macToBinary(const char* mac) {
    unsigned int bytes[6];
    char binary[49];
    binary[48] = '\0';
    sscanf(mac, "%x:%x:%x:%x:%x:%x", &bytes[0], &bytes[1], &bytes[2], &bytes[3], &bytes[4], &bytes[5]);
    for (int i = 0; i < 6; ++i) {
        for (int bit = 0; bit < 8; ++bit) {
            binary[i * 8 + (7 - bit)] = (bytes[i] & (1 << bit)) ? '1' : '0';
        }
    }
    printf("Binary representation: %s\n", binary);
}

int main() {
    char mac_address[18];
    printf("Example of a MAC address: 2C-3B-70-58-1E-0B\n");
    printf("Enter a MAC address: ");
    scanf("%17s", mac_address);
    macToBinary(mac_address);
    return 0;
}