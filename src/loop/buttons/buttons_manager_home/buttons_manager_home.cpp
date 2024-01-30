#include "buttons_manager_home.h"

void buttons_manager_home(){
	if (digitalRead(BUTTON_OK_PIN) == LOW){
			switch(item_selected){
				case 0:
					current_screen = 1; //SPEED SCREEN
					break;
				case 3:
					setting_selected = 0;
					setting_box_position = 0;
					settings_first_item_to_show = 0;
					current_screen = 4; //SETTINGS SCREEN
					break;
				case 4:
					shutdown();
					break;
			}
	}

	if(digitalRead(BUTTON_UP_PIN) == LOW){
		item_selected -= 1;
		if (item_selected < 0){item_selected = NUM_ITEMS - 1; }
	}

	if (digitalRead(BUTTON_DOWN_PIN) == LOW){
		item_selected += 1;
		if (item_selected >= NUM_ITEMS){item_selected = 0; }
	}

	item_selected_previous = item_selected - 1;
	if (item_selected_previous < 0){ item_selected_previous = NUM_ITEMS - 1;}
	item_selected_next = item_selected + 1;
	if (item_selected_next >= NUM_ITEMS){ item_selected_next = 0; }
}