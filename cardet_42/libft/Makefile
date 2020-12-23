CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

TARGET = libft.a
SOURCES = ./ft_memset.c \
		  ./ft_isalnum.c \
		  ./ft_isprint.c \
		  ./ft_memcpy.c \
		  ./ft_strcpy.c \
		  ./ft_strlen.c \
		  ./ft_strrchr.c \
		  ./ft_atoi.c \
	  	  ./ft_isalpha.c \
		  ./ft_memccpy.c \
		  ./ft_memmove.c \
		  ./ft_strdup.c \
		  ./ft_strncmp.c \
		  ./ft_tolower.c \
		  ./ft_bzero.c \
		  ./ft_isascii.c \
		  ./ft_memchr.c \
		  ./ft_memset.c \
		  ./ft_strlcat.c \
		  ./ft_strncpy.c \
		  ./ft_toupper.c \
		  ./ft_calloc.c \
		  ./ft_isdigit.c \
		  ./ft_memcmp.c \
		  ./ft_strchr.c \
		  ./ft_strlcpy.c \
		  ./ft_strnstr.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
	
$(TARGET): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all