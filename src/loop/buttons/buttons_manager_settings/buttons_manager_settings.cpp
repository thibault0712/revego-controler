#include "buttons_manager_settings.h"

void buttons_manager_settings(){
	if (digitalRead(BUTTON_OK_PIN) == LOW){

	}

	if(digitalRead(BUTTON_UP_PIN) == LOW){
		if (setting_selected > 0){
			setting_selected -= 1;
		}

		if (setting_box_position > 0){
			setting_box_position -= 1;
		}else if(setting_box_position == 0 && setting_selected != 0){
			settings_first_item_to_show -= 1;
		}
	}

	if (digitalRead(BUTTON_DOWN_PIN) == LOW){
		if (setting_selected < NUM_SETTINGS_NAME){
			setting_selected += 1;
		}

		if (setting_box_position < 3){
			setting_box_position += 1;
		}else if(setting_box_position == 3 && setting_selected != NUM_SETTINGS_NAME){
			settings_first_item_to_show += 1;
		}
	}
}