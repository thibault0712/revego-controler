#include "get_battery_controler.h"

int get_battery_controler(){
    analogic_battery_controler = analogRead(ANALOGIC_BATTERY_CONTROLER);
	int percentage_battery_controler = map(analogic_battery_controler, 2667, 3400, 0, 100);
	if (percentage_battery_controler < 0){
		percentage_battery_controler = 0;
	}else if (percentage_battery_controler > 100){
		percentage_battery_controler = 100;
	}
    return percentage_battery_controler;
}