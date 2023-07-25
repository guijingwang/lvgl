#include "circular.h"

circular_t ball_all = {
    .ball_black.angle = 67,
    .ball_black.dist = 5,
    .ball_black.x = 250,
    .ball_black.y = 100,
    .ball_red.angle = 190,
    .ball_red.dist = 3,
    .ball_red.x = 100,
    .ball_red.y = 100,
};

lv_timer_t* circular_timer;

static circular_obj_t pos_edge_calculate(circular_obj_t ball)
{
    static uint8_t i = 0, j = 0;
    circular_obj_t temp = ball;
    if ((temp.x < 0) || (temp.x > 750)) {
        if (i > 5) {
            temp.angle = 180 - temp.angle;
            if (temp.angle < 0) {
                temp.angle += 360;
                i = 0;
            }
        }
    }
    if ((temp.y < 0) || (temp.y > 430)) {
        if (j > 5) {
            temp.angle = 360 - temp.angle;
            j = 0;
        }
    }
    if (i < 6) { i++; }
    if (j < 6) { j++; }
    return temp;
}

static void next_pos_calculate(circular_obj_t* ball)
{
    ball->x += ball->dist * cos(ball->angle * RADIAN);
    ball->y += ball->dist * sin(ball->angle * RADIAN);
}

static circular_t* pos_collision_calculate(circular_t* ball_all)
{
    static uint16_t i = 0;
    float vector1_pa, vector1_ve, vector2_pa, vector2_ve;
    float angle_collision;
    if (((ball_all->ball_black.x - ball_all->ball_red.x) * (ball_all->ball_black.x - ball_all->ball_red.x) +
        (ball_all->ball_black.y - ball_all->ball_red.y) * (ball_all->ball_black.y - ball_all->ball_red.y)) <= 50 * 50) {

        if (i > 5) {
            angle_collision = asin((ball_all->ball_black.y - ball_all->ball_red.y) / 50) * ANGLE;

            if (angle_collision > 0) {
                if (ball_all->ball_black.x > ball_all->ball_red.x) {
                    ball_all->ball_black.angle_coll = angle_collision + 180;
                    ball_all->ball_red.angle_coll = angle_collision;
                } else {
                    ball_all->ball_black.angle_coll = 360 - angle_collision;
                    ball_all->ball_red.angle_coll = 180 - angle_collision;
                }
            }
            else {
                if (ball_all->ball_black.x > ball_all->ball_red.x) {
                    ball_all->ball_black.angle_coll = 180 + angle_collision;
                    ball_all->ball_red.angle_coll = 360 + angle_collision;
                    if (ball_all->ball_red.angle_coll >= 360) {
                        ball_all->ball_red.angle_coll -= 360;
                    }
                }
                else {
                    ball_all->ball_black.angle_coll = -angle_collision;
                    ball_all->ball_red.angle_coll = 180 + (-angle_collision);
                }
            }
            vector1_pa = cos((ball_all->ball_black.angle - ball_all->ball_black.angle_coll) * RADIAN) * ball_all->ball_black.dist;
            vector1_ve = sin((ball_all->ball_black.angle - ball_all->ball_black.angle_coll) * RADIAN) * ball_all->ball_black.dist;
            vector2_pa = cos((ball_all->ball_red.angle - ball_all->ball_red.angle_coll) * RADIAN) * ball_all->ball_red.dist;
            vector2_ve = sin((ball_all->ball_red.angle - ball_all->ball_red.angle_coll) * RADIAN) * ball_all->ball_red.dist;

            ball_all->ball_black.dist = sqrt(vector1_ve * vector1_ve + vector2_pa * vector2_pa);
            ball_all->ball_red.dist = sqrt(vector2_ve * vector2_ve + vector1_pa * vector1_pa);

            if (ball_all->ball_black.dist == 0) {
                ball_all->ball_black.angle = 0;
            } else {
                ball_all->ball_black.angle = ball_all->ball_red.angle_coll - (asin(vector1_ve / ball_all->ball_black.dist) * ANGLE);
            }
            if (ball_all->ball_red.dist == 0) {
                ball_all->ball_red.angle = 0;
            } else {
                ball_all->ball_red.angle = ball_all->ball_black.angle_coll - (asin(vector2_ve / ball_all->ball_red.dist) * ANGLE);
            }
            i = 0;
        }
    }
    if (i < 6) {
        i++;
    }
}

static circular_t* pos_calculate(circular_t* ball_all)
{
    ball_all->ball_black = pos_edge_calculate(ball_all->ball_black);
    ball_all->ball_red = pos_edge_calculate(ball_all->ball_red);

    pos_collision_calculate(ball_all);

    next_pos_calculate(&ball_all->ball_black);
    next_pos_calculate(&ball_all->ball_red);
}

static bool set_pos(circular_t* ball_all)
{
    for (int16_t i = 0; i < 1; i++) {
        if (ball_all->ball_black.img != NULL) {
            lv_obj_set_pos(ball_all->ball_black.img, (lv_coord_t)ball_all->ball_black.x, (lv_coord_t)ball_all->ball_black.y);
            lv_obj_set_pos(ball_all->ball_red.img, (lv_coord_t)ball_all->ball_red.x, (lv_coord_t)ball_all->ball_red.y);
        }
        else {
            return 0;
        }
    }
    return 1;
}

static int16_t circular_x(int16_t angle)
{
    return (int16_t)(40 * PI * cos(angle * PI / 180));
}

static int16_t circular_y(int16_t angle)
{
    return (int16_t)(40 * PI * sin(angle * PI / 180));
}

static void circular_timer_cb(lv_timer_t* t)
{
    pos_calculate(&ball_all);
    set_pos(&ball_all);
}

void circular_timer_create(void)
{
    circular_timer = lv_timer_create(circular_timer_cb, 1, 0);
}
