#include "setup.h"

void serialMonitor(){
    Serial.begin(115200);
    Serial.println("Startup");
}

void screenInitialisation(){
    Serial.println("Load : screen");
    u8g2.begin();
    u8g2.setFont(u8g2_font_freedoomr10_tu);
    u8g2.setColorIndex(1);
    Serial.println("Loaded : screen");
}

void buttonsInitialisation(){
    Serial.println("Load : buttons");
    pinMode(BUTTON_LEAVE_PIN, INPUT);
    pinMode(BUTTON_UP_PIN, INPUT);
    pinMode(BUTTON_OK_PIN, INPUT);
    pinMode(BUTTON_DOWN_PIN, INPUT);
    Serial.println("Loaded : buttons");
}

void setConfig(){
    Serial.println("Load : config");
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_25, 0);
    isEnable = true;
    Serial.println("Loaded : config");
}