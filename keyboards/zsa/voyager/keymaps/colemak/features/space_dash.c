#include "space_dash.h"
#include <complex.h>

static bool space_dash_status = false;

bool process_space_dash(uint16_t keycode, keyrecord_t *record) {
    if (!space_dash_status) {
        return true;
    }

    switch (keycode) {
        case KC_SPACE:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)) {
                    SEND_STRING("_");
                    return false;
                } else {
                    SEND_STRING("-");
                    return false;
                }
                return false;
            }
        case KC_ESCAPE:
            if (record->event.pressed) {
                turn_space_dash_off();
                return true;
            }
    }
    return true;
}

bool toggle_space_dash(void) {
    space_dash_status = !space_dash_status;
    space_dash_change_status(space_dash_status);
    return get_space_dash_status();
}

void turn_space_dash_on(void) {
    space_dash_status = true;
    space_dash_change_status(true);
}

void turn_space_dash_off(void) {
    space_dash_status = false;
    space_dash_change_status(false);
}

bool get_space_dash_status(void) {
    if (space_dash_status) {
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) void space_dash_change_status(bool status) {}
