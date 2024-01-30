#include "shutdown.h"

void shutdown(){
    previousTime=currentTime;
	Serial.println("POWER OFF");
	isEnable = false;
	u8g2.clearBuffer();
	u8g2.sendBuffer();
	delay(2000);
	esp_deep_sleep_start(); 
}