#include "config.h" //configuration & authentication data
#include "utils.h" //utility functions
#include "mythingspeak.h" //thingspeak engines

void setup() {
  Serial.begin(115200);
  sht21.begin();
  Serial.printf("\n\n\n");
  Serial.printf("iFarmSensorbox Version: beta-1");
  Serial.printf("FreeRTOS version: %s\n", tskKERNEL_VERSION_NUMBER);
  //Free RTOS ZONE
//  xTaskCreate(&serialReadSensor, "serialReadSensor", 1000, NULL, 1, NULL);
  xTaskCreate(&wifiConnectionCheck,"wifiConnectinoCheck",2000, NULL, 2, NULL);
  xTaskCreate(&ThingConnectionCheck, "ThingConnectionCheck", 2000, NULL, 2, NULL);
  xTaskCreate(&ThingSendSensorData, "ThingSendSensordData", 3000, NULL, 3, NULL);
}

void loop() {
}
