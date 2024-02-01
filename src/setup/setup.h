#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <RF24.h>
#include "../variables/globalVariables.h"

#ifndef SETUP_H
#define SETUP_H

void serialMonitor();
void screenInitialisation();
void buttonsInitialisation();
void radioInitialisation();
void setConfig();

#endif