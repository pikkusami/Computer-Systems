#include <stdio.h>
#include <inttypes.h>

// Prototypes
void movavg(float *array, uint8_t array_size, uint8_t window_size);

// Main
/* int main() {
    float data[5] = { 1.0, 2.0, 4.0, 6.0, 9.0 };
    movavg(data, 5, 3);
} */

// Functions
void movavg(float *array, uint8_t array_size, uint8_t window_size) {
    for (uint8_t i = 0; i <= array_size - window_size; i++) {
        float sum = 0.0;
        for (uint8_t j = 0; j < window_size; j++) {
            sum += array[i + j];
        }
        float average = sum / window_size;

        printf("%.2f", average);

        if (i < array_size - window_size) {
            printf(",");
        }
    }
}
