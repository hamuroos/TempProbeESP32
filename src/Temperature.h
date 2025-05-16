#pragma once
#include <Adafruit_MAX31856.h>
#include <lvgl.h>

#define CS    18
#define DI    43
#define DO    44
#define CLK   15

extern float Temp_C;
extern Adafruit_MAX31856 maxthermo;

void Temp_Init(void);
//float Temp_get(void);