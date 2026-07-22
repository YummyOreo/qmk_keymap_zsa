#include "title_case.h"
#include <complex.h>

static bool title_case_status = false;
static bool just_spaced = false;

bool process_title_case(uint16_t keycode, keyrecord_t *record) {
    if (!title_case_status) {
        return true;
    }

    if (just_spaced) {
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    }

    switch (keycode) {
        case KC_SPACE:
            just_spaced = true;
            break;
        case KC_ESCAPE:
        case KC_ENTER:
            if (record->event.pressed) {
                turn_title_case_off();
                return true;
            }
        default:
            just_spaced = false;
    }
    return true;
}

bool toggle_title_case(void) {
    title_case_status = !title_case_status;
    title_case_change_status(title_case_status);
    return get_title_case_status();
}

void turn_title_case_on(void) {
    title_case_status = true;
    title_case_change_status(true);
}

void turn_title_case_off(void) {
    title_case_status = false;
    just_spaced = false;
    title_case_change_status(false);
}

bool get_title_case_status(void) {
    if (title_case_status) {
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) void title_case_change_status(bool status) {}
