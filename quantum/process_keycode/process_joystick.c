/* Copyright 2022
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

#include "process_joystick.h"
#include "joystick.h"

bool process_joystick(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_JOYSTICK_BUTTON_MIN ... QK_JOYSTICK_BUTTON_MAX:
            if (record->event.pressed) {
                register_joystick_button(keycode - QK_JOYSTICK_BUTTON_MIN);
            } else {
                unregister_joystick_button(keycode - QK_JOYSTICK_BUTTON_MIN);
            }
            return false;
    }
    return true;
}
