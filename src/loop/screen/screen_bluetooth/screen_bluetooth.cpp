#include "screen_bluetooth.h"

void screen_bluetooth(){
    if (bluetooth){
       	u8g2.drawBitmap(0, 0, 128/8, 64, epd_bitmap_Bluetooth); 
    }else{
        u8g2.setDrawColor(1);
        u8g2.drawBitmap(0, 0, 128/8, 64, epd_bitmap_popup); 
        u8g2.setFont(u8g2_font_5x7_tf);
        int16_t x = (128 - u8g2.getStrWidth("Vous devez activer")) / 2;
        u8g2.drawStr(x, 25, "Vous devez activer");

        x = (128 - u8g2.getStrWidth("le bluetooth")) / 2;
        u8g2.drawStr(x, 35, "le bluetooth");

        u8g2.setDrawColor(1);
        x = (128 - u8g2.getStrWidth("Retour")) / 2;
        u8g2.drawBox(x-1, 39, u8g2.getStrWidth("Retour") + 2, 8); // Rectangle blanc pour l'arrière-plan
        u8g2.setFont(u8g2_font_5x7_tf);
        u8g2.setDrawColor(0);
        u8g2.drawStr(x, 46, "Retour");
    }
}