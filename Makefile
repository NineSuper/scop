# @Makefile by tde-los- (http://github.com/NineSuper)
INC=/usr/include
INCLIB=$(INC)/../lib

MLX_PATH=lib/mlx/

INC_SRCH_PATH :=
INC_SRCH_PATH += -I$(MLX_PATH)

LFLAGS = -lbsd -L $(MLX_PATH) -lmlx -L$(INCLIB) -lXext -lX11 -lm

NAME = Scop

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LIB = lib/ft_printf/*.c lib/libft/*.c lib/gnl/*.c
HEADER_FILE = utils.h lib/ft_printf/ft_printf.h lib/lib/libft.h lib/gnl/get_next_line.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

# ------------------------------ Couleurs ------------------------------

BOLD_RED	=	\033[1;31m

BOLD_PURPLE     =       \033[1;35m

BOLD_CYAN       =       \033[1;36m

BOLD_YELLOW     =       \033[1;33m

BOLD		=	\033[1m

NO_COLOR        =       \033[0m

# ------------------------------ Messages ------------------------------

HEADER_NAME	=	$(HEADER_TOP) $(HEADER_TOP_MID) $(HEADER_MID)$(HEADER_BOT)

HEADER_COMP     =       echo "\n👾 $(BOLD_PURPLE)$(NAME) $(NO_COLOR)$(BOLD)by $(BOLD_RED)tde-los-\n\n"

MLX_READY	=	echo "\n\n📥 $(BOLD)Compilation de la $(BOLD_YELLOW)Mlx$(NO_COLOR) $(BOLD)reussi !$(NO_COLOR)\n"

COMP_START      =       printf "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Debut de compilation...\r$(NO_COLOR)"

EXE_READY       =       echo "\n\n🎮 $(BOLD)Compilation de $(BOLD_PURPLE)$(NAME)$(NO_COLOR) $(BOLD)reussi !$(NO_COLOR)\n"

CLEANED         =       echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Suppression des fichiers .o et de l'executable \n"

FCLEANED        =       echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Suppression des fichiers .o et de l'executable \n"

NORM		= 	echo "\n📢 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme de tous les fichiers en .c !\n$(BOLD_PURPLE)"

NORM_LIB	= 	echo "\n📢 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme du dossier $(BOLD_CYAN)/libft $(BOLD_YELLOW)!\n$(BOLD_YELLOW)"

NORM_H		=	echo "\n📣 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme du .h\n$(BOLD_PURPLE)"

# ------------------------------ Regles ------------------------------
MAKEFLAGS += --silent

TOTAL_FILES := $(words $(SRC))
COMPILED_FILES := 0

$(NAME): comp_start $(OBJ)
	@$(MAKE) -C $(MLX_PATH)
	@$(CC) $(LIB) $(OBJ) -o $(NAME) $(INC_SRCH_PATH) $(LFLAGS)
	echo "\n"
	@$(MLX_READY)
	@$(EXE_READY)

all: $(NAME) norminette


norminette:
	$(NORM_LIB)
	norminette $(LIB)
	$(NORM)
	norminette *.c
	$(NORM_H)
	norminette -R checkDefine $(HEADER_FILE)
	echo "\n"

comp_start:
	@$(HEADER_COMP)
	@$(COMP_START)

clean:
	$(CLEANED)
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean:
	rm -f $(NAME) $(OBJ) *~ core *.core
	$(FCLEANED)

re: clean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Compilation des fichiers :$(BOLD_CYAN) %-33.33s $(BOLD_YELLOW)[%3d%%] \r$(NO_COLOR)" $? $(shell expr \( $(COMPILED_FILES) \) \* 100 / $(TOTAL_FILES))
	@$(CC) $(FLAGS) -c $< -o $@
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Compilation des fichiers :$(BOLD_CYAN) %-33.33s $(BOLD_YELLOW)[%3d%%] \r$(NO_COLOR)" $? $(shell expr \( $(COMPILED_FILES) \) \* 100 / $(TOTAL_FILES))