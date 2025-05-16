#include "BAT_Driver.h"

float BAT_analogVolts = 0;

int BAT_percent = 0;

void BAT_Init(void)
{
  //set the resolution to 12 bits (0-4095)
  analogReadResolution(12);
}
float BAT_Get_Volts(void)
{
  int Volts = analogReadMilliVolts(BAT_ADC_PIN); // millivolts
  BAT_analogVolts = (float)(Volts * 3.0 / 1000.0) / Measurement_offset;

  BAT_percent = map(BAT_analogVolts*100, 3.1*100, 4.1*100, 0, 100);
  BAT_percent = int(BAT_percent);
  BAT_percent = constrain(BAT_percent, 0, 100);
  
  //printf("BAT Percent : %d %\r\n", BAT_percent);

  return BAT_analogVolts,BAT_percent;
}



