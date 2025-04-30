#include "gba.h"

volatile u16* Scanline = (volatile u16*) 0x4000006;
volatile u16* VRAM     = (volatile u16*) 0x6000000;
volatile u16* VRAM_F   = (volatile u16*) 0x6000000;
volatile u16* VRAM_B   = (volatile u16*) 0x600A000;
