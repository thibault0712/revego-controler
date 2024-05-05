#include "screen_battery.h"

void screen_battery(){
	u8g2.setFont(u8g2_font_6x12_te );
	u8g2.drawBitmap(0, 0, 128/8, 64, epd_bitmap_batterie);
	u8g2.drawStr((128 - u8g2.getUTF8Width(format_battery_remote()))/2, 26, format_battery_remote());
	u8g2.drawStr((128 - u8g2.getUTF8Width(format_trailer_remote()))/2, 56, format_trailer_remote());
}

char* format_battery_remote(){
	static char result[13];
	snprintf(result, sizeof(result), "30%% / 1h50");
	return result;
}

char* format_trailer_remote(){
	static char result[13];
	if (battery_trailer > 0){
		float time = (Q_trailer*0.75)/I_max_trailer * 10 * 0.01 + (Q_trailer*0.25)/I_min_trailer * battery_trailer * 0.01;
		if (eco_batterie){
			time = (Q_trailer*0.75)/(I_max_trailer * 0.75) * 10 * 0.01 + (Q_trailer*0.25)/I_min_trailer * battery_trailer * 0.01;
		}
		const int hours = floor(time);
		const int minutes = (time - hours) * 60;
		snprintf(result, sizeof(result), "%d%% / %dh%d", battery_trailer, hours, minutes);
	}else{
		snprintf(result, sizeof(result), "Indisponible");
	}
	return result;
}