/*
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

#include "vnmm.h"
#include "iton_bt.h"

void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

#ifdef BLUETOOTH_ENABLE
void iton_bt_entered_pairing() {
    pairing = true;
}

void iton_bt_enters_connection_state() {
    pairing = false;
}

void iton_bt_battery_level(uint8_t data) {
    switch (data) {
        case batt_above_70:
            power_above_70      = true;
            power_between_30_70 = false;
            power_below_30      = false;
            break;
        case batt_between_30_70:
            power_above_70      = false;
            power_between_30_70 = true;
            power_below_30      = false;
            break;
        case batt_below_30:
            power_above_70      = false;
            power_between_30_70 = false;
            power_below_30      = true;
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case BT_PROFILE1:
            case BT_PROFILE2:
            case BT_PROFILE3:
                current_profile_indicator = keycode;
            default:
                break;
        }
    }
    return true;
}
#endif
