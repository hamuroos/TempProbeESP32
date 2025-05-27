/*Using LVGL with Arduino requires some extra steps:
 *Be sure to read the docs here: https://docs.lvgl.io/master/get-started/platforms/arduino.html  */

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
// Time that the daily task runs in 24 hour format
const int task1Hour = 2;    // Task 1 at 8:15 AM
const int task1Minute = 00;
// Store the day when the task last ran to ensure it only runs once per day
int lastRunDayTask1 = -1;
unsigned long lastNTPUpdate = 0; // Timestamp for the last NTP sync
const unsigned long ntpSyncInterval = 2 * 60 * 1000; // Sync every 30 minutes (in ms)

void syncTime() {
  Serial.print("Synchronizing time with NTP server...");
  configTime(0, 0, "pool.ntp.org", "time.nist.gov"); // UTC offset set to 0
  time_t now = time(nullptr);
  while (now < 24 * 3600) { // Wait until time is valid
    delay(100);
    now = time(nullptr);
  }
  Serial.println(" Time synchronized!");
  
  // Set timezone
  setenv("TZ", timezone, 1);
  tzset();

  lastNTPUpdate = millis(); // Record the time of the last sync
}

void DriverTask(void *parameter) {
  //Wireless_Test2();
  while(1){
    PWR_Loop();
    BAT_Get_Volts();
    PCF85063_Loop();
    QMI8658_Loop(); 

    //Temp_get();

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
  
  // lv_demo_widgets();               
  // lv_demo_benchmark();          
  // lv_demo_keypad_encoder();     
  // lv_demo_music();              
  // lv_demo_printer();
  // lv_demo_stress();   
  Driver_Loop();
}

void loop()
{
  Lvgl_Loop();
  vTaskDelay(pdMS_TO_TICKS(5));

  time_t now = time(nullptr);
  struct tm timeinfo;
  localtime_r(&now, &timeinfo);
  
  /*if (timeinfo.tm_hour == task1Hour && timeinfo.tm_min == task1Minute && lastRunDayTask1 != timeinfo.tm_mday) {
    getSKUFromAPI();
    // Set the day to ensure it only runs once per day
    lastRunDayTask1 = timeinfo.tm_mday;
  }*/

  if (millis() - lastNTPUpdate > ntpSyncInterval) {
    printf("TEST ONE MIN INTERVAL AT : %02d:%02d:%02d \n", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    syncTime();
  }

}
