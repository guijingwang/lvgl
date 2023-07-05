/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "saver_events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"

lv_timer_t* task1;
lv_timer_t* user_to_saver;

void saver_events_init(saver_lv_ui*ui)
{
}

static void user_screen_timer_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCREEN_UNLOAD_START:
    {
        lv_timer_del(user_to_saver);
        break;
    }
    case LV_EVENT_SCREEN_LOADED:
    {
        user_to_saver = lv_timer_create(user_screen_to_saver_timer_cb, 1000, 0);
        lv_timer_set_repeat_count(user_to_saver, -1);
        mytime_count = 0;
        break;
    }
    default:
        break;
    }
}

static void user_sw_1_event_handler(lv_event_t* e)
{
    static bool val = 0;
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
    {
        mytime_count = 0;
        val = !val;
        if (val) {
            lv_obj_add_flag(saver_guider_ui.user_screen_img_1, LV_OBJ_FLAG_HIDDEN);
        }
        else {
            lv_obj_clear_flag(saver_guider_ui.user_screen_img_1, LV_OBJ_FLAG_HIDDEN);
        }

        //lv_obj_t* act_scr = lv_scr_act();
        //lv_disp_t* d = lv_obj_get_disp(act_scr);
        //if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        //{
        //    if (saver_guider_ui.screen_del == true)
        //        saver_setup_scr_screen(&saver_guider_ui);
        //    lv_scr_load_anim(saver_guider_ui.screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        //    saver_guider_ui.user_screen_del = true;
        //}
        break;
    }
    default:
        break;
    }
}

void events_init_saver_user(saver_lv_ui* ui)
{
    lv_obj_add_event_cb(ui->user_screen_sw_1, user_sw_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->user_screen, user_screen_timer_event_handler, LV_EVENT_ALL, ui);
}


static void saver_screen_anim_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCREEN_UNLOAD_START:
    {
        lv_timer_del(task1);
        break;
    }
    case LV_EVENT_SCREEN_LOADED:
    {
        task1 = lv_timer_create(my_timer_cb, 1, 0);
        lv_timer_set_repeat_count(task1, -1);
        break;
    }
    default:
        break;
    }
}

static void saver_screen_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t* act_scr = lv_scr_act();
        lv_disp_t* d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (saver_guider_ui.user_screen_del == true)
                user_setup_scr_screen(&saver_guider_ui);
            lv_scr_load_anim(saver_guider_ui.user_screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
            saver_guider_ui.screen_del = true;
        }

        break;
    }
    default:
        break;
    }
}


void events_init_saver_saver(saver_lv_ui* ui)
{
    lv_obj_add_event_cb(ui->screen, saver_screen_anim_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen, saver_screen_event_handler, LV_EVENT_ALL, ui);
}
