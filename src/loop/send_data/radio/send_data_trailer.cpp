#include "send_data_trailer.h"

void send_data_trailer(){
    radio.stopListening();
    char _data_to_send[5];
    if (eco_batterie && data_to_send > eco_max_pwm){
        data_to_send = eco_max_pwm;
    }
    sprintf(_data_to_send, "%d", data_to_send);
    if (!eco_batterie || (eco_batterie && currentTime >= last_sended_data + eco_radio_delay)){
        radio.write(&_data_to_send, sizeof(_data_to_send));
        debug_print("RADIO DATA sending [ motor speed : " + String(data_to_send) + " ]");
        last_sended_data = currentTime;
    }
}