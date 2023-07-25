#include "user_event.h"

lv_timer_t* user_to_saver;

void saver_events_init(saver_lv_ui* ui)
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
            lv_obj_add_flag(user_guider_ui.user_screen_img_1, LV_OBJ_FLAG_HIDDEN);
        }
        else {
            lv_obj_clear_flag(user_guider_ui.user_screen_img_1, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_user(user_lv_ui* ui)
{
    lv_obj_add_event_cb(ui->user_screen_sw_1, user_sw_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->user_screen, user_screen_timer_event_handler, LV_EVENT_ALL, ui);
}

