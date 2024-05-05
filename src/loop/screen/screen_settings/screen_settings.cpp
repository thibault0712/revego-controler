#include "screen_settings.h"

//Affichage des valeurs pour les paramètres un peu sale

void screen_settings(){
    u8g2.setColorIndex(1); //Sinon bug de couleurs car non reset quand on est tout en bas
	u8g2.drawBitmap(126, 0, 8/8, 63, epd_bitmap_scrollbar_background);
	u8g2.drawRBox(0, setting_box_position * 16, 124, 16, 4);
	u8g2.setFont(u8g2_font_6x12_te );

	u8g2.setColorIndex(settings_text_color(setting_box_position, 0));
	u8g2.drawStr(4, 12, settings_name[settings_first_item_to_show]);
	u8g2.drawStr(u8g2.getDisplayWidth() - 7 - u8g2.getUTF8Width(get_setting_value(settings_first_item_to_show)), 12, get_setting_value(settings_first_item_to_show));

	u8g2.setColorIndex(settings_text_color(setting_box_position, 1));
	u8g2.drawStr(4, 28, settings_name[settings_first_item_to_show + 1]);
	u8g2.drawStr(u8g2.getDisplayWidth() - 7 - u8g2.getUTF8Width(get_setting_value(settings_first_item_to_show + 1)), 28, get_setting_value(settings_first_item_to_show + 1));

	u8g2.setColorIndex(settings_text_color(setting_box_position, 2));
	u8g2.drawStr(4, 44, settings_name[settings_first_item_to_show + 2]);
	u8g2.drawStr(u8g2.getDisplayWidth() - 7 - u8g2.getUTF8Width(get_setting_value(settings_first_item_to_show + 2)), 44, get_setting_value(settings_first_item_to_show + 2));

	u8g2.setColorIndex(settings_text_color(setting_box_position, 3));
	u8g2.drawStr(4, 60, settings_name[settings_first_item_to_show + 3]);
	u8g2.drawStr(u8g2.getDisplayWidth() - 7 - u8g2.getUTF8Width(get_setting_value(settings_first_item_to_show + 3)), 60, get_setting_value(settings_first_item_to_show + 3));

}

char* get_setting_value(int setting){
	//Sizeof bug sur le km/h et % car il garde en mémoire "3" au lieu de "4"
	static char result[5];
	switch (setting){
	case 0: //Eco Batterie
        snprintf(result, sizeof(result), eco_batterie ? "oui" : "non");
		break;
	case 1: //Limiteur
		snprintf(result, sizeof(result), enable_speed_limiter ? "oui" : "non");
		break;
	case 2: //Regulateur
		snprintf(result, sizeof(result), enable_speed_regulator ? "oui" : "non");
		break;
	case 3: //Speed
		if (speed_viewer_type == "PERCENTAGE")
			snprintf(result, sizeof(result), "%%");
		else
			snprintf(result, sizeof(result), "km/h");
		break;
	case 4: //Bluetooth
		snprintf(result, sizeof(result), bluetooth ? "oui" : "non");
		break;
	}
	return result;
}

int settings_text_color(int _setting_box_position, int _text_position){
	//0 -> Black color
	//1 -> White Color
	if (_text_position == _setting_box_position){
		return 0;
	}else{
		return 1;
	}
}