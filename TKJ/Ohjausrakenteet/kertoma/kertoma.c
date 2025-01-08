#include <stdio.h>
#include <inttypes.h>

// Prototypes
int64_t laske_kertoma(int8_t n);

// Main
/* int main() {
    printf("%d",laske_kertoma(5));
} */

// Functions
int64_t laske_kertoma(int8_t n) {
    if (n > 20) {
        return -1;
    }
    else {
        int64_t tulos = 1;
        for (int i = 2; i <= n; i++) {
            tulos *= i;
        }

        return tulos;
    }
}
