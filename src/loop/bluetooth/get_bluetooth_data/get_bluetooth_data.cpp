#include "get_bluetooth_data.h"

void EcoPwmCharacteristicCallbacks::onWrite(BLECharacteristic* pEcoPwmCharacteristic) {
    Preferences preferences;
    std::string value = pEcoPwmCharacteristic->getValue();
    if (value.length() > 0) {
        pEcoPwmCharacteristic->setValue(String(static_cast<int>(value[0])).c_str());
        eco_max_pwm = map(static_cast<int>(value[0]), 0, 100, 0, 255);
        debug_print("New data entering for economic max pwm : " + eco_max_pwm);
        preferences.begin("preferences", false);
        preferences.putInt("eco_max_pwm", eco_max_pwm);
        preferences.end();
    }
};

void EcoDelayCharacteristicCallbacks::onWrite(BLECharacteristic* pEcoDelayCharacteristic) {
    Preferences preferences;
    std::string value = pEcoDelayCharacteristic->getValue();
    if (value.length() > 0) {
        uint8_t byte1 = static_cast<uint8_t>(value[0]);
        uint8_t byte2 = static_cast<uint8_t>(value[1]);
        eco_radio_delay = (byte2 << 8) | byte1;
        debug_print("New data entering for economic radio delay : " + eco_radio_delay);
        preferences.begin("preferences", false);
        preferences.putInt("eco_radio_delay", eco_radio_delay);
        preferences.end();
        pEcoDelayCharacteristic->setValue(String(eco_radio_delay).c_str());
    }
};

void SettingsEcoModeCharacteristicCallbacks::onWrite(BLECharacteristic* pSettingsEcoModeCharacteristic) {
    Preferences preferences;
    std::string value = pSettingsEcoModeCharacteristic->getValue();
    if (value.length() > 0) {
        eco_batterie = static_cast<bool>(value[0]);
        debug_print("New data entering for eco battery : " + String(eco_batterie));
        preferences.begin("preferences", false);
        preferences.putBool("eco_batterie", eco_batterie);
        preferences.end();
    }
};

void SettingsRegulatorModeCharacteristicCallbacks::onWrite(BLECharacteristic* pSettingsRegulatorModeCharacteristic) {
    Preferences preferences;
    std::string value = pSettingsRegulatorModeCharacteristic->getValue();
    if (value.length() > 0) {
        enable_speed_regulator = static_cast<bool>(value[0]);
        debug_print("New data entering for enable speed regulator : %d" + String(enable_speed_regulator));
        preferences.begin("preferences", false);
        preferences.putInt("enable_regulator", enable_speed_regulator);
        preferences.end();
    }
};

void SettingsLimiterModeCharacteristicCallbacks::onWrite(BLECharacteristic* pSettingsLimiterModeCharacteristic) {
    Preferences preferences;
    std::string value = pSettingsLimiterModeCharacteristic->getValue();
    if (value.length() > 0) {
        enable_speed_limiter = static_cast<bool>(value[0]);
        debug_print("New data entering for enable speed limite : " + String(enable_speed_limiter));
        preferences.begin("preferences", false);
        preferences.putInt("enable_limiter", enable_speed_limiter);
        preferences.end();
    }
};

void SettingsSpeedViewerCharacteristicCallbacks::onWrite(BLECharacteristic* pSettingsSpeedViewerCharacteristic) {
    Preferences preferences;
    std::string value = pSettingsSpeedViewerCharacteristic->getValue();
    if (value.length() > 0) {
        int _value = static_cast<int>(value[0]);
        if (_value == 1){
            speed_viewer_type = "PERCENTAGE";
        }else{
            speed_viewer_type = "SPEED";
        }
        debug_print("New data entering for speed viewer type : " + speed_viewer_type);
        preferences.begin("preferences", false);
        preferences.putString("viewer_type", speed_viewer_type);
        preferences.end();
    }
};

void SecuritySenderCharacteristicCallbacks::onWrite(BLECharacteristic* pSecuritySenderCharacteristic) {
    Preferences preferences;
    std::string value = pSecuritySenderCharacteristic->getValue();
    if (value.length() > 0) {
        std::string _value = value.substr(0, 6);
        debug_print("New data entering for sender adress : " + String(_value.c_str()));
        preferences.begin("preferences", false);
        preferences.putString("sender_adress", String(_value.c_str()));
        preferences.end();
    }
}

void SecurityReceiverCharacteristicCallbacks::onWrite(BLECharacteristic* pSecurityReceiverCharacteristic) {
    Preferences preferences;
    std::string value = pSecurityReceiverCharacteristic->getValue();
    if (value.length() > 0) {
        std::string _value = value.substr(0, 6);
        debug_print("New data entering for receiver adress : " + String(_value.c_str()));
        preferences.begin("preferences", false);
        preferences.putString("receiver_adress", String(_value.c_str()));
        preferences.end();
        // ESP.restart();
    }
};
