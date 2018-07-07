


void ThingConnectionCheck(void *pParam) {
  while (1) {
    if(!client.connected()) {
      client.connect((char*) clientName.c_str());
    }
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}

void ThingSendSensorData(void *pParams) {
  while(1) {
    String t = String(sht21.getTemperature());
    String h = String(sht21.getHumidity());
    String mqttMsg = "field1=";
    mqttMsg += t;
    mqttMsg += "&field2=";
    mqttMsg += h;
    
    if(client.connected()) {
      if(client.publish(mqttTopic, (char*) mqttMsg.c_str())) {
        Serial.println("MQTT-PUBLISH: Temp: " + t + " *C, Humid: " + h + " %");
      } else {
        Serial.println("MQTT-PUBLISH: Publishing Failed!");
      }
    }
    vTaskDelay(15000 / portTICK_PERIOD_MS);
  }
}

