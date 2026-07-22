#include "quantum.h"

bool process_title_case(uint16_t keycode, keyrecord_t *record);
bool toggle_title_case(void);
void turn_title_case_on(void);
void turn_title_case_off(void);
bool get_title_case_status(void);
void title_case_change_status(bool status);
