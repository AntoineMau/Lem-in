SHELL = bash

# Executable name, can be change
NAME = lem-in

# Sources names
SRCS_NAME = main.c

# Sources, objects and includes path
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
INCS_PATH = ./includes/

# Sources and objects
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS))

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g $(CPPFLAGS) $(LIBH)
CPPFLAGS = -I $(INCS_PATH)
LIBH = -I $(LDFLAGS)includes/
LDFLAGS = ./libft/

# Text format
_DEF = $'\033[0m
_GRAS = $'\033[1m
_SOUL = $'\033[4m
_CLIG = $'\033[5m
_SURL = $'\033[7m

# Colors
_BLACK = $'\033[30m
_RED = $'\033[31m
_GREEN = $'\033[32m
_YELLOW = $'\033[33m
_BLUE = $'\033[34m
_PURPLE = $'\033[35m
_CYAN = $'\033[36m
_GREY = $'\033[37m

# Background
_IBLACK = $'\033[40m
_IRED = $'\033[41m
_IGREEN = $'\033[42m
_IYELLOW = $'\033[43m
_IBLUE = $'\033[44m
_IPURPLE = $'\033[45m
_ICYAN = $'\033[46m
_IGREY = $'\033[47m

verif = 0

all: lib $(NAME)

lib:
		@make -sC libft -j100

librm:
		@make -sC libft fclean

$(NAME): lib $(OBJS)
		@$(CC) $(OBJS) libft/libft.a -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@if [[ $(verif) -eq 0 ]]; then printf "\n$(_GRAS)$(_CYAN)|===========================================>  $(NAME)   |============================================>$(_DEF)\n";\
	else printf "\e[1A"; fi
	$(eval FNCT = $(words $(SRCS)))
	$(eval verif = $(shell echo $(verif) + 1 | bc ))
	$(eval PCR = $(shell echo "$(verif) / $(FNCT) * 1000" | bc -l))
	@printf " \n$(_GREEN)[%4d%%]\t$(_DEF)%-40s $(_DEF)👉\t\t$(_GREEN) %-40s$(_DEF)" $(shell echo $(PCR) | sed -E "s:\.[0-9]{20}::") $< $@
	@mkdir -p objs/libft
	@mkdir -p objs/get_next_line
	@mkdir -p objs/ft_printf
	@printf "$(_DEF)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
		@echo
		@rm -rf objs/ 2> /dev/null || true
		@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(OBJS_PATH)

fclean: clean
		@rm -f $(NAME)
		@rm -f $(CH)
		@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(NAME)
		@echo

fcleanall: librm fclean

re: fclean all

reall: librm re

norme:
		@norminette $(SRCS_PATH)
		@norminette $(INCS_PATH)

.PHONY: all lib librm ps ch clean fclean cleanall re reall norme