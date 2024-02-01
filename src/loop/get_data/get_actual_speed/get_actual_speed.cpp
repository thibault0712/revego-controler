#include "get_actual_speed.h"

void get_actual_speed(){
	current_speed = 10;
	DataTrailer dataTrailer;
    radio.read(&dataTrailer, sizeof(DataTrailer));
    battery_trailer = dataTrailer.speedData;
}