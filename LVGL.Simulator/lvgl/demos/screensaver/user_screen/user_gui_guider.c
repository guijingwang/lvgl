/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "user_gui_guider.h"
#include "lvgl/demos/screensaver/saver_screen/saver_setup_scr_screen.h"


user_lv_ui user_guider_ui;
saver_lv_ui saver_guider_ui;

void saver_ui_init_style(lv_style_t * style)
{
	if (style->prop_cnt > 1)
		lv_style_reset(style);
	else
		lv_style_init(style);
}

static void user_init_scr_del_flag(user_lv_ui*ui)
{
    ui->user_screen_del = true;
}

static void user_setup_ui(user_lv_ui*ui)
{
    user_init_scr_del_flag(ui);
    user_setup_scr_screen(ui);
    lv_scr_load(ui->user_screen);
}

static void saver_init_scr_del_flag(saver_lv_ui* ui)
{
    ui->saver_screen_del = true;
}

static void saver_setup_ui(saver_lv_ui* ui)
{
    saver_init_scr_del_flag(ui);
    saver_setup_scr_screen(ui);
    lv_scr_load(ui->saver_screen);
}

void screensaver_set_ui(void)
{
    user_setup_ui(&user_guider_ui);
}
