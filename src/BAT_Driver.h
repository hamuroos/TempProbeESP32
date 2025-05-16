#pragma once
#include <Arduino.h> 

#define BAT_ADC_PIN   8
#define Measurement_offset 0.990476   

extern float BAT_analogVolts;
extern int BAT_percent;

void BAT_Init(void);
float BAT_Get_Volts(void);