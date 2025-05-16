#include "Temperature.h"

float Temp_C = 0;

Adafruit_MAX31856 maxthermo = Adafruit_MAX31856(CS,DI,DO,CLK);

void Temp_Init(void) {
  Serial.begin(115200);
  while (!Serial) delay(10);
  Serial.println("MAX31856 thermocouple test");

  if (!maxthermo.begin()) {
    Serial.println("Could not initialize thermocouple.");
    while (1) delay(10);
  }

  maxthermo.setThermocoupleType(MAX31856_TCTYPE_K);
  /*
  Serial.print("Thermocouple type: ");
  switch (maxthermo.getThermocoupleType() ) {
    case MAX31856_TCTYPE_B: Serial.println("B Type"); break;
    case MAX31856_TCTYPE_E: Serial.println("E Type"); break;
    case MAX31856_TCTYPE_J: Serial.println("J Type"); break;
    case MAX31856_TCTYPE_K: Serial.println("K Type"); break;
    case MAX31856_TCTYPE_N: Serial.println("N Type"); break;
    case MAX31856_TCTYPE_R: Serial.println("R Type"); break;
    case MAX31856_TCTYPE_S: Serial.println("S Type"); break;
    case MAX31856_TCTYPE_T: Serial.println("T Type"); break;
    case MAX31856_VMODE_G8: Serial.println("Voltage x8 Gain mode"); break;
    case MAX31856_VMODE_G32: Serial.println("Voltage x8 Gain mode"); break;
    default: Serial.println("Unknown"); break;
  }
  maxthermo.setConversionMode(MAX31856_CONTINUOUS);
  */
  maxthermo.setConversionMode(MAX31856_ONESHOT_NOWAIT);
}

/*
float Temp_get(void){

  Temp_C = (float)(maxthermo.readThermocoupleTemperature()); // printf("BAT voltage : %.2f V\r\n", BAT_analogVolts);
  Serial.println(maxthermo.readThermocoupleTemperature());
  delay(1000);

  return Temp_C;
}
*/
