#ifndef __CIRCULAR_H__
#define __CIRCULAR_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "math.h"

#include "lvgl/demos/screensaver/saver_screen/customer_trailing.h"

#define PI               3.1415926
#define RADIAN           PI/180
#define ANGLE            180/PI

typedef struct cirular_obj {
    float x;
    float y;
    float angle;
    float angle_coll;
    float dist;
    lv_obj_t* img;
}circular_obj_t;

typedef struct circular {
    circular_obj_t ball_black;
    circular_obj_t ball_red;
}circular_t;

extern circular_t ball_all;
extern lv_timer_t* circular_timer;
void circular_timer_create(void);

#ifdef __cplusplus
}
#endif
#endif // ! __CIRCULAR_H__

