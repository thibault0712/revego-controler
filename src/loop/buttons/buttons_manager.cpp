#include "buttons_manager.h"

void buttons_manager(){
    button_leave_manager();
    do {
        switch(current_screen){
            case 0: //home screen
                buttons_manager_home();
                break;
            case 1: //speed screen
                buttons_manager_speed();
                break;
            case 4: //settings screen
                buttons_manager_settings();
                break; 
        }
    } while (u8g2.nextPage());
}