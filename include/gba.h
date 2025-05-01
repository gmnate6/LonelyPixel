#ifndef GBA_H
#define GBA_H

#include <stdint.h>

/* ------------------------------------------------------------------ */
/*  Basic typedefs                                                    */
/* ------------------------------------------------------------------ */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* ------------------------------------------------------------------ */
/*  Registers                                                         */
/* ------------------------------------------------------------------ */
#define MEM_IO             0x04000000
#define MEM_VRAM           0x06000000

#define DISPCNT            *((volatile u32*) MEM_IO)
#define BACKB              0x10

// --- DISPCNT defines ---
#define DISPCNT_MODE0      0x0000
#define DISPCNT_MODE1      0x0001
#define DISPCNT_MODE2      0x0002
#define DISPCNT_MODE3      0x0003
#define DISPCNT_MODE4      0x0004
#define DISPCNT_MODE5      0x0005
// layers
#define DISPCNT_BG0        0x0100
#define DISPCNT_BG1        0x0200
#define DISPCNT_BG2        0x0400
#define DISPCNT_BG3        0x0800
#define DISPCNT_OBJ        0x1000

// Mode-5 Scaling
#define REG_BG2PA *(volatile u16 *) (MEM_IO + 0x0020)
#define REG_BG2PD *(volatile u16 *) (MEM_IO + 0x0026)

/* ------------------------------------------------------------------ */
/*  Display constants                                                 */
/* ------------------------------------------------------------------ */
#define SCREEN_WIDTH       160   // Hardware Pixels
#define GAME_WIDTH         120
#define GAME_HEIGHT         80

extern volatile u16* Scanline;
extern volatile u16* VRAM;
#define VRAM_F  (u16*) (MEM_VRAM + 0x0000)
#define VRAM_B  (u16*) (MEM_VRAM + 0xA000)

/* ------------------------------------------------------------------ */
/*  Input                                                             */
/* ------------------------------------------------------------------ */
#define KEY_INPUT (*(volatile u16*) (MEM_IO + 0x0130))

// Individual Bit Masks
#define KEY_MASK_A        (1 << 0)
#define KEY_MASK_B        (1 << 1)
#define KEY_MASK_SELECT   (1 << 2)
#define KEY_MASK_START    (1 << 3)
#define KEY_MASK_RIGHT    (1 << 4)
#define KEY_MASK_LEFT     (1 << 5)
#define KEY_MASK_UP       (1 << 6)
#define KEY_MASK_DOWN     (1 << 7)
#define KEY_MASK_R_BTN    (1 << 8)   // Shoulder R
#define KEY_MASK_L_BTN    (1 << 9)   // Shoulder L

// Helper – Evaluates to non-zero while the key is PRESSED
#define KEY_PRESSED(mask) ( !(KEY_INPUT & (mask)) )

// High-Level Aliases
#define KEY_A             KEY_PRESSED(KEY_MASK_A)
#define KEY_B             KEY_PRESSED(KEY_MASK_B)
#define KEY_SELECT        KEY_PRESSED(KEY_MASK_SELECT)
#define KEY_START         KEY_PRESSED(KEY_MASK_START)

#define KEY_RIGHT         KEY_PRESSED(KEY_MASK_RIGHT)
#define KEY_LEFT          KEY_PRESSED(KEY_MASK_LEFT)
#define KEY_UP            KEY_PRESSED(KEY_MASK_UP)
#define KEY_DOWN          KEY_PRESSED(KEY_MASK_DOWN)

#define KEY_R_SHOULDER    KEY_PRESSED(KEY_MASK_R_BTN)
#define KEY_L_SHOULDER    KEY_PRESSED(KEY_MASK_L_BTN)

/* ------------------------------------------------------------------ */
/*  Timers                                                            */
/* ------------------------------------------------------------------ */
#define GBA_CLOCK_HZ   16777216u     /* 16.78 MHz master clock */

// Timer-2 registers (counter + control)
#define REG_TM2CNT_L  *((volatile u16*) (MEM_IO + 0x0108))
#define REG_TM2CNT_H  *((volatile u16*) (MEM_IO + 0x010A))

// Control-register bit masks
#define TM_ENABLE         0x0080

#define TM_PRESCALE_1     0x0000     /* /1     → 16 777 216 Hz */
#define TM_PRESCALE_64    0x0001     /* /64    →   262 144 Hz */
#define TM_PRESCALE_256   0x0002     /* /256   →    65 536 Hz */
#define TM_PRESCALE_1024  0x0003     /* /1024  →    16 384 Hz */

/* ------------------------------------------------------------------ */
/*  Fast RAM sections                                                 */
/* ------------------------------------------------------------------ */
#define IN_IWRAM     __attribute__ ((section (".iwram")))
#define IN_EWRAM     __attribute__ ((section (".ewram")))

#endif