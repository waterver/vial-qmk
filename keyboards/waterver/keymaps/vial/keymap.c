#include QMK_KEYBOARD_H

#define _KEY 0
#define _KATEX 1
#define _MEDIA 2

// enum custom_keycodes {
//     lambda = SAFE_RANGE,
//     mu,
//     ,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_KEY] = LAYOUT(
        KC_7,   KC_8,   KC_9,   KC_KP_ASTERISK, TO(1),
        KC_4,   KC_5,   KC_6,   KC_KP_MINUS,
        KC_1,   KC_2,   KC_3,  KC_KP_PLUS,  KC_MEDIA_PLAY_PAUSE,
        KC_0, KC_KP_DOT,KC_KP_SLASH,KC_ENTER
    )

    // [_KATEX] = LAYOUT(
    //     ,   KC_8,   KC_9,   , TO(0),
    //     KC_4,   KC_5,   KC_6,   KC_KP_MINUS,
    //     KC_1,   KC_2,   KC_3,   KC_KP_PLUS,     KC_MEDIA_PLAY_PAUSE,
    //     KC_0, KC_KP_DOT,KC_KP_SLASH,MO(2)
    // )

};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
   [_KEY] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    
};
#endif


// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {

//     case _KATEX:
//         rgblight_setrgb (0x28,  0xC8, 0x42);
//         break;
//     case _MEDIA:
//         rgblight_setrgb (0xFA,  0x84, 0x2B);
//         break;
//     default: 
//         break;
//     }
//   return state;
// }


#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0, 1, 2, 3,  NO_LED},
  {   7, 6, 5, 4 },
  {   8, 9,10,11,  NO_LED},
  {  15,14,13,12 }
}, {
  // 位置
  { 0, 0 }, { 56, 0  }, { 112,  0 }, { 168,  0 }, { 168 ,  16 }, { 112 ,  16 }, { 56 ,  16 }, { 0 ,  16 }, {0 ,  32}, { 56, 32  }, { 112,  32 }, { 168,  32 }, { 172 ,  58 }, { 112 ,  48 }, { 56 ,  48 }, { 0 ,  48 }
}, {
  // 分组
  1, 1,1, 1, 1, 1,1, 1,1, 1, 1, 1,1, 1,1, 1
} };

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _KATEX:
            RGB_MATRIX_INDICATOR_SET_COLOR(12,0x28,  0xC8, 0x42);
            break;
        case _MEDIA:
            RGB_MATRIX_INDICATOR_SET_COLOR(12,0xFA,  0x84, 0x2B);
            break;
        default:
            break;
    }
}

#endif


