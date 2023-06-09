#include QMK_KEYBOARD_H
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  LAYOUT_all(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,    \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
    KC_LSFT, KC_SLSH, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_NO,    KC_RSFT, KC_UP,    TG(2),     \
    KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, MO(1),    KC_LEFT, KC_DOWN,  KC_RIGHT
  ),

  // 1: Function Layer
  LAYOUT_all(
    KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  BL_DEC,   BL_INC,  KC_F13,   KC_F14,    \
    KC_NO,    KC_WH_U, KC_UP,   KC_WH_D, KC_BSPC,KC_HOME,KC_CALC,KC_NO,  KC_INS, KC_NO,   KC_PSCR, KC_SCRL,  KC_PAUS,           KC_DEL,    \
    KC_NO,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_DEL, KC_END, KC_PGDN,KC_NO,  KC_NO,  KC_NO,   KC_HOME, KC_PGUP,  KC_NO,             KC_ENT,    \
    KC_LSFT,  KC_NO,   KC_NO,   KC_APP,  BL_STEP,KC_NO,  KC_NO,  KC_VOLD,KC_VOLU,KC_MUTE, KC_END,  KC_PGDN,  KC_RSFT, KC_PGUP,  TG(2),     \
    KC_LCTL,  KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, MO(1),    KC_HOME, KC_PGDN,  KC_END
  ),

  // 2: Cool Layer
  LAYOUT_all(
    QK_BOOT, BL_DEC,   BL_INC,  BL_ON,   BL_OFF, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_MODE_PLAIN, KC_TRNS,    \
    KC_NO,    KC_WH_U, KC_UP,   KC_WH_D, KC_BSPC,KC_HOME,KC_CALC,KC_NO,  KC_INS, KC_NO,   KC_PSCR, KC_SCRL,  KC_PAUS,           KC_DEL,       \
    KC_NO,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_DEL, KC_END, KC_PGDN,KC_NO,  KC_NO,  KC_NO,   KC_HOME, KC_PGUP,  KC_NO,             KC_ENT,       \
    KC_LSFT,  KC_NO,   KC_NO,   KC_APP,  BL_STEP,KC_NO,  KC_NO,  KC_VOLD,KC_VOLU,KC_MUTE, KC_END,  KC_PGDN,  KC_RSFT, KC_PGUP,  TG(2),       \
    KC_LCTL,  KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, MO(1),    KC_HOME, KC_PGDN,  KC_END
  )
};

bool edit = false;
uint32_t mode;
uint16_t hue;
uint8_t sat;
uint8_t val;

layer_state_t layer_state_set_user(layer_state_t state) {

  if (state == 0 && edit == true) {
    mode = rgblight_get_mode();
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
    edit = false;
  }

  switch (get_highest_layer(state)) {
    case 1:
      rgblight_mode(1);
      rgblight_setrgb(0xD3, 0x7F, 0xED);
      break;
    case 2:
      rgblight_mode(1);
      rgblight_setrgb(0xFF, 0x00, 0x00);
      edit = true;
      break;
    default:
      rgblight_mode(mode);
      rgblight_sethsv(hue, sat, val);
      break;
  }
  return state;
}
