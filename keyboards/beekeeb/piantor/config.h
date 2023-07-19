// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define TAPPING_TERM       180

// Eannble rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM     0

// Enable CAPS_WORD by pressing both shift keys
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
