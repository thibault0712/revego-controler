#include "screen_home.h"

void screen_home(){
	u8g2.drawBitmap(126, 0, 8/8, 63, epd_bitmap_scrollbar_background);
	u8g2.drawBitmap(1, 22, 120/8, 21, epd_bitmap_item_sel_background);
	u8g2.drawBitmap(4, 2, 16/8, 16, bitmap_icons[item_selected_previous]);
	u8g2.setFont(u8g2_font_7x14_tf);
	u8g2.drawStr(26, 15, menu_items[item_selected_previous]);
	u8g2.drawBitmap(4, 24, 16/8, 16, bitmap_icons[item_selected]);
	u8g2.setFont(u8g2_font_7x14B_tf);
	u8g2.drawStr(26, 37, menu_items[item_selected]);
	u8g2.drawBitmap(4, 46, 16/8, 16, bitmap_icons[item_selected_next]);
	u8g2.setFont(u8g2_font_7x14_tf);
	u8g2.drawStr(26, 59, menu_items[item_selected_next]);
}