#include "buttons_manager.h"

void buttons_manager(){
    button_leave_manager();
    if (currentTime >= lastButtonClickTime + 150){
        do {
            switch(current_screen){
                case 0: //home screen
                    buttons_manager_home();
                    lastButtonClickTime = currentTime;
                    break;
                case 1: //speed screen
                    buttons_manager_speed();
                    lastButtonClickTime = currentTime;
                    break;
                case 3: //bluetooth screen
                    buttons_manager_bluetooth();
                    lastButtonClickTime = currentTime;
                    break;
                case 4: //settings screen
                    buttons_manager_settings();
                    lastButtonClickTime = currentTime;
                    break; 
            }
        } while (u8g2.nextPage());
    }
}