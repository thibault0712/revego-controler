#include "screen_manager.h"

void screen_manager(){
    u8g2.firstPage();
    do {
        switch(current_screen){
            case 0: //home screen
                screen_home();
                break;
            case 1: //speed screen
                screen_speed();
                break;
            case 2:
                screen_battery();
                break;
            case 3:
                screen_bluetooth();
                break;
            case 4: //settings screen
                screen_settings();
                break; 
        }
    } while (u8g2.nextPage());
}