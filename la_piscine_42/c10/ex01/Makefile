# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 09:19:17 by mylee             #+#    #+#              #
#    Updated: 2020/12/09 09:19:18 by mylee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
TARGET = ft_cat
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
		gcc $(CFLAGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJECTS)
		gcc $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(TARGET)

re: fclean all
