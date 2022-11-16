# ═══ NAMES ═══════════════════════════════════════════════════════════════════#

NAME				= minitalk
NAME_BONUS	= minitalk_bonus

# ═══ COLORS ══════════════════════════════════════════════════════════════════#

GREEN		=\033[0;32m
BLUE 		=\033[0;34m
ORANGE	=\033[38;5;214m
RED			=\033[0;31m
YELLOW	=\033[0;33m
WHITE		=\033[0;37m

# ═══ COMPILATE ═══════════════════════════════════════════════════════════════#

CC			= gcc
CFLAGS	= -Wall -Wextra -Werror
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
CLIENT_FILES_BONUS	= client_bonus
SERVER_FILES_BONUS	= server_bonus

SRC_FILES+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))
SRC_FILES+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES))
SRC_FILES+=$(addprefix $(SERVER_DIR),$(SERVER_FILES))

SRC_FILES_BONUS+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES_BONUS))
SRC_FILES_BONUS+=$(addprefix $(SERVER_DIR),$(SERVER_FILES_BONUS))


EXE_FILES+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES))
EXE_FILES+=$(addprefix $(SERVER_DIR),$(SERVER_FILES))

EXE_FILES_BONUS+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES_BONUS))
EXE_FILES_BONUS+=$(addprefix $(SERVER_DIR),$(SERVER_FILES_BONUS))


SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
EXECS = $(addprefix $(EXE_DIR), $(EXE_FILES))

SRCS_CLIENT_BONUS += $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))
DEPS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES_BONUS)))
EXECS_BONUS = $(addprefix $(EXE_DIR), $(EXE_FILES_BONUS))


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

bonus: LIBFS $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(EXECS_BONUS)

$(EXE_DIR)% :
			@$(MKDIR) $(dir $@)
			$(CC) $(CFLAGS) -MMD -MP $(LIBSFT) -I$(INCLUDES) $< -o $@
# @echo "$(ORANGE) Compilando Ejecutables  ➟  $(BLUE)$< $(WHITE)"


clean :
			@make clean -s -C $(LIBFT_DIR)
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