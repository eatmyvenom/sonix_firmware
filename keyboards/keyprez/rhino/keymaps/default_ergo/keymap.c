/* Copyright 2021 Christian Sandven
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _LOWER,
    _RAISE
};

#define LOWER MO(_LOWER)
#define FN MO(_FN)
#define TAB_CTL MT(MOD_LCTL, KC_TAB)
#define SPC_RAISE LT(_RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |                                                                                                                     KC_MUTE |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | GESC   | Q      | W      | E      | R      | T      |        |        | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+   [    +    ]   +--------+--------+--------+-----------------+--------|
     * | TAB    | A      | S      | D      | F      | G      |--------|--------| H      | J      | K      | L      | ;      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+  HOME  +  END   +--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      |        |        | N      | M      | ,      | .      | /      | ENTER  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        | LGUI   | FN     | LALT   | LOWER  |      SPACE      |      SPACE      | LEFT   | UP     | DOWN   | RIGHT  |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_ergo_2x2u(
                                                                                                                             KC_MUTE,
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        TAB_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_END,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                 KC_LGUI, FN,      KC_LALT, LOWER,       KC_SPC,          SPC_RAISE,     KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    /* FN Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |                                                                                                                     KC_APP  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | `      | F1     | F2     | F3     | F4     | F5     |        |        | F8     | F9     | F10    | F11    | F12    |        |
     * |--------+--------+--------+--------+--------+--------+   F6   +   F7  +--------+--------+--------+-----------------+---------|
     * |        | F7     | F8     | F9     | F10    | F11    |--------|--------|        |        |        |        |        | PRT SC |
     * |--------+--------+--------+--------+--------+--------+  F12   +        +--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        | QK_BOOT  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        | MU TOG | MU MOD |        |        |                 |                 | MUTE   | VOL UP |VOL DOWN| PAUSE  |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ergo_2x2u(
                                                                                                                             KC_APP,
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, KC_PSCR,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, QK_BOOT,
                 MU_TOG,  MU_MOD,  _______, _______,     _______,           _______,     KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY
    ),

    /* LOWER Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |                                                                                                                     KC_APP  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | `      | 1      | 2      | 3      | 4      | 5      |        |        | 8      | 9      | 0      | -      | =      | |      |
     * |--------+--------+--------+--------+--------+--------+   6    +    7   +--------+--------+--------+-----------------+--------|
     * |        | F1     | F2     | F3     | F4     | F5     |--------|--------|        |        |        |        | DEL    | INSERT |
     * |--------+--------+--------+--------+--------+--------+  F12   +        +--------+--------+--------------------------+--------|
     * |        | F7     | F8     | F9     | F10    | F11    |        |        |        |        |        |        | \      |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |                 |                 | HOME   | PG UP  | PG DN  | END    |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ergo_2x2u(
                                                                                                                            KC_APP,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PIPE,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F12, _______, _______, _______, _______, _______, KC_DEL,  KC_INS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                   _______, _______, _______, _______, KC_BSLS, _______,
                 _______, _______, _______, _______,     _______,           _______,    KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),

    /* RAISE Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |                                                                                                                     KC_APP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | ~      | !      | @      | #      | $      | %      |        |        | *      | (      | )      | -      | =      | |      |
     * |--------+--------+--------+--------+--------+--------+   ^    +    &   +--------+--------+--------+-----------------+--------|
     * |        | F1     | F2     | F3     | F4     | F5     |--------|--------| =      | {      | }      |        | DEL    | INSERT |
     * |--------+--------+--------+--------+--------+--------+  F12   +   _    +--------+--------+--------------------------+--------|
     * |        | F7     | F8     | F9     | F10    | F11    |        |        | ISO ~  | ISO |  |        |        | \      |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |                 |                 |        |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ergo_2x2u(
                                                                                                                                      KC_APP,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR,   KC_ASTR,    KC_LPRN,    KC_RPRN, KC_MINS, KC_EQL,  KC_PIPE,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F12,   KC_UNDS,   KC_PLUS,    KC_LCBR,    KC_RCBR, _______, KC_DEL,  KC_INS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                       S(KC_NUHS), S(KC_NUBS), _______, _______, _______, KC_BSLS,
                 _______, _______, _______, _______,     _______,            _______,          _______, _______, _______, _______
    ),
};

const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_ergo_2x2u(
    0,
    0, 0, 0, 0, 0, 0, 10, 0, 0,  0,  0,  0,  0,  0,
    0, 1, 3, 0, 6, 8, 9, 11, 13, 15, 0,  18, 20, 0,
    0, 0, 2, 4, 5, 7,        12, 14, 16, 17, 19, 0,
       0, 0, 0, 0,    0,  0,     0,  0,  0,  0
);
