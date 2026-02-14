// Generic ESP32-S3 + external SX1276 (LoRa) – DIY variant
// Adjust pins below to match your wiring.

#pragma once

// No GPS by default on a generic DIY build
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// -------- Display (I2C SSD1306 OLED) --------
#define USE_SSD1306

#define I2C_SDA 18
#define I2C_SCL 17

// -------- User button (active-low, BOOT button on most dev-kits) --------
#define BUTTON_PIN 0
#define BUTTON_NEED_PULLUP

// -------- LED (accent / TX indicator) --------
// Uncomment if you want a heartbeat/TX LED:
// #define LED_POWER 2

// -------- LoRa radio – SX1276 / RFM95 --------
#define USE_RF95 // RFM95 / SX1276 / SX1278

#define LORA_SCK 12
#define LORA_MOSI 13
#define LORA_MISO 11
#define LORA_CS 10
#define LORA_RESET 9
#define LORA_DIO0 4 // IRQ
#define LORA_DIO1 5

// Uncomment if your module has an RF switch controlled by the MCU:
// #define SX127X_RXEN 7
// #define SX127X_TXEN 6
