/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef COFFEE_GUI_GUIDER_H
#define COFFEE_GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "lvgl/demos/coffee_pour/guider_fonts/coffee_guider_fonts.h"

typedef struct
{
	lv_obj_t *coffeePour;
	bool coffeePour_del;
	lv_obj_t *coffeePour_animimg_coffee;
	lv_obj_t *coffeePour_line_right;
	lv_obj_t *coffeePour_btn_reset;
	lv_obj_t *coffeePour_btn_reset_label;
	lv_obj_t *coffeePour_btn_continue;
	lv_obj_t *coffeePour_btn_continue_label;
	lv_obj_t *coffeePour_img_logo;
	lv_obj_t *coffeePour_line_left;
	lv_obj_t *coffeePour_btn_stop;
	lv_obj_t *coffeePour_btn_stop_label;
	lv_obj_t *coffeePour_btn_full;
	lv_obj_t *coffeePour_btn_full_label;
	lv_obj_t *coffeePour_label_1;
    lv_obj_t* coffeepour_animing_coffeef31;
}coffee_lv_ui;

void coffee_ui_init_style(lv_style_t * style);
void coffee_init_scr_del_flag(coffee_lv_ui*ui);
void coffee_setup_ui(coffee_lv_ui*ui);
extern coffee_lv_ui coffee_guider_ui;
void setup_scr_coffeePour(coffee_lv_ui*ui);

#include "lvgl/src/extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(coffeePour_animimg_coffeef01)
LV_IMG_DECLARE(coffeePour_animimg_coffeef02)
LV_IMG_DECLARE(coffeePour_animimg_coffeef03)
LV_IMG_DECLARE(coffeePour_animimg_coffeef04)
LV_IMG_DECLARE(coffeePour_animimg_coffeef05)
LV_IMG_DECLARE(coffeePour_animimg_coffeef06)
LV_IMG_DECLARE(coffeePour_animimg_coffeef07)
LV_IMG_DECLARE(coffeePour_animimg_coffeef08)
LV_IMG_DECLARE(coffeePour_animimg_coffeef09)
LV_IMG_DECLARE(coffeePour_animimg_coffeef10)
LV_IMG_DECLARE(coffeePour_animimg_coffeef11)
LV_IMG_DECLARE(coffeePour_animimg_coffeef12)
LV_IMG_DECLARE(coffeePour_animimg_coffeef13)
LV_IMG_DECLARE(coffeePour_animimg_coffeef14)
LV_IMG_DECLARE(coffeePour_animimg_coffeef15)
LV_IMG_DECLARE(coffeePour_animimg_coffeef16)
LV_IMG_DECLARE(coffeePour_animimg_coffeef17)
LV_IMG_DECLARE(coffeePour_animimg_coffeef18)
LV_IMG_DECLARE(coffeePour_animimg_coffeef19)
LV_IMG_DECLARE(coffeePour_animimg_coffeef20)
LV_IMG_DECLARE(coffeePour_animimg_coffeef21)
LV_IMG_DECLARE(coffeePour_animimg_coffeef22)
LV_IMG_DECLARE(coffeePour_animimg_coffeef23)
LV_IMG_DECLARE(coffeePour_animimg_coffeef24)
LV_IMG_DECLARE(coffeePour_animimg_coffeef25)
LV_IMG_DECLARE(coffeePour_animimg_coffeef26)
LV_IMG_DECLARE(coffeePour_animimg_coffeef27)
LV_IMG_DECLARE(coffeePour_animimg_coffeef28)
LV_IMG_DECLARE(coffeePour_animimg_coffeef29)
LV_IMG_DECLARE(coffeePour_animimg_coffeef30)
LV_IMG_DECLARE(coffeePour_animimg_coffeef31)
LV_IMG_DECLARE(_logo_alpha_60x20);

#ifdef __cplusplus
}
#endif
#endif
