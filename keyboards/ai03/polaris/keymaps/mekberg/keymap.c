/* Copyright 2019 Ryota Goto
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAV,
    _FN
};

#define MY_LOCK C(LCMD(KC_L))      // Mac: Custom lock hotkey in BTT (when Alt/Command have been swapped in macOS)

/*
KBD6x ANSI physical layout
1u == 8chars
    ┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
    |        |        |        |        |        |        |        |        |        |        |        |        |        |        |       |
    |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
    |    1,5u    |        |        |        |        |        |        |        |        |        |        |        |        |     1,5u   |
    |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
    |     1,75u    |        |        |        |        |        |        |        |        |        |        |        |        1,25u      |
    |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
    |       2,25u      |        |        |        |        |        |        |        |        |        |        |     1,75u     |        |
    └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
                 |        |   1,25u    |                                                        |   1,25u    |        |
                 └────────────────────────────────────────────────────────────────────────────────────────────────────┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_tsangan_hhkb(
//  ┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
//  |        |        |        |        |        |        |        |        |        |        |        |        |        |        |       |
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_NUBS, KC_RBRC,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |    1,5u    |        |        |        |        |        |        |        |        |        |        |        |        |     1,5u   |
  LT(_NAV,KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,   KC_LBRC, KC_NUHS,   KC_BSPC,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |     1,75u    |        |        |        |        |        |        |        |        |        |        |        |        1,25u      |
         KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      KC_ENT,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |   1,25u          |        |        |        |        |        |        |        |        |        |        |     1,75u     |        |
           KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,     MO(_FN),
//  └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
//                   |        |   1,25u    |                                                        |   1,25u    |        |
         XXXXXXX,     KC_LGUI,   KC_LALT,                         KC_SPACE,                            KC_RALT,   KC_RGUI,      XXXXXXX
//                   └────────────────────────────────────────────────────────────────────────────────────────────────────┘
  ),
  [_NAV] = LAYOUT_60_tsangan_hhkb(
//  ┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
//  |        |        |        |        |        |        |        |        |        |        |        |        |        |        |       |
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_INS, KC_BSPC,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |    1,5u    |        |        |        |        |        |        |        |        |        |        |        |        |     1,5u   |
      _______,    _______, _______, _______, _______, _______, KC_END,  KC_PGDN, KC_UP,   KC_PGUP, KC_HOME, _______, _______,    KC_DEL,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |     1,75u    |        |        |        |        |        |        |        |        |        |        |        |        1,25u      |
       _______,     _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,       _______,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |   1,25u          |        |        |        |        |        |        |        |        |        |        |     1,75u     |        |
          _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,     _______,
//  └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
//                   |        |   1,25u    |                                                        |   1,25u    |        |
         XXXXXXX,     _______,  _______,                         _______,                             _______,    _______,      XXXXXXX
//                   └────────────────────────────────────────────────────────────────────────────────────────────────────┘
  ),
  [_FN] = LAYOUT_60_tsangan_hhkb(
//  ┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
//  |        |        |        |        |        |        |        |        |        |        |        |        |        |        |       |
      QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |    1,5u    |        |        |        |        |        |        |        |        |        |        |        |        |     1,5u   |
      _______,   _______,  _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______,   _______,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |     1,75u    |        |        |        |        |        |        |        |        |        |        |        |        1,25u      |
        KC_RCTL,    KC_VOLD, KC_VOLU, KC_MUTE, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______,       MY_LOCK,
//  |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
//  |   1,25u          |        |        |        |        |        |        |        |        |        |        |     1,75u     |        |
          _______,      BL_TOGG,  BL_INC,  BL_DEC, BL_STEP, _______, _______, _______, KC_MRWD, KC_MFFD, _______,    _______,     _______,
//  └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
//                   |        |   1,25u    |                                                        |   1,25u    |        |
         XXXXXXX,     _______,  _______,                          KC_MPLY,                            _______,    _______,      XXXXXXX
//                   └────────────────────────────────────────────────────────────────────────────────────────────────────┘
  ),
};
