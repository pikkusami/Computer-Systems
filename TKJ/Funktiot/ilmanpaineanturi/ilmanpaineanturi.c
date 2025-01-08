#include <stdio.h>
#include <inttypes.h>

// Prototypes
uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb);

// Main
int main() {
    uint32_t tulos = ilmanpaine(-34, -68, 24);
    printf("%u",tulos);
    return 0;
}

// Functions
uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb) {
    uint32_t paine = (msb << 12) | (lsb << 4) | (xlsb >> 4);
    return paine;
}
