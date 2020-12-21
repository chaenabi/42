# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 09:17:54 by mylee             #+#    #+#              #
#    Updated: 2020/12/09 09:17:56 by mylee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

TARGET = ft_display_file
SOURCES = main.c 
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
		gcc $(CFLAGS) -c $<

$(TARGET): $(OBJECTS)
		gcc $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(TARGET)

re: fclean all

