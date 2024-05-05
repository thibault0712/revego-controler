#include "buttons_manager_bluetooth.h"

void buttons_manager_bluetooth(){
    	if (digitalRead(BUTTON_OK_PIN) == LOW && !bluetooth){
            current_screen = 0;
			u8g2.setColorIndex(1); //Colors can be dereglated if it removed
        }
}