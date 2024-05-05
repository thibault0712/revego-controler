#include <U8g2lib.h>
#include "../../../variables/globalVariables.h"
#include "../../../variables/images/speedImagesVariables.h"
#include "../../get_data/get_data.h"

#ifndef SCREEN_SPEED_H
#define SCREEN_SPEED_H

char* percentage_convertissor_for_screen();
char* speed_convertissor_for_screen();
char* battery_controler_convertissor_for_screen();
char* battery_trailer_convertissor_for_screen();
void screen_speed();

#endif