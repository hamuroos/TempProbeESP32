#pragma once

#include "LVGL_Driver.h"
#include "Gyro_QMI8658.h"
#include "Display_ST7789.h"
#include "RTC_PCF85063.h"
#include "SD_MMC.h"
#include "Wireless.h"
#include "BAT_Driver.h"

#include "Temperature.h"

#define EXAMPLE1_LVGL_TICK_PERIOD_MS  1000


void Backlight_adjustment_event_cb(lv_event_t * e);

void Lvgl_Example1(void);
static void getSKUFromAPI();
void LVGL_Backlight_adjustment(uint8_t Backlight);

float Temp_get(void);

const char BAKERY_SKU_ENDPOINT[] = "https://ebe105tyej.execute-api.ap-southeast-1.amazonaws.com/prod/mes/bakery/planning/detail";