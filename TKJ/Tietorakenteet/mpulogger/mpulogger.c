#include <stdio.h>
#include <inttypes.h>

#define DATA_VALID 2

// Tietorakenteet
struct accelerometer_t {
    float ax, ay, az;
};

struct gyroscope_t {
    float gx, gy, gz;
};

struct mpu_status_t {
    int status_code;  // MPU:n tila
    int battery_level;  // Akun varausprosentti
};

struct mpu_sample_t {
    uint32_t timestamp;
    struct accelerometer_t accel;  // Kiihtyvyysanturin tiedot (ax, ay, az)
    struct gyroscope_t gyro;  // Gyroskoopin tiedot (gx, gy, gz)
    struct mpu_status_t status;  // Tilatiedot
};

// Prototypes
void printcsv(struct mpu_sample_t *samples, int size);

// Main
/* int main() {
    struct mpu_sample_t samples[5] = {
    {1695046347, {0.98, -0.43, 0.12}, {0.01, 0.02, 0.03}, {2, 85}},
    {1695046350, {1.02, -0.45, 0.14}, {0.02, 0.03, 0.04}, {1, 90}},
    {1695046353, {0.99, -0.40, 0.13}, {0.03, 0.04, 0.05}, {2, 75}},
    {1695046356, {1.01, -0.42, 0.15}, {0.05, 0.06, 0.07}, {0, 50}},
    {1695046359, {1.03, -0.41, 0.16}, {0.07, 0.08, 0.09}, {1, 60}}
    };

    printcsv(samples, 5);
    return 0;
} */

// Functions
void printcsv(struct mpu_sample_t *samples, int size) {
    for (int i = 0; i < size; i++) {
        if (samples[i].status.status_code == DATA_VALID) {
            printf("%d,%.2f,%.2f,%.2f\n", samples[i].timestamp, samples[i].accel.ax, samples[i].accel.ay, samples[i].accel.az);
        }
    }
}