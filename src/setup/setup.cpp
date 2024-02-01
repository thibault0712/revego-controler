#include "setup.h"

void serialMonitor(){
    Serial.begin(115200);
    Serial.println("Startup");
}

// //Utiliser pointeur pour optimiser et éviter une écriture dans la ram
// void get_data_in_speef(){
//     trailer_adress = "TRAIL";
// }

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

void radioInitialisation(){
    Serial.println("Load : radio");
    memcpy(adress_trailer, "traile", 6);

    radio.begin();
    radio.setChannel(1); //2401 MHZ
    radio.setPALevel(RF24_PA_MIN); //Best for 3.3V
    radio.setDataRate(RF24_1MBPS); //1Mb/s best between stability and transmission speed 
    Serial.println("Loaded : radio");
}

void setConfig(){
    Serial.println("Load : config");
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_25, 0);
    isEnable = true;
    Serial.println("Loaded : config");
}