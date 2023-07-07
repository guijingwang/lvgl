/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "saver_gui_guider.h"
#include "saver_events_init.h"


void user_setup_scr_screen(saver_lv_ui *ui)
{
    ui->user_screen = lv_obj_create(NULL);

    lv_obj_set_style_bg_color(ui->user_screen, lv_color_make(0xf8, 0x88, 0x88), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->user_screen, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->user_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->user_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes user_sw_1
    ui->user_screen_sw_1 = lv_switch_create(ui->user_screen);
    lv_obj_set_pos(ui->user_screen_sw_1, 367, 204);
    lv_obj_set_size(ui->user_screen_sw_1, 40, 20);
    lv_obj_set_scrollbar_mode(ui->user_screen_sw_1, LV_SCROLLBAR_MODE_OFF);

    //Set style for user_screen_sw_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_radius(ui->user_screen_sw_1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->user_screen_sw_1, lv_color_make(0xf8, 0x88, 0x88), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->user_screen_sw_1, lv_color_make(0xe6, 0xe2, 0xe6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->user_screen_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->user_screen_sw_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->user_screen_sw_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->user_screen_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->user_screen_sw_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->user_screen_sw_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->user_screen_sw_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->user_screen_sw_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->user_screen_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->user_screen_sw_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->user_screen_sw_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //Set style for user_screen_sw_1. Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED
    lv_obj_set_style_bg_color(ui->user_screen_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_color(ui->user_screen_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->user_screen_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->user_screen_sw_1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->user_screen_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->user_screen_sw_1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->user_screen_sw_1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    //Set style for user_screen_sw_1. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
    lv_obj_set_style_radius(ui->user_screen_sw_1, 100, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->user_screen_sw_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->user_screen_sw_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->user_screen_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->user_screen_sw_1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->user_screen_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->user_screen_sw_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->user_screen_sw_1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Write codes screen_img_1
    ui->user_screen_img_1 = lv_img_create(ui->user_screen);
    lv_obj_set_pos(ui->user_screen_img_1, 0, 0);
    lv_obj_set_size(ui->user_screen_img_1, 100, 100);
    lv_obj_set_scrollbar_mode(ui->user_screen_img_1, LV_SCROLLBAR_MODE_OFF);

    //Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->user_screen_img_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->user_screen_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->user_screen_img_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->user_screen_img_1, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_1
    lv_obj_update_layout(ui->user_screen_img_1);

    lv_img_set_src(ui->user_screen_img_1, &_grute_alpha_100x100);
    lv_img_set_pivot(ui->user_screen_img_1, 50, 50);
    lv_img_set_angle(ui->user_screen_img_1, 0);

    events_init_saver_user(ui);
}

/////////////////////////////////////////////////////////////////////////////////////

static lv_obj_t* g_kb_user;
static void kb_user_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* kb = lv_event_get_target(e);
    if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

void saver_setup_scr_screen(saver_lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL);

    g_kb_user = lv_keyboard_create(ui->screen);
    lv_obj_add_event_cb(g_kb_user, kb_user_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(g_kb_user, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(g_kb_user, &lv_font_simsun_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->screen, lv_color_make(0x3c, 0xa2, 0xf7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_1
    ui->screen_img_18 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_18, 0, 0);
    lv_obj_set_size(ui->screen_img_18, 86, 86);
    lv_obj_set_scrollbar_mode(ui->screen_img_18, LV_SCROLLBAR_MODE_OFF);

    //Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->screen_img_18, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_18, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_18, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_18, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_1
    lv_obj_update_layout(ui->screen_img_18);

    lv_img_set_src(ui->screen_img_18, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_18, 50, 50);
    lv_img_set_angle(ui->screen_img_18, 0);

    //Write codes screen_img_1
    ui->screen_img_17 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_17, 0, 0);
    lv_obj_set_size(ui->screen_img_17, 88, 88);
    lv_obj_set_scrollbar_mode(ui->screen_img_17, LV_SCROLLBAR_MODE_OFF);

    //Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->screen_img_17, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_17, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_17, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_17, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_1
    lv_obj_update_layout(ui->screen_img_17);

    lv_img_set_src(ui->screen_img_17, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_17, 50, 50);
    lv_img_set_angle(ui->screen_img_17, 0);

    //Write codes screen_img_1
    ui->screen_img_16 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_16, 0, 0);
    lv_obj_set_size(ui->screen_img_16, 90, 90);
    lv_obj_set_scrollbar_mode(ui->screen_img_16, LV_SCROLLBAR_MODE_OFF);

    //Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->screen_img_16, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_16, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_16, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_16, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_1
    lv_obj_update_layout(ui->screen_img_16);

    lv_img_set_src(ui->screen_img_16, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_16, 50, 50);
    lv_img_set_angle(ui->screen_img_16, 0);

    //Write codes screen_img_1
    ui->screen_img_15 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_15, 0, 0);
    lv_obj_set_size(ui->screen_img_15, 92, 92);
    lv_obj_set_scrollbar_mode(ui->screen_img_15, LV_SCROLLBAR_MODE_OFF);

    //Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->screen_img_15, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_15, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_15, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_15, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_1
    lv_obj_update_layout(ui->screen_img_15);

    lv_img_set_src(ui->screen_img_15, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_15, 50, 50);
    lv_img_set_angle(ui->screen_img_15, 0);

    //Write codes screen_img_1
    ui->screen_img_14 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_14, 0, 0);
    lv_obj_set_size(ui->screen_img_14, 94, 94);
    lv_obj_set_scrollbar_mode(ui->screen_img_14, LV_SCROLLBAR_MODE_OFF);

    //Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->screen_img_14, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_14, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_14, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_14, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_1
    lv_obj_update_layout(ui->screen_img_14);

    lv_img_set_src(ui->screen_img_14, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_14, 50, 50);
    lv_img_set_angle(ui->screen_img_14, 0);

    //Write codes screen_img_1
    ui->screen_img_13 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_13, 0, 0);
    lv_obj_set_size(ui->screen_img_13, 96, 96);
    lv_obj_set_scrollbar_mode(ui->screen_img_13, LV_SCROLLBAR_MODE_OFF);

    //Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->screen_img_13, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_13, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_13, 205, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_13, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_1
    lv_obj_update_layout(ui->screen_img_13);

    lv_img_set_src(ui->screen_img_13, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_13, 50, 50);
    lv_img_set_angle(ui->screen_img_13, 0);

    //Write codes screen_img_1
    ui->screen_img_12 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_12, 0, 0);
    lv_obj_set_size(ui->screen_img_12, 98, 98);
    lv_obj_set_scrollbar_mode(ui->screen_img_12, LV_SCROLLBAR_MODE_OFF);

    //Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
    lv_obj_set_style_img_recolor(ui->screen_img_12, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_12, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_12, 230, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_12, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_1
    lv_obj_update_layout(ui->screen_img_12);

    lv_img_set_src(ui->screen_img_12, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_12, 50, 50);
    lv_img_set_angle(ui->screen_img_12, 0);

	//Write codes screen_img_1
	ui->screen_img_11 = lv_img_create(ui->screen);
	lv_obj_set_pos(ui->screen_img_11, 0, 0);
	lv_obj_set_size(ui->screen_img_11, 100, 100);
	lv_obj_set_scrollbar_mode(ui->screen_img_11, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->screen_img_11, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_img_11, 90, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_img_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_11, LV_OBJ_FLAG_CLICKABLE);

	//Update pos for widget screen_img_1
	lv_obj_update_layout(ui->screen_img_11);

	lv_img_set_src(ui->screen_img_11,&_my_alpha_100x100);
	lv_img_set_pivot(ui->screen_img_11, 50,50);
	lv_img_set_angle(ui->screen_img_11, 0);


    //write code screen_img_2
    ui->screen_img_28 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_28, 500, 350);
    lv_obj_set_size(ui->screen_img_28, 86, 86);
    lv_obj_set_scrollbar_mode(ui->screen_img_28, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_img_recolor(ui->screen_img_28, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_28, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_28, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_28, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_2
    lv_obj_update_layout(ui->screen_img_28);

    lv_img_set_src(ui->screen_img_28, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_28, 50, 50);
    lv_img_set_angle(ui->screen_img_28, 0);

    //write code screen_img_2
    ui->screen_img_27 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_27, 500, 350);
    lv_obj_set_size(ui->screen_img_27, 88, 88);
    lv_obj_set_scrollbar_mode(ui->screen_img_27, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_img_recolor(ui->screen_img_27, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_27, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_27, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_27, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_2
    lv_obj_update_layout(ui->screen_img_27);

    lv_img_set_src(ui->screen_img_27, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_27, 50, 50);
    lv_img_set_angle(ui->screen_img_27, 0);

    //write code screen_img_2
    ui->screen_img_26 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_26, 500, 350);
    lv_obj_set_size(ui->screen_img_26, 90, 90);
    lv_obj_set_scrollbar_mode(ui->screen_img_26, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_img_recolor(ui->screen_img_26, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_26, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_26, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_26, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_2
    lv_obj_update_layout(ui->screen_img_26);

    lv_img_set_src(ui->screen_img_26, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_26, 50, 50);
    lv_img_set_angle(ui->screen_img_26, 0);

    //write code screen_img_2
    ui->screen_img_25 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_25, 500, 350);
    lv_obj_set_size(ui->screen_img_25, 92, 92);
    lv_obj_set_scrollbar_mode(ui->screen_img_25, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_img_recolor(ui->screen_img_25, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_25, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_25, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_25, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_2
    lv_obj_update_layout(ui->screen_img_25);

    lv_img_set_src(ui->screen_img_25, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_25, 50, 50);
    lv_img_set_angle(ui->screen_img_25, 0);

    //write code screen_img_2
    ui->screen_img_24 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_24, 500, 350);
    lv_obj_set_size(ui->screen_img_24, 94, 94);
    lv_obj_set_scrollbar_mode(ui->screen_img_24, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_img_recolor(ui->screen_img_24, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_24, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_24, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_24, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_2
    lv_obj_update_layout(ui->screen_img_24);

    lv_img_set_src(ui->screen_img_24, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_24, 50, 50);
    lv_img_set_angle(ui->screen_img_24, 0);

    //write code screen_img_2
    ui->screen_img_23 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_23, 500, 350);
    lv_obj_set_size(ui->screen_img_23, 96, 96);
    lv_obj_set_scrollbar_mode(ui->screen_img_23, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_img_recolor(ui->screen_img_23, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_23, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_23, 205, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_23, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_2
    lv_obj_update_layout(ui->screen_img_23);

    lv_img_set_src(ui->screen_img_23, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_23, 50, 50);
    lv_img_set_angle(ui->screen_img_23, 0);

    //write code screen_img_2
    ui->screen_img_22 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_22, 500, 350);
    lv_obj_set_size(ui->screen_img_22, 98, 98);
    lv_obj_set_scrollbar_mode(ui->screen_img_22, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_img_recolor(ui->screen_img_22, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_22, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_22, 230, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_22, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_2
    lv_obj_update_layout(ui->screen_img_22);

    lv_img_set_src(ui->screen_img_22, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_22, 50, 50);
    lv_img_set_angle(ui->screen_img_22, 0);

    //write code screen_img_2
    ui->screen_img_21 = lv_img_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_21, 500, 350);
    lv_obj_set_size(ui->screen_img_21, 100, 100);
    lv_obj_set_scrollbar_mode(ui->screen_img_21, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_img_recolor(ui->screen_img_21, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_21, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_21, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui->screen_img_21, LV_OBJ_FLAG_CLICKABLE);

    //Update pos for widget screen_img_2
    lv_obj_update_layout(ui->screen_img_21);

    lv_img_set_src(ui->screen_img_21, &_my_alpha_100x100);
    lv_img_set_pivot(ui->screen_img_21, 50, 50);
    lv_img_set_angle(ui->screen_img_21, 0);

    events_init_saver_saver(ui);
}

