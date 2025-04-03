// altitude_measurement.h
#ifndef ALTITUDE_MEASUREMENT_H
#define ALTITUDE_MEASUREMENT_H

#include "stm32f4xx_hal.h"
#include "bmp280.h"

extern float pressure, temperature, humidity;
extern float max_pressure, min_pressure, altitude;

void init_bmp280(BMP280_HandleTypedef *bmp280, I2C_HandleTypeDef *hi2c);
void read_altitude(BMP280_HandleTypedef *bmp280);

#endif // ALTITUDE_MEASUREMENT_H
