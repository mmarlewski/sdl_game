BIN_FILE = sdl_game
SRC_DIR = ./src
INC_DIR = ./inc
BUILD_DIR = ./build

CC = gcc
OPT = -O0

# generate files that encode make rules for the .h dependencies
DEP_FLAGS = -MP -MD

# automatically add the -I onto each include directory
CC_FLAGS = -Wall -Wextra -g -I$(INC_DIR) $(OPT) $(DEP_FLAGS)

# regular expression completions (wildcard)
C_FILES = $(wildcard $(SRC_DIR)/*.c)

# regular expression replacement
O_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_FILES))
D_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(C_FILES))

all : $(BIN_FILE)

$(BIN_FILE) : $(O_FILES)
	$(CC) -lm -lSDL2 -lSDL2_image -lSDL2_mixer -o $@ $^

# only want the .c file dependency here, thus $< instead of $^.
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@

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