#include <stdio.h>
#include <stdlib.h>
#include "lvgl/lvgl.h"
#include "saver_gui_guider.h"
#include <math.h>

int mytime_count = 0;

void my_timer_cb(lv_timer_t* t)
{
    static int x1 = 0;
    static int y1 = 0;
    static bool cx1 = 1;
    static bool cy1 = 1;
    static int x2 = 500;
    static int y2 = 350;
    static bool cx2 = 1;
    static bool cy2 = 1;

    if (abs(x1 - x2) > abs(y1 - y2)) {
        if (abs(x1 - x2) <= 100) {
            cx1 = !cx1;
            cx2 = !cx2;
        }
    }
    else {
        if (abs(y1 - y2) <= 100) {
            cy1 = !cy1;
            cy2 = !cy2;
        }
    }

    if (cx1) {
        x1 += 3;
        if (x1 > 700) cx1 = 0;
    }
    else {
        x1 -= 3;
        if (x1 < 0) cx1 = 1;
    }

    if (cy1) {
        y1 += 3;
        if (y1 > 380) cy1 = 0;
    }
    else {
        y1 -= 3;
        if (y1 < 0) cy1 = 1;
    }

    if (cx2) {
        x2 += 4;
        if (x2 > 700) cx2 = 0;
    }
    else {
        x2 -= 4;
        if (x2 < 0) cx2 = 1;
    }

    if (cy2) {
        y2 += 2;
        if (y2 > 380) cy2 = 0;
    }
    else {
        y2 -= 2;
        if (y2 < 0) cy2 = 1;
    }

    lv_obj_set_pos(saver_guider_ui.screen_img_1, x1, y1);
    lv_obj_set_pos(saver_guider_ui.screen_img_2, x2, y2);
}

static void set_saver_screen(void)
{
    lv_obj_t* act_scr = lv_scr_act();
    lv_disp_t* d = lv_obj_get_disp(act_scr);
    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
    {
        if (saver_guider_ui.screen_del == true)
            saver_setup_scr_screen(&saver_guider_ui);
        lv_scr_load_anim(saver_guider_ui.screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        saver_guider_ui.user_screen_del = true;
    }
}

void user_screen_to_saver_timer_cb(lv_timer_t* t)
{
    mytime_count++;
    if (mytime_count >= 5) {
        set_saver_screen();
    }
}

