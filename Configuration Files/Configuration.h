// Release Version: v3.1.5
// Release Date: 12-27-2022
/**
 * Firmware Version 3.1.5
 * Only For CPU Type: STM32F103RET6 (For older Creality 4.2.3 Ender 2 Pro Mainboards)

 * File Name: Configuration_.h
 * File Directory: Marlin\Configuration.h
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 Marlin Firmware
 * Change Date 11-8-2022
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 * 
 * For The Creality Ender 2 Pro, Version 3.1.5 Firmware is for the 4.2.3 MAIN CONTROL BOARD (CPU Type: STM32F103RET6)
 * Reconfigured from Original Creality Firmware v2.0.6.1 to v3.1.5 by The 300lb Gorilla
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details..
 *
 */


#pragma once

#define CONFIGURATION_H_VERSION 020006
// @section info

#define STRING_CONFIG_H_AUTHOR "The 300lb Gorilla" // Who made the changes.    CHANGE DATE 11-8-2022  Firmware Version 3.1.5
//#define CUSTOM_VERSION_FILE Version.h 

#define SHOW_BOOTSCREEN

#define SHOW_CUSTOM_BOOTSCREEN           //<------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5 Enabled

//#define CUSTOM_STATUS_SCREEN_IMAGE    //<--------------(Disabled to Clean Up Main Status Screen)----------------------------------------  Gorilla-Tech v3.1.5 Disabled

// @section machine

#define SERIAL_PORT 1

#define SERIAL_PORT_2 3

#define BAUDRATE 115200

//#define BLUETOOTH

// Define Main Control Board (Creality 4.2.3)<------------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5
// default_envs = STM32F103RET6_creality (From Platformio.ini File)<---------------------------------------------- Stock Ender 2 Pro OEM BOARD 4.2.3 Gorilla-Tech v3.1.5
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_CREALITY_V4  //<------------------------------------------Only For CPU Type: STM32F103RET6 (For older Creality 4.2.3 Ender 2 Pro Mainboards)
#endif                                                                              //This will NOT work on Mainboard version 2.4.s4

#define CUSTOM_MACHINE_NAME "Ender 2 Pro Beta v3.1.5"     //<-----(Removed "-" Between Ender and 2)------------------------------------------------------------- Gorilla-Tech v3.1.5
                                                      
//#define MACHINE_UUID "00000000-0000-0000-0000-000000000000"

// @section extruder

#define EXTRUDERS 1

#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

//#define SINGLENOZZLE  //<----(No need to change because the Ender 2 Pro comes by default with only 1 nozzle)-----------------------------------------Gorilla-Tech v3.1.5
#if ENABLED(SINGLENOZZLE)
  //#define SINGLENOZZLE_STANDBY_TEMP
  //#define SINGLENOZZLE_STANDBY_FAN
#endif

//#define MK2_MULTIPLEXER
#if ENABLED(MK2_MULTIPLEXER)
  //#define E_MUX0_PIN 40
  //#define E_MUX1_PIN 42
  //#define E_MUX2_PIN 44
#endif

//#define PRUSA_MMU2

//#define SWITCHING_EXTRUDER
#if ENABLED(SWITCHING_EXTRUDER)
  #define SWITCHING_EXTRUDER_SERVO_NR 0
  #define SWITCHING_EXTRUDER_SERVO_ANGLES { 0, 90 }
  #if EXTRUDERS > 3
    #define SWITCHING_EXTRUDER_E23_SERVO_NR 1
  #endif
#endif

//#define SWITCHING_NOZZLE
#if ENABLED(SWITCHING_NOZZLE)
  #define SWITCHING_NOZZLE_SERVO_NR 0
  //#define SWITCHING_NOZZLE_E1_SERVO_NR 1
  #define SWITCHING_NOZZLE_SERVO_ANGLES { 0, 90 }
#endif

//#define PARKING_EXTRUDER

//#define MAGNETIC_PARKING_EXTRUDER

#if EITHER(PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER)

  #define PARKING_EXTRUDER_PARKING_X { -78, 184 }
  #define PARKING_EXTRUDER_GRAB_DISTANCE 1
  //#define MANUAL_SOLENOID_CONTROL
  #if ENABLED(PARKING_EXTRUDER)

    #define PARKING_EXTRUDER_SOLENOIDS_INVERT
    #define PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE LOW  
    #define PARKING_EXTRUDER_SOLENOIDS_DELAY 250        
    //#define MANUAL_SOLENOID_CONTROL

  #elif ENABLED(MAGNETIC_PARKING_EXTRUDER)

    #define MPE_FAST_SPEED      9000      
    #define MPE_SLOW_SPEED      4500      
    #define MPE_TRAVEL_DISTANCE   10      
    #define MPE_COMPENSATION       0      

  #endif

#endif

//#define SWITCHING_TOOLHEAD

//#define MAGNETIC_SWITCHING_TOOLHEAD

//#define ELECTROMAGNETIC_SWITCHING_TOOLHEAD

#if ANY(SWITCHING_TOOLHEAD, MAGNETIC_SWITCHING_TOOLHEAD, ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
  #define SWITCHING_TOOLHEAD_Y_POS          235         
  #define SWITCHING_TOOLHEAD_Y_SECURITY      10         
  #define SWITCHING_TOOLHEAD_Y_CLEAR         60         
  #define SWITCHING_TOOLHEAD_X_POS          { 215, 0 }  
  #if ENABLED(SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_SERVO_NR       2         
    #define SWITCHING_TOOLHEAD_SERVO_ANGLES { 0, 180 }  
  #elif ENABLED(MAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Y_RELEASE      5         
    #define SWITCHING_TOOLHEAD_X_SECURITY   { 90, 150 } 
    //#define PRIME_BEFORE_REMOVE                       
    #if ENABLED(PRIME_BEFORE_REMOVE)
      #define SWITCHING_TOOLHEAD_PRIME_MM           20  
      #define SWITCHING_TOOLHEAD_RETRACT_MM         10  
      #define SWITCHING_TOOLHEAD_PRIME_FEEDRATE    300  
      #define SWITCHING_TOOLHEAD_RETRACT_FEEDRATE 2400  
    #endif
  #elif ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Z_HOP          2         
  #endif
#endif

//#define MIXING_EXTRUDER
#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 2        
  #define MIXING_VIRTUAL_TOOLS 16  
  //#define DIRECT_MIXING_IN_G1    
  //#define GRADIENT_MIX           
  #if ENABLED(GRADIENT_MIX)
    //#define GRADIENT_VTOOL       
  #endif
#endif

//#define HOTEND_OFFSET_X { 0.0, 20.00 } // (mm) relative X-offset for each nozzle
//#define HOTEND_OFFSET_Y { 0.0, 5.00 }  // (mm) relative Y-offset for each nozzle
//#define HOTEND_OFFSET_Z { 0.0, 0.00 }  // (mm) relative Z-offset for each nozzle

// @section machine

//#define PSU_CONTROL
//#define PSU_NAME "Power Supply"

#if ENABLED(PSU_CONTROL)
  #define PSU_ACTIVE_HIGH false     

  //#define PSU_DEFAULT_OFF         
  //#define PSU_POWERUP_DELAY 250   

  //#define AUTO_POWER_CONTROL      
  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS         
    #define AUTO_POWER_E_FANS
    #define AUTO_POWER_CONTROLLERFAN
    #define AUTO_POWER_CHAMBER_FAN
    //#define AUTO_POWER_E_TEMP        50 
    //#define AUTO_POWER_CHAMBER_TEMP  30 
    #define POWER_TIMEOUT 30
  #endif
#endif

// @section temperature

#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_6 0
#define TEMP_SENSOR_7 0
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_PROBE 0
#define TEMP_SENSOR_CHAMBER 0
#define DUMMY_THERMISTOR_998_VALUE 25
#define DUMMY_THERMISTOR_999_VALUE 100
//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10
#define TEMP_RESIDENCY_TIME     10  
#define TEMP_WINDOW              1  
#define TEMP_HYSTERESIS          3  
#define TEMP_BED_RESIDENCY_TIME 10  
#define TEMP_BED_WINDOW          1  
#define TEMP_BED_HYSTERESIS      3  
#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define HEATER_6_MINTEMP   5
#define HEATER_7_MINTEMP   5
#define BED_MINTEMP        5
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 255
#define HEATER_2_MAXTEMP 255
#define HEATER_3_MAXTEMP 255
#define HEATER_4_MAXTEMP 255
#define HEATER_5_MAXTEMP 255
#define HEATER_6_MAXTEMP 255
#define HEATER_7_MAXTEMP 255
#define BED_MAXTEMP       90 //<------------------ (Reduced from 100c) ----------------------------------------------------------------------------- Gorilla-Tech v3.1.5
#define PIDTEMP
#define BANG_MAX 255     
#define PID_MAX BANG_MAX 
#define PID_K1 0.95      
#if ENABLED(PIDTEMP)
  #define PID_EDIT_MENU           
  #define PID_AUTOTUNE_MENU       
  //#define PID_PARAMS_PER_HOTEND

  // Ender-2 Pro  with silicone sock and 100% fan tuned at 220c
  #define DEFAULT_Kp 10.3
  #define DEFAULT_Ki 0.53
  #define DEFAULT_Kd 49.8

  // MakerGear
  //#define DEFAULT_Kp 7.0
  //#define DEFAULT_Ki 0.1
  //#define DEFAULT_Kd 12

  // Mendel Parts V9 on 12V
  //#define DEFAULT_Kp 63.0
  //#define DEFAULT_Ki 2.25
  //#define DEFAULT_Kd 440

#endif // PIDTEMP

#define PIDTEMPBED

//#define BED_LIMIT_SWITCHING   //<-------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Disabled
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current
#if ENABLED(PIDTEMPBED)
  //#define MIN_BED_POWER 0
  //#define PID_BED_DEBUG 

  //24V 270W silicone heater onto 3mm Aluminium (Ender-2 Pro) tuned at 55c
  #define DEFAULT_bedKp 96.72
  #define DEFAULT_bedKi 16.17
  #define DEFAULT_bedKd 385.83

  //120V 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)
  //from pidautotune
  //#define DEFAULT_bedKp 97.1
  //#define DEFAULT_bedKi 1.41
  //#define DEFAULT_bedKd 1675.16
#endif // PIDTEMPBED

#if EITHER(PIDTEMP, PIDTEMPBED)
  //#define PID_DEBUG             
  //#define PID_OPENLOOP          
  //#define SLOW_PWM_HEATERS      
  #define PID_FUNCTIONAL_RANGE 20 

#endif

// @section extruder

#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170         //<-------------------------- (Changed from 180c to 170c) ------------------------------------------------------ Gorilla-Tech v3.1.5 

#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 500       //<----------------- (Longer Feed) ----------------------------------------------------------------------------- Gorilla-Tech v3.1.5 

#define THERMAL_PROTECTION_HOTENDS   // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED       // Enable thermal protection for the heated bed
//#define THERMAL_PROTECTION_CHAMBER //<---------------- (No Chamber On An Ender 2 Pro) --------------------------------------------------- Gorilla-Tech v3.1.5 Disabled 

// @section machine

//#define COREXY
//#define COREXZ
//#define COREYZ
//#define COREYX
//#define COREZX
//#define COREZY

// @section homing

#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG
//#define USE_XMAX_PLUG
//#define USE_YMAX_PLUG
//#define USE_ZMAX_PLUG
#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
  // Disable ENDSTOPPULLUPS to set pullups individually
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // Disable ENDSTOPPULLDOWNS to set pulldowns individually
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

#define X_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // Set to true to invert the logic of the probe.
#define X_DRIVER_TYPE TMC2208_STANDALONE //<---------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Confirmed
#define Y_DRIVER_TYPE TMC2208_STANDALONE //<---------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Confirmed
#define Z_DRIVER_TYPE A4988              //<---------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Confirmed
//#define X2_DRIVER_TYPE A4988           
//#define Y2_DRIVER_TYPE A4988
//#define Z2_DRIVER_TYPE A4988
//#define Z3_DRIVER_TYPE A4988
//#define Z4_DRIVER_TYPE A4988
#define E0_DRIVER_TYPE A4988             //<---------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Confirmed
//#define E1_DRIVER_TYPE A4988
//#define E2_DRIVER_TYPE A4988
//#define E3_DRIVER_TYPE A4988
//#define E4_DRIVER_TYPE A4988
//#define E5_DRIVER_TYPE A4988
//#define E6_DRIVER_TYPE A4988
//#define E7_DRIVER_TYPE A4988
#define ENDSTOP_INTERRUPTS_FEATURE
//#define ENDSTOP_NOISE_THRESHOLD 2
//#define DETECT_BROKEN_ENDSTOP         //<------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5 Disabled

// @section motion

//#define DISTINCT_E_FACTORS
//***************************************************************************************************************************************************************
//*******************************************************IMPORTANT Information***********************************************************************************
//***************************************************************************************************************************************************************
// WARNING: you can only define one DEFAULT_AXIS_STEPS_PER_UNIT at a time, if you leave both uncommented, the firmware will NOT compile
// MAKE SURE THAT AT LEAST ONE IS UNCOMMENTED FOR THE FIRMWARE TO COMPILE
// Uncomment 92.6 E-Steps for Regular Stock Extruder (Line 369), and Comment out "//" (Line 371)
//#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 92.6 }       //<-------------------- Gorilla-Tech v3.1.5 Set to 92.6 for Stock Regular Extruder
// Uncomment 143.5 E-Steps for Dual Gear Extruder (Line 371), and Comment out "//" (Line 369)
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 143.5 }        //<-------------------- Gorilla Tech v3.1.5 Set to 143.5 for Dual Gear Extruder
//***************************************************************************************************************************************************************
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }

#define LIMITED_MAX_FR_EDITING        // Limit edit via M203 or LCD to DEFAULT_MAX_FEEDRATE * 2 //<----------------------------------------- Gorilla-Tech v3.1.5 Enabled
#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 600, 600, 10, 50 }
#endif

#define DEFAULT_MAX_ACCELERATION      { 300, 300, 100, 1000 }     //<------------------------------------------------------------- Gorilla-Tech v3.1.5 Changed - Doubled

#define LIMITED_MAX_ACCEL_EDITING     // Limit edit via M201 or LCD to DEFAULT_MAX_ACCELERATION * 2 //<------------------------------------- Gorilla-Tech v3.1.5 Enabled
#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 6000, 6000, 200, 20000 } // ...or, set your own edit limits
#endif

#define DEFAULT_ACCELERATION          300    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  300    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   600    // X, Y, Z acceleration for travel (non printing) moves

#define CLASSIC_JERK     //<---------------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Enabled
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 6.0
  #define DEFAULT_YJERK 6.0
  #define DEFAULT_ZJERK  0.4
//#define TRAVEL_EXTRA_XYJERK 0.0
  #define LIMITED_JERK_EDITING        // Limit edit via M205 or LCD to DEFAULT_aJERK * 2 <-------------------------------------------------- Gorilla-Tech v3.1.5 Enabled
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits
  #endif
#endif

#define DEFAULT_EJERK    5.0

#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.013 
  #define JD_HANDLE_SMALL_SEGMENTS    

#endif

#define S_CURVE_ACCELERATION     //<-------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Enabled

// @section probes

#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
//#define USE_PROBE_FOR_Z_HOMING
//#define Z_MIN_PROBE_PIN 32 // Pin 32 is the RAMPS default
//#define PROBE_MANUALLY
//#define MANUAL_PROBE_START_Z 0.2
//#define FIX_MOUNTED_PROBE
//#define NOZZLE_AS_PROBE
//#define Z_PROBE_SERVO_NR 0
//#define Z_SERVO_ANGLES { 70, 0 }

//**********************************************************************************************************************************************************************
//***************************************************** INFORMATION GATHERED AND PROVIDED BY THE 300LB GORILLA *********************************************************
//**********************************************************************************************************************************************************************

//**********************************************************************************************************************************************************************
//******************************************************* IMPORTANT INFORMATION FOR BL-TOUCH ON AN ENDER 2 PRO *********************************************************
//**********************************************************************************************************************************************************************
/**
 * The BLTouch probe uses a Hall effect sensor and emulates a servo.
 * You wil need to configure the firmware manually for the BL-Touch if you want use all the features added to Gorilla Tech v3.1.5 Firmware
 * Otherwise use the link provided below to get precompiled firmware created by Creality. For more information, you can watch this YOUTUBE video
 * provided by djsprc: https://www.youtube.com/c/djsprc
 */
//#define BLTOUCH  //<-----------------------------------------------------------------------------------------------------------------------------------BL-TOUCH OPTION

// NOTE: YOU MUST USE THE 5 PIN CONNECTOR PORT FOR BL-TOUCH ABL PROBE TO USE THIS PRECOMPILED FIRMWARE FROM CREALITY

// Get the Firmware here FOR 4.2.3 mainboard:
// https://drive.google.com/drive/folders/1VC5Sc7Sqn674EWwYtAZCbGtPCdF0EFs1?usp=share_link    //<--------------------------Link is for a Google Repository from Creality
// Firmware at URl above has folder Mainboard for Ender 2 Pro: 4.2.3 Board (CPU Type: STM32F103RET6)

// Get the Firmware here FOR 2.4.s4 mainboard:
// https://drive.google.com/drive/folders/1dWQ1jXCX2rqwlUlK8LF1e1sHX1VLg00S?usp=share_link    //<--------------------------Link is for a Google Repository from Creality
// Firmware at URl above has folder Mainboard for Ender 2 Pro: 2.4.s4 Board (CPU Type: UNKNOWN)

//**********************************************************************************************************************************************************************
//******************************************************* IMPORTANT INFORMATION FOR CR_TOUCH ON AN ENDER 2 PRO *********************************************************
//**********************************************************************************************************************************************************************
// NOTE: YOU MUST USE THE 5 PIN CONNECTOR PORT FOR BL-TOUCH ABL PROBE TO USE THIS PRECOMPILED FIRMWARE FROM CREALITY

// Get the Firmware here FOR 4.2.3 mainboard:
// https://drive.google.com/drive/folders/1VC5Sc7Sqn674EWwYtAZCbGtPCdF0EFs1?usp=share_link    //<--------------------------Link is for a Google Repository from Creality
// Firmware at URl above has folder Mainboard for Ender 2 Pro: 4.2.3 Mainboard (CPU Type: STM32F103RET6)

// Get the Firmware here FOR 2.4.s4 mainboard:
// https://drive.google.com/drive/folders/1dWQ1jXCX2rqwlUlK8LF1e1sHX1VLg00S?usp=share_link    //<--------------------------Link is for a Google Repository from Creality
// Firmware at URl above has folder Mainboard for Ender 2 Pro: 2.4.s4 Mainboard

/**
 * Pressure sensor with a BLTouch-like interface. CR Touch uses an optical sensor, rather than the BL Touch electromagnetic sensor system.
 * You wil need to configure the firmware manually for the CR-Touch if you want use all the features added to Gorilla Tech v3.1.5 Firmware
 * Otherwise use the link provided above to get precompiled firmware created by Creality. For more information, you can watch this YOUTUBE video
 * provided by djsprc: https://www.youtube.com/c/djsprc
 */
//#define CREALITY_TOUCH  //<----------------------------------------------------------------------------------------------------------------------------CR-TOUCH OPTION

//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************


//#define TOUCH_MI_PROBE
#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 0.5                  
  //#define TOUCH_MI_DEPLOY_XPOS (X_MAX_BED + 2)  
  //#define TOUCH_MI_MANUAL_DEPLOY                
#endif

//#define SOLENOID_PROBE
//#define Z_PROBE_SLED
//#define SLED_DOCKING_OFFSET 5  // The extra distance the X axis must travel to pickup the sled. 0 should be fine but you can push it further if you'd like.
//#define RACK_AND_PINION_PROBE
#if ENABLED(RACK_AND_PINION_PROBE)
  #define Z_PROBE_DEPLOY_X  X_MIN_POS
  #define Z_PROBE_RETRACT_X X_MAX_POS
#endif

//#define DUET_SMART_EFFECTOR
#if ENABLED(DUET_SMART_EFFECTOR)
  #define SMART_EFFECTOR_MOD_PIN  -1  // Connect a GPIO pin to the Smart Effector MOD pin
#endif

/**
 * Use StallGuard2 to probe the bed with the nozzle.
 * Requires stallGuard-capable Trinamic stepper drivers.
 * CAUTION: This can damage machines with Z lead screws.
 *          Take extreme care when setting up this feature.
 */
//#define SENSORLESS_PROBING

#define NOZZLE_TO_PROBE_OFFSET { 10, 10, 0 } 
#define PROBING_MARGIN 10
#define XY_PROBE_SPEED 1500
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z
#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)  
#define MULTIPLE_PROBING 2  
#define EXTRA_PROBING    1  
#define Z_CLEARANCE_DEPLOY_PROBE   10 
#define Z_CLEARANCE_BETWEEN_PROBES  5   
#define Z_CLEARANCE_MULTI_PROBE     5 
#define Z_AFTER_PROBING           5 
#define Z_PROBE_LOW_POINT          -2 
#define Z_PROBE_OFFSET_RANGE_MIN -10  
#define Z_PROBE_OFFSET_RANGE_MAX 10  
//#define Z_MIN_PROBE_REPEATABILITY_TEST
//#define PAUSE_BEFORE_DEPLOY_STOW
#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
  //#define PAUSE_PROBE_DEPLOY_WHEN_TRIGGERED 
#endif
//#define PROBING_HEATERS_OFF    //<------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Disabled
#if ENABLED(PROBING_HEATERS_OFF)
  //#define WAIT_FOR_BED_HEATER     
#endif
//#define PROBING_FANS_OFF      // Turn fans off when probing <---------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Disabled
//#define PROBING_STEPPERS_OFF      
//#define DELAY_BEFORE_PROBING 200 
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders
// Disables axis stepper immediately when it's not being used.
// WARNING: When motors turn off there is a chance of losing position accuracy!
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
// Warn on display about possibly reduced accuracy
//#define DISABLE_REDUCED_ACCURACY_WARNING

// @section extruder

#define DISABLE_E false             
#define DISABLE_INACTIVE_EXTRUDER   

// @section machine

// Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
#define INVERT_X_DIR false
#define INVERT_Y_DIR false
#define INVERT_Z_DIR true

// @section extruder

// For direct drive extruder v9 set to true, for geared extruder set to false.
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

// @section homing

//#define NO_MOTION_BEFORE_HOMING 
//#define UNKNOWN_Z_NO_RAISE      
//#define Z_HOMING_HEIGHT  4      
//#define Z_AFTER_HOMING  10
// Direction of endstops when homing; 1=MAX, -1=MIN
// :[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

// @section machine

// The size of the print bed
#define X_BED_SIZE 165     //<--------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Set To Actual Size
#define Y_BED_SIZE 165     //<--------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Set To Actual Size

//**********************************************************************************************************************************************************************
//                                                      FOR DUAL PARTS COOLING FAN SETUP
// Travel limits (mm) after homing, corresponding to endstop positions.
//#define X_MIN_POS -11     //<------------------(Designed for Dual Parts Fan Bracket) ----------------------------------------- Gorilla-Tech v3.1.5 Set To Actual Size
// Here is the Link for the Second Parts Cooling Fan: https://www.amazon.com/FYSETC-Printer-Extruder-Radiator-Creality/dp/B07TFFZ2BW   (NOT A PAID LINK)
// The fan cable is long enough to snake it through the braided wire loom and plug into port in front of other blue/yellow wired parts fan port.
// For Second Parts Cooling Fan Mounting Bracket. This bracket also replaces the hot end cover, and has holes in the end to mount the 40mm hot end fan. M4 Screws,
// self cutting threads into the printed part.

//**********************************************************************************************************************************************************************
// Travel limits (mm) after homing, corresponding to endstop positions.
#define X_MIN_POS -18   //<------------------------------------------------------------------------------------------------------ OEM Firmware X Min Pos Offset
#define Y_MIN_POS -4     //<----------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Set To Actual Size
#define Z_MIN_POS 0      //<----------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Set To Actual Size
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE

#define Z_MAX_POS 180  //<------------------------------------------------------OEM Firware for Z Max Pos

//**********************************************************************************************************************************************************************
//*************************************NEW Top Handle and Z-Axis Couple Spacer Designs By THE 300LB Gorilla*************************************************************
//**********************************************************************************************************************************************************************
//#define Z_MAX_POS 210  //<-------------------(Only if you use spacers on the Lead Screw Coupler & And replace top Red Handle with the parts below)-- Gorilla-Tech v3.1.5
// If you choose NOT to use this option, the the #define Z_MAX_POS is set to 180  (This the OEM Factory setting for MAX PRINTABLE HEIGHT)
// Spacer for UNDER Z Axis Coupler: 
// 10mm Diameter, 6mm tall with a 5.5mm bore 
// Fold a piece of paper 4 times as a gap spacer between spacer and coupler, then set coupler with screws and remove folded paper.
//.
// Spacer for inside the 8mm bore end of the Z Axis Coupler: 
// 7.8mm Diameter, 8.3mm tall, solid infill. 
// Insert this spacer under the Z Axis Lead Screw inside thecoupler and tighten screws.
//
//**********************************************************************************************************************************************************************  


// Min software endstops constrain movement within minimum coordinate bounds
#define MIN_SOFTWARE_ENDSTOPS  //<---------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Enabled
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif
// Max software endstops constrain movement within maximum coordinate bounds
#define MAX_SOFTWARE_ENDSTOPS   //<--------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Enabled
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

#if EITHER(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
  //#define SOFT_ENDSTOPS_MENU_ITEM  // Enable/Disable software endstops from the LCD
#endif

#define FILAMENT_RUNOUT_SENSOR     //<------------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5 Enabled
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define NUM_RUNOUT_SENSORS   1     
  #define FIL_RUNOUT_STATE     LOW  // Pin state indicating that filament is NOT present.<------------(Set to LOW for Creality Brand FRS)----------- Gorilla-Tech v3.1.5 
  #define FIL_RUNOUT_PULLUP          // Use internal pullup for filament runout pins.  
  //#define FIL_RUNOUT_PULLDOWN      // Use internal pulldown for filament runout pins.    
  #define FILAMENT_RUNOUT_SCRIPT "M600"
  //#define FILAMENT_RUNOUT_DISTANCE_MM 25
  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
    // Enable this option to use an encoder disc that toggles the runout pin
    // as the filament moves. (Be sure to set FILAMENT_RUNOUT_DISTANCE_MM
    // large enough to avoid false positives.)
    //#define FILAMENT_MOTION_SENSOR
  #endif
#endif

// @section calibrate

//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
//#define AUTO_BED_LEVELING_BILINEAR
//#define AUTO_BED_LEVELING_UBL
#define MESH_BED_LEVELING    //<------------------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5 Enabled
//#define RESTORE_LEVELING_AFTER_G28
#define DEBUG_LEVELING_FEATURE    //<------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Enabled

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  #define ENABLE_LEVELING_FADE_HEIGHT
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Length of all segments (except the last one)

  //#define G26_MESH_VALIDATION
  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  
    #define MESH_TEST_LAYER_HEIGHT   0.2  
    #define MESH_TEST_HOTEND_TEMP  210    
    #define MESH_TEST_BED_TEMP      65    
    #define G26_XY_FEEDRATE         20    
    #define G26_RETRACT_MULTIPLIER   1.0  
  #endif

#endif

#if EITHER(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)
  #define GRID_MAX_POINTS_X 3
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
  //#define PROBE_Y_FIRST

  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)
    //#define EXTRAPOLATE_BEYOND_GRID
    //#define ABL_BILINEAR_SUBDIVISION
    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  //#define MESH_EDIT_GFX_OVERLAY   

  #define MESH_INSET 1              
  #define GRID_MAX_POINTS_X 10      
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  #define UBL_MESH_EDIT_MOVES_Z     
  #define UBL_SAVE_ACTIVE_ON_M500   

  //#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 

#elif ENABLED(MESH_BED_LEVELING)
  #define MESH_INSET 20          // Set Mesh bounds as an inset region of the bed    //<---------------------------------- Gorilla-Tech v3.1.5 Changed From 10mm to 20mm
  #define GRID_MAX_POINTS_X 3    // Don't not change for the Ender 2 Pro. Throws a "Outside of Printable Area ERROR"     //<------------------------ Gorilla-Tech v3.1.5
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define MESH_G28_REST_ORIGIN // After homing all axes ('G28' or 'G28 XYZ') rest Z at Z_MIN_POS

#endif // BED_LEVELING

#define LCD_BED_LEVELING  //<--------------(Needed for LCD Manual MESH BED LEVELING and 4 CORNER LCD ASSISTED BED LEVELING)----------------- Gorilla-Tech v3.1.5 Enabled
#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 
  #define LCD_PROBE_Z_RANGE 4     
  #define MESH_EDIT_MENU        
#endif

#define LEVEL_BED_CORNERS  //<------(LCD ASSITED 4 CORNER BED LEVELING)---------------- Gorilla-Tech v3.1.5 Enabled for Adjusting Height with Bed Height Ajusting Wheels

#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET_LFRB { 30, 30, 30, 30 }
  #define LEVEL_CORNERS_HEIGHT      0.0   
  #define LEVEL_CORNERS_Z_HOP       4.0  
  //#define LEVEL_CENTER_TOO             
#endif

//#define Z_PROBE_END_SCRIPT "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"

// @section homing

// The center of the bed is at (X=0, Y=0)
//#define BED_CENTER_AT_0_0
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0
//#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT X_CENTER  // X point for Z homing
  #define Z_SAFE_HOMING_Y_POINT Y_CENTER  // Y point for Z homing
#endif
// Homing speeds (mm/m)
#define HOMING_FEEDRATE_XY (25*60)
#define HOMING_FEEDRATE_Z  (4*60)
#define VALIDATE_HOMING_ENDSTOPS

// @section calibrate

#define SKEW_CORRECTION   //<--------- Gorilla-Tech v3.1.5 Enabled
#if ENABLED(SKEW_CORRECTION)
  // Input all length measurements here:
  #define XY_DIAG_AC 230  //<---------------------------------------------- Changed for New Version of Firmware, v3.1.5 (The 300lb Gorilla) Changed, Correct Measurement
  #define XY_DIAG_BD 230  //<---------------------------------------------- Changed for New Version of Firmware, v3.1.5 (The 300lb Gorilla) Changed, Correct Measurement
  #define XY_SIDE_AD 165  //<---------------------------------------------- Changed for New Version of Firmware, v3.1.5 (The 300lb Gorilla) Changed, Correct Measurement

  // Or, set the default skew factors directly here
  // to override the above measurements:
  #define XY_SKEW_FACTOR 0.0   //<--------------------(DO NOT CHANGE)------------------------------------------------------------------------------- Gorilla-Tech v3.1.5

  #define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 230 //<------------------------------Changed for New Version of Firmware, v3.1.5 (The 300lb Gorilla) Changed, Correct Measurement for Ender 2 Pro
    #define XZ_DIAG_BD 230 //<------------------------------Changed for New Version of Firmware, v3.1.5 (The 300lb Gorilla) Changed, Correct Measurement for Ender 2 Pro
    #define YZ_DIAG_AC 230 //<------------------------------Changed for New Version of Firmware, v3.1.5 (The 300lb Gorilla) Changed, Correct Measurement for Ender 2 Pro
    #define YZ_DIAG_BD 230 //<------------------------------Changed for New Version of Firmware, v3.1.5 (The 300lb Gorilla) Changed, Correct Measurement for Ender 2 Pro
    #define YZ_SIDE_AD 165 //<--------------------------Changed for New Version of Firmware, now v3.1.5 (The 300lb Gorilla) Changed, Correct Measurement for Ender 2 Pro
    #define XZ_SKEW_FACTOR 0.0  //<------------------------------------------------------------------------------------DO NOT CHANGE FOR ENDER 2 PRO (The 300lb Gorilla)
    #define YZ_SKEW_FACTOR 0.0  //<------------------------------------------------------------------------------------DO NOT CHANGE FOR ENDER 2 PRO (The 300lb Gorilla)
  #endif

  //#define SKEW_CORRECTION_GCODE  //<---------------------------------------------------------------------------------DO NOT CHANGE FOR ENDER 2 PRO (The 300lb Gorilla)
#endif

// @section extras

#define EEPROM_SETTINGS       
//#define DISABLE_M503        
#define EEPROM_CHITCHAT       
#define EEPROM_BOOT_SILENT    
#if ENABLED(EEPROM_SETTINGS)
  #define EEPROM_AUTO_INIT    
#endif

#define HOST_KEEPALIVE_FEATURE        
#define DEFAULT_KEEPALIVE_INTERVAL 2  
#define BUSY_WHILE_HEATING            
//#define INCH_MODE_SUPPORT
//#define TEMPERATURE_UNITS_SUPPORT

// @section temperature

// Preheat Constants                 //<------------------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5
                                     //<------------------------------------------------------------------Changed Pre Heat from 200c/55c to 210c/65c Gorilla-Tech v3.1.5
#define PREHEAT_1_LABEL       "PLA"  //<------------------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5
#define PREHEAT_1_TEMP_HOTEND 210    //<------------------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5
#define PREHEAT_1_TEMP_BED     65    //<------------------------------------------------------------------------------------------------------------ Gorilla-Tech v3.1.5 
#define PREHEAT_1_FAN_SPEED   255 // Value from 0 to 255
// Since the Ender 2 Pro has a LIMITED BED HEAT of 90c, ABS is pretty much a non starter<------------------------------------------------------------Gorilla-Tech v3.1.5

// ABS Preheat Settings have been Removed <--------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5

#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  // Specify a park position as { X, Y, Z_raise }
  #define NOZZLE_PARK_POINT { (0), (0), 0 }
  //#define NOZZLE_PARK_X_ONLY          
  //#define NOZZLE_PARK_Y_ONLY          
  #define NOZZLE_PARK_Z_RAISE_MIN   0   
  #define NOZZLE_PARK_XY_FEEDRATE 100   
  #define NOZZLE_PARK_Z_FEEDRATE    5   
#endif

//#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  #define NOZZLE_CLEAN_STROKES  12
  #define NOZZLE_CLEAN_TRIANGLES  3
  #define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5
  #define NOZZLE_CLEAN_CIRCLE_FN 10
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT
  #define NOZZLE_CLEAN_GOBACK
  //#define NOZZLE_CLEAN_NO_Z
  //#define WIPE_SEQUENCE_COMMANDS "G1 X-17 Y25 Z10 F4000\nG1 Z1\nM114\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 Z15\nM400\nG0 X-10.0 Y-9.0"

#endif

#define PRINTJOB_TIMER_AUTOSTART
//#define PRINTCOUNTER    //<-----------(Removed due to Maintenance Reminders)------------------------------------------------------------- Gorilla-Tech v3.1.5 Disabled


// @section lcd
// Language Change is no longer available: See Marlin\src\lcd\menu\menu_main.cpp if you are compiling your own version
// Code Line: 209 <---------------------------- SUBMENU(MSG_LANGUAGE, menu_language); is commented out to disable the language function in main menu (THE 300LB GORILLA)
#define LCD_LANGUAGE en        //<----------------------------------------------Language Change Option Has Been Remove From The Main Menu Completely (THE 300LB GORILLA)
#define LCD_LANGUAGE_2 zh_CN   //<----------------------------------------------Language Change Option Has Been Remove From The Main Menu Completely (THE 300LB GORILLA)
#define DISPLAY_CHARSET_HD44780 JAPANESE //<------------------------------------Language Change Option Has Been Remove From The Main Menu Completely (THE 300LB GORILLA)
#define LCD_INFO_SCREEN_STYLE 0  //<-------------------------------------------------------------------------------------------------- DO NOT CHANGE (THE 300LB GORILLA)
#define SDSUPPORT  //<---------------------------------------------------------------------------------------------------------------- DO NOT CHANGE (THE 300LB GORILLA)
//#define SPI_SPEED SPI_HALF_SPEED
//#define SPI_SPEED SPI_QUARTER_SPEED
//#define SPI_SPEED SPI_EIGHTH_SPEED
//#define SD_CHECK_AND_RETRY
//#define NO_LCD_MENUS
//#define SLIM_LCD_MENUS
//#define ENCODER_PULSES_PER_STEP 4
//#define ENCODER_STEPS_PER_MENU_ITEM 1
//#define REVERSE_ENCODER_DIRECTION
//#define REVERSE_MENU_DIRECTION
//#define REVERSE_SELECT_DIRECTION
#define INDIVIDUAL_AXIS_HOMING_MENU   //<--------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Enabled

#define SPEAKER //<------------------------------------------------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Enabled

#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2  //<------------------------------------------------------------------------------- Gorilla-Tech v3.1.5 Changed from 5 to 2
#define LCD_FEEDBACK_FREQUENCY_HZ 1000       //<---------------------------------------------------------------------- Gorilla-Tech v3.1.5 Changed from 5000hz to 1000hz

//#define REPRAP_DISCOUNT_SMART_CONTROLLER
//#define RADDS_DISPLAY
//#define ULTIMAKERCONTROLLER
//#define ULTIPANEL
//#define PANEL_ONE
//#define G3D_PANEL
//#define RIGIDBOT_PANEL
//#define MAKEBOARD_MINI_2_LINE_DISPLAY_1602
//#define ZONESTAR_LCD            
//#define ULTRA_LCD
//#define RA_CONTROL_PANEL
//#define LCD_SAINSMART_I2C_1602
//#define LCD_SAINSMART_I2C_2004
//#define LCM1602
//#define LCD_I2C_PANELOLU2
//#define LCD_I2C_VIKI
//#define SAV_3DLCD
//#define FF_INTERFACEBOARD
//#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
//#define REPRAPWORLD_GRAPHICAL_LCD
//#define VIKI2
//#define miniVIKI
//#define MINIPANEL
//#define MAKRPANEL
//#define ELB_FULL_GRAPHIC_CONTROLLER
//#define BQ_LCD_SMART_CONTROLLER
//#define CARTESIO_UI
//#define LCD_FOR_MELZI
//#define ULTI_CONTROLLER
//#define MKS_MINI_12864
//#define MKS_LCD12864
//#define FYSETC_MINI_12864_X_X    // Type C/D/E/F. No tunable RGB Backlight by default
//#define FYSETC_MINI_12864_1_2    // Type C/D/E/F. Simple RGB Backlight (always on)
//#define FYSETC_MINI_12864_2_0    // Type A/B. Discreet RGB Backlight
//#define FYSETC_MINI_12864_2_1    // Type A/B. Neopixel RGB Backlight
//#define FYSETC_GENERIC_12864_1_1 // Larger display with basic ON/OFF backlight.
#define CR10_STOCKDISPLAY    //<------------------------------------------------------------------------ Gorilla-Tech v3.1.5 This is the correct Display for Ender 2 Pro
//#define ENDER2_STOCKDISPLAY
//#define ANET_FULL_GRAPHICS_LCD
//#define AZSMZ_12864
//#define SILVER_GATE_GLCD_CONTROLLER
//#define U8GLIB_SSD1306
//#define SAV_3DGLCD
#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
  //#define U8GLIB_SH1106
#endif

//#define OLED_PANEL_TINYBOY2
//#define MKS_12864OLED          // Uses the SH1106 controller (default)
//#define MKS_12864OLED_SSD1306  // Uses the SSD1306 controller
//#define U8GLIB_SH1106_EINSTART
//#define OVERLORD_OLED
//#define FYSETC_242_OLED_12864   // Uses the SSD1309 controller
//#define DGUS_LCD_UI_ORIGIN
//#define DGUS_LCD_UI_FYSETC
//#define DGUS_LCD_UI_HIPRECY
//#define MALYAN_LCD
//#define TOUCH_UI_FTDI_EVE
//#define EXTENSIBLE_UI

#if ENABLED(EXTENSIBLE_UI)
  //#define EXTUI_LOCAL_BEEPER // Enables use of local Beeper pin with external display
#endif

//#define FSMC_GRAPHICAL_TFT
//#define TFT_LVGL_UI_FSMC  // Robin nano v1.2 uses FSMC
//#define TFT_LVGL_UI_SPI   // Robin nano v2.0 uses SPI
//#define ANYCUBIC_TFT_MODEL
//#define ANYCUBIC_TFT_DEBUG
//#define DWIN_CREALITY_LCD
#define RET6_12864_LCD  //<---Leave this alone! Your Stock CR10_STOCKDISPLAY is a RET6 128x64 LCD  <------------------------------------------------ Gorilla-Tech v3.1.5
//#define TOUCH_BUTTONS
#if ENABLED(TOUCH_BUTTONS)
  #define BUTTON_DELAY_EDIT  50 // (ms) Button repeat delay for edit screens
  #define BUTTON_DELAY_MENU 250 // (ms) Button repeat delay for menus

  #define XPT2046_X_CALIBRATION   12316
  #define XPT2046_Y_CALIBRATION  -8981
  #define XPT2046_X_OFFSET       -43
  #define XPT2046_Y_OFFSET        257
#endif

//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // (mm) Distance to move per key-press

// @section extras

//#define FAST_PWM_FAN
//#define FAN_SOFT_PWM
#define SOFT_PWM_SCALE 0
//#define SOFT_PWM_DITHER
//#define TEMP_STAT_LEDS
//#define SF_ARC_FIX
//#define BARICUDA
//#define BLINKM
//#define PCA9632
//#define PCA9533
//#define RGB_LED
//#define RGBW_LED

#if EITHER(RGB_LED, RGBW_LED)
  //#define RGB_LED_R_PIN 34
  //#define RGB_LED_G_PIN 43
  //#define RGB_LED_B_PIN 35
  //#define RGB_LED_W_PIN -1
#endif

// Support for Adafruit Neopixel LED driver
//#define NEOPIXEL_LED
#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE   NEO_GRBW // NEO_GRBW / NEO_GRB - four/three channel driver type (defined in Adafruit_NeoPixel.h)
  #define NEOPIXEL_PIN     4       // LED driving pin
  //#define NEOPIXEL2_TYPE NEOPIXEL_TYPE
  //#define NEOPIXEL2_PIN    5
  #define NEOPIXEL_PIXELS 30       // Number of LEDs in the strip, larger of 2 strips if 2 neopixel strips are used
  #define NEOPIXEL_IS_SEQUENTIAL   // Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
  #define NEOPIXEL_BRIGHTNESS 127  // Initial brightness (0-255)
  //#define NEOPIXEL_STARTUP_TEST  // Cycle through colors at startup
  //#define NEOPIXEL_BKGD_LED_INDEX  0               // Index of the LED to use
  //#define NEOPIXEL_BKGD_COLOR { 255, 255, 255, 0 } // R, G, B, W
#endif

#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

//#define NUM_SERVOS 3 // Servo index starts with 0 for M280 command
#define SERVO_DELAY { 300 }
//#define DEACTIVATE_SERVOS_AFTER_MOVE
//#define EDITABLE_SERVO_ANGLES


// All changes made by The 300lb Gorilla are noted in the code for Configuration.h