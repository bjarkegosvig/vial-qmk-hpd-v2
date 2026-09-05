#include QMK_KEYBOARD_H
#include "ergohaven.h"
#include "src/eh_pointing.h"

// see https://docs.qmk.fm/#/keycodes for keycodes
#define KC_AWDW  LALT(LSFT(KC_H))
#define KC_AWIW  LALT(LSFT(KC_L))
#define KC_AWMM  LCTRL(LGUI(KC_ENTER))
#define KC_MCHAT  LCTRL(LSFT(KC_M))
#define KC_MMON  LGUI(LSFT(KC_LEFT))
#define KC_MXL   LGUI(KC_LEFT)
#define KC_MXR   LGUI(KC_RIGHT)
#define KC_MAX   LGUI(KC_UP)
#define KC_MIN   LGUI(KC_DOWN)
#define KC_MDT   LGUI(LCTL(KC_D))
#define KC_DTL   LGUI(LCTL(KC_LEFT))
#define KC_DTR   LGUI(LCTL(KC_RIGHT))

enum bgk_keycodes {
  KCAE = SAFE_RANGE,
  KCOE,
  KCAA,
};

// TAPDANCE cannot compile, There is something to look into

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case KCOE:
          if( record->event.pressed)
          {
              if(keyboard_report->mods & (MOD_BIT(KC_LSFT)))
              {
                  /* clear_mods(); */
                  unregister_code(KC_LSFT);
                  SEND_STRING(SS_RALT("/O"));
                  register_code(KC_LSFT);
              }
              else
                    SEND_STRING(SS_RALT("/o"));
          };
          break;
        case KCAE:
          if( record->event.pressed)
          {
              if(keyboard_report->mods & (MOD_BIT(KC_LSFT)))
              {
                  /* clear_mods(); */
                  unregister_code(KC_LSFT);
                  SEND_STRING(SS_RALT("AE"));
                  register_code(KC_LSFT);
              }
              else
                    SEND_STRING(SS_RALT("ae"));
          };
          break;
	  case KCAA:
		if( record->event.pressed)
          {
              if(keyboard_report->mods & (MOD_BIT(KC_LSFT)))
              {
                  /* clear_mods(); */
                  unregister_code(KC_LSFT);
                  SEND_STRING(SS_RALT("oA"));
                  register_code(KC_LSFT);
              }
              else
                    SEND_STRING(SS_RALT("oa"));
          };
        break;
      }
   return true;
};

// clang-format off

/* keymap 0: Basic layer
 *
 * ,--------------------------------------------------.                    ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  | Rofi |                    | Esc  |   6  |   7  |   8  |   9  |   0  | TG NM  |
 * |--------+------+------+------+------+-------------|                    |------+------+------+------+------+------+--------|
 * |Tab/ARRW|   Q  |   W  |   E  |   R  |   T  | Tab  |                    |      |   Y  |   U  |   I  |   O  |   P  |   +=   |
 * |--------+------+------+------+------+------|------|                    |------|------+------+------+------+------+--------|
 * | Shift  |   A  |   S  |   D  |   F  |   G  | :/;  |                    | -/_  |   H  |   J  |   K  |   L  | ;    |   '"   |
 * |--------+------+------+------+------+------|------'                    '------|------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  |  _-    |
 * `--------+------+------+------+------+------'                                  `-------------+------+------+------+--------'
 *   | L FUN|       | LALT |LCTRL|                                                              | LALT | LCTRL|      | L ARRW|
 *   `---------------------------'                            									'----------------------------'
 *						    ,------------------------------.                        ,-----------------------------.
 '						    |  Space | asdad | adad| Enter |                        |  Shft | asda| adsda  |BckSP |
 *                          `------------------------------'                        `-----------------------------'
 *
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
KC_ESC,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                             KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
OSM(MOD_LSFT),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                             KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
OSM(MOD_LCTL),  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                             KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                    LOWER,  KC_PGUP,  OSM(MOD_LCTL),  KC_SPACE, KC_ENTER,  KC_GRV,             KC_LGUI,   OSM(MOD_LSFT),  KC_BSPC,    OSM(MOD_LALT),  KC_PGDN,  RAISE,
                                                                           KC_MUTE,            KC_MUTE
    ),

[_LOWER] = LAYOUT(
KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                                            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
KC_PLUS,   KC_PIPE,   KC_LCBR,    KC_PERC,  KC_RCBR,   KC_AMPR,                                    KC_MUTE,   KC_HOME,   KC_UP,     KC_END,    KC_INS,    KC_PLUS,
_______,   KC_HASH,   KC_LPRN,    KC_DLR,   KC_RPRN,   KC_ASTR,                                    KC_MPLY,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO,     KC_TRNS,
_______,   KC_AT,     KC_LBRC,    KC_CIRC,  KC_RBRC,   KC_TILD,                                    KC_VOLD,   KC_VOLU,   KC_MNXT,   KC_MPRV,   KC_BSLS,   KC_PIPE,
                    _______,  QK_BOOT,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  QK_BOOT,     ADJUST,
                                                                      _______,            _______
    ),

[_RAISE] = LAYOUT(
_______,   _______,   _______,    _______,  _______,   _______,                               _______,   _______,   _______,   _______,   _______,   _______,
_______,   KC_MMON,   KC_DTL,     KC_DTR,   KC_MDT,    _______,                               _______,   KC_HOME,   KC_UP,     KC_END,    KC_INS,    _______,
_______,   KC_MXL,    KC_MIN,     KC_MAX,   KC_MXR,    _______,                                         _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______,   _______,
_______,   _______,   _______,    _______,  _______,   _______,                                         _______,   KC_PGUP,   _______,   KC_PGDN,   KC_BSLS,   _______,
    ADJUST,  QK_BOOT,  _______,  _______,  _______,  _______,          _______,    _______,  _______,  _______,  QK_BOOT,  _______,
                                                                      _______,          _______
    ),

[_ADJUST] = LAYOUT(
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  KCAE,     KCOE,     KCAA,     _______,
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
                    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                                                      _______,            _______
    ),

    [_FOUR] = LAYOUT(
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  EH_SCR,   KC_BTN3,  KC_BTN2,  KC_BTN1,  EH_SNP,                                           EH_SNP,   KC_BTN1,  KC_BTN2,  KC_BTN3,  EH_SCR,   _______,
_______,  _______,  _______,  _______,  _______,  EH_TXT,                                           EH_TXT,   _______,  _______,  _______,  _______,  _______,
                    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                                                      _______,            _______
    ),
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, //
    [1] = {ENCODER_CCW_CW(_______, _______)}, //
    [2] = {ENCODER_CCW_CW(_______, _______)}, //
    [3] = {ENCODER_CCW_CW(_______, _______)}, //
    [4] = {ENCODER_CCW_CW(_______, _______)}, //
};
#endif
