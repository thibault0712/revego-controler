#include "buttons_manager_settings.h"

void buttons_manager_settings(){
	if (digitalRead(BUTTON_OK_PIN) == LOW){
		Preferences preferences;
		preferences.begin("preferences", false);
		switch(setting_selected){
			case 0:
				eco_batterie = !eco_batterie;
				preferences.putBool("eco_batterie", eco_batterie);
				if (bluetooth){
        			pSettingsEcoModeCharacteristic->setValue(String(eco_batterie).c_str());
					pSettingsEcoModeCharacteristic->notify();
				}
				break;
			case 1:
				enable_speed_limiter = !enable_speed_limiter;
				preferences.putBool("enable_limiter", enable_speed_limiter);
				if(bluetooth){
       				pSettingsLimiterModeCharacteristic->setValue(String(enable_speed_limiter).c_str());
					pSettingsLimiterModeCharacteristic->notify();
				}
				break;
			case 2:
				enable_speed_regulator = !enable_speed_regulator;
				preferences.putBool("enable_regulat", enable_speed_regulator);
				if(bluetooth){
					pSettingsRegulatorModeCharacteristic->setValue(String(enable_speed_regulator).c_str());
					pSettingsRegulatorModeCharacteristic->notify();
				}
				break;
			case 3:
				if(speed_viewer_type == "SPEED"){
					speed_viewer_type = "PERCENTAGE";
					pSettingsSpeedViewerCharacteristic->setValue("1"); //If you don't understand "1" go to setup
					pSettingsSpeedViewerCharacteristic->notify();
				}
				else if(speed_viewer_type == "PERCENTAGE"){
					speed_viewer_type = "SPEED";
					pSettingsSpeedViewerCharacteristic->setValue("0"); //Same
					pSettingsSpeedViewerCharacteristic->notify();
				}
				preferences.putString("viewer_type", speed_viewer_type);
				break;
			case 4:
				bluetooth = !bluetooth;
				bluetoothInitialisation(); //Choose if I had to load bluetooth or not with the variable bluetooth
				preferences.putBool("bluetooth", bluetooth);
				break;
		}
		preferences.end();
	}

	if(digitalRead(BUTTON_UP_PIN) == LOW){
		if (setting_selected > 0){
			setting_selected -= 1;
		}

		if (setting_box_position > 0){
			setting_box_position -= 1;
		}else if(setting_box_position == 0 && setting_selected >= 0 && settings_first_item_to_show > 0){
			settings_first_item_to_show -= 1;
		}
	}
	
	if (digitalRead(BUTTON_DOWN_PIN) == LOW){
		if (setting_selected < NUM_SETTINGS_NAME - 1){
			setting_selected += 1;
		}

		if (setting_box_position < 3){
			setting_box_position += 1;
		}else if(setting_box_position == 3 && setting_selected <= NUM_SETTINGS_NAME - 1 && settings_first_item_to_show < NUM_SETTINGS_NAME - 4){
			settings_first_item_to_show += 1;
		}
	}
}