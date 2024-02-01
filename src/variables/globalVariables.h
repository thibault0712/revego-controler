#include <Arduino.h>
#include <U8g2lib.h>
#include <RF24.h>
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H


extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
extern RF24 radio;

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

struct DataTrailer {
  int batteryData;
  int speedData;
};

extern byte adress_trailer[6];
extern String speed_viewer_type;
extern int accelerator_value_for_motor;
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
extern int speed_limiter_value;
extern int speed_regulator_value;
extern int current_speed;
extern int current_screen; 
//0 -> Menu
//1 -> Spedd Monitor
//4 -> Settings
extern unsigned long currentTime;
extern unsigned long previousTime;
extern unsigned long lastButtonClickTime;
extern bool already_pressed_leave;
extern bool isEnable;
extern bool speed_limiter;
extern bool speed_regulator;
extern bool eco_batterie;

#endif