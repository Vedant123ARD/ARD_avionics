/*
 * Altitude_Measurement.c
 *
 *  Created on: Apr 3, 2025
 *      Author: vedan
 */
#include "altitude_measurement.h"
#include <math.h>

float pressure, temperature, humidity;
float max_pressure = 0.0f;
float min_pressure = 100000000.0f;
float altitude;

void init_bmp280(BMP280_HandleTypedef *bmp280, I2C_HandleTypeDef *hi2c) {
    bmp280_init_default_params(&bmp280->params);
    bmp280->addr = BMP280_I2C_ADDRESS_0;
    bmp280->i2c = hi2c;

    while (!bmp280_init(bmp280, &bmp280->params)) {
        HAL_Delay(2000);
    }
}

void read_altitude(BMP280_HandleTypedef *bmp280) {
    if (bmp280_read_float(bmp280, &temperature, &pressure, &humidity)) {
        if (pressure > max_pressure) max_pressure = pressure;
        if (pressure < min_pressure && pressure > 0) min_pressure = pressure;
    }
    altitude = 44330.0f * (1.0f - pow((pressure / 101325.0f), (1.0f / 5.255f)));
}


