#include QMK_KEYBOARD_H

#include "quantum/rgblight/rgblight.h"
#include "quantum/split_common/split_util.h"
#include "platforms/gpio.h"

// Helpful defines
// #define GRAVE_MODS  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.
enum layer_names {
    QWERTY,
    QWERTY_2,
    QWERTY_3,
    QWERTY_4,
    GAMING,
    GAMING_2,
    STENO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        // left
        KC_Q, KC_W, KC_E,     KC_R,         KC_T,
        KC_A, KC_S, KC_D,     KC_F,         KC_G,
        KC_Z, KC_X, KC_C,     KC_V,         KC_B,
                    KC_ENTER, MO(QWERTY_2), KC_SPACE,

        // right
        KC_P,         KC_O,    KC_I,     KC_U,    KC_Y,
        KC_SEMICOLON, KC_L,    KC_K,     KC_J,    KC_H,
        KC_LGUI,      KC_DOT,  KC_COMMA, KC_M,    KC_N,
                               KC_LALT,  KC_LCTL, KC_LSFT
    ),
    [QWERTY_2] = LAYOUT(
        // left
        KC_ESC,    KC_PGUP, KC_UP,          KC_PGDN,  KC_BACKSPACE,
        KC_TAB,    KC_LEFT, KC_DOWN,        KC_RIGHT, XXXXXXX,
        KC_DELETE, KC_HOME, RALT(KC_COMMA), KC_END,   XXXXXXX,
                            MO(QWERTY_3),   KC_TRNS,  _______,

        // right
        KC_F10,  KC_F9,   KC_F8,   KC_F7,   KC_PSCR,
        KC_F11,  KC_F6,   KC_F5,   KC_F4,   XXXXXXX,
        _______, KC_F3,   KC_F2,   KC_F1,   KC_SLASH,
                          _______, _______, _______
    ),
    [QWERTY_3] = LAYOUT(
        // left
        KC_MINS, KC_7, KC_8,    KC_9,    KC_0,
        KC_EQL,  KC_4, KC_5,    KC_6,    KC_BSLS,
        KC_QUOT, KC_1, KC_2,    KC_3,    KC_GRV,
                       KC_TRNS, KC_TRNS, MO(QWERTY_4),

        // right
        KC_WH_U, KC_BTN3, KC_MS_U, KC_RBRC, KC_LBRC,
        KC_WH_D, KC_MS_R, KC_MS_D, KC_MS_L, XXXXXXX,
        _______, KC_BTN5, KC_BTN4, KC_BTN2, KC_BTN1,
                          _______, _______, _______
    ),
    [QWERTY_4] = LAYOUT(
        // left
         DF(STENO),     XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,
         DF(GAMING),    KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,
         QK_BOOTLOADER, XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX,
                                 KC_TRNS, KC_TRNS, KC_TRNS,
        // right
        KC_F22, KC_F21, KC_F20, KC_F19, XXXXXXX,
        KC_F23, KC_F18, KC_F17, KC_F16, QK_CLEAR_EEPROM,
        KC_F24, KC_F15, KC_F14, KC_F13, XXXXXXX,
                          _______, _______, _______
    ),
    [GAMING] = LAYOUT(
        // left
        KC_ESC, KC_Q, KC_W,     KC_E,    KC_R,
        KC_TAB, KC_A, KC_S,     KC_D,    KC_F,
        KC_Z,   KC_X, KC_C,     KC_V,    MO(GAMING_2),
                      KC_SPACE, KC_LSFT, KC_LCTL,

        // right
        DF(QWERTY),   KC_O,    KC_I,     KC_U,    KC_Y,
        KC_SEMICOLON, KC_L,    KC_K,     KC_J,    KC_H,
        KC_SLASH,     KC_DOT,  KC_COMMA, KC_M,    KC_N,
                               KC_LALT,  KC_LCTL, KC_LSFT
    ),
    [GAMING_2] = LAYOUT(
        // left
        KC_T, KC_7, KC_8,       KC_9,    KC_0,
        KC_G, KC_4, KC_5,       KC_6,    KC_ENTER,
        KC_B, KC_1, KC_2,       KC_3,    KC_TRNS,
                    DF(QWERTY), KC_LALT, KC_G,

        // right
        DF(QWERTY),   KC_O,    KC_I,     KC_U,    KC_Y,
        KC_SEMICOLON, KC_L,    KC_K,     KC_J,    KC_H,
        KC_SLASH,     KC_DOT,  KC_COMMA, KC_M,    KC_N,
                               KC_LALT,  KC_LCTL, KC_LSFT
    ),
	[STENO] = LAYOUT(
        // LEFT SIDE
        STN_N1, STN_N2, STN_N3, STN_N4, STN_N5,
        STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,
        STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2,
                        STN_FN, STN_A,  STN_O,

        // RIGHT SIDE
        DF(QWERTY), STN_N9, STN_N8, STN_N7, STN_N6,
        STN_DR,     STN_TR, STN_LR, STN_PR, STN_FR,
        STN_ZR,     STN_SR, STN_GR, STN_BR, STN_RR,
                            STN_NB, STN_U,  STN_E
	)
};


#define LED_PIN GP25
#define COLOR_VALUE 0x30

#define QWERTY_LAYER_COLOR 300 * 255 / 360,  0xFF, COLOR_VALUE
#define QWERTY2_LAYER_COLOR 180 * 255 / 360,  0xFF, COLOR_VALUE
#define QWERTY3_LAYER_COLOR 90 * 255 / 360,  0xFF, COLOR_VALUE
#define QWERTY4_LAYER_COLOR 0 * 255 / 360,  0xFF, COLOR_VALUE
#define GAMING_LAYER_COLOR 40 * 255 / 360,  0xFF, COLOR_VALUE
#define GAMING_LAYER_2_COLOR 70 * 255 / 360,  0xFF, COLOR_VALUE
#define STENO_LAYER_COLOR 240 * 255 / 360,  0xFF, COLOR_VALUE

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, QWERTY_LAYER_COLOR}
);
const rgblight_segment_t PROGMEM qwerty2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, QWERTY2_LAYER_COLOR}
);
const rgblight_segment_t PROGMEM qwerty3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, QWERTY3_LAYER_COLOR}
);
const rgblight_segment_t PROGMEM qwerty4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, QWERTY4_LAYER_COLOR}
);
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, GAMING_LAYER_COLOR}
);
const rgblight_segment_t PROGMEM gaming_2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, GAMING_LAYER_2_COLOR}
);
const rgblight_segment_t PROGMEM steno_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, STENO_LAYER_COLOR}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    qwerty2_layer,
    qwerty3_layer,
    qwerty4_layer,
    gaming_layer,
    gaming_2_layer,
    steno_layer
);

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(LED_PIN);
}

void keyboard_post_init_user(void){
    rgblight_layers = my_rgb_layers;
    if (isLeftHand) {
        // rgblight_sethsv_at(240 * 255 / 360, 0xFF, 0x0A, 0);
        // rgblght_sethsv_at(240 * 255 / 360, 0xFF, 0x0A, 0);
    } else {
        // rgblight_sethsv_at(0, 0, 0, 0);
    }
}

bool shutdown_kb(bool jump_to_bootloader) {
    rgblight_setrgb_at(0, 0, 0, 0);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, QWERTY));
    rgblight_set_layer_state(4, layer_state_cmp(state, GAMING));
    rgblight_set_layer_state(6, layer_state_cmp(state, STENO));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, QWERTY_2));
    rgblight_set_layer_state(2, layer_state_cmp(state, QWERTY_3));
    rgblight_set_layer_state(3, layer_state_cmp(state, QWERTY_4));
    rgblight_set_layer_state(4, layer_state_cmp(state, GAMING));
    rgblight_set_layer_state(5, layer_state_cmp(state, GAMING_2));
    return state;
}
