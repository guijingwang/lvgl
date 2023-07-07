#include "customer_trailing.h"

#define SIZE_TRAILING    8
#define TIMER_CB_PERIOD  10
#define POS1_X            350
#define POS1_Y            50
#define POS2_X            55
#define POS2_Y            300

#define SPEED1_X          3
#define SPEED1_Y          4
#define SPEED2_X          5
#define SPEED2_Y          4

#define PI               3.1415926

lv_timer_t* timer1;


int16_t arr1_x[SIZE_TRAILING];
int16_t arr1_y[SIZE_TRAILING];
int16_t arr2_x[SIZE_TRAILING];
int16_t arr2_y[SIZE_TRAILING];

lv_obj_t *img1_x[SIZE_TRAILING];
lv_obj_t *img2_x[SIZE_TRAILING];

static int16_t* arr_con(int16_t arr[])
{
    int16_t i = SIZE_TRAILING - 1;
    for (i; i > 0 ; i--) {
        arr[i] = arr[i - 1];
    }
    return arr;
}

static arr_init(int16_t arr[], int16_t num)
{
        for (int16_t i = 0; i < SIZE_TRAILING; i++) {
            arr[i] = num;
        }
}


static bool timer1_circular_set_pos(lv_obj_t* img[], int16_t x[], int16_t y[])
{
    for (int16_t i = 0; i < SIZE_TRAILING; i++) {
        if (img[i] != NULL) {
            lv_obj_set_pos(img[i], x[i]+350, y[i]+150);
        }
        else {
            return 0;
        }
    }
    return 1;
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


static int16_t calc1_x(int16_t x, int16_t speed, bool ars)
{
    if (ars) {
        x += speed;
    }
    else {
        x -= speed;
    }
    return x;
}

static int16_t calc1_y(int16_t y, int16_t speed, bool ars)
{
    if (ars) {
        y += speed;
    }
    else {
        y -= speed;
    }
    return y;
}

static int16_t calc2_x(int16_t x, int16_t speed, bool ars)
{
    if (ars) {
        x += speed;
    }
    else {
        x -= speed;
    }
    return x;
}

static int16_t calc2_y(int16_t y, int16_t speed, bool ars)
{
    if (ars) {
        y += speed;
    }
    else {
        y -= speed;
    }
    return y;
}


//#define MY_COS(Rx, angle) (int16_t)(Rx * PI * cos((angle) * PI / 180))
//#define MY_SIN(RY, angle) (int16_t)(RY * PI * sin((angle) * PI / 180))
//
//static int16_t circular_x(int16_t angle)
//{
//    return (int16_t)(40 * PI * cos(angle * PI / 180));
//}
//
//static int16_t circular_y(int16_t angle)
//{
//    return (int16_t)(40 * PI * sin(angle * PI / 180));
//}

static void timer1_cb(lv_timer_t* t)
{

    static bool cy1 = 1;
    static bool cx1 = 1;
    static bool cy2 = 1;
    static bool cx2 = 1;
    static int16_t angle = 0;
    static int16_t angle1 = 90;

    arr_con(arr1_x);
    arr_con(arr1_y);
    arr_con(arr2_x);
    arr_con(arr2_y);

    //if (angle1 == 360) angle1 = 0;
    //angle1 += 5;
    //if (angle == 360) angle = 0;
    //angle += 3;
    //arr1_x[0] = circular_x(angle);
    //arr1_y[0] = circular_y(angle1);

    if ((arr1_x[0] > 700) || (arr1_x[0] <  0)) cx1 = !cx1;
    if ((arr2_x[0] > 700) || (arr2_x[0] <  0)) cx2 = !cx2;
    if ((arr1_y[0] > 380) || (arr1_y[0] <  0)) cy1 = !cy1;
    if ((arr2_y[0] > 380) || (arr2_y[0] <  0)) cy2 = !cy2;

    if (abs(arr1_x[0] - arr2_x[0]) > abs(arr1_y[0] - arr2_y[0])) {
        if (abs(arr1_x[0] - arr2_x[0]) <= 100) {
            cx1 = !cx1;
            cx2 = !cx2;
        }
    }
    else {
        if (abs(arr1_y[0] - arr2_y[0]) <= 100) {
            cy1 = !cy1;
            cy2 = !cy2;
        }
    }

    arr1_x[0] = calc1_x(arr1_x[0], SPEED1_X, cx1);
    arr1_y[0] = calc1_y(arr1_y[0], SPEED1_Y, cy1);
    arr2_x[0] = calc2_x(arr2_x[0], SPEED2_X, cx2);
    arr2_y[0] = calc2_y(arr2_y[0], SPEED2_Y, cy2);


    timer1_set_pos(img1_x, arr1_x, arr1_y);
    timer1_set_pos(img2_x, arr2_x, arr2_y);
}


void timer1_create(void)
{

    img1_x[0] = saver_guider_ui.screen_img_11;
    img1_x[1] = saver_guider_ui.screen_img_12;
    img1_x[2] = saver_guider_ui.screen_img_13;
    img1_x[3] = saver_guider_ui.screen_img_14;
    img1_x[4] = saver_guider_ui.screen_img_15;
    img1_x[5] = saver_guider_ui.screen_img_16;
    img1_x[6] = saver_guider_ui.screen_img_17;
    img1_x[7] = saver_guider_ui.screen_img_18;

    img2_x[0] = saver_guider_ui.screen_img_21;
    img2_x[1] = saver_guider_ui.screen_img_22;
    img2_x[2] = saver_guider_ui.screen_img_23;
    img2_x[3] = saver_guider_ui.screen_img_24;
    img2_x[4] = saver_guider_ui.screen_img_25;
    img2_x[5] = saver_guider_ui.screen_img_26;
    img2_x[6] = saver_guider_ui.screen_img_27;
    img2_x[7] = saver_guider_ui.screen_img_28;

    arr_init(arr1_x, POS1_X);
    arr_init(arr1_y, POS1_Y);
    arr_init(arr2_x, POS2_X);
    arr_init(arr2_y, POS2_Y);
    timer1 = lv_timer_create(timer1_cb, TIMER_CB_PERIOD, 0);

}
