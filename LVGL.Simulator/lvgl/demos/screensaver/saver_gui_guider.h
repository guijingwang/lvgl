/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef SAVER_GUI_GUIDER_H
#define SAVER_GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "lvgl/demos/screensaver/guider_fonts/saver_guider_fonts.h"
#include <math.h>

typedef struct
{
	lv_obj_t *screen;
    bool screen_del;
	lv_obj_t *screen_img_1;
    lv_obj_t *screen_img_2;

	
    lv_obj_t *user_screen;
    bool user_screen_del;
    lv_obj_t *user_screen_sw_1;
    lv_obj_t* user_screen_img_1;
}saver_lv_ui;


extern saver_lv_ui saver_guider_ui;
extern int mytime_count;


void saver_ui_init_style(lv_style_t * style);
void saver_init_scr_del_flag(saver_lv_ui*ui);
void saver_setup_ui(saver_lv_ui*ui);
void saver_setup_scr_screen(saver_lv_ui*ui);
void user_setup_scr_screen(saver_lv_ui* ui);

void my_timer_cb(lv_timer_t* t);
void user_screen_to_saver_timer_cb(lv_timer_t* t);

void events_init_saver_user(saver_lv_ui* ui);
void events_init_saver_saver(saver_lv_ui* ui);
LV_IMG_DECLARE(_grute_alpha_100x100);
LV_IMG_DECLARE(_my_alpha_100x100);

#ifdef __cplusplus
}
#endif
#endif
