/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Arduino Mega with RAMPS v1.4 adjusted pin assignments
 *
 *  MKS GEN v1.3  (Extruder, Fan, Bed)
 *  MKS GEN v1.3  (Extruder, Extruder, Fan, Bed)
 *  MKS GEN v1.4  (Extruder, Fan, Bed)
 *  MKS GEN v1.4  (Extruder, Extruder, Fan, Bed)
 */

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS GEN 1.3/1.4 supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_NAME "MKS GEN >= v1.3"

//
// Heaters / Fans
//
// Power outputs EFBF or EFBE
#define MOSFET_D_PIN 7

//
// PSU / SERVO
//
// If POWER_SUPPLY is specified, always hijack Servo 3
//
#if POWER_SUPPLY > 0
  #define SERVO3_PIN      -1
  #define PS_ON_PIN        4
#endif

#include "pins_RAMPS.h"

//
// LCD / Controller
//
#if ENABLED(VIKI2) || ENABLED(miniVIKI)
  /**
   * VIKI2 Has two groups of wires with...
   *
   * +Vin     + Input supply, requires 120ma for LCD and mSD card
   * GND      Ground Pin
   * MOSI     Data input for LCD and SD
   * MISO     Data output for SD
   * SCK      Clock for LCD and SD
   * AO       Reg. Sel for LCD
   * LCS      Chip Select for LCD
   * SDCS     Chip Select for SD
   * SDCD     Card Detect pin for SD
   * ENCA     Encoder output A
   * ENCB     Encoder output B
   * ENCBTN   Encoder button switch
   *
   * BTN      Panel mounted button switch
   * BUZZER   Piezo buzzer
   * BLUE-LED Blue LED ring pin (3 to 5v, mosfet buffered)
   * RED-LED  Red LED ring pin (3 to 5v, mosfet buffered)
   *
   * This configuration uses the following arrangement:
   *
   * config for ender display
   * 5V = PIN1                        D41 = PIN1
   * EXP1 D37 = BUZZ   D35 = ENC      EXP2 D50 = MISO    D52 = SCK
   *      D17 = LCDE   D16 = LCDRS         D31 = EN2     D53 = SDCS
   *      D23 = LCD4   D25 = LCD5          D33 = EN1     D51 = MOSI
   *      D27 = LCD6   D29 = LCD7          D49 = SDCD    RST = RESET
   *      GND = GND    5V  = 5V            GND = GND     D41 = KILL
   *
   */



  #undef BTN_EN1
  #undef BTN_EN2
  #undef BTN_ENC
  #undef SD_DETECT_PIN
  #undef BEEPER_PIN
  #undef KILL_PIN

  //
  // VIKI2 12-wire lead
  //

  // orange/white         SDCD
  #define SD_DETECT_PIN   49

  // white                ENCA
  #define BTN_EN1         33

  // green                ENCB
  #define BTN_EN2         31

  // purple               ENCBTN
  #define BTN_ENC         35

                       // 50    gray   MISO
                       // 51    yellow MOSI
                       // 52    orange SCK

  // blue                 SDCS
  //#define SDSS            53

  //
  // VIKI2 4-wire lead
  //

  // blue                 BTN
  #define KILL_PIN        41

  // green                BUZZER
  #define BEEPER_PIN      37

  #define LCD_PINS_RS     16
  #define LCD_PINS_ENABLE 17
  #define LCD_PINS_D4     23
  #define LCD_PINS_D5     25
  #define LCD_PINS_D6     27
  #define LCD_PINS_D7     29


#endif
