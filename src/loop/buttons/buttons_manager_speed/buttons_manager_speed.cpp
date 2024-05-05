#include "buttons_manager_speed.h"

void buttons_manager_speed(){
	if (digitalRead(BUTTON_UP_PIN) == LOW && enable_speed_regulator){
		speed_regulator = !speed_regulator;
		speed_limiter = false;
		if(speed_regulator){
			speed_regulator_value = current_speed;
		}
	}
	if (digitalRead(BUTTON_DOWN_PIN) == LOW && enable_speed_limiter){
		speed_limiter = !speed_limiter;
		speed_regulator = false;
		if(speed_limiter){
			speed_limiter_value = current_speed;
		}
	}
}