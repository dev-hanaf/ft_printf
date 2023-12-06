RED = \033[0;31m
BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m

NAME = libftprintf.a

SRC = ft_printf.c
 
#BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c \
#		ft_lstlast_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


OBJ = $(SRC:.c=.o)
#OBJ_BNS = $(BNS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rc


all: header $(NAME) 

$(NAME): $(OBJ)


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

#bonus: header $(OBJ_BNS)



clean: header
	@rm -f $(OBJ) $(OBJ_BNS)

fclean:  clean
	@rm -f $(NAME)

re :fclean all 


header:
	@echo "$(RED)$(BOLD)"
	@echo " ██░ ██  ▄▄▄       ███▄    █  ▄▄▄        █████▒"
	@echo "▓██░ ██▒▒████▄     ██ ▀█   █ ▒████▄    ▓██   ▒ "
	@echo "▒██▀▀██░▒██  ▀█▄  ▓██  ▀█ ██▒▒██  ▀█▄  ▒████ ░ "
	@echo "░▓█ ░██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒░██▄▄▄▄██ ░▓█▒  ░ "
	@echo "░▓█▒░██▓ ▓█   ▓██▒▒██░   ▓██░ ▓█   ▓██▒░▒█░    "
	@echo " ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒░   ▒ ▒  ▒▒   ▓▒█░ ▒ ░    "
	@echo " ▒ ░▒░ ░  ▒   ▒▒ ░░ ░░   ░ ▒░  ▒   ▒▒ ░ ░      "
	@echo " ░  ░░ ░  ░   ▒      ░   ░ ░   ░   ▒    ░ ░    "
	@echo " ░  ░  ░      ░  ░         ░       ░  ░        "
    
	@echo "$(NC)"  
	
	@printf "$(YELLOW)$(BOLD)ahanaf Sama!$(NC)\n"