
void serialReadSensor(void *pParams) {
  //Read Sensor Data and Print to terminal
  while(1) {
    Serial.println("Temp: " + String(sht21.getTemperature()) + " *C");
    Serial.println("Humid: " + String(sht21.getHumidity()) + " %");
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

void wifiConnectionCheck(void *pParams) {
  while(1) {
    if(WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pwd);
    } else {
      Serial.println("WiFi connection remaining...");
    }
    vTaskDelay(5000/portTICK_PERIOD_MS);
  }
}

