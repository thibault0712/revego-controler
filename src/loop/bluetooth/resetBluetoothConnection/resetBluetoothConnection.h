#include "../../../variables/globalVariables.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#ifndef RESET_BLUETOOTH_CONNECTION_H
#define RESET_BLUETOOTH_CONNECTION_H

class MyServerCallbacks : public BLEServerCallbacks {
public:
    void onDisconnect(BLEServer* pServer);
};
#endif