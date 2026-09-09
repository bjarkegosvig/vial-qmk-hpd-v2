#include QMK_KEYBOARD_H
#include "ergohaven.h"
#include "src/eh_pointing.h"

// see https://docs.qmk.fm/#/keycodes for keycodes

#define KC_MWL   LGUI(LCTL(KC_LEFT)) // Switch to the previous virtual desktop
#define KC_MWR   LGUI(LCTL(KC_RIGHT)) //Switch to the next virtual desktop
#define KC_MXL   LGUI(LSFT(KC_LEFT)) // Move current window to the screen on the left of current screen
#define KC_MXR   LGUI(LSFT(KC_RIGHT)) // // Moce current window to the screen on the right of current screen
#define KC_MWSL  LGUI(LCTL(LSFT(KC_LEFT))) // Move current window to the previous desktop - see  https://superuser.com/questions/1685845/moving-current-window-to-another-desktop-in-windows-11-using-shortcut-keys
#define KC_MWSR  LGUI(LCTL(LSFT(KC_RIGHT))) // Move current window to the next desktop - see https://superuser.com/questions/1685845/moving-current-window-to-another-desktop-in-windows-11-using-shortcut-keys
#define KC_MAX   LGUI(KC_LEFT) // Snap current window to the left side of the screen
#define KC_MIN   LGUI(KC_RIGHT) // Snap current window to the right side of the screen
#define KC_MAXI  LGUI(KC_UP) // Maximize current window
#define KC_MINI  LGUI(KC_DOWN) // Minimize curreng windows
#define KC_GMX   LGUI(LSFT(KC_GRAVE))

#define KC_WSV  LCTL(LSFT(KC_ENTER)) // wezterm split pane vertical
#define KC_WSH  LCTL(LSFT(KC_EQL)) // wezterm split pane horizontal
#define KC_WRP  LALT(LCTL(KC_F)) // wezterm rotate/promote pane
#define KC_WNP  LSFT(LCTL(KC_LEFT_BRACKET)) // wezterm move to next pane
#define KC_WPP  LSFT(LCTL(KC_RIGHT_BRACKET)) // wezterm move to previously pane
#define KC_WIF  LCTL(KC_EQL) // wezterm increase front size
#define KC_WDF  LCTL(KC_MINUS) // wezterm decrease font size
#define KC_WRF  LCTL(KC_0) // wezterm reset front size
#define KC_Launch LGUI(LALT(KC_SPACE))

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
 * ,-------------------------------------------.                    ,-------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | TG NM  |
 * |--------+------+------+------+------+-------                    |------+------+------+------+------+--------|
 * |Tab/ARRW|   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   +=   |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * | Shift  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  | ;    |   '"   |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |   /  |  _-    |
 * `--------+------+------+------+------+------'                    `-------------+------+------+------+--------'
 *          | L FUN | PGUP |                                                      | PGDN | L ARRW|
 *          `--------------'                            		   		          '--------------'
 *						    ,------------------------------.                        ,-----------------------------.
 *						    |  LCTRL | Space| Enter|   ~   |                        |  LGUI | Shift | BckSP| LALT |
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


/*
 * ,-----------------------------------------------.             ,-----------------------------------------------.
 * |            |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 |    F11     |
 * |------------+------+------+------+------+------|             |------+------+------+------+------+------------|
 * |    +       |   |  |   {  |   %  |   }  |   &  |             | Mute | Home |  Up  | End  |Insert|    +       |
 * |------------+------+------+------+------+------|             |------+------+------+------+------+------------|
 * |            |   #  |   (  |   $  |   )  |   *  |             | Play | Left | Down |Right |      | (un)lck    |
 * |------------+------+------+------+------+------|             |------+------+------+------+------+------------|
 * |            |   @  |   [  |   ^  |   ]  |   ~  |             | VolDn|VolUp |NextTk|PrevTk|   \  |     |      |
 * `------------+------+------+------+------+------'             `------+------+------+------+------+------------'
 *          |       | Boot |                                                      | Boot | ADJUST|
 *          `--------------'                            		   		          '--------------'
 *				     ,------------------------------.                        ,-----------------------------.
 *				     |        |      |      |       |                        |       |       |      |      |
 *                   `------------------------------'                        `-----------------------------'
 *
 */


[_LOWER] = LAYOUT(
_______,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                                      KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,
KC_PLUS,   KC_PIPE,   KC_LCBR,    KC_PERC,  KC_RCBR,   KC_AMPR,                                    KC_MUTE,   KC_HOME,   KC_UP,     KC_END,    KC_INS,    KC_PLUS,
_______,   KC_HASH,   KC_LPRN,    KC_DLR,   KC_RPRN,   KC_ASTR,                                    KC_MPLY,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO,     KC_TRNS,
_______,   KC_AT,     KC_LBRC,    KC_CIRC,  KC_RBRC,   KC_TILD,                                    KC_VOLD,   KC_VOLU,   KC_MNXT,   KC_MPRV,   KC_BSLS,   KC_PIPE,
                    _______,  QK_BOOT,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  QK_BOOT,     ADJUST,
                                                                      _______,            _______
    ),

/*
 * ,-----------------------------------------------.           ,-----------------------------------------------.
 * |            |      |      |      |      |Launch|           |      |      |      |      |      |            |
 * |------------+------+------+------+------+------|           |------+------+------+------+------+------------|
 * |            |      |      |      |      |      |           |      | Home |  Up  | End  |Insert|            |
 * |------------+------+------+------+------+------|           |------+------+------+------+------+------------|
 * |            |      |      |      |      |      |           |      | Left | Down |Right |      |            |
 * |------------+------+------+------+------+------|           |------+------+------+------+------+------------|
 * |            |      |      |      |      |      |           |      | PGUP |      | PGDN |   \  |            |
 * `------------+------+------+------+------+------'           `------+------+------+------+------+------------'
 *          | ADJUST| Boot |                                                      | Boot |       |
 *          `--------------'                            		   		          '--------------'
 *				     ,------------------------------.                        ,-----------------------------.
 *				     |        |      |      |       |                        |       |       |      |      |
 *                   `------------------------------'                        `-----------------------------'
 *
 */

[_RAISE] = LAYOUT(
_______,   _______,   _______,    _______,  _______,   KC_Launch,                             _______,   _______,   _______,   _______,   _______,   _______,
KC_WSH,    KC_WSV,    KC_WNP,     KC_WPP,   KC_WRF,    _______,                               _______,   KC_HOME,   KC_UP,     KC_END,    KC_INS,    _______,
_______,   KC_MXL,    KC_MXR,     KC_MAX,   KC_MIN,    KC_MAXI,                               _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______,   _______,
_______,   KC_MWSL,   KC_MWSR,    KC_MWL,   KC_MWR,    KC_MINI,                               _______,   KC_PGUP,   _______,   KC_PGDN,   KC_BSLS,   _______,
    ADJUST,  QK_BOOT,  _______,  _______,  _______,  _______,          _______,          _______,  _______,  _______,  QK_BOOT,  _______,
                                                                       _______,          _______
    ),

/*
 * ,-----------------------------------------------.           ,-----------------------------------------------.
 * |            |      |      |      |      |      |           |      |      |      |      |      |            |
 * |------------+------+------+------+------+------|           |------+------+------+------+------+------------|
 * |            |      |      |      |      |      |           |      |      |      |      |      |            |
 * |------------+------+------+------+------+------|           |------+------+------+------+------+------------|
 * |            |      |      |      |      |      |           |      |      |   æ  |   ø  |  å   |            |
 * |------------+------+------+------+------+------|           |------+------+------+------+------+------------|
 * |            |      |      |      |      |      |           |      |      |      |      |      |            |
 * `------------+------+------+------+------+------'           `------+------+------+------+------+------------'
 *          |       |      |                                                      |      |       |
 *          `--------------'                            		   		          '--------------'
 *				     ,------------------------------.                        ,-----------------------------.
 *				     |        |      |      |       |                        |       |       |      |      |
 *                   `------------------------------'                        `-----------------------------'
 *
 */

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
    [1] = {ENCODER_CCW_CW(MS_WHLD, _______)}, //
    [2] = {ENCODER_CCW_CW(MS_WHLU, _______)}, //
    [3] = {ENCODER_CCW_CW(_______, _______)}, //
    [4] = {ENCODER_CCW_CW(_______, _______)}, //
};
#endif
