#include "variables/globalVariables.h"
#include "setup/setup.h"
#include "loop/buttons/buttons_manager.h"
#include "loop/screen/screen_manager.h"
#include "loop/get_data/get_data.h"
#include "loop/functionality/functionality_manager.h" 
#include "loop/send_data/radio/send_data_trailer.h"
#include "loop/bluetooth/bluetooth.h"

void setup() {
  serialMonitor();
  preferencesInitialisation();
  bluetoothInitialisation();
  screenInitialisation();
  buttonsInitialisation();
  radioInitialisation();
  setConfig();
}

void loop() {
  if (isEnable == false){ 
    return;
  }else{
	  currentTime=millis();
    get_analogic_accelerator();

    screen_manager();
    buttons_manager();
    speed_regulator_breaker();
    speed_gestionary();

    send_data_trailer();
    get_data_trailer();

    send_bluetooth_battery_trailer();
  }
}