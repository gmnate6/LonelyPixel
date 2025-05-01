#include "gba.h"

volatile u16* Scanline = (volatile u16*) (MEM_IO   + 0x0006);
volatile u16* VRAM     = (volatile u16*) (MEM_VRAM + 0x0000);
