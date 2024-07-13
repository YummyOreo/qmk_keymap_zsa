#include <wchar.h>
#include QMK_KEYBOARD_H
#include "version.h"
#include "features/sentence_case.h"
#include "features/space_dash.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#include <stdbool.h>

// clang-format off
enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    EXIT_GAME,
    TOGGLE_SPACE_DASH,
};

#define OBSIDIAN_TEMPLATE MEH(KC_T)
#define OBSIDIAN_NEW_NOTE MEH(KC_N)
#define OBSIDIAN_NEW_NOTE_SELECTED MEH(KC_S)
#define OBSIDIAN_LIT_NOTE MEH(KC_L)

#define OBSIDIAN_QUICKADD MEH(KC_A)
#define OBSIDIAN_CALLOUT MEH(KC_C)
#define OBSIDIAN_MODE_SWAP MEH(KC_G)
#define OBSIDIAN_ADVANCED_TABLES MEH(KC_F)

enum layers { BASE, LOWER, RAISED, MOVEMENT, OBSIDIAN, GAME, NUMPAD, QWERTY, MOUSE };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // main
  [BASE] = LAYOUT_voyager(
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_BSPC,
    KC_ESCAPE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_ENTER,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       MT(MOD_RSFT, KC_QUOTE),
    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    TO(MOUSE),      KC_LEFT_ALT,    QK_LEAD,                                        KC_RIGHT_CTRL,  QK_LEAD,        KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,
                                                    MO(LOWER),      KC_SPACE,                               LT(MOVEMENT, KC_BSPC),  MO(RAISED)
  ),
  // Lower
  [LOWER] = LAYOUT_voyager(
    KC_TILD,        KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MINUS,       KC_UNDS,        KC_EQUAL,       KC_PLUS,        KC_TRANSPARENT,
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_PIPE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Raies
  [RAISED] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Movement
  [MOVEMENT] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_LEFT),  LALT(KC_RIGHT), KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   LCTL(KC_T),     LCTL(KC_W),     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_DOWN),  LALT(KC_UP),    KC_TRANSPARENT,                                 KC_TRANSPARENT, LALT(KC_1),     LALT(KC_2),     LALT(KC_3),     LALT(KC_4),     LALT(KC_5),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Obsidian
  [OBSIDIAN] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OBSIDIAN_NEW_NOTE_SELECTED, KC_TRANSPARENT,                     KC_TRANSPARENT, OBSIDIAN_MODE_SWAP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OBSIDIAN_LIT_NOTE, OBSIDIAN_NEW_NOTE,      OBSIDIAN_TEMPLATE,                   OBSIDIAN_QUICKADD,OBSIDIAN_CALLOUT, OBSIDIAN_ADVANCED_TABLES, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, TOGGLE_SPACE_DASH,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Game
  [GAME] = LAYOUT_voyager(
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_F3,          KC_TRANSPARENT, MO(NUMPAD),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUOTE,
                                                    KC_LEFT_CTRL,   KC_SPACE,                                       EXIT_GAME,      KC_LEFT_GUI
  ),
  // Numpad
  [NUMPAD] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // QWERTY
  [QWERTY] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_J,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TO(BASE),          KC_TRANSPARENT
  ),
  // MOUSE
  [MOUSE] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_ACCEL0,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_ACCEL1,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_BTN3,     KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_ACCEL2,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TO(BASE),       KC_TRANSPARENT
  ),
};
// clang-format on

void enter_game(void) {
    layer_move(GAME);
    autocorrect_disable();
    sentence_case_off();
    turn_space_dash_off();
    STATUS_LED_1(false);
    STATUS_LED_2(false);
}

void exit_game(void) {
    autocorrect_enable();
    sentence_case_on();
    STATUS_LED_1(true);
    STATUS_LED_2(true);
    layer_move(BASE);
}

enum complex_combos {
    ENTER_GAME = 2,
    TOGGLE_AUTOCORRECT,
};

const uint16_t PROGMEM obsidian_combo[]           = {KC_SPACE, LT(MOVEMENT, KC_BSPC), COMBO_END};
const uint16_t PROGMEM game_enter_combo[]         = {KC_BSPC, KC_ENTER, COMBO_END};
const uint16_t PROGMEM qwerty_enter_combo[]       = {MT(MOD_RSFT, KC_QUOTE), KC_BSPC, COMBO_END};
const uint16_t PROGMEM toggle_autocorrect_combo[] = {KC_BACKSPACE, KC_RIGHT, COMBO_END};

combo_t key_combos[] = {
    COMBO(obsidian_combo, OSL(OBSIDIAN)),
    COMBO(qwerty_enter_combo, TO(QWERTY)),
    [ENTER_GAME]         = COMBO_ACTION(game_enter_combo),
    [TOGGLE_AUTOCORRECT] = COMBO_ACTION(toggle_autocorrect_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case TOGGLE_AUTOCORRECT:
            if (pressed) {
                autocorrect_toggle();
                STATUS_LED_1(autocorrect_is_enabled());
            }
            break;
        case ENTER_GAME:
            if (pressed) {
                enter_game();
            }
            break;
    }
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_A)) {
        autocorrect_toggle();
        STATUS_LED_1(autocorrect_is_enabled());
    } else if (leader_sequence_one_key(KC_G)) {
        enter_game();
    } else if (leader_sequence_two_keys(KC_LEFT_SHIFT, KC_Q)) {
        tap_code16(KC_ESCAPE);
        SEND_STRING("I- \"\"");
        tap_code16(KC_LEFT);
    } else if (leader_sequence_one_key(KC_Q)) {
        tap_code16(KC_ESCAPE);
        SEND_STRING("o- \"\"");
        tap_code16(KC_LEFT);
    } else if (leader_sequence_one_key(KC_LEFT_SHIFT)) {
        sentence_case_toggle();
        STATUS_LED_2(is_sentence_case_on());
    } else if (leader_sequence_one_key(KC_D)) {
        toggle_space_dash();
    }
}

void caps_word_set_user(bool active) {
    if (active) {
        STATUS_LED_3(true);
    } else {
        STATUS_LED_3(false);
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    STATUS_LED_1(true);
    STATUS_LED_2(true);
}

// clang-format off
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [BASE] = { {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201}, {20,255,201} },

    [LOWER] = { {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [RAISED] = { {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MOVEMENT] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [OBSIDIAN] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [GAME] = { {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255} },

    [NUMPAD] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [MOUSE] = { {0,0,0}, {252,3,244}, {252,3,244}, {252,3,244}, {252,3,244}, {0,0,0}, {0,0,0}, {252,3,244}, {252,3,244}, {252,3,244}, {252,3,244}, {0,0,0}, {0,0,0}, {252,3,244}, {252,3,244}, {252,3,244}, {252,3,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {252,3,244}, {0,0,0} },
};
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control) {
        return false;
    }
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (biton32(layer_state)) {
        case MOUSE:
        case BASE ... NUMPAD:
            set_layer_color(biton32(layer_state));
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
                rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
    }
    return true;
}

void space_dash_change_status(bool status) {
    if (status) {
        STATUS_LED_4(true);
    } else {
        STATUS_LED_4(false);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_sentence_case(keycode, record)) {
        return false;
    }
    if (!process_space_dash(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case EXIT_GAME:
            if (record->event.pressed) {
                exit_game();
            }
            return false;
        case TOGGLE_SPACE_DASH:
            if (record->event.pressed) {
                toggle_space_dash();
            }
    }
    return true;
}

void suspend_power_down_user(void) {
    STATUS_LED_1(false);
    STATUS_LED_2(false);
    STATUS_LED_3(false);
    STATUS_LED_4(false);
}

void suspend_wakeup_init_user(void) {
    STATUS_LED_1(autocorrect_is_enabled());
    STATUS_LED_2(is_sentence_case_on());
    STATUS_LED_3(is_caps_word_on());
    STATUS_LED_4(get_space_dash_status());
    layer_move(BASE);
}
bool shutdown_user(bool jump_to_bootloader) {
    STATUS_LED_1(false);
    STATUS_LED_2(false);
    STATUS_LED_3(false);
    STATUS_LED_4(false);
    layer_move(BASE);
    // false to not process kb level
    return false;
}

// sentence case stuff
char sentence_case_press_user(uint16_t keycode, keyrecord_t *record, uint8_t mods) {
    if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        const bool shifted = mods & MOD_MASK_SHIFT;
        switch (keycode) {
            case KC_A ... KC_Z:
                return 'a'; // Letter key.

            case KC_DOT: // . is punctuation, Shift . is a symbol (>)
            case KC_RIGHT_BRACKET:
                return !shifted ? '.' : '#';
            case KC_1:
            case KC_SLSH:
                return shifted ? '.' : '#';
            case KC_EXLM:
            case KC_QUES:
                return '.';
            case KC_2 ... KC_0:     // 2 3 4 5 6 7 8 9 0
            case KC_AT ... KC_RPRN: // @ # $ % ^ & * ( )
            case KC_MINS ... KC_LEFT_BRACKET:
            case KC_BACKSLASH ... KC_SEMICOLON:
            case KC_UNDS ... KC_COLN: // _ + { } | :
            case KC_GRV:
            case KC_COMM:
                return '#'; // Symbol key.

            case KC_SPC:
                return ' '; // Space key.

            case KC_QUOT:
                return '\''; // Quote key.
        }
    }

    // Otherwise clear Sentence Case to initial state.
    sentence_case_clear();
    return '\0';
}
