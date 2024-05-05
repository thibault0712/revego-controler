#include "setup.h"

void serialMonitor(){
    Serial.begin(115200);
    Serial.println("Startup");
}

void preferencesInitialisation(){
    Serial.println("Load : preferences");
    Preferences preferences;

    preferences.begin("preferences", false); //false -> Read
    eco_batterie = preferences.getBool("eco_batterie", 0);
    bluetooth = preferences.getBool("bluetooth", 0);
    enable_speed_limiter = preferences.getBool("enable_limiter", 0);
    enable_speed_regulator = preferences.getBool("enable_regulat", 0);
    speed_viewer_type = preferences.getString("viewer_type", "SPEED");
    eco_max_pwm = preferences.getInt("eco_max_pwm", 172);
    eco_radio_delay = preferences.getInt("eco_radio_delay", 0);
    not_converted_sender_adress = preferences.getString("sender_adress", "PIPE1");
    not_converted_receiver_adress = preferences.getString("receiver_adress", "PIPE2");
    preferences.end();
    Serial.println("Loaded : preferences");
}

void bluetoothInitialisation(){
    if(bluetooth){
        Serial.println("Load : bluetooth");
        BLEDevice::init("Revego");
        pServer = BLEDevice::createServer();
        pServer->setCallbacks(new MyServerCallbacks()); //class call in loop/bluetooth/resetBluetoothConnection (I don't know where I had to place it)
        BLEService *pService = pServer->createService(SERVICE_UUID);
        pDebugCharacteristic = pService->createCharacteristic(
                                            DEBUG_CHARACTERISTIC_UUID,
                                            BLECharacteristic::PROPERTY_READ |
                                            BLECharacteristic::PROPERTY_NOTIFY |
                                            BLECharacteristic::PROPERTY_INDICATE
                                            );
        pBatteryTrailerCharacteristic = pService->createCharacteristic(
                                            BATTERY_TRAILER_CHARACTERISTIC_UUID,
                                            BLECharacteristic::PROPERTY_READ |
                                            BLECharacteristic::PROPERTY_NOTIFY |
                                            BLECharacteristic::PROPERTY_INDICATE
                                            );
        pBatteryRemoteCharacteristic = pService->createCharacteristic(
                                            BATTERY_REMOTE_CHARACTERISTIC_UUID,
                                            BLECharacteristic::PROPERTY_READ |
                                            BLECharacteristic::PROPERTY_NOTIFY |
                                            BLECharacteristic::PROPERTY_INDICATE
                                            );
        pEcoDelayCharacteristic = pService->createCharacteristic(
                                            ECO_DELAY_CHARACTERISTIC_UUID,
                                            BLECharacteristic::PROPERTY_READ |
                                            BLECharacteristic::PROPERTY_WRITE |
                                            BLECharacteristic::PROPERTY_NOTIFY |
                                            BLECharacteristic::PROPERTY_INDICATE
                                            );
        pEcoPwmCharacteristic = pService->createCharacteristic(
                                            ECO_PWM_CHARACTERISTIC_UUID,
                                            BLECharacteristic::PROPERTY_READ |
                                            BLECharacteristic::PROPERTY_WRITE |
                                            BLECharacteristic::PROPERTY_NOTIFY |
                                            BLECharacteristic::PROPERTY_INDICATE
                                            );
                                            
        pEcoDelayCharacteristic->setCallbacks(new EcoDelayCharacteristicCallbacks());
        pEcoPwmCharacteristic->setCallbacks(new EcoPwmCharacteristicCallbacks());

        pDebugCharacteristic->addDescriptor(new BLE2902());
        pBatteryTrailerCharacteristic->addDescriptor(new BLE2902());
        pEcoDelayCharacteristic->addDescriptor(new BLE2902());
        pBatteryRemoteCharacteristic->addDescriptor(new BLE2902());
        pEcoPwmCharacteristic->addDescriptor(new BLE2902());

        pDebugCharacteristic->setValue("Bluetooth is enabled");
        pBatteryTrailerCharacteristic->setValue("0");
        pBatteryRemoteCharacteristic->setValue("30"); //Battery captor is broken so we simulate the data
        pEcoDelayCharacteristic->setValue(String(eco_radio_delay).c_str()); //All data are set by preferences()
        pEcoPwmCharacteristic->setValue(String(map(eco_max_pwm, 0, 255, 0, 100)).c_str());
        pService->start();

        BLEService *pServiceSettings = pServer->createService(SETTINGS_SERVICE_UUID);
        pSettingsEcoModeCharacteristic = pServiceSettings->createCharacteristic(
                                    SETTINGS_ECO_MODE_CHARACTERISTIC_UUID,
                                    BLECharacteristic::PROPERTY_READ |
                                    BLECharacteristic::PROPERTY_WRITE |
                                    BLECharacteristic::PROPERTY_NOTIFY |
                                    BLECharacteristic::PROPERTY_INDICATE
                                    );
        pSettingsRegulatorModeCharacteristic = pServiceSettings->createCharacteristic(
                                    SETTINGS_REGULATOR_MODE_CHARACTERISTIC_UUID,
                                    BLECharacteristic::PROPERTY_READ |
                                    BLECharacteristic::PROPERTY_WRITE |
                                    BLECharacteristic::PROPERTY_NOTIFY |
                                    BLECharacteristic::PROPERTY_INDICATE
                                    );
        pSettingsLimiterModeCharacteristic = pServiceSettings->createCharacteristic(
                                    SETTINGS_LIMITER_MODE_CHARACTERISTIC_UUID,
                                    BLECharacteristic::PROPERTY_READ |
                                    BLECharacteristic::PROPERTY_WRITE |
                                    BLECharacteristic::PROPERTY_NOTIFY |
                                    BLECharacteristic::PROPERTY_INDICATE
                                    );
        pSettingsSpeedViewerCharacteristic = pServiceSettings->createCharacteristic(
                                    SETTINGS_SPEED_VIEWER_CHARACTERISTIC_UUID,
                                    BLECharacteristic::PROPERTY_READ |
                                    BLECharacteristic::PROPERTY_WRITE |
                                    BLECharacteristic::PROPERTY_NOTIFY |
                                    BLECharacteristic::PROPERTY_INDICATE
                                    );
        pSettingsEcoModeCharacteristic->setCallbacks(new SettingsEcoModeCharacteristicCallbacks());
        pSettingsRegulatorModeCharacteristic->setCallbacks(new SettingsRegulatorModeCharacteristicCallbacks());
        pSettingsLimiterModeCharacteristic->setCallbacks(new SettingsLimiterModeCharacteristicCallbacks());
        pSettingsSpeedViewerCharacteristic->setCallbacks(new SettingsSpeedViewerCharacteristicCallbacks());


        pSettingsEcoModeCharacteristic->addDescriptor(new BLE2902());
        pSettingsRegulatorModeCharacteristic->addDescriptor(new BLE2902());
        pSettingsLimiterModeCharacteristic->addDescriptor(new BLE2902());
        pSettingsSpeedViewerCharacteristic->addDescriptor(new BLE2902());

        pSettingsEcoModeCharacteristic->setValue(String(eco_batterie).c_str());
        pSettingsLimiterModeCharacteristic->setValue(String(enable_speed_limiter).c_str());
		pSettingsRegulatorModeCharacteristic->setValue(String(enable_speed_regulator).c_str());
        if (speed_viewer_type == "PERCENTAGE"){ //0->SPEED  1->PERCENTAGE
            pSettingsSpeedViewerCharacteristic->setValue("1"); //Same data if I send 1 in int I think (not tested). We send a number to optimize the data size
        }else{
            pSettingsSpeedViewerCharacteristic->setValue("0"); //Same
        }
        pServiceSettings->start();


        BLEService *pServiceSecurity = pServer->createService(SECURITY_SERVICE_UUID);
        pSecuritySenderCharacteristic = pServiceSecurity->createCharacteristic(
                                    SECURITY_RADIO_SENDER_CHARACTERISTIC_UUID,
                                    BLECharacteristic::PROPERTY_READ |
                                    BLECharacteristic::PROPERTY_WRITE |
                                    BLECharacteristic::PROPERTY_NOTIFY |
                                    BLECharacteristic::PROPERTY_INDICATE
                                    );
        pSecurityReceiverCharacteristic = pServiceSecurity->createCharacteristic(
                                    SECURITY_RADIO_RECEIVER_CHARACTERISTIC_UUID,
                                    BLECharacteristic::PROPERTY_READ |
                                    BLECharacteristic::PROPERTY_WRITE |
                                    BLECharacteristic::PROPERTY_NOTIFY |
                                    BLECharacteristic::PROPERTY_INDICATE
                                    );
        pSecuritySenderCharacteristic->setCallbacks(new SecuritySenderCharacteristicCallbacks());
        pSecurityReceiverCharacteristic->setCallbacks(new SecurityReceiverCharacteristicCallbacks());
        pSecuritySenderCharacteristic->addDescriptor(new BLE2902());
        pSecurityReceiverCharacteristic->addDescriptor(new BLE2902());
        pSecuritySenderCharacteristic->setValue(not_converted_sender_adress.c_str());
        pSecurityReceiverCharacteristic->setValue(not_converted_receiver_adress.c_str());
        pServiceSecurity->start();

        BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
        pAdvertising->addServiceUUID(SERVICE_UUID);
        pAdvertising->addServiceUUID(SETTINGS_SERVICE_UUID);
        pAdvertising->addServiceUUID(SECURITY_SERVICE_UUID);
        pAdvertising->setScanResponse(true);
        pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
        pAdvertising->setMinPreferred(0x12);
        BLEDevice::startAdvertising();
        Serial.println("Loaded : bluetooth");
    }else{
        BLEDevice::deinit();
    }
}

void screenInitialisation(){
    debug_print("Load : screen");
    u8g2.begin();
    u8g2.setFont(u8g2_font_freedoomr10_tu);
    u8g2.setColorIndex(1);
    debug_print("Loaded : screen");
}

void buttonsInitialisation(){
    debug_print("Load : buttons");
    pinMode(BUTTON_LEAVE_PIN, INPUT);
    pinMode(BUTTON_UP_PIN, INPUT);
    pinMode(BUTTON_OK_PIN, INPUT);
    pinMode(BUTTON_DOWN_PIN, INPUT);
    debug_print("Loaded : buttons");
}

void radioInitialisation(){
    debug_print("Load : radio");

    radio.begin();
    radio.setPALevel(RF24_PA_MIN);
    radio.setDataRate(RF24_1MBPS);
    not_converted_sender_adress.getBytes(sender_adress, 6);
    not_converted_receiver_adress.getBytes(receiver_adress, 6);

    radio.openWritingPipe(sender_adress);
    radio.openReadingPipe(1, receiver_adress);
    debug_print("Loaded : radio");
}

void setConfig(){
    debug_print("Load : config");
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_25, 0);
    isEnable = true;
    debug_print("Loaded : config");
}