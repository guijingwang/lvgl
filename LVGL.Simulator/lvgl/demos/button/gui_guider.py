# Copyright 2023 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=480,h=272)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(480*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 480
disp_drv.ver_res = 272
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)
        
def ta_zh_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.keyboard_set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.keyboard_set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)



# create blueCounter
blueCounter = lv.obj()
blueCounter.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_bluecounter_main_main_default
style_bluecounter_main_main_default = lv.style_t()
style_bluecounter_main_main_default.init()
style_bluecounter_main_main_default.set_bg_color(lv.color_make(0x2F,0xCA,0xDA))
style_bluecounter_main_main_default.set_bg_grad_color(lv.color_make(0x2F,0xCA,0xDA))
style_bluecounter_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_bluecounter_main_main_default.set_bg_opa(255)

# add style for blueCounter
blueCounter.add_style(style_bluecounter_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create blueCounter_cont_1
blueCounter_cont_1 = lv.obj(blueCounter)
blueCounter_cont_1.set_pos(int(93),int(51))
blueCounter_cont_1.set_size(294,170)
blueCounter_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create blueCounter_plus
blueCounter_plus = lv.imgbtn(blueCounter_cont_1)
blueCounter_plus.set_pos(int(193),int(13))
blueCounter_plus.set_size(65,65)
blueCounter_plus.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\button\\generated\\mPythonImages\\mp752668387.png','rb') as f:
        blueCounter_plus_imgReleased_data = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\button\\generated\\mPythonImages\\mp752668387.png')
    sys.exit()

blueCounter_plus_imgReleased = lv.img_dsc_t({
  'data_size': len(blueCounter_plus_imgReleased_data),
  'header': {'always_zero': 0, 'w': 65, 'h': 65, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': blueCounter_plus_imgReleased_data
})
blueCounter_plus.set_src(lv.imgbtn.STATE.RELEASED, None, blueCounter_plus_imgReleased, None)





blueCounter_plus.add_flag(lv.obj.FLAG.CHECKABLE)
blueCounter_plus_label = lv.label(blueCounter_plus)
blueCounter_plus_label.set_text("+")
blueCounter_plus.set_style_pad_all(0, lv.STATE.ANY)
blueCounter_plus_label.align(lv.ALIGN.CENTER,0,0)
# create style style_bluecounter_plus_main_main_default
style_bluecounter_plus_main_main_default = lv.style_t()
style_bluecounter_plus_main_main_default.init()
style_bluecounter_plus_main_main_default.set_text_color(lv.color_make(0x4d,0x6e,0x81))
try:
    style_bluecounter_plus_main_main_default.set_text_font(lv.font_arial_34)
except AttributeError:
    try:
        style_bluecounter_plus_main_main_default.set_text_font(lv.font_montserrat_34)
    except AttributeError:
        style_bluecounter_plus_main_main_default.set_text_font(lv.font_montserrat_16)
style_bluecounter_plus_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_bluecounter_plus_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_bluecounter_plus_main_main_default.set_img_recolor_opa(0)
style_bluecounter_plus_main_main_default.set_img_opa(255)

# add style for blueCounter_plus
blueCounter_plus.add_style(style_bluecounter_plus_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_bluecounter_plus_main_main_pressed
style_bluecounter_plus_main_main_pressed = lv.style_t()
style_bluecounter_plus_main_main_pressed.init()
style_bluecounter_plus_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_bluecounter_plus_main_main_pressed.set_text_font(lv.font_montserratMedium_34)
except AttributeError:
    try:
        style_bluecounter_plus_main_main_pressed.set_text_font(lv.font_montserrat_34)
    except AttributeError:
        style_bluecounter_plus_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_bluecounter_plus_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_bluecounter_plus_main_main_pressed.set_img_recolor_opa(0)
style_bluecounter_plus_main_main_pressed.set_img_opa(129)

# add style for blueCounter_plus
blueCounter_plus.add_style(style_bluecounter_plus_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)


# create blueCounter_minus
blueCounter_minus = lv.imgbtn(blueCounter_cont_1)
blueCounter_minus.set_pos(int(193),int(85))
blueCounter_minus.set_size(65,65)
blueCounter_minus.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\button\\generated\\mPythonImages\\mp752668387.png','rb') as f:
        blueCounter_minus_imgReleased_data = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\button\\generated\\mPythonImages\\mp752668387.png')
    sys.exit()

blueCounter_minus_imgReleased = lv.img_dsc_t({
  'data_size': len(blueCounter_minus_imgReleased_data),
  'header': {'always_zero': 0, 'w': 65, 'h': 65, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': blueCounter_minus_imgReleased_data
})
blueCounter_minus.set_src(lv.imgbtn.STATE.RELEASED, None, blueCounter_minus_imgReleased, None)





blueCounter_minus.add_flag(lv.obj.FLAG.CHECKABLE)
blueCounter_minus_label = lv.label(blueCounter_minus)
blueCounter_minus_label.set_text("-")
blueCounter_minus.set_style_pad_all(0, lv.STATE.ANY)
blueCounter_minus_label.align(lv.ALIGN.CENTER,0,0)
# create style style_bluecounter_minus_main_main_default
style_bluecounter_minus_main_main_default = lv.style_t()
style_bluecounter_minus_main_main_default.init()
style_bluecounter_minus_main_main_default.set_text_color(lv.color_make(0x4d,0x6e,0x81))
try:
    style_bluecounter_minus_main_main_default.set_text_font(lv.font_arial_34)
except AttributeError:
    try:
        style_bluecounter_minus_main_main_default.set_text_font(lv.font_montserrat_34)
    except AttributeError:
        style_bluecounter_minus_main_main_default.set_text_font(lv.font_montserrat_16)
style_bluecounter_minus_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_bluecounter_minus_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_bluecounter_minus_main_main_default.set_img_recolor_opa(0)
style_bluecounter_minus_main_main_default.set_img_opa(255)

# add style for blueCounter_minus
blueCounter_minus.add_style(style_bluecounter_minus_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_bluecounter_minus_main_main_pressed
style_bluecounter_minus_main_main_pressed = lv.style_t()
style_bluecounter_minus_main_main_pressed.init()
style_bluecounter_minus_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_bluecounter_minus_main_main_pressed.set_text_font(lv.font_montserratMedium_34)
except AttributeError:
    try:
        style_bluecounter_minus_main_main_pressed.set_text_font(lv.font_montserrat_34)
    except AttributeError:
        style_bluecounter_minus_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_bluecounter_minus_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_bluecounter_minus_main_main_pressed.set_img_recolor_opa(0)
style_bluecounter_minus_main_main_pressed.set_img_opa(129)

# add style for blueCounter_minus
blueCounter_minus.add_style(style_bluecounter_minus_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)


# create blueCounter_counter
blueCounter_counter = lv.label(blueCounter_cont_1)
blueCounter_counter.set_pos(int(58),int(63))
blueCounter_counter.set_size(114,43)
blueCounter_counter.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
blueCounter_counter.set_text("0")
blueCounter_counter.set_long_mode(lv.label.LONG.WRAP)
# create style style_bluecounter_counter_main_main_default
style_bluecounter_counter_main_main_default = lv.style_t()
style_bluecounter_counter_main_main_default.init()
style_bluecounter_counter_main_main_default.set_radius(7)
style_bluecounter_counter_main_main_default.set_bg_color(lv.color_make(0x4d,0x2c,0x2c))
style_bluecounter_counter_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_bluecounter_counter_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_bluecounter_counter_main_main_default.set_bg_opa(0)
style_bluecounter_counter_main_main_default.set_text_color(lv.color_make(0x02,0x4f,0x5a))
try:
    style_bluecounter_counter_main_main_default.set_text_font(lv.font_arial_40)
except AttributeError:
    try:
        style_bluecounter_counter_main_main_default.set_text_font(lv.font_montserrat_40)
    except AttributeError:
        style_bluecounter_counter_main_main_default.set_text_font(lv.font_montserrat_16)
style_bluecounter_counter_main_main_default.set_text_letter_space(2)
style_bluecounter_counter_main_main_default.set_text_line_space(0)
style_bluecounter_counter_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_bluecounter_counter_main_main_default.set_pad_left(0)
style_bluecounter_counter_main_main_default.set_pad_right(0)
style_bluecounter_counter_main_main_default.set_pad_top(0)
style_bluecounter_counter_main_main_default.set_pad_bottom(0)

# add style for blueCounter_counter
blueCounter_counter.add_style(style_bluecounter_counter_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create blueCounter_logo
blueCounter_logo = lv.img(blueCounter_cont_1)
blueCounter_logo.set_pos(int(24),int(13))
blueCounter_logo.set_size(37,13)
blueCounter_logo.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
blueCounter_logo.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\button\\generated\\mPythonImages\\mp-1768648344.png','rb') as f:
        blueCounter_logo_img_data = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\button\\generated\\mPythonImages\\mp-1768648344.png')
    sys.exit()

blueCounter_logo_img = lv.img_dsc_t({
  'data_size': len(blueCounter_logo_img_data),
  'header': {'always_zero': 0, 'w': 37, 'h': 13, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': blueCounter_logo_img_data
})

blueCounter_logo.set_src(blueCounter_logo_img)
blueCounter_logo.set_pivot(50,50)
blueCounter_logo.set_angle(0)
# create style style_bluecounter_logo_main_main_default
style_bluecounter_logo_main_main_default = lv.style_t()
style_bluecounter_logo_main_main_default.init()
style_bluecounter_logo_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_bluecounter_logo_main_main_default.set_img_recolor_opa(0)
style_bluecounter_logo_main_main_default.set_img_opa(255)

# add style for blueCounter_logo
blueCounter_logo.add_style(style_bluecounter_logo_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_bluecounter_cont_1_main_main_default
style_bluecounter_cont_1_main_main_default = lv.style_t()
style_bluecounter_cont_1_main_main_default.init()
style_bluecounter_cont_1_main_main_default.set_radius(12)
style_bluecounter_cont_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_bluecounter_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x4e,0x95,0xcb))
style_bluecounter_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_bluecounter_cont_1_main_main_default.set_bg_opa(255)
style_bluecounter_cont_1_main_main_default.set_border_color(lv.color_make(0xac,0xce,0xea))
style_bluecounter_cont_1_main_main_default.set_border_width(4)
style_bluecounter_cont_1_main_main_default.set_border_opa(255)
style_bluecounter_cont_1_main_main_default.set_pad_left(0)
style_bluecounter_cont_1_main_main_default.set_pad_right(0)
style_bluecounter_cont_1_main_main_default.set_pad_top(0)
style_bluecounter_cont_1_main_main_default.set_pad_bottom(0)

# add style for blueCounter_cont_1
blueCounter_cont_1.add_style(style_bluecounter_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


def blueCounter_minus_clicked_1_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    global counter
    if(counter > 0):
       counter -= 1
       blueCounter_counter.set_text(str(counter))

blueCounter_minus.add_event_cb(lambda e: blueCounter_minus_clicked_1_event_cb(e), lv.EVENT.CLICKED, None)

def blueCounter_minus_long_pressed_repeat_2_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    global counter
    if(counter > 0):
       counter -= 1
       blueCounter_counter.set_text(str(counter))

blueCounter_minus.add_event_cb(lambda e: blueCounter_minus_long_pressed_repeat_2_event_cb(e), lv.EVENT.LONG_PRESSED_REPEAT, None)

counter = 0
def blueCounter_plus_clicked_1_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    global counter
    counter += 1
    blueCounter_counter.set_text(str(counter))

blueCounter_plus.add_event_cb(lambda e: blueCounter_plus_clicked_1_event_cb(e), lv.EVENT.CLICKED, None)

def blueCounter_plus_long_pressed_repeat_2_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    global counter
    counter += 1
    blueCounter_counter.set_text(str(counter))

blueCounter_plus.add_event_cb(lambda e: blueCounter_plus_long_pressed_repeat_2_event_cb(e), lv.EVENT.LONG_PRESSED_REPEAT, None)



# content from custom.py

# Load the default screen
lv.scr_load(blueCounter)

while SDL.check():
    time.sleep_ms(5)
