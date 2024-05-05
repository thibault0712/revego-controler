#include <U8g2lib.h>
#include "../../../variables/globalVariables.h"
#include "../../../variables/images/batteryImagesVariables.h"

#ifndef SCREEN_BATTERY_H
#define SCREEN_BATTERY_H

void screen_battery();
char* format_battery_remote();
char* format_trailer_remote();

#endif