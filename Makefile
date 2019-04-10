SHELL =			bash

# Executable name
EXE =			lem-in

# Sources, includes and lib names
SRCS_NAME =		main.c

INCS_NAMES =	lemin.h

LDLIBS =		libft.a

# Sources, objects, includes and lib path
SRCS_PATH =		./srcs/
OBJS_PATH =		./objs/
INCS_PATH =		./includes/
LDFLAGS =		./libft/

# Sources and objects
SRCS =			$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS =			$(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS))
INC =			$(addprefix $(INCS_PATH), $(INCS_NAMES))

# Compilation
CC =			gcc
CPPFLAGS =		-I $(INCS_PATH)
LIBH =			-I $(LDFLAGS)includes/
CFLAGS =		-Wall -Wextra -Werror $(CPPFLAGS) $(LIBH)

# For Mac
# MLX =			-I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
# For Ubuntu
# MLX =			-I /usr/local/include/ -L /usr/local/lib/ -lmlx -lXext -lX11 -lm

# Text format
_DEF =			$'\033[0m
_GRAS =			$'\033[1m
_SOUL =			$'\033[4m
_CLIG =			$'\033[5m
_SURL =			$'\033[7m

# Colors
_BLACK =		$'\033[30m
_RED =			$'\033[31m
_GREEN =		$'\033[32m
_YELLOW =		$'\033[33m
_BLUE =			$'\033[34m
_PURPLE =		$'\033[35m
_CYAN =			$'\033[36m
_GREY =			$'\033[37m

# Background
_IBLACK =		$'\033[40m
_IRED =			$'\033[41m
_IGREEN =		$'\033[42m
_IYELLOW =		$'\033[43m
_IBLUE =		$'\033[44m
_IPURPLE =		$'\033[45m
_ICYAN =		$'\033[46m
_IGREY =		$'\033[47m

verif1 =		0
verif2 =		0

all: lib $(EXE)

lib:
		@make -sC $(LDFLAGS) -j

librm:
		@make -sC $(LDFLAGS) fclean

$(EXE): $(OBJS)
		$(CC) $(OBJS) $(LDFLAGS)$(LDLIBS) -o $(EXE)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
		@if [[ $(verif1) -eq 0 ]]; then printf "\n\n$(_GRAS)$(_CYAN)|===========================================>  $(EXE)  <============================================|$(_DEF)\n";\
		else printf "\e[1A"; fi
		$(eval FNCT = $(words $(SRCS)))
		$(eval verif1 = $(shell echo $(verif1) + 1 | bc ))
		$(eval PCR = $(shell echo "$(verif1) / $(FNCT) * 1000" | bc -l))
		@printf " \n$(_GREEN)[%d%%]\t$(_DEF)%-40s $(_DEF)👉\t\t$(_GREEN) %-40s$(_DEF)" $(shell echo $(PCR) | sed -E "s:\.[0-9]{20}::") $< $@
		@mkdir -p objs/
		@printf "$(_DEF)"
		@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
		@echo
		@rm -rf objs/ 2> /dev/null || true
		@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(OBJS_PATH)

fclean: clean
		@rm -f $(EXE)
		@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(EXE)
		@echo

fcleanall: librm fclean

re: fclean all

reall: librm re

norme:
		@norminette $(SRCS_PATH)
		@norminette $(INCS_PATH)

.PHONY: all lib librm clean fclean cleanall re reall norme
