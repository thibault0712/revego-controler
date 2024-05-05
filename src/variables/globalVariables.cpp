#include "globalVariables.h"

U8G2_SSD1309_128X64_NONAME0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
RF24 radio(pinCE, pinCSN);

BLEServer* pServer = NULL;
BLECharacteristic* pDebugCharacteristic = NULL;
BLECharacteristic* pBatteryTrailerCharacteristic = NULL;
BLECharacteristic* pBatteryRemoteCharacteristic = NULL;
BLECharacteristic* pEcoDelayCharacteristic = NULL;
BLECharacteristic* pEcoPwmCharacteristic = NULL;
BLECharacteristic* pSettingsEcoModeCharacteristic = NULL;
BLECharacteristic* pSettingsRegulatorModeCharacteristic = NULL;
BLECharacteristic* pSettingsLimiterModeCharacteristic = NULL;
BLECharacteristic *pSettingsSpeedViewerCharacteristic = NULL;
BLECharacteristic *pSecuritySenderCharacteristic = NULL;
BLECharacteristic *pSecurityReceiverCharacteristic = NULL;


String not_converted_sender_adress = "PIPE1"; //Default value
String not_converted_receiver_adress = "PIPE2"; //Default value
byte sender_adress[6] = {0x12, 0xAB, 0xCD, 0x34, 0x56, 0x78};
byte receiver_adress[6] = {0x12, 0xAC, 0xCA, 0xAA, 0xAA, 0xAA};
String speed_viewer_type = "SPEED"; // SPEED || PERCENTAGE
int accelerator_value_for_motor = 0;
int eco_max_pwm = 0;
int eco_radio_delay = 0;
int data_to_send = 0;
int item_selected = 0;
int item_selected_previous = 0;
int item_selected_next = 0;
int setting_selected = 0;
int setting_box_position = 0;
int settings_first_item_to_show = 0;
int analogic_accelerator = 0;
int analogic_battery_controler = 0;
int battery_trailer = 0;
int last_battery_trailer = 0;
int speed_limiter_value = 0;
int speed_regulator_value = 0;
int current_speed = 0;
int current_screen = 0; 
//0 -> Menu
//1 -> Spedd Monitor
//4 -> Settings
unsigned long currentTime = 0;
unsigned long last_time_trailer_data_recived = 0;
unsigned long previousTime = 0;
unsigned long lastButtonClickTime = 0;
unsigned long last_sended_data = 0;
bool already_pressed_leave = false;
bool isEnable = true;
bool speed_regulator = false;
bool speed_limiter = false;
bool enable_speed_limiter = false;
bool enable_speed_regulator = false;
bool eco_batterie = true;
bool bluetooth = true;

//Todo : ajouter un struct pour les régulateurs de vitesses