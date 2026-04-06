#ifndef _VARIANT_PROMICRO_DIY_RA01SH_
#define _VARIANT_PROMICRO_DIY_RA01SH_

#define VARIANT_MCK (64000000ul)

// #define USE_LFXO
#define USE_LFRC

// Keeps VBUS detection working in Power.cpp
#define PROMICRO_DIY_TCXO

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
NRF52 PRO MICRO — AI-Thinker RA-01SH wiring

| RA-01SH | nRF Pin | Function      |
| ------- | ------- | ------------- |
| NSS     | P1.04   | SX126X_CS     |
| MOSI    | P0.11   | SPI MOSI      |
| MISO    | P1.00   | SPI MISO      |
| SCK     | P0.24   | SPI SCK       |
| BUSY    | P0.22   | SX126X_BUSY   |
| DIO1    | P1.15   | SX126X_DIO1   |
| RST     | P1.13   | SX126X_RESET  |
| 3V3     | P1.11   | Power (3.3V)  |

| GPS     | nRF Pin | Function      |
| ------- | ------- | ------------- |
| RX      | P0.09   | GPS_TX (MCU→) |
| TX      | P0.10   | GPS_RX (→MCU) |
| EN      | P1.06   | GPS enable    |
*/

#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (1)
#define NUM_ANALOG_OUTPUTS (0)

// Pin 13 enables 3.3V periphery (hardwired on Pro Micro PCB)
#define PIN_3V3_EN (0 + 13) // P0.13

// Battery ADC
#define BATTERY_PIN (0 + 31) // P0.31
#define ADC_CHANNEL ADC1_GPIO4_CHANNEL
#define ADC_RESOLUTION 14
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
#define VBAT_MV_PER_LSB (0.73242188F)
#define VBAT_DIVIDER (0.6F)
#define VBAT_DIVIDER_COMP (1.73)
#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)
#undef AREF_VOLTAGE
#define AREF_VOLTAGE 3.0
#define VBAT_AR_INTERNAL AR_INTERNAL_3_0
#define ADC_MULTIPLIER VBAT_DIVIDER_COMP
#define VBAT_RAW_TO_SCALED(x) (REAL_VBAT_MV_PER_LSB * x)

// LED
#define PIN_LED1 (0 + 15) // P0.15
#define LED_BLUE PIN_LED1
#define LED_STATE_ON 1

// Button
#define BUTTON_PIN (0 + 29) // P0.29

// GPS
#define GPS_TX_PIN (0 + 9)  // P0.09 — MCU TX → GPS module RX
#define GPS_RX_PIN (0 + 10) // P0.10 — MCU RX ← GPS module TX
#define PIN_GPS_EN (32 + 6) // P1.06

// UART interfaces
#define PIN_SERIAL1_TX GPS_TX_PIN
#define PIN_SERIAL1_RX GPS_RX_PIN

#define PIN_SERIAL2_RX (0 + 6) // P0.06
#define PIN_SERIAL2_TX (0 + 8) // P0.08

// SPI
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO (32 + 0) // P1.00
#define PIN_SPI_MOSI (0 + 11) // P0.11
#define PIN_SPI_SCK (0 + 24)  // P0.24

#define LORA_MISO PIN_SPI_MISO
#define LORA_MOSI PIN_SPI_MOSI
#define LORA_SCK PIN_SPI_SCK
#define LORA_CS (32 + 4) // P1.04

// SX1262 only — AI-Thinker RA-01SH (XTAL, internal RF switch)
#define USE_SX1262

#define SX126X_CS LORA_CS
#define SX126X_DIO1 (32 + 15)    // P1.15
#define SX126X_DIO2_AS_RF_SWITCH // RA-01SH handles TX/RX switching internally via DIO2
#define SX126X_BUSY (0 + 22)     // P0.22
#define SX126X_RESET (32 + 13)   // P1.13
#define LORA_RESET SX126X_RESET

#ifdef __cplusplus
}
#endif

#endif
