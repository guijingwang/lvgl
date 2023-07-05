/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "coffee_gui_guider.h"
#include "coffee_events_init.h"

const lv_img_dsc_t* coffeePour_animimg_coffee_imgs[31] = {
	&coffeePour_animimg_coffeef01,
	&coffeePour_animimg_coffeef02,
	&coffeePour_animimg_coffeef03,
	&coffeePour_animimg_coffeef04,
	&coffeePour_animimg_coffeef05,
	&coffeePour_animimg_coffeef06,
	&coffeePour_animimg_coffeef07,
	&coffeePour_animimg_coffeef08,
	&coffeePour_animimg_coffeef09,
	&coffeePour_animimg_coffeef10,
	&coffeePour_animimg_coffeef11,
	&coffeePour_animimg_coffeef12,
	&coffeePour_animimg_coffeef13,
	&coffeePour_animimg_coffeef14,
	&coffeePour_animimg_coffeef15,
	&coffeePour_animimg_coffeef16,
	&coffeePour_animimg_coffeef17,
	&coffeePour_animimg_coffeef18,
	&coffeePour_animimg_coffeef19,
	&coffeePour_animimg_coffeef20,
	&coffeePour_animimg_coffeef21,
	&coffeePour_animimg_coffeef22,
	&coffeePour_animimg_coffeef23,
	&coffeePour_animimg_coffeef24,
	&coffeePour_animimg_coffeef25,
	&coffeePour_animimg_coffeef26,
	&coffeePour_animimg_coffeef27,
	&coffeePour_animimg_coffeef28,
	&coffeePour_animimg_coffeef29,
	&coffeePour_animimg_coffeef30,
	&coffeePour_animimg_coffeef31
};

void setup_scr_coffeePour(coffee_lv_ui*ui){

	//Write codes coffeePour
	ui->coffeePour = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->coffeePour, LV_SCROLLBAR_MODE_OFF);

	//Set style for coffeePour. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->coffeePour, lv_color_make(0x2a, 0x26, 0x31), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->coffeePour, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->coffeePour, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->coffeePour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes coffeePour_animimg_coffee
	ui->coffeePour_animimg_coffee = lv_animimg_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_animimg_coffee, 192, 107);
	lv_obj_set_size(ui->coffeePour_animimg_coffee, 96, 85);
	lv_obj_set_scrollbar_mode(ui->coffeePour_animimg_coffee, LV_SCROLLBAR_MODE_OFF);
	lv_animimg_set_src(ui->coffeePour_animimg_coffee, (const void **) coffeePour_animimg_coffee_imgs, 31);
	lv_animimg_set_duration(ui->coffeePour_animimg_coffee, 930);
	lv_animimg_set_repeat_count(ui->coffeePour_animimg_coffee, 0);
	lv_animimg_start(ui->coffeePour_animimg_coffee);

	//Write codes coffeePour_line_right
	ui->coffeePour_line_right = lv_line_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_line_right, 330, 58);
	lv_obj_set_size(ui->coffeePour_line_right, 122, 182);
	lv_obj_set_scrollbar_mode(ui->coffeePour_line_right, LV_SCROLLBAR_MODE_OFF);

	//Set style for coffeePour_line_right. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_line_color(ui->coffeePour_line_right, lv_color_make(0x60, 0x60, 0x60), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->coffeePour_line_right, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->coffeePour_line_right, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t coffeePour_line_right[] ={{0, 0},{0, 180},{0, 90},{120, 90},};
	lv_line_set_points(ui->coffeePour_line_right,coffeePour_line_right,4);

	//Write codes coffeePour_btn_reset
	ui->coffeePour_btn_reset = lv_btn_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_btn_reset, 368, 164);
	lv_obj_set_size(ui->coffeePour_btn_reset, 73, 50);
	lv_obj_set_scrollbar_mode(ui->coffeePour_btn_reset, LV_SCROLLBAR_MODE_OFF);

	//Set style for coffeePour_btn_reset. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->coffeePour_btn_reset, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->coffeePour_btn_reset, lv_color_make(0xf2, 0x65, 0x65), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->coffeePour_btn_reset, lv_color_make(0x15, 0x15, 0x15), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->coffeePour_btn_reset, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->coffeePour_btn_reset, 99, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->coffeePour_btn_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->coffeePour_btn_reset, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->coffeePour_btn_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->coffeePour_btn_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->coffeePour_btn_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->coffeePour_btn_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->coffeePour_btn_reset, lv_color_make(0xB7, 0x87, 0x58), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->coffeePour_btn_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->coffeePour_btn_reset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->coffeePour_btn_reset, lv_color_make(0xd1, 0xc1, 0xb2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->coffeePour_btn_reset, &lv_font_arial_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->coffeePour_btn_reset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->coffeePour_btn_reset_label = lv_label_create(ui->coffeePour_btn_reset);
	lv_label_set_text(ui->coffeePour_btn_reset_label, "RESET");
	lv_obj_set_style_pad_all(ui->coffeePour_btn_reset, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->coffeePour_btn_reset_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes coffeePour_btn_continue
	ui->coffeePour_btn_continue = lv_btn_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_btn_continue, 358, 82);
	lv_obj_set_size(ui->coffeePour_btn_continue, 100, 50);
	lv_obj_set_scrollbar_mode(ui->coffeePour_btn_continue, LV_SCROLLBAR_MODE_OFF);

	//Set style for coffeePour_btn_continue. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->coffeePour_btn_continue, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->coffeePour_btn_continue, lv_color_make(0xf2, 0x65, 0x65), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->coffeePour_btn_continue, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->coffeePour_btn_continue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->coffeePour_btn_continue, 97, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->coffeePour_btn_continue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->coffeePour_btn_continue, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->coffeePour_btn_continue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->coffeePour_btn_continue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->coffeePour_btn_continue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->coffeePour_btn_continue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->coffeePour_btn_continue, lv_color_make(0xd1, 0xc1, 0xb2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->coffeePour_btn_continue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->coffeePour_btn_continue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->coffeePour_btn_continue, lv_color_make(0xd1, 0xc1, 0xb2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->coffeePour_btn_continue, &lv_font_arial_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->coffeePour_btn_continue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->coffeePour_btn_continue_label = lv_label_create(ui->coffeePour_btn_continue);
	lv_label_set_text(ui->coffeePour_btn_continue_label, "CONTINUE");
	lv_obj_set_style_pad_all(ui->coffeePour_btn_continue, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->coffeePour_btn_continue_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes coffeePour_img_logo
	ui->coffeePour_img_logo = lv_img_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_img_logo, 19, 12);
	lv_obj_set_size(ui->coffeePour_img_logo, 60, 20);
	lv_obj_set_scrollbar_mode(ui->coffeePour_img_logo, LV_SCROLLBAR_MODE_OFF);

	//Set style for coffeePour_img_logo. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->coffeePour_img_logo, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->coffeePour_img_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->coffeePour_img_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->coffeePour_img_logo, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_update_layout(ui->coffeePour_img_logo);

    //Write animation: coffeePour_img_logomove in x direction
    lv_anim_t coffeePour_img_logo_x;
    lv_anim_init(&coffeePour_img_logo_x);
    lv_anim_set_var(&coffeePour_img_logo_x, ui->coffeePour_img_logo);
    lv_anim_set_time(&coffeePour_img_logo_x, 1000);
    lv_anim_set_exec_cb(&coffeePour_img_logo_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
    lv_anim_set_values(&coffeePour_img_logo_x, lv_obj_get_x(ui->coffeePour_img_logo), 200);
    lv_anim_set_path_cb(&coffeePour_img_logo_x, lv_anim_path_linear);
    lv_anim_start(&coffeePour_img_logo_x);

    //Write animation: coffeePour_img_logomove in y direction
    lv_anim_t coffeePour_img_logo_y;
    lv_anim_init(&coffeePour_img_logo_y);
    lv_anim_set_var(&coffeePour_img_logo_y, ui->coffeePour_img_logo);
    lv_anim_set_time(&coffeePour_img_logo_y, 1000);
    lv_anim_set_exec_cb(&coffeePour_img_logo_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_values(&coffeePour_img_logo_y, lv_obj_get_y(ui->coffeePour_img_logo), 10);
    lv_anim_set_path_cb(&coffeePour_img_logo_y, lv_anim_path_linear);
    lv_anim_start(&coffeePour_img_logo_y);

    lv_img_set_src(ui->coffeePour_img_logo, &_logo_alpha_60x20);
    lv_img_set_pivot(ui->coffeePour_img_logo, 50, 50);
    lv_img_set_angle(ui->coffeePour_img_logo, 0);

	//Write codes coffeePour_line_left
	ui->coffeePour_line_left = lv_line_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_line_left, 19, 58);
	lv_obj_set_size(ui->coffeePour_line_left, 122, 182);
	lv_obj_set_scrollbar_mode(ui->coffeePour_line_left, LV_SCROLLBAR_MODE_OFF);

	//Set style for coffeePour_line_left. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_line_color(ui->coffeePour_line_left, lv_color_make(0x60, 0x60, 0x60), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->coffeePour_line_left, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->coffeePour_line_left, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t coffeePour_line_left[] ={{120, 0},{120, 180},{120, 90},{0, 90},};
	lv_line_set_points(ui->coffeePour_line_left,coffeePour_line_left,4);

	//Write codes coffeePour_btn_stop
	ui->coffeePour_btn_stop = lv_btn_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_btn_stop, 40, 82);
	lv_obj_set_size(ui->coffeePour_btn_stop, 80, 50);
	lv_obj_set_scrollbar_mode(ui->coffeePour_btn_stop, LV_SCROLLBAR_MODE_OFF);

	//Set style for coffeePour_btn_stop. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->coffeePour_btn_stop, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->coffeePour_btn_stop, lv_color_make(0xf2, 0x65, 0x65), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->coffeePour_btn_stop, lv_color_make(0x15, 0x15, 0x15), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->coffeePour_btn_stop, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->coffeePour_btn_stop, 99, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->coffeePour_btn_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->coffeePour_btn_stop, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->coffeePour_btn_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->coffeePour_btn_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->coffeePour_btn_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->coffeePour_btn_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->coffeePour_btn_stop, lv_color_make(0xB7, 0x87, 0x58), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->coffeePour_btn_stop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->coffeePour_btn_stop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->coffeePour_btn_stop, lv_color_make(0xd1, 0xc1, 0xb2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->coffeePour_btn_stop, &lv_font_arial_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->coffeePour_btn_stop, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->coffeePour_btn_stop_label = lv_label_create(ui->coffeePour_btn_stop);
	lv_label_set_text(ui->coffeePour_btn_stop_label, "STOP");
	lv_obj_set_style_pad_all(ui->coffeePour_btn_stop, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->coffeePour_btn_stop_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes coffeePour_btn_full
	ui->coffeePour_btn_full = lv_btn_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_btn_full, 40, 168);
	lv_obj_set_size(ui->coffeePour_btn_full, 80, 50);
	lv_obj_set_scrollbar_mode(ui->coffeePour_btn_full, LV_SCROLLBAR_MODE_OFF);

	//Set style for coffeePour_btn_full. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->coffeePour_btn_full, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->coffeePour_btn_full, lv_color_make(0xf2, 0x65, 0x65), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->coffeePour_btn_full, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->coffeePour_btn_full, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->coffeePour_btn_full, 99, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->coffeePour_btn_full, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->coffeePour_btn_full, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->coffeePour_btn_full, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->coffeePour_btn_full, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->coffeePour_btn_full, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->coffeePour_btn_full, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->coffeePour_btn_full, lv_color_make(0xd1, 0xc1, 0xb2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->coffeePour_btn_full, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->coffeePour_btn_full, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->coffeePour_btn_full, lv_color_make(0xd1, 0xc1, 0xb2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->coffeePour_btn_full, &lv_font_arial_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->coffeePour_btn_full, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->coffeePour_btn_full_label = lv_label_create(ui->coffeePour_btn_full);
	lv_label_set_text(ui->coffeePour_btn_full_label, "FULL");
	lv_obj_set_style_pad_all(ui->coffeePour_btn_full, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->coffeePour_btn_full_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes coffeePour_label_1
	ui->coffeePour_label_1 = lv_label_create(ui->coffeePour);
	lv_obj_set_pos(ui->coffeePour_label_1, 132, 39);
	lv_obj_set_size(ui->coffeePour_label_1, 217, 29);
	lv_obj_set_scrollbar_mode(ui->coffeePour_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->coffeePour_label_1, "Coffee Latte");
	lv_label_set_long_mode(ui->coffeePour_label_1, LV_LABEL_LONG_WRAP);

	//Set style for coffeePour_label_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->coffeePour_label_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->coffeePour_label_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->coffeePour_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->coffeePour_label_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->coffeePour_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->coffeePour_label_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->coffeePour_label_1, &lv_font_arial_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->coffeePour_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->coffeePour_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->coffeePour_label_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->coffeePour_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //write code coffeepour_animing_coffeef31
    ui->coffeepour_animing_coffeef31 = lv_img_create(ui->coffeePour);
    lv_obj_set_pos(ui->coffeepour_animing_coffeef31, 202, 1);
    lv_obj_set_size(ui->coffeepour_animing_coffeef31, 96, 85);
    lv_obj_set_scrollbar_mode(ui->coffeepour_animing_coffeef31, LV_SCROLLBAR_MODE_OFF);

    //set style for coffeeppour_animing_coffeef31. part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->coffeepour_animing_coffeef31, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->coffeepour_animing_coffeef31, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui->coffeepour_animing_coffeef31, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->coffeepour_animing_coffeef31, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->coffeepour_animing_coffeef31, &coffeePour_animimg_coffeef31);
    lv_img_set_pivot(ui->coffeepour_animing_coffeef31, 50, 50);
    lv_img_set_angle(ui->coffeepour_animing_coffeef31, 0);

	//Init events for screen
	events_init_coffeePour(ui);
}
