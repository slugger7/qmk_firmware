#include QMK_KEYBOARD_H

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define WSPR LCTL(LGUI(KC_RIGHT))
#define WSPL LCTL(LGUI(KC_LEFT))
#define ALT_F2 LALT(KC_F2)
#define ALT_F3 LALT(KC_F3)
#define ALT_F4 LALT(KC_F4)
#define GUI_UP LGUI(KC_UP)
#define GUI_DN LGUI(KC_DOWN)
#define GUI_RT LGUI(KC_RIGHT)
#define GUI_LT LGUI(KC_LEFT)
#define CTL_PGUP LCTL(KC_PGUP)
#define CTL_PGDN LCTL(KC_PGDOWN)

enum layers {
             _BL,
             _DL,
             _FL,
             _ML
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_60_ansi(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
        TT(_FL), KC_LGUI, KC_LALT,                   KC_SPC,                             TT(_ML), KC_RGUI, KC_RCTL, TT(_FL)
    ),
    [_DL] = LAYOUT_60_ansi(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC, \
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS, \
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, KC_ENT, \
        KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSPC, \
        TT(_FL), KC_LGUI, KC_LALT,                   KC_SPC,                             TT(_ML), KC_RGUI, KC_RCTL, TT(_FL)
    ),
    [_FL] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,  \
        KC_TRNS, KC_VOLD, KC_UP,   KC_VOLU, KC_HOME, DF(_BL), KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PGUP, KC_INS,  KC_DEL, \
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,  DF(_DL), KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PGDN, KC_PENT, \
        KC_TRNS, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, KC_NLCK, KC_PDOT, KC_P1,   KC_P2,   KC_P3,   KC_PSCR, KC_TRNS, \
        MO(_FL), KC_TRNS, KC_TRNS,                   KC_P0,                              TT(_ML), KC_TRNS, KC_TRNS, MO(_FL)
    ),
    [_ML] = LAYOUT_60_ansi(
        KC_TRNS, KC_TRNS, ALT_F2,  ALT_F3,  ALT_F4,  KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, \
        KC_TRNS, WSPL,    GUI_UP,  WSPR,    KC_TRNS, KC_TRNS, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, GUI_LT,  GUI_DN,  GUI_RT,  KC_TRNS, KC_TRNS, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, CTL_PGUP,CTL_PGDN,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            MO(_ML), KC_TRNS, KC_TRNS, KC_TRNS
    )
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
