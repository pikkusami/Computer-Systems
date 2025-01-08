#include <stdio.h>
#include <inttypes.h>

// Prototypes
int8_t tictactoe_check(int8_t * gameboard, int win_len);

// Main
/* int main() {
    int8_t gameboard[100] = {
        1, 0, 0, 2, 2, 1, 0, 0, 1, 0,
        2, 1, 0, 0, 2, 1, 0, 2, 1, 0,
        0, 0, 1, 0, 2, 0, 1, 2, 0, 0,
        0, 1, 0, 2, 0, 2, 0, 1, 0, 0,
        1, 1, 1, 1, 1, 0, 2, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 0, 2, 2,
        2, 2, 2, 2, 0, 0, 1, 0, 1, 0,
        0, 0, 0, 0, 2, 2, 2, 0, 2, 2,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 2
    };
    
    int result = tictactoe_check(gameboard, 5);
    printf("Voittaja: %d\n", result);  // Tulostaa voittajan
    
    return 0;
} */

// Functions
int8_t tictactoe_check(int8_t *gameboard, int win_len) {
    int x_wins = 0, o_wins = 0;

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            int x_count = 0, o_count = 0;

            // Vaakasuora tarkistus
            if (col <= 10 - win_len) {
                for (int k = 0; k < win_len; k++) {
                    if (gameboard[row * 10 + col + k] == 1) x_count++;
                    else if (gameboard[row * 10 + col + k] == 2) o_count++;
                }
                if (x_count == win_len) x_wins = 1;
                if (o_count == win_len) o_wins = 1;
            }

            x_count = o_count = 0;

            // Pystysuora tarkistus
            if (row <= 10 - win_len) {
                for (int k = 0; k < win_len; k++) {
                    if (gameboard[(row + k) * 10 + col] == 1) x_count++;
                    else if (gameboard[(row + k) * 10 + col] == 2) o_count++;
                }
                if (x_count == win_len) x_wins = 1;
                if (o_count == win_len) o_wins = 1;
            }

            x_count = o_count = 0;

            // Vinottainen tarkistus oikealle alaspäin
            if (row <= 10 - win_len && col <= 10 - win_len) {
                for (int k = 0; k < win_len; k++) {
                    if (gameboard[(row + k) * 10 + col + k] == 1) x_count++;
                    else if (gameboard[(row + k) * 10 + col + k] == 2) o_count++;
                }
                if (x_count == win_len) x_wins = 1;
                if (o_count == win_len) o_wins = 1;
            }

            x_count = o_count = 0;

            // Vinottainen tarkistus vasemmalle alaspäin
            if (row <= 10 - win_len && col >= win_len - 1) {
                for (int k = 0; k < win_len; k++) {
                    if (gameboard[(row + k) * 10 + col - k] == 1) x_count++;
                    else if (gameboard[(row + k) * 10 + col - k] == 2) o_count++;
                }
                if (x_count == win_len) x_wins = 1;
                if (o_count == win_len) o_wins = 1;
            }
        }
    }

    if (x_wins && o_wins) return 0;  // Molemmat täyttävät voittoehdon, peli mahdoton
    if (x_wins) return 1;            // X voittaa
    if (o_wins) return 2;            // O voittaa

    return 0; // Kumpikaan ei voita
}
