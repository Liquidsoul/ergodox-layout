#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_french_osx.h"

#ifdef SUBPROJECT_infinity
#include "visualizer/lcd_backlight.h"
#endif

#define QWERTY 0 // qwerty keys
#define GAME 1 // games mapping
#define SYMB 2 // qwerty symbols
#define MDIA 3 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap: Basic QWERTY layer
*********************************************************************************************************************
*                                                                                                                   *
* .--------+------+------+------+------+------+------.         .------+------+------+------+------+------+--------. *
* |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |         | RIGHT|   6  |   7  |   8  |   9  |   0  |    -   | *
* +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
* | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |         |  L1  |   Y  |   U  |   I  |   O  |   P  |    \   | *
* +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
* | Esc    |   A  |   S  |   D  |   F  |   G  +------+         +------+   H  |   J  |   K  |   L  |   ;  | '/LGui | *
* +--------+------+------+------+------+------+ Hyper|         | Hyper+------+------+------+------+------+--------+ *
* | LShift |   Z  |   X  |   C  |   V  |   B  |      |         |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift | *
* '-+------+------+------+------+------+------+------'         '------+------+------+------+------+------+------+-' *
*   | ` /L1|'/Ctrl| Alt  | LGui |   ç  |                                     |dead ´|dead `|   [  |] / L2|  ~L1 |   *
*   '------+------+------+------+------'                                     '------+------+------+------+------'   *
*                                       .------+------.       .------+--------.                                     *
*                                       |  Alt | LGui |       |  Alt |Ctrl/Esc|                                     *
*                                .------+------+------+       +------+--------+------.                              *
*                                |      |      | ^L1  |       | LGui |        |      |                              *
*                                | BkSp | Del  +------+       +------+  Enter | Space|                              *
*                                |      |      | Ctrl |       | ^L2  |        |      |                              *
*                                '------+------+------'       '------+--------+------'                              *
*                                                                                                                   *
*********************************************************************************************************************
*/
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[QWERTY] = KEYMAP(
        // left hand
        KC_EQL,          KC_1,           KC_2,    KC_3,    KC_4,       KC_5,    KC_LEFT,
        KC_TAB,          KC_Q,           KC_W,    KC_E,    KC_R,       KC_T,    TG(SYMB),
        KC_ESC,          KC_A,           KC_S,    KC_D,    KC_F,       KC_G,
        KC_LSFT,         KC_Z,           KC_X,    KC_C,    KC_V,       KC_B,    ALL_T(KC_NO),
        LT(SYMB,KC_GRV), CTL_T(KC_QUOT), KC_LALT, KC_LGUI, LALT(KC_C),
                     KC_LALT, KC_LGUI,
                              MO(SYMB),
            KC_BSPC, KC_DELT, KC_LCTL,

        // right hand
        KC_RGHT,      KC_6, KC_7,       KC_8,         KC_9,    KC_0,              KC_MINS,
        TG(SYMB),     KC_Y, KC_U,       KC_I,         KC_O,    KC_P,              KC_BSLS,
                      KC_H, KC_J,       KC_K,         KC_L,    KC_SCLN,           GUI_T(KC_QUOT),
        ALL_T(KC_NO), KC_N, KC_M,       KC_COMM,      KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
                            LALT(KC_E), LALT(KC_GRV), KC_LBRC, LT(MDIA, KC_RBRC), MO(SYMB),
            KC_LALT,  KC_RCTL,
            KC_LGUI,
            MO(MDIA), KC_ENT, KC_SPC
    ),
/* Keymap: Symbol Layer
 *********************************************************************************************************************
 *                                                                                                                   *
 * .--------+------+------+------+------+------+------.         .------+------+------+------+------+------+--------. *
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  |      |         |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  | *
 * +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
 * |        |   <  |   >  |   {  |   }  |   |  |      |         |      |   %  |   7  |   8  |   9  |   *  |   F12  | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |   -  |   _  |   (  |   )  |   `  +------+         +------+   $  |   4  |   5  |   6  |   +  |        | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |   @  |   ^  |   [  |   ]  |   ~  |      |         |      |   &  |   1  |   2  |   3  |   /  |        | *
 * '-+------+------+------+------+------+------+------'         '------+------+------+------+------+------+------+-' *
 *   |      |dead ´|dead `|dead ^|      |                                     |   0  |   ,  |   .  |   -  |      |   *
 *   '------+------+------+------+------'                                     '------+------+------+------+------'   *
 *                                       .------+------.       .------+------.                                       *
 *                                       |      |      |       |      |      |                                       *
 *                                .------+------+------+       +------+------+------.                                *
 *                                |      |      |      |       |      |      |      |                                *
 *                                |      |      +------+       +------+      |      |                                *
 *                                |      |      |      |       |      |      |      |                                *
 *                                '------+------+------'       '------+------+------'                                *
 *                                                                                                                   *
 *********************************************************************************************************************
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       RESET,   KC_F1,      KC_F2,        KC_F3,      KC_F4,      KC_F5,      KC_TRNS,
       KC_TRNS, S(KC_COMM), S(KC_DOT),    S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_TRNS,
       KC_TRNS, KC_MINS,    S(KC_MINS),   S(KC_9),    S(KC_0),    KC_GRV,
       KC_TRNS, S(KC_2),    S(KC_6),      KC_LBRC,    KC_RBRC,    S(KC_GRV),  KC_TRNS,
       KC_TRNS, LALT(KC_E), LALT(KC_GRV), LALT(KC_I), KC_TRNS,
                                          KC_TRNS,    KC_TRNS,
                                                      KC_TRNS,
                                KC_TRNS,  KC_TRNS,    KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, S(KC_5), KC_P7, KC_P8,   KC_P9,   KC_PAST, KC_F12,
                S(KC_4), KC_P4, KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
       KC_TRNS, S(KC_7), KC_P1, KC_P2,   KC_P3,   KC_PSLS, KC_TRNS,
                         KC_P0, KC_COMM, KC_PDOT, KC_PMNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap: Media and mouse keys
 *********************************************************************************************************************
 *                                                                                                                   *
 * .--------+------+------+------+------+------+------.         .------+------+------+------+------+------+--------. *
 * |        |      |      |      |      |      |      |         |      |      |      |      |      |      | RESET  | *
 * +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
 * |        |      | Lclk | MsUp | Rclk |      |      |         | ^GAME| PGUP | HOME |  UP  | END  |      |        | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |      |MsLeft|MsDown|MsRght|      +------+         +------+ PGDN | LEFT | DOWN |RIGHT |      |        | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |      |      |      |      |      |      |         |      | Sleep| Prev | Play | Next |      |        | *
 * '-+------+------+------+------+------+------+------'         '------+------+------+------+------+------+------+-' *
 *   |      |      |      |      |      |                                     | VolUp| VolDn| Mute |      |      |   *
 *   '------+------+------+------+------'                                     '------+------+------+------+------'   *
 *                                       .------+------.       .------+------.                                       *
 *                                       |      |      |       |      |      |                                       *
 *                                .------+------+------+       +------+------+------.                                *
 *                                |      |      |      |       |      |      |Brwser|                                *
 *                                |      |      +------+       +------+      |Back  |                                *
 *                                |      |      |      |       |      |      |      |                                *
 *                                '------+------+------'       '------+------+------'                                *
 *                                                                                                                   *
 *********************************************************************************************************************
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                       KC_TRNS, KC_TRNS,
                                                                KC_TRNS,
                                              KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       TG(GAME), KC_PGUP,           KC_HOME, KC_UP,   KC_END,  KC_TRNS, KC_TRNS,
                 KC_PGDN,           KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  S(LCTL(KC_POWER)), KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
                                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap: game layer
*********************************************************************************************************************
*                                                                                                                   *
* .--------+------+------+------+------+------+------.         .------+------+------+------+------+------+--------. *
* |   =    |   1  |   2  |   3  |   4  |   5  |  6   |         |      |      |      |      |      |      |        | *
* +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
* | Tab    |   Q  |   W  |   E  |   R  |   T  |  Y   |         |^GAME |      |      |      |      |      |        | *
* +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
* | Esc    |   A  |   S  |   D  |   F  |   G  +------+         +------+      |      |      |      |      |        | *
* +--------+------+------+------+------+------+  N   |         |      +------+------+------+------+------+--------+ *
* | LShift |   Z  |   X  |   C  |   V  |   B  |      |         |      |      |      |      |      |      |        | *
* '-+------+------+------+------+------+------+------'         '------+------+------+------+------+------+------+-' *
*   | Ctrl | Alt  | LGui |   J  |   M  |                                     |      |      |      |      |      |   *
*   '------+------+------+------+------'                                     '------+------+------+------+------'   *
*                                       .------+------.       .------+--------.                                     *
*                                       |      |      |       |      |        |                                     *
*                                .------+------+------+       +------+--------+------.                              *
*                                |      |      |      |       |      |        |      |                              *
*                                | Space| Alt  +------+       +------+        |      |                              *
*                                |      |      | Ctrl |       |      |        |      |                              *
*                                '------+------+------'       '------+--------+------'                              *
*                                                                                                                   *
*********************************************************************************************************************
*/
[GAME] = KEYMAP(
        // left hand
        KC_EQL,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,
        KC_ESC,  KC_A,    KC_S,    KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N,
        KC_LCTL, KC_LALT, KC_LGUI, KC_J, KC_M,
                    KC_TRNS, KC_TRNS,
                             KC_TRNS,
            KC_SPC, KC_LALT, KC_LCTL,

        // right hand
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TG(GAME), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TG(MDIA), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS,
            KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case QWERTY:
#ifdef SUBPROJECT_infinity
            lcd_backlight_hal_color(0, 0, 0);
#endif
            break;
        case SYMB:
#ifdef SUBPROJECT_infinity
            lcd_backlight_hal_color(5000, 0, 0);
#endif
            ergodox_right_led_1_on();
            break;
        case MDIA:
#ifdef SUBPROJECT_infinity
            lcd_backlight_hal_color(0, 5000, 0);
#endif
            ergodox_right_led_2_on();
            break;
        case GAME:
#ifdef SUBPROJECT_infinity
            lcd_backlight_hal_color(0, 0, 5000);
#endif
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
