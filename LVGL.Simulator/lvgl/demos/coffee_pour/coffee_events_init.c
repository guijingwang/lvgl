/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "coffee_events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"

static int current_value = 0;


static void coffeePour_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_animimg_t * animimg1 = (lv_animimg_t *)coffee_guider_ui.coffeePour_animimg_coffee;
		lv_anim_set_values(&animimg1->anim, 0, 31);
        lv_animimg_set_repeat_count(coffee_guider_ui.coffeePour_animimg_coffee, 3);
		lv_animimg_start(coffee_guider_ui.coffeePour_animimg_coffee);
	}
		break;
	default:
		break;
	}
}

static void coffeePour_btn_reset_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    static zoom = 512;
    static count = 0;
	switch (code)
	{
	case LV_EVENT_CLICKED:
    {
        lv_animimg_t* animimg1 = (lv_animimg_t*)coffee_guider_ui.coffeePour_animimg_coffee;
        lv_anim_set_values(&animimg1->anim, 0, 1);
        lv_animimg_start(coffee_guider_ui.coffeePour_animimg_coffee);
        if (count) {
            zoom += 64;
            if (zoom == 512)count = 0;
        }
        else {
            zoom -= 64;
            if (zoom == 0)count = 1;
        }
        lv_img_set_zoom(coffee_guider_ui.coffeepour_animing_coffeef31, zoom);
        break;
    }

	default:
		break;
	}
}

static void coffeePour_btn_continue_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_animimg_t * animimg1 = (lv_animimg_t *)coffee_guider_ui.coffeePour_animimg_coffee;
		lv_anim_set_values(&animimg1->anim, current_value, 31);
		lv_animimg_set_repeat_count(coffee_guider_ui.coffeePour_animimg_coffee, 1);
		lv_animimg_start(coffee_guider_ui.coffeePour_animimg_coffee);
		current_value = 0;
	}
		break;
	default:
		break;
	}
}

static void coffeePour_btn_stop_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_animimg_t * animimg1 = (lv_animimg_t *)coffee_guider_ui.coffeePour_animimg_coffee;
		if(lv_anim_get(coffee_guider_ui.coffeePour_animimg_coffee, NULL) != NULL) {
		    lv_anim_t *anim_status = lv_anim_get(coffee_guider_ui.coffeePour_animimg_coffee, NULL);
		    current_value = anim_status->current_value;
		    lv_anim_del(coffee_guider_ui.coffeePour_animimg_coffee, NULL);
		}
	}
		break;
	default:
		break;
	}
}

static void coffeePour_btn_full_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_animimg_t * animimg1 = (lv_animimg_t *)coffee_guider_ui.coffeePour_animimg_coffee;
		lv_anim_set_values(&animimg1->anim, 0, 31);
		lv_animimg_set_repeat_count(coffee_guider_ui.coffeePour_animimg_coffee, 3);//LV_ANIM_REPEAT_INFINITE
		lv_animimg_start(coffee_guider_ui.coffeePour_animimg_coffee);
	}
		break;
	default:
		break;
	}
}

void events_init_coffeePour(coffee_lv_ui*ui)
{
	lv_obj_add_event_cb(ui->coffeePour, coffeePour_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->coffeePour_btn_reset, coffeePour_btn_reset_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->coffeePour_btn_continue, coffeePour_btn_continue_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->coffeePour_btn_stop, coffeePour_btn_stop_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->coffeePour_btn_full, coffeePour_btn_full_event_handler, LV_EVENT_ALL, ui);
}
