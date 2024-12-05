NAME = push_swap

CC = cc
CFLAGS = -g

SRC =	ft_pshswp.c			\
	ft_pshswp_2.c			\
	ft_pshswp_3.c			\
	ft_apply.c			\
	ft_is.c				\
	ft_instructions.c		\
	ft_instructions_next.c		\
	ft_instructions_next_2.c	\
	ft_lib.c			\
	ft_lib_2.c			\
	ft_list_lib.c			\
	ft_list_lib_2.c			\
	ft_split.c

OBJ = $(SRC:.c=.o)

PRINTF_DIR = Printf
PRINTF = libftprintf.a


RESET			= "\033[0m"
GREEN			= "\033[32m"	# Green
RED			= "\033[31m"	# Red


all: $(NAME) $(PRINTF)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(PRINTF_DIR) -lftprintf
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

re: fclean all

rf: re
	rm -f $(OBJ)
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

.PHONY: all clean fclean re rf s
