#include "get_battery_trailer.h"

void get_battery_trailer(){
    battery_trailer = 20;
    DataTrailer dataTrailer;
    radio.read(&dataTrailer, sizeof(DataTrailer));
    battery_trailer = dataTrailer.batteryData;
}