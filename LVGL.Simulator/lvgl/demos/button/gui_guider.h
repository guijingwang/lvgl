/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "lvgl/demos/button/guider_fonts/guider_fonts.h"

typedef struct
{
	lv_obj_t *blueCounter;
	bool blueCounter_del;
	lv_obj_t *blueCounter_cont_1;
	lv_obj_t *blueCounter_plus;
	lv_obj_t *blueCounter_plus_label;
	lv_obj_t *blueCounter_minus;
	lv_obj_t *blueCounter_minus_label;
	lv_obj_t *blueCounter_counter;
	lv_obj_t *blueCounter_logo;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_blueCounter(lv_ui *ui);
LV_IMG_DECLARE(_btn_alpha_65x65);
LV_IMG_DECLARE(_logo_alpha_37x13);

#ifdef __cplusplus
}
#endif
#endif
