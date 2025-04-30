# PixelLive

my-gba-game/
├── assets/               # Raw game assets (graphics, audio, etc.)
│   ├── sprites/          # Sprite images (e.g. .png)
│   ├── music/            # Music/audio files
│   └── levels/           # Level data
├── build/                # Auto-generated build files
│   ├── gba/              # Compiled .gba file (final ROM)
│   ├── obj/              # Object files (.o)
│   └── deps/             # Dependency files (.d)
├── data/                 # Embedded binary data (e.g. .bin files)
│   ├── sprites.bin       # Compiled sprite data
│   ├── tileset.bin       # Compiled tileset data
│   └── level1.bin        # Compiled level data
├── include/              # Header files
│   ├── game.h            # Main game header
│   └── sprites.h         # Sprite-related functions
├── source/               # C/ASM source code
│   ├── main.c            # Main game loop
│   ├── sprites.c         # Sprite handling code
│   └── level.c           # Level logic
├── tools/                # Scripts or tools for asset conversion
│   ├── convert_sprites.sh  # Convert .png to .bin
│   └── convert_music.sh    # Convert .ogg to .bin
├── .gitignore            # Ignore files (e.g. build files, IDE configs)
├── Makefile              # Makefile for building the game
├── README.md             # Project documentation
└── LICENSE               # Project license
