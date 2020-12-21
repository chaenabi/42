# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 16:47:53 by mylee             #+#    #+#              #
#    Updated: 2020/12/09 11:54:36 by mylee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all: libft.a

%.o: %.c
		gcc -c -Wall -Wextra -Werror $< -o $@ -I includes
			
libft.a: $(OBJECTS)
		ar cr $@ $(OBJECTS)

clean:
		rm $(OBJECTS)

fclean: clean
		rm libft.a

re: fclean all

