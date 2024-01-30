#include "button_leave_manager.h"

void button_leave_manager(){
    if (digitalRead(BUTTON_LEAVE_PIN) == LOW){
		if (already_pressed_leave == false){
			already_pressed_leave = true;
			previousTime = currentTime;
		}
		if((currentTime-previousTime)>2000){
			shutdown();
			already_pressed_leave = false;
		}
	}else{
		if (already_pressed_leave == true){
			current_screen = 0;
			u8g2.setColorIndex(1); //Sinon les couleurs peuvent bug en fonction du menu
			already_pressed_leave = false; 
		}
	}
}