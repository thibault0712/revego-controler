#include "send_data_trailer.h"

void send_data_trailer(){
    radio.stopListening();
    char _data_to_send[3];
    itoa(data_to_send, _data_to_send, 10); //10 pour base 10
    radio.write(&_data_to_send, sizeof(_data_to_send));
}