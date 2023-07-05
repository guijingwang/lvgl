/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"


void setup_scr_blueCounter(lv_ui *ui){

	//Write codes blueCounter
	ui->blueCounter = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->blueCounter, LV_SCROLLBAR_MODE_OFF);

	//Set style for blueCounter. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->blueCounter, lv_color_make(0x2F, 0xCA, 0xDA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->blueCounter, lv_color_make(0x2F, 0xCA, 0xDA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->blueCounter, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blueCounter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blueCounter_cont_1
	ui->blueCounter_cont_1 = lv_obj_create(ui->blueCounter);
	lv_obj_set_pos(ui->blueCounter_cont_1, 93, 51);
	lv_obj_set_size(ui->blueCounter_cont_1, 294, 170);
	lv_obj_set_scrollbar_mode(ui->blueCounter_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for blueCounter_cont_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->blueCounter_cont_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->blueCounter_cont_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->blueCounter_cont_1, lv_color_make(0x4e, 0x95, 0xcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->blueCounter_cont_1, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blueCounter_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blueCounter_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->blueCounter_cont_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->blueCounter_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->blueCounter_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->blueCounter_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->blueCounter_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->blueCounter_cont_1, lv_color_make(0xac, 0xce, 0xea), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->blueCounter_cont_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->blueCounter_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blueCounter_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blueCounter_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blueCounter_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blueCounter_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blueCounter_plus
	ui->blueCounter_plus = lv_imgbtn_create(ui->blueCounter_cont_1);
	lv_obj_set_pos(ui->blueCounter_plus, 193, 13);
	lv_obj_set_size(ui->blueCounter_plus, 65, 65);
	lv_obj_set_scrollbar_mode(ui->blueCounter_plus, LV_SCROLLBAR_MODE_OFF);

	//Set style for blueCounter_plus. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->blueCounter_plus, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->blueCounter_plus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blueCounter_plus, lv_color_make(0x4d, 0x6e, 0x81), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blueCounter_plus, &lv_font_arial_34, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blueCounter_plus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->blueCounter_plus, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->blueCounter_plus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for blueCounter_plus. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->blueCounter_plus, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->blueCounter_plus, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->blueCounter_plus, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->blueCounter_plus, &lv_font_montserratMedium_34, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->blueCounter_plus, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->blueCounter_plus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->blueCounter_plus, 129, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_imgbtn_set_src(ui->blueCounter_plus, LV_IMGBTN_STATE_RELEASED, NULL, &_btn_alpha_65x65, NULL);
	lv_obj_add_flag(ui->blueCounter_plus, LV_OBJ_FLAG_CHECKABLE);
	ui->blueCounter_plus_label = lv_label_create(ui->blueCounter_plus);
	lv_label_set_text(ui->blueCounter_plus_label, "+");
	lv_obj_set_style_pad_all(ui->blueCounter_plus, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->blueCounter_plus_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes blueCounter_minus
	ui->blueCounter_minus = lv_imgbtn_create(ui->blueCounter_cont_1);
	lv_obj_set_pos(ui->blueCounter_minus, 193, 85);
	lv_obj_set_size(ui->blueCounter_minus, 65, 65);
	lv_obj_set_scrollbar_mode(ui->blueCounter_minus, LV_SCROLLBAR_MODE_OFF);

	//Set style for blueCounter_minus. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->blueCounter_minus, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->blueCounter_minus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blueCounter_minus, lv_color_make(0x4d, 0x6e, 0x81), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blueCounter_minus, &lv_font_arial_34, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blueCounter_minus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->blueCounter_minus, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->blueCounter_minus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for blueCounter_minus. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->blueCounter_minus, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->blueCounter_minus, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->blueCounter_minus, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->blueCounter_minus, &lv_font_montserratMedium_34, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->blueCounter_minus, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->blueCounter_minus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->blueCounter_minus, 129, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_imgbtn_set_src(ui->blueCounter_minus, LV_IMGBTN_STATE_RELEASED, NULL, &_btn_alpha_65x65, NULL);
	lv_obj_add_flag(ui->blueCounter_minus, LV_OBJ_FLAG_CHECKABLE);
	ui->blueCounter_minus_label = lv_label_create(ui->blueCounter_minus);
	lv_label_set_text(ui->blueCounter_minus_label, "-");
	lv_obj_set_style_pad_all(ui->blueCounter_minus, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->blueCounter_minus_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes blueCounter_counter
	ui->blueCounter_counter = lv_label_create(ui->blueCounter_cont_1);
	lv_obj_set_pos(ui->blueCounter_counter, 58, 63);
	lv_obj_set_size(ui->blueCounter_counter, 114, 43);
	lv_obj_set_scrollbar_mode(ui->blueCounter_counter, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->blueCounter_counter, "0");
	lv_label_set_long_mode(ui->blueCounter_counter, LV_LABEL_LONG_WRAP);

	//Set style for blueCounter_counter. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->blueCounter_counter, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->blueCounter_counter, lv_color_make(0x4d, 0x2c, 0x2c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->blueCounter_counter, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->blueCounter_counter, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->blueCounter_counter, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->blueCounter_counter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blueCounter_counter, lv_color_make(0x02, 0x4f, 0x5a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blueCounter_counter, &lv_font_arial_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blueCounter_counter, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blueCounter_counter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blueCounter_counter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blueCounter_logo
	ui->blueCounter_logo = lv_img_create(ui->blueCounter_cont_1);
	lv_obj_set_pos(ui->blueCounter_logo, 24, 13);
	lv_obj_set_size(ui->blueCounter_logo, 37, 13);
	lv_obj_set_scrollbar_mode(ui->blueCounter_logo, LV_SCROLLBAR_MODE_OFF);

	//Set style for blueCounter_logo. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->blueCounter_logo, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->blueCounter_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->blueCounter_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->blueCounter_logo, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->blueCounter_logo,&_logo_alpha_37x13);
	lv_img_set_pivot(ui->blueCounter_logo, 50,50);
	lv_img_set_angle(ui->blueCounter_logo, 0);

	//Init events for screen
	events_init_blueCounter(ui);
}
