#include "speed_gestionary.h"

void speed_gestionary(){
    if (speed_limiter){
		if (current_speed > speed_limiter_value){
			data_to_send = 0;
		}else{
			data_to_send = accelerator_value_for_motor;
		}
	}else if(speed_regulator){
		if (current_speed > speed_regulator_value){
			data_to_send = 0;
		}else{
			data_to_send = 255;
		}
	}else{
		data_to_send = accelerator_value_for_motor;
	}
}

void speed_regulator_breaker(){
    if (speed_regulator){
		if (accelerator_value_for_motor > 0){
			speed_regulator = false;
		}
	}
}