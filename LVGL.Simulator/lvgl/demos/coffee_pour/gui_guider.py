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



# create coffeePour
coffeePour = lv.obj()
coffeePour.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_coffeepour_main_main_default
style_coffeepour_main_main_default = lv.style_t()
style_coffeepour_main_main_default.init()
style_coffeepour_main_main_default.set_bg_color(lv.color_make(0x2a,0x26,0x31))
style_coffeepour_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_coffeepour_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_coffeepour_main_main_default.set_bg_opa(255)

# add style for coffeePour
coffeePour.add_style(style_coffeepour_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create coffeePour_animimg_coffee
coffeePour_animimg_coffee = lv.animimg(coffeePour)
coffeePour_animimg_coffee.set_pos(int(192),int(107))
coffeePour_animimg_coffee.set_size(96,85)
coffeePour_animimg_coffee.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
coffeePour_animimg_coffee_animimgs = [None]*31
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-388248852.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_0 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-388248852.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[0] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_0),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_0
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-681651859.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_1 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-681651859.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[1] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_1),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_1
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-975054866.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_2 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-975054866.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[2] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_2),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_2
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1268457873.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_3 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1268457873.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[3] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_3),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_3
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1561860880.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_4 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1561860880.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[4] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_4),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_4
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1855263887.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_5 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1855263887.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[5] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_5),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_5
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp2146300402.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_6 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp2146300402.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[6] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_6),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_6
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1852897395.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_7 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1852897395.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[7] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_7),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_7
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1559494388.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_8 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1559494388.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[8] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_8),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_8
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-600404470.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_9 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-600404470.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[9] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_9),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_9
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-893807477.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_10 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-893807477.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[10] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_10),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_10
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1187210484.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_11 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1187210484.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[11] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_11),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_11
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1480613491.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_12 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1480613491.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[12] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_12),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_12
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1774016498.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_13 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1774016498.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[13] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_13),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_13
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-2067419505.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_14 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-2067419505.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[14] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_14),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_14
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1934144784.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_15 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1934144784.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[15] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_15),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_15
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1640741777.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_16 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1640741777.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[16] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_16),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_16
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1347338770.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_17 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1347338770.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[17] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_17),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_17
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1053935763.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_18 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1053935763.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[18] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_18),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_18
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1105963095.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_19 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1105963095.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[19] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_19),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_19
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1399366102.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_20 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1399366102.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[20] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_20),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_20
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1692769109.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_21 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1692769109.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[21] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_21),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_21
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1986172116.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_22 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1986172116.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[22] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_22),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_22
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp2015392173.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_23 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp2015392173.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[23] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_23),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_23
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1721989166.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_24 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1721989166.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[24] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_24),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_24
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1428586159.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_25 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1428586159.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[25] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_25),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_25
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1135183152.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_26 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1135183152.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[26] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_26),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_26
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp841780145.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_27 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp841780145.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[27] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_27),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_27
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp548377138.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_28 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp548377138.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[28] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_28),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_28
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1611521720.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_29 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1611521720.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[29] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_29),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_29
})
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1904924727.png','rb') as f:
        coffeePour_animimg_coffee_animimg_data_30 = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp-1904924727.png')
    sys.exit()

coffeePour_animimg_coffee_animimgs[30] = lv.img_dsc_t({
  'data_size': len(coffeePour_animimg_coffee_animimg_data_30),
  'header': {'always_zero': 0, 'w': 96, 'h': 85, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_animimg_coffee_animimg_data_30
})

coffeePour_animimg_coffee.set_src(coffeePour_animimg_coffee_animimgs, 31)
coffeePour_animimg_coffee.set_duration(30 * 31)
coffeePour_animimg_coffee.set_repeat_count(3000)
coffeePour_animimg_coffee.start()

# create coffeePour_line_right
coffeePour_line_right = lv.line(coffeePour)
coffeePour_line_right.set_pos(int(330),int(58))
coffeePour_line_right.set_size(122,182)
coffeePour_line_right.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":0, "y":180}, 
                   {"x":0, "y":90}, 
                   {"x":120, "y":90}, 
			  ]
coffeePour_line_right.set_points(line_points, 4)
# create style style_coffeepour_line_right_main_main_default
style_coffeepour_line_right_main_main_default = lv.style_t()
style_coffeepour_line_right_main_main_default.init()
style_coffeepour_line_right_main_main_default.set_line_color(lv.color_make(0x60,0x60,0x60))
style_coffeepour_line_right_main_main_default.set_line_width(1)
style_coffeepour_line_right_main_main_default.set_line_rounded(True)

# add style for coffeePour_line_right
coffeePour_line_right.add_style(style_coffeepour_line_right_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create coffeePour_btn_reset
coffeePour_btn_reset = lv.btn(coffeePour)
coffeePour_btn_reset.set_pos(int(368),int(164))
coffeePour_btn_reset.set_size(73,50)
coffeePour_btn_reset.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
coffeePour_btn_reset_label = lv.label(coffeePour_btn_reset)
coffeePour_btn_reset_label.set_text("RESET")
coffeePour_btn_reset.set_style_pad_all(0, lv.STATE.DEFAULT)
coffeePour_btn_reset_label.align(lv.ALIGN.CENTER,0,0)
# create style style_coffeepour_btn_reset_main_main_default
style_coffeepour_btn_reset_main_main_default = lv.style_t()
style_coffeepour_btn_reset_main_main_default.init()
style_coffeepour_btn_reset_main_main_default.set_radius(25)
style_coffeepour_btn_reset_main_main_default.set_bg_color(lv.color_make(0xf2,0x65,0x65))
style_coffeepour_btn_reset_main_main_default.set_bg_grad_color(lv.color_make(0x15,0x15,0x15))
style_coffeepour_btn_reset_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_coffeepour_btn_reset_main_main_default.set_bg_opa(99)
style_coffeepour_btn_reset_main_main_default.set_border_color(lv.color_make(0xB7,0x87,0x58))
style_coffeepour_btn_reset_main_main_default.set_border_width(0)
style_coffeepour_btn_reset_main_main_default.set_border_opa(255)
style_coffeepour_btn_reset_main_main_default.set_text_color(lv.color_make(0xd1,0xc1,0xb2))
try:
    style_coffeepour_btn_reset_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_coffeepour_btn_reset_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_coffeepour_btn_reset_main_main_default.set_text_font(lv.font_montserrat_16)
style_coffeepour_btn_reset_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for coffeePour_btn_reset
coffeePour_btn_reset.add_style(style_coffeepour_btn_reset_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create coffeePour_btn_continue
coffeePour_btn_continue = lv.btn(coffeePour)
coffeePour_btn_continue.set_pos(int(358),int(82))
coffeePour_btn_continue.set_size(100,50)
coffeePour_btn_continue.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
coffeePour_btn_continue_label = lv.label(coffeePour_btn_continue)
coffeePour_btn_continue_label.set_text("CONTINUE")
coffeePour_btn_continue.set_style_pad_all(0, lv.STATE.DEFAULT)
coffeePour_btn_continue_label.align(lv.ALIGN.CENTER,0,0)
# create style style_coffeepour_btn_continue_main_main_default
style_coffeepour_btn_continue_main_main_default = lv.style_t()
style_coffeepour_btn_continue_main_main_default.init()
style_coffeepour_btn_continue_main_main_default.set_radius(50)
style_coffeepour_btn_continue_main_main_default.set_bg_color(lv.color_make(0xf2,0x65,0x65))
style_coffeepour_btn_continue_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_coffeepour_btn_continue_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_coffeepour_btn_continue_main_main_default.set_bg_opa(97)
style_coffeepour_btn_continue_main_main_default.set_border_color(lv.color_make(0xd1,0xc1,0xb2))
style_coffeepour_btn_continue_main_main_default.set_border_width(0)
style_coffeepour_btn_continue_main_main_default.set_border_opa(255)
style_coffeepour_btn_continue_main_main_default.set_text_color(lv.color_make(0xd1,0xc1,0xb2))
try:
    style_coffeepour_btn_continue_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_coffeepour_btn_continue_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_coffeepour_btn_continue_main_main_default.set_text_font(lv.font_montserrat_16)
style_coffeepour_btn_continue_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for coffeePour_btn_continue
coffeePour_btn_continue.add_style(style_coffeepour_btn_continue_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create coffeePour_img_logo
coffeePour_img_logo = lv.img(coffeePour)
coffeePour_img_logo.set_pos(int(19),int(12))
coffeePour_img_logo.set_size(60,20)
coffeePour_img_logo.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
coffeePour_img_logo.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1617545546.png','rb') as f:
        coffeePour_img_logo_img_data = f.read()
except:
    print('Could not open D:\\NXP\\GUI-Guider-Projects\\coffee_pour_animation\\generated\\mPythonImages\\mp1617545546.png')
    sys.exit()

coffeePour_img_logo_img = lv.img_dsc_t({
  'data_size': len(coffeePour_img_logo_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': coffeePour_img_logo_img_data
})

coffeePour_img_logo.set_src(coffeePour_img_logo_img)
coffeePour_img_logo.set_pivot(50,50)
coffeePour_img_logo.set_angle(0)
# create style style_coffeepour_img_logo_main_main_default
style_coffeepour_img_logo_main_main_default = lv.style_t()
style_coffeepour_img_logo_main_main_default.init()
style_coffeepour_img_logo_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_coffeepour_img_logo_main_main_default.set_img_recolor_opa(0)
style_coffeepour_img_logo_main_main_default.set_img_opa(255)

# add style for coffeePour_img_logo
coffeePour_img_logo.add_style(style_coffeepour_img_logo_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create coffeePour_line_left
coffeePour_line_left = lv.line(coffeePour)
coffeePour_line_left.set_pos(int(19),int(58))
coffeePour_line_left.set_size(122,182)
coffeePour_line_left.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":120, "y":0}, 
                   {"x":120, "y":180}, 
                   {"x":120, "y":90}, 
                   {"x":0, "y":90}, 
			  ]
coffeePour_line_left.set_points(line_points, 4)
# create style style_coffeepour_line_left_main_main_default
style_coffeepour_line_left_main_main_default = lv.style_t()
style_coffeepour_line_left_main_main_default.init()
style_coffeepour_line_left_main_main_default.set_line_color(lv.color_make(0x60,0x60,0x60))
style_coffeepour_line_left_main_main_default.set_line_width(1)
style_coffeepour_line_left_main_main_default.set_line_rounded(True)

# add style for coffeePour_line_left
coffeePour_line_left.add_style(style_coffeepour_line_left_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create coffeePour_btn_stop
coffeePour_btn_stop = lv.btn(coffeePour)
coffeePour_btn_stop.set_pos(int(40),int(82))
coffeePour_btn_stop.set_size(80,50)
coffeePour_btn_stop.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
coffeePour_btn_stop_label = lv.label(coffeePour_btn_stop)
coffeePour_btn_stop_label.set_text("STOP")
coffeePour_btn_stop.set_style_pad_all(0, lv.STATE.DEFAULT)
coffeePour_btn_stop_label.align(lv.ALIGN.CENTER,0,0)
# create style style_coffeepour_btn_stop_main_main_default
style_coffeepour_btn_stop_main_main_default = lv.style_t()
style_coffeepour_btn_stop_main_main_default.init()
style_coffeepour_btn_stop_main_main_default.set_radius(25)
style_coffeepour_btn_stop_main_main_default.set_bg_color(lv.color_make(0xf2,0x65,0x65))
style_coffeepour_btn_stop_main_main_default.set_bg_grad_color(lv.color_make(0x15,0x15,0x15))
style_coffeepour_btn_stop_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_coffeepour_btn_stop_main_main_default.set_bg_opa(99)
style_coffeepour_btn_stop_main_main_default.set_border_color(lv.color_make(0xB7,0x87,0x58))
style_coffeepour_btn_stop_main_main_default.set_border_width(0)
style_coffeepour_btn_stop_main_main_default.set_border_opa(255)
style_coffeepour_btn_stop_main_main_default.set_text_color(lv.color_make(0xd1,0xc1,0xb2))
try:
    style_coffeepour_btn_stop_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_coffeepour_btn_stop_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_coffeepour_btn_stop_main_main_default.set_text_font(lv.font_montserrat_16)
style_coffeepour_btn_stop_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for coffeePour_btn_stop
coffeePour_btn_stop.add_style(style_coffeepour_btn_stop_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create coffeePour_btn_full
coffeePour_btn_full = lv.btn(coffeePour)
coffeePour_btn_full.set_pos(int(40),int(168))
coffeePour_btn_full.set_size(80,50)
coffeePour_btn_full.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
coffeePour_btn_full_label = lv.label(coffeePour_btn_full)
coffeePour_btn_full_label.set_text("FULL")
coffeePour_btn_full.set_style_pad_all(0, lv.STATE.DEFAULT)
coffeePour_btn_full_label.align(lv.ALIGN.CENTER,0,0)
# create style style_coffeepour_btn_full_main_main_default
style_coffeepour_btn_full_main_main_default = lv.style_t()
style_coffeepour_btn_full_main_main_default.init()
style_coffeepour_btn_full_main_main_default.set_radius(50)
style_coffeepour_btn_full_main_main_default.set_bg_color(lv.color_make(0xf2,0x65,0x65))
style_coffeepour_btn_full_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_coffeepour_btn_full_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_coffeepour_btn_full_main_main_default.set_bg_opa(99)
style_coffeepour_btn_full_main_main_default.set_border_color(lv.color_make(0xd1,0xc1,0xb2))
style_coffeepour_btn_full_main_main_default.set_border_width(0)
style_coffeepour_btn_full_main_main_default.set_border_opa(255)
style_coffeepour_btn_full_main_main_default.set_text_color(lv.color_make(0xd1,0xc1,0xb2))
try:
    style_coffeepour_btn_full_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_coffeepour_btn_full_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_coffeepour_btn_full_main_main_default.set_text_font(lv.font_montserrat_16)
style_coffeepour_btn_full_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for coffeePour_btn_full
coffeePour_btn_full.add_style(style_coffeepour_btn_full_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create coffeePour_label_1
coffeePour_label_1 = lv.label(coffeePour)
coffeePour_label_1.set_pos(int(132),int(39))
coffeePour_label_1.set_size(217,29)
coffeePour_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
coffeePour_label_1.set_text("Coffee Latte")
coffeePour_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_coffeepour_label_1_main_main_default
style_coffeepour_label_1_main_main_default = lv.style_t()
style_coffeepour_label_1_main_main_default.init()
style_coffeepour_label_1_main_main_default.set_radius(0)
style_coffeepour_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_coffeepour_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_coffeepour_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_coffeepour_label_1_main_main_default.set_bg_opa(0)
style_coffeepour_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_coffeepour_label_1_main_main_default.set_text_font(lv.font_arial_18)
except AttributeError:
    try:
        style_coffeepour_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_coffeepour_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_coffeepour_label_1_main_main_default.set_text_letter_space(2)
style_coffeepour_label_1_main_main_default.set_text_line_space(0)
style_coffeepour_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_coffeepour_label_1_main_main_default.set_pad_left(0)
style_coffeepour_label_1_main_main_default.set_pad_right(0)
style_coffeepour_label_1_main_main_default.set_pad_top(8)
style_coffeepour_label_1_main_main_default.set_pad_bottom(0)

# add style for coffeePour_label_1
coffeePour_label_1.add_style(style_coffeepour_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def coffeePour_btn_reset_clicked_1_event_cb(e,coffeePour_animimg_coffee):
    src = e.get_target()
    code = e.get_code()
    coffeePour_animimg_coffee.set_src(coffeePour_animimg_coffee_animimgs, 1)
    coffeePour_animimg_coffee.set_duration(30 * 1)
    coffeePour_animimg_coffee.set_repeat_count(30)
    coffeePour_animimg_coffee.start()

coffeePour_btn_reset.add_event_cb(lambda e: coffeePour_btn_reset_clicked_1_event_cb(e,coffeePour_animimg_coffee), lv.EVENT.CLICKED, None)


def coffeePour_btn_continue_clicked_1_event_cb(e,coffeePour_animimg_coffee):
    src = e.get_target()
    code = e.get_code()
    coffeePour_animimg_coffee.set_src(coffeePour_animimg_coffee_animimgs, 31)
    coffeePour_animimg_coffee.set_duration(30 * 31)
    coffeePour_animimg_coffee.set_repeat_count(1)
    coffeePour_animimg_coffee.start()

coffeePour_btn_continue.add_event_cb(lambda e: coffeePour_btn_continue_clicked_1_event_cb(e,coffeePour_animimg_coffee), lv.EVENT.CLICKED, None)


def coffeePour_btn_full_clicked_1_event_cb(e,coffeePour_animimg_coffee):
    src = e.get_target()
    code = e.get_code()
    coffeePour_animimg_coffee.set_src(coffeePour_animimg_coffee_animimgs, 31)
    coffeePour_animimg_coffee.set_duration(30 * 31)
    coffeePour_animimg_coffee.set_repeat_count(3000)
    coffeePour_animimg_coffee.start()

coffeePour_btn_full.add_event_cb(lambda e: coffeePour_btn_full_clicked_1_event_cb(e,coffeePour_animimg_coffee), lv.EVENT.CLICKED, None)


def coffeePour_btn_stop_clicked_1_event_cb(e,coffeePour_animimg_coffee):
    src = e.get_target()
    code = e.get_code()
    if(lv.anim_get(coffeePour_animimg_coffee, None)):
        currentValue = lv.anim_get(coffeePour_animimg_coffee, None).current_value
        lv.anim_del(coffeePour_animimg_coffee, None)

coffeePour_btn_stop.add_event_cb(lambda e: coffeePour_btn_stop_clicked_1_event_cb(e,coffeePour_animimg_coffee), lv.EVENT.CLICKED, None)


def coffeePour_clicked_1_event_cb(e,coffeePour_animimg_coffee):
    src = e.get_target()
    code = e.get_code()
    coffeePour_animimg_coffee.set_src(coffeePour_animimg_coffee_animimgs, 31)
    coffeePour_animimg_coffee.set_duration(30 * 31)
    coffeePour_animimg_coffee.set_repeat_count(3000)
    coffeePour_animimg_coffee.start()

coffeePour.add_event_cb(lambda e: coffeePour_clicked_1_event_cb(e,coffeePour_animimg_coffee), lv.EVENT.CLICKED, None)



# content from custom.py

# Load the default screen
lv.scr_load(coffeePour)

while SDL.check():
    time.sleep_ms(5)
