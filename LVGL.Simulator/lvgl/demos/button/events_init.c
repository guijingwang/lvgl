/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"
static unsigned int counter = 0;
static char buf[4];


void events_init(lv_ui *ui)
{
}

static void blueCounter_plus_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_LONG_PRESSED_REPEAT:
	{
		counter++;
		sprintf(buf,  "%d" , counter);
		lv_label_set_text(guider_ui.blueCounter_counter, buf);
	}
		break;
	case LV_EVENT_CLICKED:
	{
		counter++;
		sprintf(buf,  "%d" , counter);
		lv_label_set_text(guider_ui.blueCounter_counter, buf);
	}
		break;
	default:
		break;
	}
}

static void blueCounter_minus_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_LONG_PRESSED_REPEAT:
	{
		if(counter) counter--;
		sprintf(buf,  "%d" , counter);
		lv_label_set_text(guider_ui.blueCounter_counter, buf);
	}
		break;
	case LV_EVENT_CLICKED:
	{
		counter--;
		sprintf(buf,  "%d" , counter);
		lv_label_set_text(guider_ui.blueCounter_counter, buf);
	}
		break;
	default:
		break;
	}
}

void events_init_blueCounter(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->blueCounter_plus, blueCounter_plus_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->blueCounter_minus, blueCounter_minus_event_handler, LV_EVENT_ALL, ui);
}
