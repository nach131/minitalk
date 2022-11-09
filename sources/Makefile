# ═══ NAMES ═══════════════════════════════════════════════════════════════════#

NAME				= minitalk
NAME_CLIENT = client
NAME_SERVER	=	server

# ═══ COLORS ══════════════════════════════════════════════════════════════════#

GREEN		=\033[0;32m
BLUE 		=\033[0;34m
ORANGE	=\033[38;5;214m
RED			=\033[0;31m
YELLOW	=\033[0;33m
WHITE		=\033[0;37m

# ═══ COMPILATE ═══════════════════════════════════════════════════════════════#

CC			= gcc
CFLAGS	= -Wall -Wextra -Werror -g3
AR 			= ar -rcs
RM			= rm -f
MKDIR		= -mkdir -p

# ═══ DIRECTORIES ═════════════════════════════════════════════════════════════#

LIBFT_DIR = libft/
INCLUDES 	= inc/
SRC_DIR 	= src/
OBJ_DIR 	= obj/
EXE_DIR		= exe/

CLIENT_DIR	= client/
UTILS_DIR		= utils/
SERVER_DIR	= server/

# ═══ SOURCES ═════════════════════════════════════════════════════════════════#

LIBSFT = $(LIBFT_DIR)libft.a

CLIENT_FILES	= client
SERVER_FILES	= server
UTILS_FILES		= utils

SRC_FILES+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))
SRC_FILES+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES))
SRC_FILES+=$(addprefix $(SERVER_DIR),$(SERVER_FILES))

EXE_FILES+=$(addprefix $(SERVER_DIR),$(SERVER_FILES))
EXE_FILES+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES))

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
EXECS = $(addprefix $(EXE_DIR), $(EXE_FILES))

# ═══ RULES ══════════════════════════════════════════════════════════════════#

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
			@$(MKDIR) $(dir $@)
			@echo "$(ORANGE) Compilando objetos  ➟  $(BLUE)$< $(WHITE)"
			@$(CC) -MT $@ -MMD -MP $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all: LIBFS $(NAME)

LIBFS:
			@make -C $(LIBFT_DIR)

$(NAME) : $(OBJS) $(EXECS)

$(EXE_DIR)% : $(OBJ_DIR)%.o
			@$(MKDIR) $(dir $@)
			@$(CC) $(CFLAGS) -MMD -MP $(LIBSFT) $(OBJ_DIR)$(UTILS_DIR)$(UTILS_FILES).o $< -o $@
			@echo "$(ORANGE) Compilando Ejecutables  ➟  $(BLUE)$< $(WHITE)"

clean : 
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf $(EXE_DIR)
			@echo "$(RED)\n ✗ Archivos objetos Minitalk borrados.‼️\n$(WHITE)";

fclean : clean
			@$(RM) -f $(NAME)
			@echo "$(BLUE) Todo Super limpito...✌🏼$(WHITE)"

re: fclean all
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

norm:
			@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

-include $(DEPS)

# Non-file targets
.PHONY: all clean fclean re norm LIBFS