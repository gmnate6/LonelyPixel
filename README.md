# Lonely Pixel

Lonely Pixel is a tiny, educational Game Boy Advance (GBA) home-brew project that demonstrates:

* A minimal C game loop (initialise → update → render → sync).
* Direct pixel access in video **Mode 5** with double-buffering.
* Basic user input handling via the GBA key-pad.
* A lightweight FPS timer built on the hardware timers.

The result is a single black pixel you can steer around a small logical play-field that is scaled to the full GBA screen.  
While simple, the codebase is intentionally clean and heavily commented, making it a good starting point for anyone wanting to learn bare-metal GBA programming.

---

## Table of Contents
1. Features
2. Controls
3. Building
4. Running the ROM
5. Directory Layout
6. Contributing
7. License

---

## 1. Features

| Topic          | Details                                                        |
| -------------- | -------------------------------------------------------------- |
| Video          | 160 × 128 **Mode 5** bitmap, 2× scaled to 240 × 160.           |
| Input          | Polling the keypad registers for real-time movement.           |
| Timing / FPS   | Timer-2 based frame pacing; target FPS configurable at start. |
| Build System   | devkitARM GNU‐make flow (compatible with devkitPro **pacman** packages). |

---

## 2. Controls

| Button | Action  |
| ------ | ------- |
| ↑      | Move pixel up    |
| ↓      | Move pixel down  |
| ←      | Move pixel left  |
| →      | Move pixel right |

*(Other buttons are currently unused.)*

---

## 3. Building

Prerequisites  
• **devkitARM** (part of [devkitPro](https://devkitpro.org/))  
• `make` (MSYS2, Linux, or macOS)

1. Install devkitPro / devkitARM. On Windows with MSYS2, the recommended way is:

   ```bash
   pacman -S devkitARM
   ```

2. Make sure the environment variable `DEVKITARM` points to your installation (usually handled automatically by the installer).  
   Verify with:

   ```bash
   echo $DEVKITARM
   ```

3. Clone the repository and run:

   ```bash
   make
   ```

The build process produces `LonelyPixel.gba` (and an ELF/map file for debugging) at the project root.

---

## 4. Running the ROM

Option A – Emulator  
Use any modern GBA emulator (e.g. [mGBA](https://mgba.io/), VisualBoyAdvance-M, NO$GBA):
