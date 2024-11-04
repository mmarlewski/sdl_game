
# https://www.youtube.com/watch?v=DtGrdB8wQ_8
# https://github.com/gwu-cs-os/evening_os_hour/blob/master/f19/10.2-makefiles/03_featureful_makefile/Makefile

BIN_FILE = sdl_game
SRC_DIR = ./src
BUILD_DIR = ./build

CC = gcc
CFLAGS = -O0
LDFLAGS = -lc -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# regular expression completions (wildcard)
C_FILES = $(wildcard $(SRC_DIR)/*.c)

# regular expression replacement
O_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_FILES))
D_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(C_FILES))

all : $(BIN_FILE)

$(BIN_FILE) : $(O_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# only want the .c file dependency here, thus $< instead of $^.
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MP -MD $(LDFLAGSS) -c $< -o $@

clean :
	rm -rf $(BIN_FILE) $(O_FILES) $(D_FILES)

# shell commands are a set of keystrokes away
distribute : clean
	tar zcvf dist.tgz *

# @ silences the printing of the command
# $(info ...) prints output
diff :
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

# include the dependencies
-include $(D_FILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY : all clean distribute diff

