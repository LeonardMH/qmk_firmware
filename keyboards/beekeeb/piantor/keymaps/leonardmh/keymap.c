// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H

// Layer Definitions
#define BASE_LAYER 0
#define NUM_LAYER  1
#define SYM_LAYER  2
#define NAV_LAYER  3
#define DBG_LAYER  4

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

#define KBOOT QK_BOOTLOADER

// Tap-Dance Keys
enum {
  TD_TAB_ESC,
};

tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Tab, twice for Escape
  [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
};

#define TAB_ESC TD(TD_TAB_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base Layer
  [BASE_LAYER] = LAYOUT_split_3x6_3(
    TAB_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_DEL,
    XXXXXXX,   HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                            KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SEMI, KC_QUOT,
    XXXXXXX,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   MO(DBG_LAYER),
                                          KC_BSPC, KC_SPC, LT_LENT,        LT_RENT, KC_SPC,  LT_RBSPC
  ),

  // Number Layer
  [NUM_LAYER] = LAYOUT_split_3x6_3(
    _______, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_EQL,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS,                            XXXXXXX, KC_RCTL, KC_RSFT, KC_RGUI, KC_RALT, XXXXXXX,
    XXXXXXX, KC_DOT,  KC_1,    KC_2,    KC_3,    KC_PPLS,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,         _______,  _______, _______
  ),

  // Symbol Layer
  [SYM_LAYER] = LAYOUT_split_3x6_3(
    _______, KC_TILD, KC_EXLM, KC_LPRN, KC_RPRN, KC_PIPE,                            XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_GRV,  KC_HASH, KC_LCBR, KC_RCBR, KC_BSLS,                            XXXXXXX, KC_RCTL, KC_RSFT, KC_RGUI, KC_RALT, XXXXXXX,
    KBOOT,   XXXXXXX, KC_AT,   KC_LBRC, KC_RBRC, KC_SLSH,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        _______, _______, _______,          _______, _______, _______
  ),

  // Navigation Layer
  [NAV_LAYER] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_PGUP, KC_UP,   KC_HOME,  XXXXXXX, _______,
    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX,                            XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
    KBOOT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_PGDN, KC_PSCR, KC_END,   XXXXXXX, _______,
                                        _______, _______, _______,          _______, _______, _______
  ),

  // Debug Layer (Dedicated)
  [DBG_LAYER] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KBOOT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
  )
};
