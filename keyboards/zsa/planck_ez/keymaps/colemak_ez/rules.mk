SRC += muse.c
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
TAP_DANCE_ENABLE = no
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no

AUTOCORRECT_ENABLE = yes

SRC += features/sentence_case.c
SRC += features/space_dash.c
SRC += features/title_case.c
SRC += features/swapper.c
SRC += features/leader.c

LTO_ENABLE = yes
CAPS_WORD_ENABLE = yes
UNICODE_COMMON = no
REPEAT_KEY_ENABLE = yes
