# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 18:23:13 by fcorvaro          #+#    #+#              #
#    Updated: 2024/06/20 19:22:33 by fcorvaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Output: Appereance ------------------------------------------------------ #

# Start and end sequences for color codes -- REMEMBER (add ; and m)
START = \033[
END = \033[0m
# ------------  FOREGROUND COLORS  ------------------------------------------- #
# Black, Red, Green, Yellow, Blue, Magenta, Cyan, White #
BK = 30
R = 31
G = 32
Y = 33
BE = 34
M = 35
C = 36
W = 37
# ------------  BACKGROUND COLORS  ------------------------------------------- #
# Black, Red, Green, Yellow, Blue, Magenta, Cyan, White #
BKK = 40
RR = 41
GG = 42
YY = 43
BEE = 44
MM = 45
CC = 46
WW = 47
# ------------  TEXT STYLES  ------------------------------------------------- #
# Bold text, Faint text, Italic text, Underlined text, Blinking text ...#
#... Reverse colors, Hidden text, Strikethrough text #
BOLD = 1
FAINT = 2
ITALIC = 3
UNDERLINE = 4
BLINKING = 5
REVERSE =7
HIDDEN = 8
STRIKE = 9


# ------------  LIBFTPRINTF -------------------------------------------------- #
LIBFTPRINTF_DIR = lib/libftprintf
LIBFTPRINTF = lib/libftprintf/build/libftprintf.a
# ------------  LIBRARY LINKING COMMAND  ------------------------------------- #
LIBRARIES	= -L./lib/libftprintf/build -lftprintf

# ------------  MLX  --------------------------------------------------------- #
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)	# Rule for Linux system
	MINILIBX_DIR = lib/mlx_linux/
	MINILIBXCC = -I mlx -L $(MINILIBX_DIR) -lmlx -lm -lXext -lX11 -lz
endif
# ------------  MINILIBX LIBRARY PATH  --------------------------------------- #
MINILIBX = $(MINILIBX_DIR)libmlx.a

# ------------  INCLUDE HEADER FILES COMMAND  -------------------------------- #
INCLUDE	= -I./include/ -I$(MINILIBX_DIR) -I$(LIBFTPRINTF_DIR)/include/

# ------------  COMPILER COMMAND  -------------------------------------------- #
CC = gcc

# ------------  COMPILER FLAGS  ---------------------------------------------- #
CFLAGS = -Wall -Wextra -Werror -O3

# ------------  DEBUGGER LEAKS FLAGS  ---------------------------------------- #
LEAKS = -g3 -ggdb

# ------------  REMOVE COMMAND  ---------------------------------------------- #
RM = rm -f

# ------------  SOURCES DIRECTORY  ------------------------------------------- #
SRCS_DIR = srcs

# ------------  OBJECTS DIRECTORY  ------------------------------------------- #
OBJS_DIR = objs

# ------------  BUILD FILE NAME  --------------------------------------------- #
BUILD = cub3d

# ------------  FULL PATH TO THE BUILD FILE  --------------------------------- #
NAME = $(BUILD)

# ------------  SOURCES FILES  ----------------------------------------------- #
SRCS = $(shell find $(SRCS_DIR) -name "*.c")

# ------------  OBJECT FILES  ------------------------------------------------ #
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

# ------------  OBJECTS DIRECTORY CREATION TARGET  --------------------------- #
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(START)$(BOLD);$(ITALIC);$(Y)mCompiling $< ...$(END)"
	@$(CC) $(CFLAGS) $(LEAKS) -c $< -o $@ $(INCLUDE)
	
# ------------  INCLUDE DEPENDENCY FILES  ------------------------------------ #
-include $(OBJS_DIR)/*.d

# ------------  PHONY TARGETS  ----------------------------------------------- #
.PHONY : all clean fclean re bonus norm makelibs help system_info

system_info:
	@echo "$(START)$(BOLD);$(ITALIC);$(G)m Compiled for $(UNAME_S)!$(END)"

# ------------  BUILD LIBRARIES  --------------------------------------------- #
makelibs:
	@$(MAKE) -sC $(LIBFTPRINTF_DIR)
	@$(MAKE) -sC $(MINILIBX_DIR)

# ------------  CUB3D CREATION TARGET  --------------------------------------- #
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LEAKS) $(OBJS) $(MINILIBXCC) -o $(NAME) $(INCLUDE) $(LIBRARIES)
	@echo "$(START)$(BOLD);$(ITALIC);$(G)m Compilation of $(NAME) completed successfully!$(END)"
	@echo "$(START)$(BOLD);$(ITALIC);$(BE)m To run the program, use: ./$(BUILD) <map_file>$(END)"
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mmap_file$(END): The file containing the map for the 3D environment."
	@echo "$(START)$(BOLD);$(ITALIC);$(M)m Authors: fcorvaro & fursini$(END)"
	
# ------------  DEFAULT TARGET  ---------------------------------------------- #
all: makelibs
	@$(MAKE) -s $(NAME) system_info

# ------------  CLEAN TARGET  ------------------------------------------------ #
clean:
	@make clean -sC $(LIBFTPRINTF_DIR)
	@make clean -sC $(MINILIBX_DIR)
	@if [ -d "$(OBJS_DIR)" ]; then \
		$(RM) -r $(OBJS_DIR); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up object files. $(OBJS_DIR) has been removed. $(END)"; \
	fi

# ------------  FCLEAN TARGET  ----------------------------------------------- #
fclean: clean
	@make -s fclean -sC $(LIBFTPRINTF_DIR)
	@$(RM) -f $(MINILIBX)
	@if [ -f "$(BUILD)" ]; then \
		$(RM) $(BUILD); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up executable file. $(BUILD) has been removed. $(END)"; \
	fi
	@$(RM) -r $(BUILD)

# ------------  RE TARGET  --------------------------------------------------- #
re : fclean
	@make -s all

# ------------  BONUS TARGET  ------------------------------------------------ #
bonus:
	

# ------------  HELP TARGET  ------------------------------------------------- #
help:
	@echo "  $(START)$(BOLD);$(ITALIC);$(G)mAvailable targets:$(END)"
	@echo "  make [command]"
	@echo ""
	@echo "  $(START)$(BOLD);$(Y)mall\t\tCompile the project$(END)"
	@echo "  $(START)$(BOLD);$(Y)mbonus\t\t$(END)"
	@echo "  $(START)$(BOLD);$(Y)mclean\t\tRemove object files$(END)"
	@echo "  $(START)$(BOLD);$(Y)mfclean\tRemove object files and the executable$(END)"
	@echo "  $(START)$(BOLD);$(Y)mnorm\t\tCheck the code with Norminette$(END)"
	@echo "  $(START)$(BOLD);$(Y)mre\t\tRecompile the project$(END)"
	@echo "  $(START)$(BOLD);$(Y)mhelp\t\tDisplay this help message$(END)"
	@echo ""
	@echo "  $(START)$(BOLD);$(M)mProject Description:$(END)"
	@echo "  This project, known as 'cub3d', is a graphic project inspired by the world-famous"
	@echo "  90's game and the first FPS ever - Wolfenstein 3D. The project is implemented in C"
	@echo "  using the MiniLibX library. The program takes a map as an argument, which describes"
	@echo "  the walls and spaces of the game, and renders a 3D view from the player's perspective."
	@echo "  The project demonstrates understanding of ray-casting, event handling, and basic"
	@echo "  graphics programming."

# ------------  NORM TARGET  ------------------------------------------------- #
norm:
	@OUTPUT="$(shell norminette $(SRCS_DIR) include/ $(LIBFTPRINTF_DIR) | grep -v OK)"; \
	if [ -z "$$OUTPUT" ]; then \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Norminette check: $(END)$(START)$(BOLD);$(ITALIC);$(G)m All files are OK! $(END)"; \
	else \
		echo "$(START)$(BOLD);$(ITALIC);$(R)m Norminette check: $(END)$(START)$(BOLD);$(ITALIC);$(R)m Errors found: \n$$OUTPUT $(END)"; \
	fi