
#if !defined(__AVR_ATmega644P__) && !defined(__AVR_ATmega1284P__)
  #error "Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu."
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME "Sanguinololu <1.2"
#endif

#ifdef __AVR_ATmega1284P__
  #define LARGE_FLASH true
#endif

//
// Limit Switches
//
#define X_STOP_PIN         18
#define Y_STOP_PIN         19
#define Z_STOP_PIN         20

//
// Steppers
//
#define X_STEP_PIN         15
#define X_DIR_PIN          21

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23

#define Z_STEP_PIN          3
#define Z_DIR_PIN           2

#define E0_STEP_PIN         1
#define E0_DIR_PIN          0

//
// Temperature Sensors
//
#define TEMP_0_PIN          7   // Analog Input (pin 33 extruder)
#define TEMP_BED_PIN        6   // Analog Input (pin 34 bed)

//
// Heaters / Fans
//
#define HEATER_0_PIN       13 // (extruder)

#if ENABLED(SANGUINOLOLU_V_1_2)

  #define HEATER_BED_PIN   12 // (bed)
  #define X_ENABLE_PIN     14
  #define Y_ENABLE_PIN     14
  #define Z_ENABLE_PIN     14
  #define E0_ENABLE_PIN    14

  #if ENABLED(LCD_I2C_PANELOLU2)
    #define FAN_PIN         4 // Uses Transistor1 (PWM) on Panelolu2's Sanguino Adapter Board to drive the fan
  #endif

#else

  #define HEATER_BED_PIN   14 // (bed)
  #define X_ENABLE_PIN     -1
  #define Y_ENABLE_PIN     -1
  #define Z_ENABLE_PIN     -1
  #define E0_ENABLE_PIN    -1

#endif

#if MB(AZTEEG_X1) || MB(STB_11) || ENABLED(IS_MELZI)
  #define FAN_PIN           4 // Works for Panelolu2 too
#endif

//
// Misc. Functions
//

//#define SDSS               24
#define SDSS               31

#if ENABLED(IS_MELZI)
  #define LED_PIN          27
#elif MB(STB_11)
  #define LCD_BACKLIGHT_PIN 17 // LCD backlight LED
#endif

#if DISABLED(SPINDLE_LASER_ENABLE) && ENABLED(SANGUINOLOLU_V_1_2) && !(ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL))  // try to use IO Header
  #define CASE_LIGHT_PIN     4 // MUST BE HARDWARE PWM  - see if IO Header is available
#endif

//
// LCD / Controller
//
#if ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL)

  #if ENABLED(DOGLCD)

    #if ENABLED(U8GLIB_ST7920) // SPI GLCD 12864 ST7920 ( like [www.digole.com] ) For Melzi V2.0

      #if ENABLED(IS_MELZI)
        #define LCD_PINS_RS     30 // CS chip select /SS chip slave select
        #define LCD_PINS_ENABLE 28 // SID (MOSI)
        #define LCD_PINS_D4     16 // SCK (CLK) clock
        // Pin 27 is taken by LED_PIN, but Melzi LED does nothing with
        // Marlin so this can be used for BEEPER_PIN. You can use this pin
        // with M42 instead of BEEPER_PIN.
        #define BEEPER_PIN      -1
      #else        // Sanguinololu >=1.3
        #define LCD_PINS_RS      30
        #define LCD_PINS_ENABLE 28
        #define LCD_PINS_D4     16
        #define LCD_PINS_D5     17
        #define LCD_PINS_D6     27
        #define LCD_PINS_D7     29
      #endif

    #else // DOGM SPI LCD Support

      #define DOGLCD_A0         30
      #define LCD_CONTRAST       1

      #if ENABLED(MAKRPANEL)

        #define BEEPER_PIN      -1
        #define DOGLCD_CS       17
        #define LCD_BACKLIGHT_PIN 28 // PA3

      #else // !MAKRPANEL

        #define DOGLCD_CS       29

      #endif

    #endif

    // Uncomment screen orientation
    #define LCD_SCREEN_ROT_0
    //#define LCD_SCREEN_ROT_90
    //#define LCD_SCREEN_ROT_180
    //#define LCD_SCREEN_ROT_270

  #else // !DOGLCD

		#define LCD_PINS_RS      30
        #define LCD_PINS_ENABLE 28
        #define LCD_PINS_D4     16
        #define LCD_PINS_D5     17
        #define LCD_PINS_D6     27
        #define LCD_PINS_D7     29

  #endif // !DOGLCD

  #define BTN_EN1               10
  #define BTN_EN2               11

  #define BTN_ENC             26
  //#define LCD_SDSS            28 // Smart Controller SD card reader rather than the Melzi


  #define SD_DETECT_PIN         -1
  
  #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
	  #define ST7920_DELAY_1 DELAY_0_NOP
	  #define ST7920_DELAY_2 DELAY_2_NOP
	  #define ST7920_DELAY_3 DELAY_0_NOP
  #endif 

#endif // ULTRA_LCD && NEWPANEL