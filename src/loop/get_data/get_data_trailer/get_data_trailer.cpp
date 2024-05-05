#include "get_data_trailer.h"

void get_data_trailer(){
    DataTrailer dataTrailer;
    radio.startListening();
    if(radio.available()) {
        radio.read(&dataTrailer, sizeof(&dataTrailer));
        current_speed = dataTrailer.speedData;
        battery_trailer = dataTrailer.batteryData;
        last_time_trailer_data_recived = currentTime;
        debug_print("RADIO DATA entering [ speed : " + String(current_speed) + " , battery trailer : " + String(battery_trailer) + " ]");
    }else{
        if(last_time_trailer_data_recived + 3000 <= currentTime){
            current_speed = 0;
            battery_trailer = 0;
        }
    }
}