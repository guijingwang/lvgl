/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "user_gui_guider.h"
#include "lvgl/demos/screensaver/saver_screen/saver_events_init.h"


void user_setup_scr_screen(user_lv_ui *ui)
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

    events_init_user(ui);
}
