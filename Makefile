SRC =	src/main/push_swap.c \
		src/std_fun/ft_putstr_fd.c src/std_fun/ft_strlcat.c src/std_fun/ft_strlen.c \
		src/std_fun/ft_strcmp.c src/std_fun/ft_split.c src/std_fun/ft_substr.c \
		src/std_fun/ft_strdup.c src/std_fun/ft_atoi.c \
		src/utils/utils.c src/utils/parser.c src/utils/moves_0.c src/utils/moves_1.c \
		src/utils/sort.c src/utils/sorting.c src/utils/max_min.c \
		src/std_fun/ft_memset.c src/utils/parser_2.c

OBJ =$(SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

PUSH_HEAD = include/push_swap.h

all : $(NAME)

$(OBJ): %.o: %.c $(PUSH_HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean bonus