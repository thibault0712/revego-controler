#include <Arduino.h>
#include <U8g2lib.h>
#include "../variables/globalVariables.h"

#ifndef SETUP_H
#define SETUP_H

void serialMonitor();
void screenInitialisation();
void buttonsInitialisation();
void setConfig();

#endif