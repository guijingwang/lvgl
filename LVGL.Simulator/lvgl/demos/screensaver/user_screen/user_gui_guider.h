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
#include "lvgl/demos/screensaver/saver_screen/saver_setup_scr_screen.h"
#include "lvgl/demos/screensaver/saver_screen/customer_trailing.h"

typedef struct
{
    lv_obj_t *user_screen;
    bool user_screen_del;
    lv_obj_t *user_screen_sw_1;
    lv_obj_t *user_screen_img_1;
}user_lv_ui;

extern user_lv_ui user_guider_ui;
extern saver_lv_ui saver_guider_ui;

extern int mytime_count;


void saver_ui_init_style(lv_style_t * style);
void saver_setup_scr_screen(saver_lv_ui*ui);
void user_setup_scr_screen(user_lv_ui* ui);
void screensaver_set_ui(void);



LV_IMG_DECLARE(_grute_alpha_100x100);
LV_IMG_DECLARE(_my_alpha_100x100);

#ifdef __cplusplus
}
#endif
#endif
