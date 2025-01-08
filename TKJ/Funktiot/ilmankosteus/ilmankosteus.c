#include <stdio.h>
#include <inttypes.h>
#include <math.h>

// Prototypes
float kosteus(uint16_t rekisteri);

// Main
/* int main() {
    uint16_t rekisteriarvo = 0x8000;
    float tulos = kosteus(rekisteriarvo);
    printf("%.2f",tulos);

    return 0;
} */

// Functions
float kosteus(uint16_t rekisteri) {
    return (rekisteri / (float)(1 << 16)) * 100;
}
