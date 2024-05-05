#include "screen_speed.h"

void screen_speed(){
    u8g2.drawBitmap(0, 0, 128/8, 64, epd_bitmap_speed_background);
	if (speed_regulator){ u8g2.drawBitmap(52, 2, 16/8, 9, epd_bitmap_icon_speed_limit); }
	if (speed_limiter){ u8g2.drawBitmap(52, 2, 16/8, 9, epd_bitmap_icon_speed_limit); }
	if (eco_batterie){ u8g2.drawBitmap(67, 2, 9/8, 9, epd_bitmap_icon_eco_batterie); }
	u8g2.setFont(u8g2_font_logisoso22_tf);
	
	const char* value = nullptr;
	if (speed_viewer_type == "PERCENTAGE"){
		value = percentage_convertissor_for_screen();
	}else if (speed_viewer_type == "SPEED"){
		value = speed_convertissor_for_screen();
	}
	
	const int xPosition_Speed = (u8g2.getDisplayWidth() - u8g2.getStrWidth(value)) / 2;
	u8g2.drawStr(xPosition_Speed, 45, value);

	u8g2.setFont(u8g2_font_6x13_tf);
	const int xPosition_Battery_Controler = (31 - u8g2.getStrWidth(battery_controler_convertissor_for_screen())) / 2 + 13;
	u8g2.drawStr(xPosition_Battery_Controler, 11, battery_controler_convertissor_for_screen());

	u8g2.setFont(u8g2_font_6x13_tf);
	const int xPosition_Battery_Trailer = (31 - u8g2.getStrWidth(battery_trailer_convertissor_for_screen())) / 2 + 85;
	u8g2.drawStr(xPosition_Battery_Trailer, 11, battery_trailer_convertissor_for_screen());
}

//Comme on renvoie un pointeur, static est important car il permet de ne pas supprimer la zone en mémoire du résultat
char* percentage_convertissor_for_screen(){
	int percentage_value = map(data_to_send, 0, 255, 0, 100);
	static char result[8];
	sprintf(result, "%d%%", percentage_value);
	return result;
}

//Comme on renvoie un pointeur, static est important car il permet de ne pas supprimer la zone en mémoire du résultat
char* speed_convertissor_for_screen(){
	static char result[8];
	sprintf(result, "%dkm/h", current_speed);
	return result;
}

//Comme on renvoie un pointeur, static est important car il permet de ne pas supprimer la zone en mémoire du résultat
char* battery_controler_convertissor_for_screen(){
	static char result[4];
	// sprintf(result, "%d%%", get_battery_controler());
	sprintf(result, "%d%%", 30);
	return result;
}

//Comme on renvoie un pointeur, static est important car il permet de ne pas supprimer la zone en mémoire du résultat
char* battery_trailer_convertissor_for_screen(){
	static char result[4];
	sprintf(result, "%d%%", 20);
    sprintf(result, "%d%%", battery_trailer);
	return result;
}