#include <U8g2lib.h>
#include <Arduino.h>
#include "../../../variables/globalVariables.h"
#include "../../../variables/images/globalImagesVariables.h"

#ifndef SCREEN_SETTINGS_H
#define SCREEN_SETTINGS_H

int settings_text_color(int _setting_box_position, int _text_position);
void screen_settings();

#endif