#include "../../../variables/globalVariables.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#ifndef SEND_BLUETOOTH_BATTERY_H
#define SEND_BLUETOOTH_BATTERY_H

void send_bluetooth_battery_trailer();
void send_bluetooth_battery_remote();

#endif