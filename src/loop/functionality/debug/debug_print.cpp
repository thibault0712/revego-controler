#include "debug_print.h"

void debug_print(String args){
    Serial.println(args);
    if (bluetooth){
        pDebugCharacteristic->setValue(args.c_str());
        pDebugCharacteristic->notify();
    }
}