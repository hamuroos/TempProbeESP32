# 1 "C:\\Users\\hamham\\AppData\\Local\\Temp\\tmpm3sto2ew"
#include <Arduino.h>
# 1 "C:/Users/hamham/Documents/PlatformIO/Projects/250507-133814-esp32-s3-devkitm-1/src/LVGL_Arduino_V12.ino"



#include "Display_ST7789.h"
#include "Audio_PCM5101.h"
#include "RTC_PCF85063.h"
#include "Gyro_QMI8658.h"
#include "LVGL_Driver.h"
#include "PWR_Key.h"
#include "SD_Card.h"
#include "LVGL_Example.h"
#include "BAT_Driver.h"
#include "Wireless.h"

#include "Temperature.h"

const char* timezone = "<+07>-7";

const int task1Hour = 2;
const int task1Minute = 00;

int lastRunDayTask1 = -1;
unsigned long lastNTPUpdate = 0;
const unsigned long ntpSyncInterval = 2 * 60 * 1000;
void syncTime();
void DriverTask(void *parameter);
void Driver_Loop();
void setup();
void loop();
#line 26 "C:/Users/hamham/Documents/PlatformIO/Projects/250507-133814-esp32-s3-devkitm-1/src/LVGL_Arduino_V12.ino"
void syncTime() {
  Serial.print("Synchronizing time with NTP server...");
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  time_t now = time(nullptr);
  while (now < 24 * 3600) {
    delay(100);
    now = time(nullptr);
  }
  Serial.println(" Time synchronized!");


  setenv("TZ", timezone, 1);
  tzset();

  lastNTPUpdate = millis();
}

void DriverTask(void *parameter) {

  while(1){
    PWR_Loop();
    BAT_Get_Volts();
    PCF85063_Loop();
    QMI8658_Loop();



    Touch_check();

    vTaskDelay(pdMS_TO_TICKS(100));

  }
}
void Driver_Loop() {
  xTaskCreatePinnedToCore(
    DriverTask,
    "DriverTask",
    4096,
    NULL,
    3,
    NULL,
    0
  );
}

void setup()
{

  Flash_test();
  PWR_Init();
  BAT_Init();
  I2C_Init();
  PCF85063_Init();
  QMI8658_Init();
  Backlight_Init();

  Temp_Init();

  SD_Init();
  Audio_Init();
  LCD_Init();
  Lvgl_Init();

  syncTime();
  Lvgl_Example1();







  Driver_Loop();
}

void loop()
{
  Lvgl_Loop();
  vTaskDelay(pdMS_TO_TICKS(5));

  time_t now = time(nullptr);
  struct tm timeinfo;
  localtime_r(&now, &timeinfo);







  if (millis() - lastNTPUpdate > ntpSyncInterval) {
    printf("TEST ONE MIN INTERVAL AT : %02d:%02d:%02d \n", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    syncTime();
  }

}