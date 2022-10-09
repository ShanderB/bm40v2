/* Copyright 2020 tominabox1
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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUMP
};

uint8_t mod_state;

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    CEDILHA,            // ç direct key
    AO,                 // ã direct key

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |     Backspace   |
 * |------+------+------+------+------+------+------+------+------+------+------+-----------------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      Enter      |
 * |------+------+------+------+------+------+------+------+------+------+------+-----------------|
 * | LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      Del       |
 * |------+------+------+------+------+------+------+------+------+------+------+-----------------|
 * | LCtrl |  |   GUI   | Enter  |   LAlt    |  Space  |  Lower  | Up | Down |  Left  |   Right   |
 * `----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
      KC_ESC  , KC_Q   , KC_W , KC_E   , KC_R , KC_T   , KC_Y  , KC_U   , KC_I    , KC_O    , KC_P    , KC_BSPC,
      KC_TAB  , KC_A   , KC_S , KC_D   , KC_F , KC_G   , KC_H  , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_ENT,
      KC_LSFT , KC_Z   , KC_X , KC_C   , KC_V , KC_B   , KC_N  , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_DEL,
      KC_LCTL , KC_NO  , KC_LGUI, KC_NO , LALT_T(KC_ENT), LT(2,KC_SPC) , MO(1) , KC_UP  , KC_DOWN , KC_LEFT , KC_RGHT
),

/* Lower (Layer 1)
 * ,---------------------------------------------------------------------------------------------------.
 * |   '   |   (  |  )   |   [{   |   }]   |    |     |    |     |     |              |      ~ `   |
 * |------+------+------+------+------+------+------+------+------+------+---------------+-------------|
 * |      |      |          |    |   |    |    |   |     |    |            |       |
 * |------+------+------+------+------+------+------+------+------+------+---------------+-------------|
 * |LShift|    |    |    |   |   |   |S(NUHS)|S(NUBS)|Home|       End                   |              |
 * |------+------+------+------+------+------+------+------+------+------+---------------+-------------|
 * |                                                     Next  |Vol - |   Vol +       |      Play      |
 * `---------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(

      KC_QUOT , KC_LPRN , KC_RPRN , KC_LBRC ,KC_RBRC , KC_NO , KC_NO , KC_NO      , KC_NO      , KC_NO   ,KC_NO  , KC_GRV,
      KC_NO   ,  KC_NO  , KC_NO   ,  KC_NO  , KC_NO  , KC_NO , KC_NO , KC_NO      , KC_NO      , KC_NO   , KC_NO , KC_NO,
      KC_LSFT , KC_NO   , KC_NO   , KC_NO   , KC_NO  , KC_NO , KC_NO , S(KC_NUHS) , S(KC_NUBS) , KC_HOME , KC_END, KC_NO,
      KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO  , MO(3) , KC_NO , KC_MNXT      , KC_VOLD      ,  KC_VOLU , KC_MPLY

),

/* Raise (Layer 2)
 * ,---------------------------------------------------------------------------------------------------.
 * |      |   1!  |   2@  |   3#  |   4$  |   5%  |   6^  |   7&  |   8*  |   9(  |   0) |  Backspace  |
 * |------+------+------+------+------+------+------+------+------+------+---------------+-------------|
 * |  Ç     | F2   |  F4  |   F5   |    |    |       |   -_ |   += |    |             |    \ |         |
 * |------+------+------+------+------+------+------+------+------+------+---------------+-------------|
 * |LShift|   F6   |   F12   |      |      |      |       | NUHS | NUBS | PgUp  |   PgDn       |       |
 * |------+------+------+------+------+------+------+------+------+------+---------------+-------------|
 * |      |      |      |      |      |             |      |      |     |               |              |
 * `---------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
      KC_NO  , KC_1  , KC_2  , KC_3  , KC_4   , KC_5   , KC_6   , KC_7    , KC_8    , KC_9     ,KC_0    , KC_BSPC,
      CEDILHA  , KC_F2 , KC_F4 , KC_F5 , KC_NO  , KC_NO  , KC_NO  , KC_MINS , KC_EQL  ,  KC_NO   ,KC_NO   , KC_BSLS,
      KC_LSFT, KC_F6 ,  KC_F12, KC_NO, KC_NO  , KC_NO  , KC_NO  , KC_NUHS , KC_NUBS , KC_PGUP  ,KC_PGDN , KC_NO,
      KC_NO  , KC_NO , KC_NO , KC_NO , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO ,  KC_NO , KC_NO

),

/* Numb (Layer 3)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset |      |      |      |      |      |      |      |      |      |     |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |                                                                                   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |                                                                                   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |                                                                                   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMP] = LAYOUT_ortho_4x12_1x2uC(

      KC_NO,RESET,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
      KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
      KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
      KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO


)

};

//Per key lights
void rgb_matrix_indicators_user(void) {
#ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) { //prevent keyboard turn on all the leds that i dont want
                switch (i) {
                    case 0 ... 46:
                        rgb_matrix_set_color(i, 0, 0, 0);
                        break;
                }
            }
            rgb_matrix_set_color(42, 255, 33, 0);  //Layer 1 button
            rgb_matrix_set_color(39, 255, 33, 0);  //Enter button

        break;

        case _RAISE:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                switch (i) {
                    case 0:
                        rgb_matrix_set_color(i, 0, 0, 0);
                        break;
                    case 1 ... 11:
                        rgb_matrix_set_color(i, 255, 255, 255); //Numbers in Layer 2
                        break;
                    case 12:
                        rgb_matrix_set_color(i, 255, 33, 0); //Cedilha in Layer 2
                        break;
                    case 13 ... 46:
                        rgb_matrix_set_color(i, 0, 0, 0);
                        break;
                }
            }
            break;

        case _LOWER:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) { //prevent keyboard turn on all the leds that i dont want
                switch (i) {
                    case 0 ... 46:
                        rgb_matrix_set_color(i, 0, 0, 0);
                        break;
                }
            }
            rgb_matrix_set_color(1, 255, 33, 0); //Coding keys
            rgb_matrix_set_color(2, 255, 33, 0); //Coding keys
            rgb_matrix_set_color(3, 255, 33, 0); //Coding keys
            rgb_matrix_set_color(4, 255, 33, 0); //Coding keys
            rgb_matrix_set_color(41, 255, 0, 0);   //Layer 3

        break;

        case _NUMP:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) { //prevent keyboard turn on all the leds that i dont want
                switch (i) {
                    case 0 ... 46:
                        rgb_matrix_set_color(i, 0, 0, 0);
                        break;
                }
            }
            rgb_matrix_set_color(1, 255, 0, 0); //Reset key
        break;

    }
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // ç key
        case CEDILHA:
            if (record->event.pressed) {
                register_code(KC_QUOT);
                unregister_code(KC_QUOT);
                register_code(KC_C);
                unregister_code(KC_C);
            }
            break;
            return false;

        // ã key
       /*  case AO:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_GRV);
                unregister_code(KC_LSFT);
                unregister_code(KC_GRV);
                register_code(KC_A);
                unregister_code(KC_A);
            }
            break;
            return false; */
    }
    return true;
}


// layer_state_t layer_state_set_user(layer_state_t state) {         Layer raise and lower same time
//   return update_tri_layer_state(state, _LOWER, _RAISE, _NUMP);
// }
