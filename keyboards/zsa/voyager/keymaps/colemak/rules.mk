# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ORYX_ENABLE = no
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
AUTOCORRECT_ENABLE = yes
SRC += features/sentence_case.c
SRC += features/space_dash.c
SRC += features/title_case.c
SRC += features/mouse_turbo_click.c
SRC += features/swapper.c
SRC += features/leader.c

MOUSEKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

LTO_ENABLE = yes
# LEADER_ENABLE = yes
# TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
UNICODE_COMMON = no
REPEAT_KEY_ENABLE = yes
