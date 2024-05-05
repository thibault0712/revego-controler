#include "send_bluetooth_battery.h"

void send_bluetooth_battery_trailer(){
    //Avoid to send same data and spam for nothing
    if (battery_trailer != last_battery_trailer){
        pBatteryTrailerCharacteristic->setValue(String(battery_trailer).c_str());
        pBatteryTrailerCharacteristic->notify();
        last_battery_trailer = battery_trailer;
    }
}