#include <Arduino.h>
#include <U8g2lib.h>
#include <Preferences.h>
#include <SPI.h>
#include <RF24.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include "../loop/bluetooth/bluetooth.h"
#include "../variables/globalVariables.h"
#include "../loop/functionality/debug/debug_print.h"

#ifndef SETUP_H
#define SETUP_H

void serialMonitor();
void bluetoothInitialisation();
void preferencesInitialisation();
void screenInitialisation();
void buttonsInitialisation();
void radioInitialisation();
void setConfig();

#endif