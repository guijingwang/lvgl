
#include "customer.h"

int mytime_count = 0;

static void set_saver_screen(void)
{
    lv_obj_t* act_scr = lv_scr_act();
    lv_disp_t* d = lv_obj_get_disp(act_scr);
    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
    {
        if (user_guider_ui.user_screen_del == true)
            saver_setup_scr_screen(&saver_guider_ui);
        lv_scr_load_anim(saver_guider_ui.saver_screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        saver_guider_ui.saver_screen_del = true;
    }
}

void user_screen_to_saver_timer_cb(lv_timer_t* t)
{
    mytime_count++;
    if (mytime_count >= 3) {
        set_saver_screen();
    }
}

