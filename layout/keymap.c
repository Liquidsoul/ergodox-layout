// French AZERTY version of the default_osx file
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_french_osx.h"

#define QWERTY 0 // qwerty keys
#define QWERTY_SYMB 1 // qwerty symbols
#define AZERTY 2 // azerty layer
#define AZERTY_SYMB 3 // symbols
#define MDIA 4 // media keys

/*
 * Note that the layouts in comments are for AZERTY OSX keyboard configuration.
 * For example, @ should be < in QWERTY representation.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap: OSX AZERTY layer
*********************************************************************************************************************
*                                                                                                                   *
* .--------+------+------+------+------+------+------.         .------+------+------+------+------+------+--------. *
* |   -    |   &  |   é  |   "  |   '  |   (  | LEFT |         | RIGHT|   §  |   è  |   !  |   ç  |   à  |    )   | *
* +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
* | Tab    |   A  |   Z  |   E  |   R  |   T  |  L1  |         |  L1  |   Y  |   U  |   I  |   O  |   P  |    `   | *
* +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
* | Esc    |   Q  |   S  |   D  |   F  |   G  +------+         +------+   H  |   J  |   K  |   L  |   M  |  LGui  | *
* +--------+------+------+------+------+------+ Hyper|         |  Meh +------+------+------+------+------+--------+ *
* | LShift |   W  |   X  |   C  |   V  |   B  |      |         |      |   N  |   ,  |   ;  |   :  |=/Ctrl| RShift | *
* '-+------+------+------+------+------+------+------'         '------+------+------+------+------+------+------+-' *
*   | ù /L1|@/Ctrl| Alt  | LGui |   <  |                                     |   ´  |   `  |   ^  |$ / L2|  ~L1 |   *
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
[AZERTY] = KEYMAP(
        // left hand
        FR_MINS,                 FR_AMP,         FR_EACU,  FR_QUOT, FR_APOS, FR_LPRN, KC_LEFT,
        KC_TAB,                  FR_A,           FR_Z,     KC_E,    KC_R,    KC_T,    TG(AZERTY_SYMB),
        KC_ESC,                  FR_Q,           KC_S,     KC_D,    KC_F,    KC_G,
        KC_LSFT,                 FR_W,           KC_X,     KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),
        LT(AZERTY_SYMB,FR_UGRV), CTL_T(FR_LESS), KC_LALT,  KC_LGUI, FR_AT,
                     KC_LALT, KC_LGUI,
                              MO(AZERTY_SYMB),
            KC_BSPC, KC_DELT, KC_LCTRL,

        // right hand
        KC_RGHT,         FR_SECT, FR_EGRV,         FR_EXLM, FR_CCED, FR_AGRV,           FR_RPRN,
        TG(AZERTY_SYMB), KC_Y,    KC_U,            KC_I,    KC_O,    KC_P,              FR_GRV,
                         KC_H,    KC_J,            KC_K,    KC_L,    FR_M,              KC_LGUI,
        MEH_T(KC_NO),    KC_N,    FR_COMM,         FR_SCLN, FR_COLN, CTL_T(FR_EQL),     KC_RSFT,
                                  S(LALT(FR_AMP)), FR_GRV,  KC_LBRC, LT(MDIA, KC_RBRC), MO(AZERTY_SYMB),
            KC_LALT,  CTL_T(KC_ESC),
            KC_LGUI,
            MO(MDIA), KC_ENT, KC_SPC
    ),
/* Keymap: Symbol Layer
 *********************************************************************************************************************
 *                                                                                                                   *
 * .--------+------+------+------+------+------+------.         .------+------+------+------+------+------+--------. *
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |         |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  | *
 * +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
 * |        |   <  |   >  |   {  |   }  |   |  |      |         |      |  UP  |   7  |   8  |   9  |   *  |   F12  | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |   -  |   $  |   (  |   )  |   `  +------+         +------+ DOWN |   4  |   5  |   6  |   +  |        | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |         |      |   &  |   1  |   2  |   3  |   /  |        | *
 * '-+------+------+------+------+------+------+------'         '------+------+------+------+------+------+------+-' *
 *   |      |      |      |      |      |                                     |   0  |   ,  |      |   -  |      |   *
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
[AZERTY_SYMB] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, FR_AT,   FR_HASH, FR_LCBR, FR_RCBR, FR_PIPE, KC_TRNS,
       KC_TRNS, FR_MINS, FR_DLR,  FR_LPRN, FR_RPRN, FR_GRV,
       KC_TRNS, FR_PERC, FR_CIRC, FR_LBRC, FR_RBRC, FR_TILD, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7, KC_F8,   KC_F9, KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_P7, KC_P8,   KC_P9, KC_PAST, KC_F12,
                KC_DOWN, KC_P4, KC_P5,   KC_P6, KC_PPLS, KC_TRNS,
       KC_TRNS, FR_AMP,  KC_P1, KC_P2,   KC_P3, KC_PSLS, KC_TRNS,
                         KC_P0, KC_PDOT, KC_P0, KC_PMNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap: Basic QWERTY layer
*********************************************************************************************************************
*                                                                                                                   *
* .--------+------+------+------+------+------+------.         .------+------+------+------+------+------+--------. *
* |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |         | RIGHT|   6  |   7  |   8  |   9  |   0  |    -   | *
* +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
* | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |         |  L1  |   Y  |   U  |   I  |   O  |   P  |    \   | *
* +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
* | Esc    |   A  |   S  |   D  |   F  |   G  +------+         +------+   H  |   J  |   K  |   L  |   ;  | '/LGui | *
* +--------+------+------+------+------+------+ Hyper|         |  Meh +------+------+------+------+------+--------+ *
* | LShift |   Z  |   X  |   C  |   V  |   B  |      |         |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift | *
* '-+------+------+------+------+------+------+------'         '------+------+------+------+------+------+------+-' *
*   | ` /L1|'/Ctrl| Alt  | LGui |      |                                     |   ´  |   `  |   [  |] / L2|  ~L1 |   *
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
        KC_EQL,                 KC_1,           KC_2,    KC_3,    KC_4,       KC_5,    KC_LEFT,
        KC_TAB,                 KC_Q,           KC_W,    KC_E,    KC_R,       KC_T,    TG(QWERTY_SYMB),
        KC_ESC,                 KC_A,           KC_S,    KC_D,    KC_F,       KC_G,
        KC_LSFT,                KC_Z,           KC_X,    KC_C,    KC_V,       KC_B,    ALL_T(KC_NO),
        LT(QWERTY_SYMB,KC_GRV), CTL_T(KC_QUOT), KC_LALT, KC_LGUI, LALT(KC_C),
                     KC_LALT, KC_LGUI,
                              MO(QWERTY_SYMB),
            KC_BSPC, KC_DELT, KC_LCTL,

        // right hand
        KC_RGHT,         KC_6, KC_7,       KC_8,         KC_9,    KC_0,              KC_MINS,
        TG(QWERTY_SYMB), KC_Y, KC_U,       KC_I,         KC_O,    KC_P,              KC_BSLS,
                         KC_H, KC_J,       KC_K,         KC_L,    KC_SCLN,           GUI_T(KC_QUOT),
        MEH_T(KC_NO),    KC_N, KC_M,       KC_COMM,      KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
                               LALT(KC_E), LALT(KC_GRV), KC_LBRC, LT(MDIA, KC_RBRC), MO(QWERTY_SYMB),
            KC_LALT,  KC_RCTL,
            KC_LGUI,
            MO(MDIA), KC_ENT, KC_SPC
    ),
/* Keymap: QWERTY Symbol Layer
 *********************************************************************************************************************
 *                                                                                                                   *
 * .--------+------+------+------+------+------+------.         .------+------+------+------+------+------+--------. *
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |         |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  | *
 * +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
 * |        |   <  |   >  |   {  |   }  |   |  |      |         |      |   %  |   7  |   8  |   9  |   *  |   F12  | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |   -  |   _  |   (  |   )  |   `  +------+         +------+   $  |   4  |   5  |   6  |   +  |        | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |   @  |   ^  |   [  |   ]  |   ~  |      |         |      |   &  |   1  |   2  |   3  |   /  |        | *
 * '-+------+------+------+------+------+------+------'         '------+------+------+------+------+------+------+-' *
 *   |      |      |      |      |      |                                     |   0  |   ,  |      |   -  |      |   *
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
// QWERTY SYMBOLS
[QWERTY_SYMB] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_TRNS,
       KC_TRNS, S(KC_COMM), S(KC_DOT),  S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_TRNS,
       KC_TRNS, KC_MINS,    S(KC_MINS), S(KC_9),    S(KC_0),    KC_GRV,
       KC_TRNS, S(KC_2),    S(KC_6),    KC_LBRC,    KC_RBRC,    S(KC_GRV),  KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                        KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,
                                KC_TRNS,KC_TRNS,    KC_TRNS,
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
 * | QWERTY |      |      |      |      |      |      |         |      |      |      |      |      |      |        | *
 * +--------+------+------+------+------+------+------+         +------+------+------+------+------+------+--------+ *
 * |        |      | Lclk | MsUp | Rclk |      |      |         |      |      | HOME |  UP  | END  |      |        | *
 * +--------+------+------+------+------+------+      |         |      +------+------+------+------+------+--------+ *
 * |        |      |MsLeft|MsDown|MsRght|      +------+         +------+      | LEFT | DOWN |RIGHT |      |        | *
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
       TG(AZERTY), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                       KC_TRNS, KC_TRNS,
                                                                KC_TRNS,
                                              KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,           KC_HOME, KC_UP,   KC_END,  KC_TRNS, KC_TRNS,
                 KC_TRNS,           KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  S(LCTL(KC_POWER)), KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
                                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(AZERTY_SYMB),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA),                // FN2 - Momentary Layer 2 (Media)
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
            break;
        case AZERTY_SYMB:
            ergodox_right_led_3_on();
        case QWERTY_SYMB:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        case AZERTY:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};