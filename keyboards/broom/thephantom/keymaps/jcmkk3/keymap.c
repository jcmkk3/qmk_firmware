#include QMK_KEYBOARD_H

#include "oneshot.h"

/* Layers */
#define DEF_L 0
#define NAV_L 1
#define UPP_L 2
#define SYM_L 3
#define NUM_L 4

/* Callum Mods */
enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

/* Shortcuts */
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define UNDO C(KC_Z)
#define SEL_ALL C(KC_A)

/* Combos */
enum combos {
    FM_LOWER_V,
    FP_LOWER_Q,
    CL_LOWER_Z,
    FM_UPPER_V,
    FP_UPPER_Q,
    CL_UPPER_Z,    
    FS_LBRC,
    YI_RBRC,
    MN_LPRN,
    OE_RPRN,
    PT_LCBR,
    UA_RCBR,
    PG_ESC,
    TB_DEL,
    CUTCOPY_SEL_ALL,
    COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM fm_combo[] = {KC_F, KC_M, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM cl_combo[] = {KC_C, KC_L, COMBO_END};
const uint16_t PROGMEM fm_upper_combo[] = {S(KC_F), S(KC_M), COMBO_END};
const uint16_t PROGMEM fp_upper_combo[] = {S(KC_F), S(KC_P), COMBO_END};
const uint16_t PROGMEM cl_upper_combo[] = {S(KC_C), S(KC_L), COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM yi_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM mn_combo[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM pt_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM ua_combo[] = {KC_U, KC_A, COMBO_END};
const uint16_t PROGMEM pg_combo[] = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM tb_combo[] = {KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM cut_copy_combo[] = {CUT, COPY, COMBO_END};

combo_t key_combos[] = {
  [FM_LOWER_V] = COMBO(fm_combo, KC_V),
  [FP_LOWER_Q] = COMBO(fp_combo, KC_Q),
  [CL_LOWER_Z] = COMBO(cl_combo, KC_Z),
  [FM_UPPER_V] = COMBO(fm_upper_combo, S(KC_V)),
  [FP_UPPER_Q] = COMBO(fp_upper_combo, S(KC_Q)),
  [CL_UPPER_Z] = COMBO(cl_upper_combo, S(KC_Z)),
  [FS_LBRC] = COMBO(fs_combo, KC_LBRC),
  [YI_RBRC] = COMBO(yi_combo, KC_RBRC),
  [MN_LPRN] = COMBO(mn_combo, KC_LPRN),
  [OE_RPRN] = COMBO(oe_combo, KC_RPRN),
  [PT_LCBR] = COMBO(pt_combo, KC_LCBR),
  [UA_RCBR] = COMBO(ua_combo, KC_RCBR),
  [PG_ESC] = COMBO(pg_combo, KC_ESC),
  [TB_DEL] = COMBO(tb_combo, KC_DEL),
  [CUTCOPY_SEL_ALL] = COMBO(cut_copy_combo, SEL_ALL),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, UPP_L, SYM_L, NUM_L);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF_L] = LAYOUT( \
    // ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
         KC_W,         KC_F,         KC_M,         KC_P,         KC_G,              KC_K,          KC_U,         KC_O,         KC_Y,         KC_QUOT,     \
         KC_R,         KC_S,         KC_N,         KC_T,         KC_B,              KC_J,          KC_A,         KC_E,         KC_I,         KC_H,        \
                       KC_C,         KC_L,         KC_D,                                           KC_X,         KC_COMMA,     KC_DOT,                    \
    // ╰─────────────┴─────────────┴─────────────╮                                                           ╭─────────────┴─────────────┴─────────────╯
                                                   MO(NAV_L),    KC_SPACE,          MO(UPP_L),     MO(SYM_L)    \
    //                                           ╰─────────────┴─────────────╯   ╰─────────────┴─────────────╯
    ),

    [NAV_L] = LAYOUT( \
    // ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
         KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,             KC_PGUP,       KC_HOME,      KC_UP,        KC_END,       XXXXXXX,     \
         OS_GUI,       OS_ALT,       OS_SHFT,      OS_CTRL,      UNDO,              KC_PGDN,       KC_LEFT,      KC_ENTER,     KC_RIGHT,     KC_ESC,      \
                       CUT,          COPY,         PASTE,                                          KC_TAB,       KC_DOWN,      XXXXXXX,                   \
    // ╰─────────────┴─────────────┴─────────────╮                                                           ╭─────────────┴─────────────┴─────────────╯
                                                   _______,      _______,           KC_BSPC,       KC_DEL       \
    //                                           ╰─────────────┴─────────────╯   ╰─────────────┴─────────────╯
    ),

    [UPP_L] = LAYOUT( \
    // ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
         S(KC_W),      S(KC_F),      S(KC_M),      S(KC_P),      S(KC_G),           S(KC_K),       S(KC_U),      S(KC_O),      S(KC_Y),      S(KC_QUOT),  \
         S(KC_R),      S(KC_S),      S(KC_N),      S(KC_T),      S(KC_B),           S(KC_J),       S(KC_A),      S(KC_E),      S(KC_I),      S(KC_H),     \
                       S(KC_C),      S(KC_L),      S(KC_D),                                        S(KC_X),      S(KC_COMMA),  S(KC_DOT),                 \
    // ╰─────────────┴─────────────┴─────────────╮                                                           ╭─────────────┴─────────────┴─────────────╯
                                                   _______,      S(KC_SPACE),       _______,       _______      \
    //                                           ╰─────────────┴─────────────╯   ╰─────────────┴─────────────╯
    ),

    [SYM_L] = LAYOUT( \
    // ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
         KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,           KC_CIRC,       KC_AMPR,      KC_SCLN,      KC_COLON,     KC_DQT,      \
         KC_MINUS,     KC_PLUS,      KC_EQUAL,     KC_ASTR,      KC_SLSH,           KC_BSLS,       OS_CTRL,      OS_SHFT,      OS_ALT,       OS_GUI,      \
                       KC_TILDE,     KC_GRAVE,     KC_QUES,                                        KC_PIPE,      KC_LT,        KC_GT,                     \
    // ╰─────────────┴─────────────┴─────────────╮                                                           ╭─────────────┴─────────────┴─────────────╯
                                                   _______,      KC_UNDS,           _______,       _______      \
    //                                           ╰─────────────┴─────────────╯   ╰─────────────┴─────────────╯
    ),

    [NUM_L] = LAYOUT( \
    // ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
         XXXXXXX,      KC_7,         KC_8,         KC_9,         XXXXXXX,           KC_F6,         KC_F7,        KC_F8,        KC_F9,        KC_F10,      \
         KC_MINUS,     KC_4,         KC_5,         KC_6,         KC_SLSH,           KC_F11,        OS_CTRL,      OS_SHFT,      OS_ALT,       OS_GUI,      \
                       KC_1,         KC_2,         KC_3,                                           KC_F12,       KC_COMMA,     KC_DOT,                    \
    // ╰─────────────┴─────────────┴─────────────╮                                                           ╭─────────────┴─────────────┴─────────────╯
                                                   _______,      KC_0,              _______,       _______      \
    //                                           ╰─────────────┴─────────────╯   ╰─────────────┴─────────────╯
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case MO(NAV_L):
    case MO(UPP_L):
    case MO(SYM_L):
    case MO(NUM_L):
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case MO(NAV_L):
    case MO(UPP_L):
    case MO(SYM_L):
    case MO(NUM_L):
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    return true;
}
