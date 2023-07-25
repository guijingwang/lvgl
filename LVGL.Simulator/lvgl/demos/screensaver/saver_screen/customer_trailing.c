#include "customer_trailing.h"

block_t block_all = {
.block_red.dir_x = 1,
.block_red.dir_y = 1,
.block_red.dist_x = 3,
.block_red.dist_y = 2,
.block_pink.dir_x = 1,
.block_pink.dir_y = 1,
.block_pink.dist_x = 3,
.block_pink.dist_y = 1,
};
lv_timer_t* trailing_timer1;

static arr_init(block_t *block)
{
    for (int16_t i = 0; i < SIZE_TRAILING; i++) {
        block->block_red.x[i] = POS1_X;
        block->block_red.y[i] = POS1_Y;
        block->block_pink.x[i] = POS2_X;
        block->block_pink.y[i] = POS2_Y;
    }
}

static block_t* pos_update(block_t *block)
{
    int16_t i = SIZE_TRAILING - 1;
    for (i; i > 0 ; i--) {
        block->block_pink.x[i] = block->block_pink.x[i - 1];
        block->block_pink.y[i] = block->block_pink.y[i - 1];
        block->block_red.x[i] = block->block_red.x[i - 1];
        block->block_red.y[i] = block->block_red.y[i - 1];
    }
    return block;
}

static bool timer1_set_pos(lv_obj_t* img[], int16_t x[], int16_t y[])
{
    for (int16_t i = 0; i < SIZE_TRAILING; i++) {
        if (img[i] != NULL) {
            lv_obj_set_pos(img[i], x[i] + i, y[i] + i);
        }
        else {
            return 0;
        }
    }
    return 1;
}

static int16_t pos_add(int16_t x, int16_t speed, bool ars)
{
    if (ars) {
        x += speed;
    }
    else {
        x -= speed;
    }
    return x;
}

static block_t* pos_claculate(block_t* block)
{

    if ((block->block_red.x[0] > 700) || (block->block_red.x[0] < 0)) {
        block->block_red.dir_x = !block->block_red.dir_x;
    }
    if ((block->block_pink.x[0] > 700) || (block->block_pink.x[0] < 0)) {
        block->block_pink.dir_x = !block->block_pink.dir_x;
    }
    if ((block->block_red.y[0] > 380) || (block->block_red.y[0] < 0)) {
        block->block_red.dir_y = !block->block_red.dir_y;
    }
    if ((block->block_pink.y[0] > 380) || (block->block_pink.y[0] < 0)) {
        block->block_pink.dir_y = !block->block_pink.dir_y;
    }

    if (abs(block->block_red.x[0] - block->block_pink.x[0]) > abs(block->block_red.y[0] - block->block_pink.y[0])) {
        if (abs(block->block_red.x[0] - block->block_pink.x[0]) <= 100) {
            block->block_pink.dir_x = !block->block_pink.dir_x;
            block->block_red.dir_x = !block->block_red.dir_x;
        }
    }
    else {
        if (abs(block->block_red.y[0] - block->block_pink.y[0]) <= 100) {
            block->block_red.dir_y = !block->block_red.dir_y;
            block->block_pink.dir_y = !block->block_pink.dir_y;
        }
    }

    block->block_red.x[0] = pos_add(block->block_red.x[0], block->block_red.dist_x, block->block_red.dir_x);
    block->block_red.y[0] = pos_add(block->block_red.y[0], block->block_red.dist_y, block->block_red.dir_y);
    block->block_pink.x[0] = pos_add(block->block_pink.x[0], block->block_pink.dist_x, block->block_pink.dir_x);
    block->block_pink.y[0] = pos_add(block->block_pink.y[0], block->block_pink.dist_y, block->block_pink.dir_y);
}

static void timer1_cb(lv_timer_t* t)
{
    (void)pos_update(&block_all);

    (void)pos_claculate(&block_all);

    
    timer1_set_pos(block_all.block_red.img, block_all.block_red.x, block_all.block_red.y);
    timer1_set_pos(block_all.block_pink.img, block_all.block_pink.x, block_all.block_pink.y);
}

void timer1_create(void)
{
    arr_init(&block_all);
    trailing_timer1 = lv_timer_create(timer1_cb, TIMER_CB_PERIOD, 0);
}
