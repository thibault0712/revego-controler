#include "screen_settings.h"

void screen_settings(){
    u8g2.setColorIndex(1); //Sinon bug de couleurs car non reset quand on est tout en bas
	u8g2.drawBitmap(126, 0, 8/8, 63, epd_bitmap_scrollbar_background);
	u8g2.drawRBox(0, setting_box_position * 16, 124, 16, 4);
	u8g2.setFont(u8g2_font_profont12_tf);
	u8g2.setColorIndex(settings_text_color(setting_box_position, 0));
	u8g2.drawStr(4, 12, settings_name[settings_first_item_to_show]);
	u8g2.setColorIndex(settings_text_color(setting_box_position, 1));
	u8g2.drawStr(4, 28, settings_name[settings_first_item_to_show + 1]);
	u8g2.setColorIndex(settings_text_color(setting_box_position, 2));
	u8g2.drawStr(4, 44, settings_name[settings_first_item_to_show + 2]);
	u8g2.setColorIndex(settings_text_color(setting_box_position, 3));
	u8g2.drawStr(4, 60, settings_name[settings_first_item_to_show + 3]);
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