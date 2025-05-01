#ifndef GBA_H
#define GBA_H

#include <stdint.h>

/* ------------------------------------------------------------------ */
/*  Basic typedefs                                                    */
/* ------------------------------------------------------------------ */
typedef unsigned short u16;
typedef unsigned long  u32;

/* ------------------------------------------------------------------ */
/*  Display constants / registers                                     */
/* ------------------------------------------------------------------ */
#define SCREEN_WIDTH       160   // Hardware Pixels
#define GAME_WIDTH         120
#define GAME_HEIGHT         80

extern volatile   u16* Scanline;
extern volatile   u16* VRAM;
extern volatile   u16* VRAM_F;
extern volatile   u16* VRAM_B;

#define DISPCNT   (*(volatile u32*) 0x4000000)
#define BACKB     0x10

// Mode-5 Scaling
#define REG_BG2PA *(volatile unsigned short *) 0x4000020
#define REG_BG2PD *(volatile unsigned short *) 0x4000026

/* ------------------------------------------------------------------ */
/*  Input                                                             */
/* ------------------------------------------------------------------ */
#define KEY_INPUT (*(volatile u16*)0x4000130)

// Individual Bit Masks
#define KEY_MASK_A        (1 << 0)
#define KEY_MASK_B        (1 << 1)
#define KEY_MASK_SELECT   (1 << 2)
#define KEY_MASK_START    (1 << 3)
#define KEY_MASK_RIGHT    (1 << 4)
#define KEY_MASK_LEFT     (1 << 5)
#define KEY_MASK_UP       (1 << 6)
#define KEY_MASK_DOWN     (1 << 7)
#define KEY_MASK_R_BTN    (1 << 8)   /* shoulder R */
#define KEY_MASK_L_BTN    (1 << 9)   /* shoulder L */

// Helper – evaluates to non-zero while the key is PRESSED
#define KEY_PRESSED(mask) ( !(KEY_INPUT & (mask)) )

// High-Level Aliases
#define KEY_A           KEY_PRESSED(KEY_MASK_A)
#define KEY_B           KEY_PRESSED(KEY_MASK_B)
#define KEY_SELECT      KEY_PRESSED(KEY_MASK_SELECT)
#define KEY_START       KEY_PRESSED(KEY_MASK_START)

#define KEY_RIGHT       KEY_PRESSED(KEY_MASK_RIGHT)
#define KEY_LEFT        KEY_PRESSED(KEY_MASK_LEFT)
#define KEY_UP          KEY_PRESSED(KEY_MASK_UP)
#define KEY_DOWN        KEY_PRESSED(KEY_MASK_DOWN)

#define KEY_R_SHOULDER  KEY_PRESSED(KEY_MASK_R_BTN)
#define KEY_L_SHOULDER  KEY_PRESSED(KEY_MASK_L_BTN)

/* ------------------------------------------------------------------ */
/*  Timers                                                            */
/* ------------------------------------------------------------------ */
#define GBA_CLOCK_HZ   16777216u     /* 16.78 MHz master clock */

/* Timer-2 registers (counter + control) */
#define REG_TM2CNT_L  (*(volatile u16*)0x04000108)   /* counter (was REG_TM2D) */
#define REG_TM2CNT_H  (*(volatile u16*)0x0400010A)   /* control register      */

/* Control-register bit masks                                         */
#define TM_ENABLE         0x0080

#define TM_PRESCALE_1     0x0000  /* /1     → 16 777 216 Hz */
#define TM_PRESCALE_64    0x0001  /* /64    →   262 144 Hz */
#define TM_PRESCALE_256   0x0002  /* /256   →    65 536 Hz */
#define TM_PRESCALE_1024  0x0003  /* /1024  →    16 384 Hz */

/* ------------------------------------------------------------------ */
/*  Fast RAM sections                                                 */
/* ------------------------------------------------------------------ */
#define IN_IWRAM     __attribute__ ((section (".iwram")))
#define IN_EWRAM     __attribute__ ((section (".ewram")))

#endif