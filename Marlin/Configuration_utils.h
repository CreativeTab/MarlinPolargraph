// Choose the name from boards.h that matches your setup

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_BTT_SKR_E3_DIP //Tab
#endif

/**
 * Select the serial port on the board to use for communication with the host.
 * This allows the connection of wireless adapters (for instance) to non-default port pins.
 * Serial port -1 is the USB emulated serial port, if available.
 * Note: The first serial port (-1 or 0) will always be used by the Arduino bootloader.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define SERIAL_PORT -1

/**
 * Serial Port Baud Rate
 * This is the default communication speed for all serial ports.
 * Set the baud rate defaults for additional serial ports below.
 *
 * 250000 works in most cases, but you might try a lower speed if
 * you commonly experience drop-outs during host printing.
 * You may try up to 1000000 to speed up SD file transfer.
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 250000

/**
 * Select a secondary serial port on the board to use for communication with the host.
 * Currently Ethernet (-2) is only supported on Teensy 4.1 boards.
 * :[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define SERIAL_PORT_2 1
#define BAUDRATE_2 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE

/**
 * Select a third serial port on the board to use for communication with the host.
 * Currently only supported for AVR, DUE, LPC1768/9 and STM32/STM32F1
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define SERIAL_PORT_3 1
//#define BAUDRATE_3 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE

// Name displayed in the LCD "Ready" message and Info menu
#define CUSTOM_MACHINE_NAME "Polargraph"

/**
 * Stepper Drivers
 *
 * These settings allow Marlin to tune stepper driver timing and enable advanced options for
 * stepper drivers that support them. You may also override timing options in Configuration_adv.h.
 *
 * Use TMC2208/TMC2208_STANDALONE for TMC2225 drivers and TMC2209/TMC2209_STANDALONE for TMC2226 drivers.
 *
 * Options: A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
 *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
 * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC26X', 'TMC26X_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 */
#define X_DRIVER_TYPE  TMC2208_STANDALONE //Tab
#define Y_DRIVER_TYPE  TMC2208_STANDALONE //Tab
#define Z_DRIVER_TYPE  TMC2208 //Tab

// Enable for Polargraph Kinematics
#define POLARGRAPH
#if ENABLED(POLARGRAPH)
  #define POLARGRAPH_MAX_BELT_LEN 618.0 //Tab
  #define POLAR_SEGMENTS_PER_SECOND 5
  #if MOTHERBOARD == BOARD_RUMBA
  #define X_MAX_PIN 37
  #define Y_MAX_PIN 36
  #endif
#endif

//===========================================================================
//============================== Endstop Settings ===========================
//===========================================================================

// @section endstops

// Specify here all the endstop connectors that are connected to any endstop or probe.
// Almost all printers will be using one per axis. Probes will use one or more of the
// extra connectors. Leave undefined any used for non-endstop and non-probe purposes.
#define USE_ZMIN_PLUG //Tab
#define USE_ZMAX_PLUG //Tab

// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
#define X_MAX_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop. //Tab
#define Y_MAX_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop. //Tab
#define Z_MAX_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop. //Tab

//=============================================================================
//============================== Movement Settings ============================
//=============================================================================
// @section motion

/**
 * Default Axis Steps Per Unit (linear=steps/mm, rotational=steps/°)
 * Override with M92
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 20, 20, 20 } //Tab

/**
 * Default Max Feed Rate (linear=mm/s, rotational=°/s)
 * Override with M203
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_FEEDRATE          { 100, 100, 100 } //Tab

/**
 * Default Max Acceleration (speed change with time) (linear=mm/(s^2), rotational=°/(s^2))
 * (Maximum start speed for accelerated moves)
 * Override with M201
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_ACCELERATION      { 100, 100, 100 } //Tab

//===========================================================================
//============================= Z Probe Options =============================
//===========================================================================

//
// See https://marlinfw.org/docs/configuration/probes.html
//

// @section motion

// Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
#define INVERT_X_DIR false //Tab
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false

// @section geometry

// The size of the printable area
#define X_BED_SIZE 501 //Tab
#define Y_BED_SIZE 564 //Tab

// Travel limits (linear=mm, rotational=°) after homing, corresponding to endstop positions.
#define X_MIN_POS ((-X_BED_SIZE/2)-1)
#define Y_MIN_POS (-Y_BED_SIZE/2)
#define Z_MIN_POS 0
#define X_MAX_POS ((X_BED_SIZE/2)+1)
#define Y_MAX_POS (Y_BED_SIZE/2)
#define Z_MAX_POS 0

//===========================================================================
//=============================== Bed Leveling ==============================
//===========================================================================

// @section homing

// The center of the bed is at (X=0, Y=0)
#define BED_CENTER_AT_0_0

// Manually set the home position. Leave these undefined for automatic settings.
// For DELTA this is the top-center of the Cartesian print volume.
#define MANUAL_X_HOME_POS 0
#define MANUAL_Y_HOME_POS (Y_MAX_POS-( sqrt(sq(POLARGRAPH_MAX_BELT_LEN)-sq(X_BED_SIZE/2)))) - 100 //Tab - 230.0

// Homing speeds (linear=mm/min, rotational=°/min)
#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (50*60) }

//
// MKS MINI12864 V3 is an alias for FYSETC_MINI_12864_2_1. Type A/B. NeoPixel RGB Backlight.
//
// #define MKS_MINI_12864_V3