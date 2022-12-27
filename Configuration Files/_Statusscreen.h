// Release Version: v4.2.3
// Release Date: 12-27-2022
/**
 * Firmware Version 4.2.3
 * Only For CPU Type: STM32F103RET6 (For older Creality v4.2.3 Ender 2 Pro Motherboards)

 * File Name: _Statusscreen.h
 * File Directory: Marlin\_Statusscreen.h
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 Marlin Firmware
 * CHANGE DATE 12-27-2022
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 * 
 * For The Creality Ender 2 Pro, Version 4.2.3 Firmware is for the v4.2.3 MAIN CONTROL BOARD (CPU Type: STM32F103RET6)
 * Reconfigured from Original Creality Firmware v2.0.6.1 to v4.2.3 by The 300lb Gorilla
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details......................
 *
 */

#pragma once

#define STATUS_SCREEN_X 72    //<----Status Screen is turned off in Configuration.h in order to alow the Ender 2 Pro to boot faster (The 300lb Gorilla)
#define STATUS_LOGO_WIDTH 40

const unsigned char status_logo_bmp[] PROGMEM = {
  B00000000,B00000000,B00000000,B00000000,B00000000,   // Line 22 to Line 40 have been set to B00000000, which blanks out any text or bitmap (The 300lb Gorilla) 
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,
};
