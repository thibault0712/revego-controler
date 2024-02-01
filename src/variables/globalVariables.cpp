#include "globalVariables.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
RF24 radio(pinCE, pinCSN);

byte adress_trailer[6] = {0};
String speed_viewer_type = "SPEED"; //SPEED || PERCENTAGE
int accelerator_value_for_motor = 0;
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
int speed_limiter_value = 0;
int speed_regulator_value = 0;
int current_speed = 0;
int current_screen = 0; 
//0 -> Menu
//1 -> Spedd Monitor
//4 -> Settings
unsigned long currentTime = 0;
unsigned long previousTime = 0;
unsigned long lastButtonClickTime = 0;
bool already_pressed_leave = false;
bool isEnable = true;
bool speed_limiter = false;
bool speed_regulator = false;
bool eco_batterie = true;