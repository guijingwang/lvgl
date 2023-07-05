/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "saver_gui_guider.h"


void saver_ui_init_style(lv_style_t * style)
{
	if (style->prop_cnt > 1)
		lv_style_reset(style);
	else
		lv_style_init(style);
}

void saver_init_scr_del_flag(saver_lv_ui*ui)
{
	ui->screen_del = true;
    ui->user_screen_del = true;
}

void saver_setup_ui(saver_lv_ui*ui)
{
    saver_init_scr_del_flag(ui);
 //   saver_setup_scr_screen(ui);
	//lv_scr_load(ui->screen);

    user_setup_scr_screen(ui);
    lv_scr_load(ui->user_screen);
}
