#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif
#include "features/sentence_case.h"
#include "features/swapper.h"
#include "features/space_dash.h"
#include "features/leader.h"
#include "features/title_case.h"

#include <stdbool.h>

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
TOGGLE_SPACE_DASH,
TURBO,
SW_WIN,
LEADER
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _MOVEMENT,
  _OBSIDIAN,
  _AUDIO,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define DUAL_FUNC_0 LT(2, KC_F18)
#define DUAL_FUNC_1 LT(8, KC_F11)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Obsidian Shortcuts
#define OBSIDIAN_TEMPLATE MEH(KC_T)
#define OBSIDIAN_NEW_NOTE MEH(KC_N)
#define OBSIDIAN_NEW_NOTE_SELECTED MEH(KC_S)
#define OBSIDIAN_LIT_NOTE MEH(KC_L)
#define OBSIDIAN_ARCHIVE_BOOK MEH(KC_B)

#define OBSIDIAN_QUICKADD MEH(KC_A)
#define OBSIDIAN_CALLOUT MEH(KC_C)
#define OBSIDIAN_MODE_SWAP MEH(KC_G)
#define OBSIDIAN_ADVANCED_TABLES MEH(KC_F)
#define OBSIDIAN_JUMPT_CURSOR LALT(KC_T)
#define OBSIDIAN_WEB_SNIPPER LSA(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
                KC_TAB, KC_Q, KC_W, KC_F, KC_P,  KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
                MT(MOD_LCTL, KC_ESCAPE), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, MT(MOD_RSFT, KC_ENTER),
                KC_LEFT_SHIFT, MT(MOD_LSFT, KC_Z), KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMMA, KC_DOT, KC_SLASH, KC_QUOTE,
                KC_LEFT_CTRL, KC_LEFT_GUI, KC_LEFT_ALT, LT(_MOVEMENT, LEADER), LOWER, KC_SPACE, KC_NO, RAISE, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT
            ),
        [_LOWER] = LAYOUT_planck_grid(
                _______, _______, KC_LBRC, KC_LPRN, KC_LCBR, _______, KC_CIRC, KC_RCBR, KC_RPRN, KC_RBRC, _______, _______,
                KC_GRAVE,KC_DLR, KC_ASTR, KC_EQUAL, KC_MINUS, KC_UNDS,KC_HASH, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_RGUI), KC_TILD,
                _______, KC_PERC, KC_PIPE, KC_AT, KC_PLUS, KC_BSLS,KC_EXLM, KC_SLSH, KC_AMPR, KC_QUES, _______, _______,
                _______, _______, _______, _______, _______, _______, KC_NO, _______, KC_HOME, KC_PGDN, KC_PAGE_UP, KC_END
                ),
        [_RAISE] = LAYOUT_planck_grid(
                KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______, KC_NO, _______, _______, _______, _______, _______
                ),
        [_MOVEMENT] = LAYOUT_planck_grid(
                _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(LSFT(KC_T)),_______, _______,
                _______, _______, SW_WIN, LALT(KC_LEFT), LALT(KC_RIGHT), _______, _______, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),LCTL(KC_T), LCTL(KC_W), _______,
                _______, _______, _______, LALT(KC_DOWN), LALT(KC_UP), _______, _______, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),
                _______, _______, _______, _______, _______, _______, KC_NO, _______, _______, _______, _______, _______
                ),
        [_OBSIDIAN] = LAYOUT_planck_grid(
                _______, _______, _______, OBSIDIAN_ARCHIVE_BOOK,OBSIDIAN_NEW_NOTE_SELECTED, _______, _______, OBSIDIAN_MODE_SWAP,_______, _______, _______, _______,
                _______, _______, _______, OBSIDIAN_LIT_NOTE,OBSIDIAN_NEW_NOTE,OBSIDIAN_TEMPLATE, OBSIDIAN_QUICKADD,OBSIDIAN_CALLOUT, OBSIDIAN_ADVANCED_TABLES,_______,_______, _______,
                _______, _______, _______, _______, OBSIDIAN_WEB_SNIPPER,_______, _______, TOGGLE_SPACE_DASH,OBSIDIAN_JUMPT_CURSOR, _______,_______, _______,
                _______, _______, _______, _______, _______, _______, KC_NO, _______, _______, _______, _______, _______
                )
};

enum complex_combos {
    TOGGLE_AUTOCORRECT,
};

const uint16_t PROGMEM obsidian_combo[]           = {LOWER, RAISE, COMBO_END};
const uint16_t PROGMEM toggle_autocorrect_combo[] = {KC_BACKSPACE, KC_RIGHT, COMBO_END};

combo_t key_combos[] = {
    COMBO(obsidian_combo, OSL(_OBSIDIAN)),
    [TOGGLE_AUTOCORRECT] = COMBO_ACTION(toggle_autocorrect_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case TOGGLE_AUTOCORRECT:
            if (pressed) {
                autocorrect_toggle();
            }
            break;
    }
}

void reset(void) {
    autocorrect_enable();
    sentence_case_on();
    turn_space_dash_off();
    caps_word_off();
    turn_title_case_off();
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_A:
            // toggle autocorrect
            autocorrect_toggle();
            return NULL; // function that will choose new base layers
        // case KC_M:
        //     // toggle music layer
        //     layer_move(AUDIO);
        //     return NULL;
        case KC_Q:
            // Make a new line for a quote
            tap_code16(KC_ESCAPE);
            SEND_STRING("o- \"\"");
            tap_code16(KC_LEFT);
            return NULL;
        case KC_T:
            // Make a new line for a todo
            tap_code16(KC_ESCAPE);
            SEND_STRING("o- [ ] ");
            return NULL;
        case KC_LEFT_SHIFT:
            toggle_title_case();
            return NULL;
        case KC_DOT:
            // Toggle sentence case
            sentence_case_toggle();
            return NULL;
        case KC_D:
            // Toggle space dash
            toggle_space_dash();
            return NULL;
        // case KC_O:
        //     // Toggle space dash
        //     OSL(_OBSIDIAN);
        //     return NULL;
        case KC_R:
            // reset
            reset();
            return NULL;
        default:
            return NULL;
    }
}

char sentence_case_press_user(uint16_t keycode, keyrecord_t *record, uint8_t mods) {
    if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        const bool shifted = mods & MOD_MASK_SHIFT;
        switch (keycode) {
            case KC_A ... KC_Z:
                return 'a'; // Letter key.
            case KC_DOT:    // . is punctuation, Shift . is a symbol (>)
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

bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_leader(keycode, record)) {
        return false;
    }
    if (!process_sentence_case(keycode, record)) {
        return false;
    }
    if (!process_space_dash(keycode, record)) {
        return false;
    }
    if (!process_title_case(keycode, record)) {
        return false;
    }
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, keycode, record);

    if (record->event.pressed) {
        switch (keycode) {
            case TOGGLE_SPACE_DASH:
                toggle_space_dash();
                return false;
            case LEADER:
                if (!is_leading()) {
                    start_leading();
                }
                return false;
        }
    }
    return true;
}

void suspend_wakeup_init_user(void) {
    reset();
    layer_move(_BASE);
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint16_t layer_state_set_user(uint16_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _MOVEMENT);
}
