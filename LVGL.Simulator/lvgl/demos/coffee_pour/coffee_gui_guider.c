/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "coffee_gui_guider.h"


void coffee_ui_init_style(lv_style_t * style)
{
	if (style->prop_cnt > 1)
		lv_style_reset(style);
	else
		lv_style_init(style);
}

void coffee_init_scr_del_flag(coffee_lv_ui*ui)
{
	ui->coffeePour_del = true;
}

void coffee_setup_ui(coffee_lv_ui*ui)
{
    coffee_init_scr_del_flag(ui);
	setup_scr_coffeePour(ui);
	lv_scr_load(ui->coffeePour);
}
