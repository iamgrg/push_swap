NAME = push_swap
SRC = main.c sort.c sort_utils.c sort_utils2.c find_comb_utils.c find_comb.c ft_sort_small.c find_pos.c roll.c sort_utils3.c free.c parse.c
OBJ = $(SRC:.c=.o)
CC	= cc
RM	= rm -rf
FLAGS	= -g -Wall -Wextra -Werror 
LIBFT_LIB = libft/libft.a


all : $(NAME)

$(LIBFT_LIB) : 
		make -C libft push_swap

$(NAME) : $(OBJ) $(LIBFT_LIB)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB)

clean :
		make -C libft fclean 
		make -C libft fclean 
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)