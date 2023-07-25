/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "saver_events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "/lvgl/git_lvgl_v8/lvgl/LVGL.Simulator/lvgl/demos/screensaver/circular/circular.h"

static void saver_screen_anim_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCREEN_UNLOAD_START:
    {
        lv_timer_del(circular_timer);
        //lv_timer_del(trailing_timer1);
        break;
    }
    case LV_EVENT_SCREEN_LOADED:
    {
        circular_timer_create();
        //timer1_create();
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
            if (user_guider_ui.user_screen_del == true)
                user_setup_scr_screen(&user_guider_ui);
            lv_scr_load_anim(user_guider_ui.user_screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
            saver_guider_ui.saver_screen_del = true;
        }

        break;
    }
    default:
        break;
    }
}


void events_init_saver(saver_lv_ui* ui)
{
    lv_obj_add_event_cb(ui->saver_screen, saver_screen_anim_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->saver_screen, saver_screen_event_handler, LV_EVENT_ALL, ui);
}
