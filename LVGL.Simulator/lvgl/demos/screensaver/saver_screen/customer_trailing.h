#ifndef __CUSTOMER_TRAILING_H__
#define __CUSTOMER_TRAILING_H__

#include "lvgl/lvgl.h"
#include "math.h"

#define SIZE_TRAILING     8
#define TIMER_CB_PERIOD   1
#define POS1_X            200
#define POS1_Y            200
#define POS2_X            100
#define POS2_Y            100


typedef struct trailing {
    lv_coord_t x[SIZE_TRAILING];
    lv_coord_t y[SIZE_TRAILING];
    bool dir_x;
    bool dir_y;
    int16_t dist_x;
    int16_t dist_y;
    lv_obj_t* img[SIZE_TRAILING];
}trailing_t;

typedef struct block {
    trailing_t block_red;
    trailing_t block_pink;
}block_t;

extern block_t block_all;
extern lv_timer_t* trailing_timer1;

void timer1_create(void);

#endif
