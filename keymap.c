#include QMK_KEYBOARD_H

// Fix for modern QMK Mouse Keycodes
#define KC_MS_UP MS_UP
#define KC_MS_DOWN MS_DOWN
#define KC_MS_LEFT MS_LEFT
#define KC_MS_RIGHT MS_RGHT
#define KC_MS_BTN1 MS_BTN1
#define KC_MS_BTN2 MS_BTN2
#define KC_MS_BTN3 MS_BTN3
#define KC_MS_WH_UP MS_WHLU
#define KC_MS_WH_DOWN MS_WHLD
#define KC_MS_WH_LEFT MS_WHLL
#define KC_MS_WH_RIGHT MS_WHLR

// Custom Mapping for MK47 MIT
// Shifting thumb keys to align: Enter below K, Backspace below H
#define LAYOUT_miryoku( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
    k30, k31, k32, k33, k34, k35 \
) \
LAYOUT( \
    k00, k01, k02, k03, k04, KC_NO, KC_NO, k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, KC_NO, KC_NO, k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24, KC_NO, KC_NO, k25, k26, k27, k28, k29, \
    KC_NO, KC_NO, k30, k31, k32,    KC_NO, k34, k33, k35, KC_NO, KC_NO \
)

enum layers { BASE, NAV, MOUSE, NUM, SYM, FUN_MEDIA };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_miryoku(
  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,            KC_J,         KC_L,         KC_U,         KC_Y,         KC_QUOT,
  LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,            KC_M,         RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O),
  KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,            KC_K,         KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
  LT(FUN_MEDIA,KC_ESC), LT(NAV,KC_SPC), LT(MOUSE,KC_TAB),                  LT(NUM,KC_BSPC), LT(SYM,KC_ENT), LT(FUN_MEDIA,KC_DEL)
),

[NAV] = LAYOUT_miryoku(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO,
  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,      KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
  KC_TRNS, KC_ALGR, KC_TRNS, KC_TRNS, KC_TRNS,      KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
  KC_TRNS, KC_TRNS, KC_TRNS,                        KC_BSPC, KC_ENT,  KC_DEL
),

[MOUSE] = LAYOUT_miryoku(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO,
  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,      KC_TRNS, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,
  KC_TRNS, KC_ALGR, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
  KC_TRNS, KC_TRNS, KC_TRNS,                        MS_BTN3, MS_BTN1, MS_BTN2
),

[NUM] = LAYOUT_miryoku(
  KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,       KC_TRNS, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_ALGR, KC_TRNS,
  KC_DOT,  KC_0,    KC_MINS,                        KC_TRNS, KC_TRNS, KC_TRNS
),

[SYM] = LAYOUT_miryoku(
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,      KC_TRNS, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,      KC_TRNS, KC_TRNS, KC_TRNS, KC_ALGR, KC_TRNS,
  KC_LPRN, KC_RPRN, KC_UNDS,                        KC_TRNS, KC_TRNS, KC_TRNS
),

[FUN_MEDIA] = LAYOUT_miryoku(
  KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,      KC_VOLD, KC_VOLU, KC_MUTE, KC_MSTP, KC_MPLY,
  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,      KC_TRNS, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_ALGR, KC_TRNS,
  KC_APP,  KC_SPC,  KC_TAB,                         KC_TRNS, KC_TRNS, KC_TRNS
)

};
