#include "resetBluetoothConnection.h"

void MyServerCallbacks::onDisconnect(BLEServer* pServer) {
    //When bluetooth connection is loose we restart the advertising
    pServer->startAdvertising();
}