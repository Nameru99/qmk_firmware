/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _SDEFAULT, //system default
  _DVORAK_Z, //dvorak based on qwertz
  _DVORAK_Y, //dvorak based on qwerty
  _LOWER, //lower based on qwerty
  _RAISE, // raised based on qwerty
  _RAISE_Z, // raised based on qwertz
  _SHIFT_Y, // shift layer based on qwerty
  _ADJUST
};

enum planck_keycodes {
  SDEFAULT = SAFE_RANGE,
  DVORAK_Z,
  DVORAK_Y
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define RAISE_Z MO(_RAISE_Z)
#define SHIFT_Y MO(_SHIFT_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty (system default)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | GUI  | ALT  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SDEFAULT] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak - QWERTZ
 * ,-----------------------------------------------------------------------------------.
 * | Tab  | [(ü) |   ,  |   .  |   P  | Y(Z) |   F  |   G  |   C  |   T  | Z(Y) | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   I  |   U  |   H  |   D  |   R  |   N  |   S  |  L   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift| '(ä) |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  | ;(ö) |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | GUI  |  Alt |Lower |    Space    |RaiseZ| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK_Z] = LAYOUT_planck_grid(
    KC_TAB,  KC_LBRC, KC_COMM, KC_DOT,  KC_P,    KC_Z,    KC_F,    KC_G,    KC_C,    KC_T,    KC_Y,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_I,    KC_U,    KC_H,    KC_D,    KC_R,    KC_N,    KC_S,    KC_L,
    KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V, 	KC_SCLN,   KC_ENT ,
    KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE_Z,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak - QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   [  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   T  |   Z  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   I  |   U  |   H  |   D  |   R  |   N  |   S  |  L   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   #  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | GUI  |  Alt |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK_Y] = LAYOUT_planck_grid(
    KC_TAB,  KC_LBRC, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_T,    KC_Z,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_I,    KC_U,    KC_H,    KC_D,    KC_R,    KC_N,    KC_S,    KC_L,
    KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V, 	KC_HASH,   KC_ENT ,
    KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower (qwerty base)
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   ?  | '(ä) | ;(ö) | [(ü) | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_QUES,    KC_QUOT,    KC_SCLN, KC_LBRC, KC_BSPC,
	_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   	 KC_7,  KC_8,    KC_9,    KC_0, 	KC_MINS,
	KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, 	KC_F7,	KC_F8,   KC_F9,   KC_F10,  	KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise (qwerty base)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   {  |   [  |   ]  |   }  |   |  |   !  |   /  |   %  |   ^  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   @  |   (  |   )  |   =  |   *  |   +  |   -  |   #  |   &  |   ~  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   <  |   >  |   ?  |      |      |   \  |Pg Up |Pg Dn |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_LCBR,   KC_LBRC,   KC_RBRC,   KC_RCBR,   KC_PIPE,    KC_EXLM,    KC_SLSH,   KC_PERC,    KC_CIRC,    KC_MINS,    KC_BSPC,
    KC_DEL,  KC_AT, 	KC_LPRN,   KC_RPRN,   KC_EQL,  	 KC_ASTR,  	 KC_PLUS, 	 KC_MINS, 	KC_HASH,  	KC_AMPR, 	KC_TILD, 	KC_UNDS,
    _______, _______,	KC_LT,  	KC_GT,   KC_QUES,   _______,  _______,  	KC_BSLS, 	KC_PGUP,	KC_PGDN, 	_______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise (qwertz base)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   {  |   [  |   ]  |   }  |   |  |   !  |   /  |   %  |   ^  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   @  |   (  |   )  |   =  |   *  |   +  |   -  |   #  |   &  |   ~  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   '  |   <  |   >  |  ss  |   ?  |   \  | home |Pg Up |Pg Dn | end  |      |
* |------+------+------+------+------+------+------+------+------+------+------+-------| 
 * |RAISE |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE_Z] = LAYOUT_planck_grid(
    S(KC_EQL),  ALGR(KC_7),    ALGR(KC_8),    ALGR(KC_9),    ALGR(KC_0),    ALGR(KC_NUBS),    S(KC_1),    S(KC_7),    S(KC_5),    KC_GRV,    KC_SLSH,    KC_BSPC,
    KC_DEL,     ALGR(KC_Q),    S(KC_8),     S(KC_9),        S(KC_0),        S(KC_RBRC),   KC_RBRC,       KC_SLSH,    KC_BSLS,    S(KC_6),    ALGR(KC_RBRC),    S(KC_SLSH),
    _______, S(KC_BSLS),  KC_NUBS,   S(KC_NUBS),   KC_MINS,  S(KC_MINS),  _______,  KC_HOME, KC_PGUP, KC_PGDN, KC_END, _______,
    RAISE, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|DEFAU.|DVOR_Y|DVOR_X|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, SDEFAULT,  DVORAK_Y,  DVORAK_Z,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SDEFAULT:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_SDEFAULT);
      }
      return false;
      break;
    case DVORAK_Y:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK_Y);
      }
      return false;
      break;
    case DVORAK_Z:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK_Z);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
