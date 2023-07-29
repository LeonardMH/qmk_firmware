// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "quantum/action.h"

#include QMK_KEYBOARD_H

// Layer Definitions
#define BASE_LAYER 0
#define NUM_LAYER  1
#define SYM_LAYER  2
#define NAV_LAYER  3
#define FUN_LAYER  4

// Left Home Row Mod Keys
#define HOME_A LALT_T(KC_A)
#define HOME_S LGUI_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right Home Row Mod Keys
#define HOME_J    RCTL_T(KC_J)
#define HOME_K    RSFT_T(KC_K)
#define HOME_L    RGUI_T(KC_L)
#define HOME_SEMI RALT_T(KC_SCLN)

// Layer Tap
#define LT_RBSPC LT(NUM_LAYER, KC_BSPC)
#define LT_RENT  LT(SYM_LAYER, KC_ENT)
#define LT_LENT  LT(NAV_LAYER, KC_ENT)

// QMK Macros
enum custom_keycodes {
    TI_PASS = SAFE_RANGE,
    TI_AID,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TI_PASS:
      if (record->event.pressed) {
        SEND_STRING("xxxxxxxx");
      }

      break;

  case TI_AID:
      if (record->event.pressed) {
        SEND_STRING("xxxxxxxx");
      }

      break;
  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base Layer
  [BASE_LAYER] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_DEL,
    KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                             KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SEMI, KC_QUOT,
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   MO(FUN_LAYER),
                                        KC_BSPC, KC_SPC,  LT_LENT,        LT_RENT, KC_SPC,  LT_RBSPC
  ),

  // Number Layer
  [NUM_LAYER] = LAYOUT_split_3x6_3(
    _______, KC_PEQL, KC_7,    KC_8,    KC_9,    KC_PPLS,                            XXXXXXX, XXXXXXX, KC_EXLM, KC_PEQL, XXXXXXX, _______,
    _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS,                            KC_PPLS, KC_RCTL, KC_RSFT, KC_RGUI, KC_RALT, KC_QUOT,
    XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_DOT,                             KC_PAST, KC_PMNS, XXXXXXX, KC_DOT,  KC_SLSH, XXXXXXX,
                                        KC_BSPC, KC_SPC,  KC_ENT,          KC_ENT,   KC_SPC,  _______
  ),

  // Symbol Layer
  [SYM_LAYER] = LAYOUT_split_3x6_3(
    _______, KC_GRV,  KC_LPRN, KC_RPRN, KC_AMPR, KC_PIPE,                            KC_CIRC, KC_DLR,  KC_EXLM, KC_PEQL, XXXXXXX,   _______,
    _______, KC_TILD, KC_LBRC, KC_RBRC, KC_HASH, KC_MINS,                            KC_PERC, KC_RCTL, KC_RSFT, KC_RGUI, HOME_SEMI, KC_QUOT,
    KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_AT,   KC_UNDS,                            KC_PAST, KC_LABK, KC_RABK, KC_COLN, KC_QUES,   XXXXXXX,
                                        KC_BSPC, KC_SPC,  KC_ENT,          _______,  KC_SPC,  KC_BSPC
  ),

  // Navigation Layer
  [NAV_LAYER] = LAYOUT_split_3x6_3(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,  KC_PSCR, _______,
    _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_INS,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_HOME, KC_END,  XXXXXXX,  KC_PAUS, XXXXXXX,
                                        KC_BSPC, KC_SPC,  _______,          KC_ENT,  KC_SPC,  KC_BSPC
  ),

  // Function Layer
  [FUN_LAYER] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F10,  KC_F7,   KC_F8,   KC_F9,   KC_VOLU,                            TI_AID,  TI_PASS, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_VOLD,                            KC_CAPS, KC_RCTL, KC_RSFT, KC_RGUI, KC_RALT, QK_RBT,
    XXXXXXX, KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_MUTE,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        KC_MPRV, KC_MPLY, KC_MNXT,          KC_ENT,  KC_SPC,  KC_BSPC
  )
};
