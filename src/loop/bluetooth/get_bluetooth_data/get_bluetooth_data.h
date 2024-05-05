#include "../../../variables/globalVariables.h"
#include "../../functionality/functionality_manager.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Preferences.h>

#ifndef GET_BLUETOOTH_DATA_H
#define GET_BLUETOOTH_DATA_H

class EcoPwmCharacteristicCallbacks : public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pEcoPwmCharacteristic);
};

class EcoDelayCharacteristicCallbacks : public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pEcoDelayCharacteristic);
};

class SettingsEcoModeCharacteristicCallbacks : public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pSettingsEcoModeCharacteristic);
};

class SettingsRegulatorModeCharacteristicCallbacks : public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pSettingsRegulatorModeCharacteristic);
};

class SettingsLimiterModeCharacteristicCallbacks : public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pSettingsLimiterModeCharacteristic);
};

class SettingsSpeedViewerCharacteristicCallbacks : public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pSettingsSpeedViewerCharacteristic);
};

class SecuritySenderCharacteristicCallbacks : public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pSecuritySenderCharacteristic);
};

class SecurityReceiverCharacteristicCallbacks : public BLECharacteristicCallbacks {
    public:
        void onWrite(BLECharacteristic* pSecurityReceiverCharacteristic);
};
#endif