#ifndef GBA_H
#define GBA_H

#include <stdint.h>

typedef unsigned short u16;
typedef unsigned long  u32;

// Screen dimensions
#define SCREEN_WIDTH   160   // hardware pixels
#define GAME_WIDTH         120   // game width
#define GAME_HEIGHT         80   // game height

// 15-bit RGB helper
#define RGB(r,g,b) ((r) + ((g)<<5) + ((b)<<10))

// Video Buffer
extern volatile u16* Scanline;
extern volatile u16* VRAM;
extern volatile u16* VRAM_F;
extern volatile u16* VRAM_B;
#define DISPCNT   (*(volatile u32*) 0x4000000)
#define BACKB     0x10

// Mode-5 Scaling
#define REG_BG2PA *(volatile unsigned short *) 0x4000020
#define REG_BG2PD *(volatile unsigned short *) 0x4000026

// Input
#define KEY_STATE      (*(volatile u16*) 0x4000130)
#define KEY_A          !(KEY_STATE &   1)
#define KEY_B          !(KEY_STATE &   2)
#define KEY_SL         !(KEY_STATE &   4)
#define KEY_ST         !(KEY_STATE &   8)
#define KEY_R          !(KEY_STATE &  16)
#define KEY_L          !(KEY_STATE &  32)
#define KEY_U          !(KEY_STATE &  64)
#define KEY_D          !(KEY_STATE & 128)
#define KEY_RS         !(KEY_STATE & 256)
#define KEY_LS         !(KEY_STATE & 512)

// Timer for FPS
#define REG_TM2D       *(volatile u16*) 0x4000108

// Fast RAM sections
#define IN_IWRAM       __attribute__ ((section (".iwram")))
#define IN_EWRAM       __attribute__ ((section (".ewram")))

#endif