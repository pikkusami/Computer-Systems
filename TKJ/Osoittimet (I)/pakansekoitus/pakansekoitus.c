#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
void shuffle(uint8_t *list, uint16_t list_size);

// Main
/* int main() {
    srand(time(NULL));
    
    uint8_t list[8] = { 1,2,3,4,5,6,7,8};

    shuffle(list, 8);
    
    for (uint16_t i = 0; i < 20 && i < 8; i++) {
        printf("%u ", list[i]);
    }
    
    return 0;
} */

// Functions
void shuffle(uint8_t *list, uint16_t list_size) {
    if (list_size < 2) return;

    uint8_t temp_list[list_size];
    uint8_t *temp_ptr = temp_list;

    for (int i = list_size - 1; i > 0; i--) {
        uint16_t j = rand() % (i + 1);

        *temp_ptr++ = list[j];

        for (uint16_t k = j; k < i; k++) {
            list[k] = list[k + 1];
        }
    }

    *temp_ptr = list[0];

    for (uint16_t i = 0; i < list_size; i++) {
        list[i] = temp_list[i];
    }
}
