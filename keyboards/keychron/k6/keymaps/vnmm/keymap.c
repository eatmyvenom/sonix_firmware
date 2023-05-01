/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Philip Mourdjis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#ifdef BLUETOOTH_ENABLE
#    include "iton_bt.h"
#    include "outputselect.h"
#endif

#include "vnmm.h"

#define BT_PRO1 BT_PROFILE1
#define BT_PRO2 BT_PROFILE2
#define BT_PRO3 BT_PROFILE3

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_65_ansi(
        QK_GESC, KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,     KC_MINS,     KC_EQL,  KC_BSPC,            RGB_MOD,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,     KC_LBRC,     KC_RBRC, KC_BSLS,            KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN,  KC_QUOT,              KC_ENT,             KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,   KC_SLSH,              KC_RSFT,   KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                      KC_RCTL,  WIN_F,       EXT_F, KC_LEFT,   KC_DOWN, KC_RGHT
    ),

    [WIN_FN] = LAYOUT_65_ansi(
        QK_GESC, KC_BRIU, KC_BRID, _______, _______, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,           _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_SPI, RGB_SAI, RGB_HUI, _______, _______, _______, _______, KC_INS,  KC_DEL,  KC_END,  _______,          KC_END,
        _______, RGB_RMOD,RGB_VAD, RGB_SPD, RGB_SAD, RGB_HUD, _______, _______, _______, _______, _______, _______,          _______,          KC_MPLY,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, KC_MUTE,
        EE_CLR,  _______, _______,                            QK_BOOT,                            KC_RALT, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    [MAC_BASE] = LAYOUT_65_ansi(
        QK_GESC, KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,    KC_MINS,     KC_EQL,  KC_BSPC,            RGB_MOD,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,    KC_LBRC,     KC_RBRC, KC_BSLS,            KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT,              KC_ENT,             KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,              KC_RSFT,   KC_UP,   KC_PGDN,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                      KC_RGUI, MAC_F,       EXT_F,   KC_LEFT,   KC_DOWN, KC_RGHT
    ),

    [MAC_FN] = LAYOUT_65_ansi(
        QK_GESC, KC_BRIU, KC_BRID, _______, _______, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,           _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_SPI, RGB_SAI, RGB_HUI, _______, _______, _______, _______, KC_INS,  KC_DEL,  KC_END,  _______,          KC_END,
        _______, RGB_RMOD,RGB_VAD, RGB_SPD, RGB_SAD, RGB_HUD, _______, _______, _______, _______, _______, _______,          _______,          KC_MPLY,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, KC_MUTE,
        EE_CLR,  _______, _______,                            QK_BOOT,                            KC_RALT, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    [EXTRA_FN] = LAYOUT_65_ansi(
        KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______,
        BT_RESET, BT_PRO1, BT_PRO2, BT_PRO3, _______,  _______, _______, _______, _______, _______, BT_PAIR, _______, _______, _______,          _______,
        _______,  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,           _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        EE_CLR,   _______, _______,                             QK_BOOT,                            _______, _______, _______, _______, _______, _______
    )
};

// clang-format on

void iton_bt_connection_successful() {
    pairing = false;
    set_output(OUTPUT_BLUETOOTH);
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:           // macos/windows togggle
            if (active) { // macos
                layer_move(MAC_BASE);
            } else { // windows
                layer_move(WIN_BASE);
            }
            break;

        case 1:
#ifdef BLUETOOTH_ENABLE
            if (active) {
                set_output(OUTPUT_USB);
                pairing = false;
            } else {
                set_output(OUTPUT_NONE);
            }
#endif
            break;
    }
    return true;
}

void housekeeping_task_user() {
    set_output(auto_detect_output());
}
