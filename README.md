
# Fallen Stalactite

![image](logo.png)

https://marcin12345.itch.io/fallen-stalactite

### About
- Explore an open world consisting of 48 unique rooms.
- Use your skills and items to interact with the environment.
- Push, pull, throw, melt and manipulate various object to gain access to other rooms and resources.
- Fight enemies ina turned based combat with telegraphed attacks.
- Lure enemies into traps and take advantage of their attacks to access hard to reach goods.
- Watch out for environmental hazards.
- Open blocked passages with skills or items.
- Exchange gemstones for other items in vending machines (or break them to gain items without paying).
- Bring to life other allies to help with room puzzles.
- Add new augmentations to your body to unlock new skills and skill synergies.
- Decide between mutually exclusive augmentations and choose your way of approaching the world (jumping or floating on water, pushing or throwing objects, pulling  or putting items into far away objects, manipulating mechanical objects or teleporting freely in room).

### How to run
- you will need to install SDL2, SDL2_image, SDL2_mixer and SDL2_ttf (from a package manager or from source)
- SDL source code: https://github.com/libsdl-org/SDL
- general installation guide: https://wiki.libsdl.org/SDL2/Installation
##### Linux
- tutorial video: https://www.youtube.com/watch?v=P3_xhDIP7bc&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=2
- run: `gcc ./src/*.c  -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o sdl_game && ./sdl_game`
- there is also Makefile available: `make && ./sdl_game`
##### Windows
- install MinGW: https://sourceforge.net/projects/mingw-w64
- tutorial video: https://www.youtube.com/watch?v=DQ-NBjBFLJ4&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=3
##### Web
- install and activate emsdk: https://emscripten.org/docs/getting_started/downloads.html
- run: `emcc -sWASM=1 -sUSE_SDL=2 -sUSE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -sUSE_SDL_MIXER=2 -sUSE_SDL_TTF=2 -o index.html --shell-file template.html ./src/*.c --preload-file ./res --use-preload-plugins -sALLOW_MEMORY_GROWTH=1 -sMAXIMUM_MEMORY=1gb -O0 && emrun --browser firefox index.html` (change 'firefox' to your specific browser)

### Inspired by
- Into the Breach : telegraphed attack to take advantage of enemy actions and 8x8 grid rooms
- metroidvanias : approach to level exploration (certain level chunks inaccessible without appropriate power-ups, new power-ups spread throughout the level)
- immersive sims : interacting with the environment in systemic ways (meltable objects can be melted with cell item by the player or with lasers by enemy turrets, water and lava tiles accessible to floating enemies or hero with floating ability, pits can be crossed by jumping, being thrown by enemy, pulling yourself to another object with chain or by flying with flying ability)

### Recordings

<p float="center">
  <img src="./doc/rec_1.gif" />
  <img src="./doc/rec_2.gif" /> 
  <img src="./doc/rec_3.gif" />
  <img src="./doc/rec_4.gif" />
  <img src="./doc/rec_5.gif" />
  <img src="./doc/rec_6.gif" />
  <img src="./doc/rec_7.gif" />
  <img src="./doc/rec_8.gif" />
  <img src="./doc/rec_9.gif" />
  <img src="./doc/rec_10.gif" />
  <img src="./doc/rec_11.gif" />
  <img src="./doc/rec_12.gif" />
</p>
