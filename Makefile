NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c ft_printstr.c ft_printnum.c ft_printptr.c
OBJ = $(SRC:.c=.o)
INCLUDEDIR = ./
HEADERS = $(INCLUDEDIR)libftprintf.h
LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDEDIR) -c

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)
	cp $(LIBFT) ./$(NAME)

clean:
	@make clean -C $(LIBFTDIR)
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@/bin/rm -f $(NAME)

re: fclean all
