NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_pshswp.c			\
	ft_pshswp_2.c			\
	ft_pshswp_3.c			\
	ft_is.c				\
	ft_push.c			\
	ft_instructions.c		\
	ft_instructions_next.c		\
	ft_instructions_next_2.c	\
	ft_lib.c			\
	ft_list_lib.c			\
	ft_list_lib_2.c			\
	ft_split.c

CHECKER_DIR = Just_checker

OBJ = $(SRC:.c=.o)

RESET			= "\033[0m"
GREEN			= "\033[92m"	# Green
RED			= "\033[91m"	# Red

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

bonus: $(NAME)
	$(MAKE) -C $(CHECKER_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(CHECKER_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(CHECKER_DIR) fclean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

re: fclean all

rf: re
	rm -f $(OBJ)
	rm -f $(NAME)
	$(MAKE) -C $(CHECKER_DIR) fclean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

help:
	@echo $(GREEN)
	@head -n 15 ft_pshswp.c
	@echo $(RESET)

.PHONY: all clean fclean re rf s help
