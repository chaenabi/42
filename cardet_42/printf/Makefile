CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g
AR = ar
ARFLAGS = rc

NAME = libftprintf.a

M_DIR = ./mandatory/
M = \
	arg_getter \
	io \
	parser \
	printer_c \
	printer_pdiuopx \
	printer_s \
	utils_double \
	utils_memory \
	utils_num \
	utils_string \
	ft_printf
M_SRC = $(addprefix $(M_DIR), $(addsuffix .c, $(M)))
OBJ = $(M_SRC:.c=.o)

B_DIR = ./bonus/
B = \
	bigint_cmp \
	bigint_divider_shift \
	bigint_from \
	bigint_lshift \
	bigint_memory \
	bigint_mult \
	bigint_multadd \
	bigint_pow5mult \
	bigint_quorem \
	bigint_to_string \
	bigint_utils \
	ft_convert_float_buf \
	ft_convert_float_e \
	ft_convert_float_f \
	ft_convert_float_g \
	ft_dtoa_utils \
	ft_dtoa \
	printer_fge
B_SRC = $(addprefix $(B_DIR), $(addsuffix _bonus.c, $(M) $(B)))
BOBJ = $(B_SRC:.c=.o)


all : $(NAME)

clean :
	@echo " ================= Cleaning Object files ================="
	rm -rf $(OBJ) $(BOBJ)
	@echo
	@echo

fclean : clean
	@echo " ================= Full Cleaning $(NAME) file ================="
	rm -rf $(NAME)
	@echo
	@echo

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME) : $(OBJ)
	@echo
	@echo " ================= Merging objects into Archive file ================="
	rm -rf $@
	$(AR) $(ARFLAGS) $@ $(OBJ)
	@echo

bonus : $(BOBJ)
	@echo
	@echo " ================= Merging objects into Archive file ================="
	rm -rf $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(BOBJ)
	@echo

re : fclean all

norme:
	norminette $(M_SRC) $(B_SRC) $(M_DIR)ft_printf.h $(B_DIR)ft_printf_bonus.h

.PHONY: all clean fclean re bonus norme
