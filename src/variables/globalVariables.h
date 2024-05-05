#include <Arduino.h>
#include <U8g2lib.h>
#include <RF24.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

//BLE ADR change in const if possible to optimize ram
#define SERVICE_UUID        	  "110A"
#define SETTINGS_SERVICE_UUID	  "1200"
#define SECURITY_SERVICE_UUID	  "130A"
#define DEBUG_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define BATTERY_TRAILER_CHARACTERISTIC_UUID "2f4bd085-b8b5-4d00-bd5a-0f54ff63a649"
#define BATTERY_REMOTE_CHARACTERISTIC_UUID "99a6e42e-0451-4d04-9442-3f7e61aa51e6"
#define ECO_DELAY_CHARACTERISTIC_UUID "11223344-5566-7788-9900-aabbccddeeff"
#define ECO_PWM_CHARACTERISTIC_UUID "aabbccdd-eeff-0011-2233-445566778899"
#define SETTINGS_ECO_MODE_CHARACTERISTIC_UUID "6defc9f1-6bf9-4093-afc2-bddf50606cdf"
#define SETTINGS_REGULATOR_MODE_CHARACTERISTIC_UUID "68aff69d-caaf-4d38-b110-bdbcf6d6e03b"
#define SETTINGS_LIMITER_MODE_CHARACTERISTIC_UUID "b4880d38-741b-4393-a119-f57ca4ad8829"
#define SETTINGS_SPEED_VIEWER_CHARACTERISTIC_UUID "0a479108-4baa-4fda-a655-68644b974c4d"
#define SECURITY_RADIO_SENDER_CHARACTERISTIC_UUID "f42cd529-8e8e-4d98-b8c8-63a899b6d2b1"
#define SECURITY_RADIO_RECEIVER_CHARACTERISTIC_UUID "5e223c61-d157-4f24-85a4-57a195f76296"


extern U8G2_SSD1309_128X64_NONAME0_F_HW_I2C u8g2;
extern RF24 radio;
extern BLEServer* pServer;
extern BLECharacteristic* pDebugCharacteristic;
extern BLECharacteristic* pBatteryTrailerCharacteristic;
extern BLECharacteristic* pBatteryRemoteCharacteristic;
extern BLECharacteristic* pEcoDelayCharacteristic;
extern BLECharacteristic* pEcoPwmCharacteristic;
extern BLECharacteristic *pSettingsEcoModeCharacteristic;
extern BLECharacteristic *pSettingsRegulatorModeCharacteristic;
extern BLECharacteristic *pSettingsLimiterModeCharacteristic;
extern BLECharacteristic *pSettingsSpeedViewerCharacteristic;
extern BLECharacteristic *pSecuritySenderCharacteristic;
extern BLECharacteristic *pSecurityReceiverCharacteristic;


const int NUM_ITEMS = 5;
const int NUM_SETTINGS_NAME = 5;
const char menu_items[NUM_ITEMS] [20] = { //Si on change char en String on doit convertir en char pour afficher les données
	{"Vitesse"},
	{"Batterie"},
	{"Bluetooth"},
	{"Parametres"},
	{"Eteindre"}
};
const char settings_name[NUM_SETTINGS_NAME] [20] = {
	{"Eco batterie"},
	{"Limiteur"},
	{"Regulateur"},
	{"Vitesse"},
	{"Bluetooth"}
};
const int BUTTON_LEAVE_PIN = 25;
const int BUTTON_UP_PIN = 26;
const int BUTTON_OK_PIN = 27;
const int BUTTON_DOWN_PIN = 14;
const int ANALOGIC_ACCELERATOR = 34;
const int ANALOGIC_BATTERY_CONTROLER = 35;
const int pinCE = 4;
const int pinCSN = 5;
const int Q_trailer = 6; //Ah 
const float I_max_trailer = 1; //A
const float I_min_trailer = 0.08; //A

struct DataTrailer{
  int16_t batteryData;
  int16_t speedData;
};

extern String not_converted_sender_adress;
extern String not_converted_receiver_adress;
extern byte receiver_adress[6];
extern byte sender_adress[6];
extern String speed_viewer_type;
extern int accelerator_value_for_motor;
extern int eco_max_pwm;
extern int eco_radio_delay;
extern int data_to_send;
extern int item_selected;
extern int item_selected_previous;
extern int item_selected_next;
extern int setting_selected;
extern int setting_box_position;
extern int settings_first_item_to_show;
extern int analogic_accelerator;
extern int analogic_battery_controler;
extern int battery_trailer;
extern int last_battery_trailer;
extern int speed_limiter_value;
extern int speed_regulator_value;
extern int current_speed;
extern int current_screen; 
//0 -> Menu
//1 -> Spedd Monitor
//4 -> Settings
extern unsigned long currentTime;
extern unsigned long last_time_trailer_data_recived;
extern unsigned long previousTime;
extern unsigned long lastButtonClickTime;
extern unsigned long last_sended_data;
extern bool already_pressed_leave;
extern bool isEnable;
extern bool speed_regulator;
extern bool speed_limiter;
extern bool enable_speed_limiter;
extern bool enable_speed_regulator;
extern bool eco_batterie;
extern bool bluetooth;

#endif