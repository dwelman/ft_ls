# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 07:29:09 by daviwel           #+#    #+#              #
#    Updated: 2016/06/13 12:34:49 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c flags.c info.c r_search.c list_view_sort.c count_files.c\
	  sort.c pad_size.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft
	gcc -I libft/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

q:
	gcc -I libft/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

norme:
	norminette $(SRC) ft_ls.h
