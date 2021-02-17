/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define TRUE 1
# define FALSE 0
# include <stdarg.h>
# include <unistd.h>

/*
** ============================================================================
**   Flags
** ============================================================================
*/

enum					e_flags
{
	Flags_None = 0,
	Flags_LeftJustify = 1 << 0,
	Flags_PaddingByZero = 1 << 1,
	Flags_Alternative = 1 << 2,
	Flags_Space = 1 << 3,
	Flags_Sign = 1 << 4
};

/*
** ============================================================================
**    Format Number (Width, Length) Enums
** ============================================================================
*/

enum					e_numbers
{
	Number_None,
	Number_Defined
};

enum					e_length
{
	Length_None,
	Length_L,
	Length_LL,
	Length_H,
	Length_HH
};

enum					e_side
{
	Side_Head,
	Side_Tail
};

/*
** ============================================================================
**   Types
** ============================================================================
*/

typedef unsigned int	t_bitflag;
typedef int				t_bool;

/*
** ============================================================================
**   Structures / Unions
** ============================================================================
*/

typedef struct			s_printf
{
	int					fd;
	size_t				len;
	const char			*format;
	va_list				*args;
}						t_printf;

typedef struct			s_format
{
	t_bitflag			flags;
	int					sign;
	int					width_mode;
	int					width;
	int					precision_mode;
	int					precision;
	int					length;
	int					specifier;
	t_bool				is_negative_num;
	const char			*prefix;
}						t_format;

/*
**  ----- for 'fge' specifiers -----
*/

typedef struct			s_bigint
{
	int					blocksmax;
	int					negative;
	int					blockcnt;
	unsigned int		*block;
}						t_bigint;

typedef struct			s_dtoa
{
	t_bigint			b;
	t_bigint			s;
	char				*buf;
	int					decpt;
	int					p2d;
	int					p10d;
	int					mode;
}						t_dtoa;

typedef union			u_modf
{
	double				f;
	uint32_t			i32[2];
	uint64_t			i;
}						t_modf;

typedef struct			s_cvt_buf
{
	char				*buf;
	int					i;
	int					scientific;
}						t_cvt_buf;

/*
** ============================================================================
**   Functions
** ============================================================================
*/

/*
**  ft_printf.c
*/

int						ft_printf(const char *format, ...);
int						ft_vprintf(int fd, const char *format,
									va_list *args);

/*
**  parser.c
*/

void					parse_flags(t_printf *p, t_format *e);
void					parse_width(t_printf *p, t_format *e);
void					parse_precision(t_printf *p, t_format *e);
void					parse_specifier(t_printf *p, t_format *e);
void					parse_length(t_printf *p, t_format *e);

/*
**  printer_c.c
*/

void					print_c(t_printf *p, t_format *e, va_list *args);

/*
**  printer_pdiuopx.c
*/

void					print_pdiuopx(t_printf *p, t_format *e, va_list *args);

/*
**  printer_s.c
*/

void					print_s(t_printf *p, t_format *e, va_list *args);

/*
**  io.c
*/

void					ft_putchar_pf(t_printf *p, int c);
void					ft_putchar_len_pf(t_printf *p, int c, int len);
void					ft_putstr_pf(t_printf *p, const char *c);
void					ft_putstr_len_pf(t_printf *p, const char *c, int len);

/*
**  utils_num.c
*/

int						ft_min(int a, int b);
int						ft_max(int a, int b);
int						ft_abs(int a);

/*
**  utils_memory.c
*/

void					ft_bzero(void *ptr, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memset(void *b, int c, size_t len);

/*
**  utils_double.c
*/

double					ft_floor(double x);
int						ft_signbit(double x);
int						ft_isinf(double nb);
int						ft_isnan(double nb);

/*
**  utils_string.c
*/

char					*ft_strchr(const char *s, int c);
int						ft_isdigit(int c);
int						ft_strlen(const char *ch);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
char					*ft_strdup(const char *s1);

/*
**  arg_getter.c
*/

uint64_t				get_arg_int(t_format *elem, va_list *args);
double					get_arg_float(t_format *elem, va_list *args);

/*
**  ---------------------- for 'fge' specifiers ----------------------
*/

/*
**  --** [[[ Printer ]]] **--
*/

/*
**  printer_fge.c
*/

void					print_fge(t_printf *p, t_format *e, va_list *args);

/*
**  --** [[[ Bigint ]]] **--
*/

/*
**  bigint_memory.c
*/

int						bigint_alloc(t_bigint *b, int blocks,
										int fill_blocks_as_zero);
void					bigint_free(uint32_t *pb, uint32_t *ps);
int						bigint_ensure(t_bigint *bigint, int needs);
void					bigint_replace(t_bigint *dest, t_bigint *src);

/*
**  bigint_from.c
*/

int						bigint_from_int(t_bigint *b, int nb);
int						bigint_from_double(t_dtoa *d, double dbl, int *pbits);

/*
**  bigint_utils.c
*/

int						count_blocks(t_bigint *res);
void					do_logarithm(t_dtoa *d, t_modf u);

/*
**  bigint_multadd.c
*/

int						bigint_multadd(t_bigint *b, int m, int a);

/*
**  bigint_mult.c
*/

int						bigint_mult(t_bigint *a, t_bigint *b);

/*
**  bigint_pow5mult.c
*/

int						bigint_pow5mult(t_bigint *b, int k);

/*
**  bigint_cmp.c
*/

int						bigint_cmp(t_bigint *a, t_bigint *b);

/*
**  bigint_quorem.c
*/

int						bigint_quorem(t_bigint *b, t_bigint *s);

/*
**  bigint_lshift.c
*/

int						bigint_lshift(t_bigint *b, int shift);

/*
**  bigint_dshift.c
*/

int						bigint_get_divider_shift(t_bigint *b, int p2);

/*
**  bigint_to_string.c
*/

int						bigint_to_string(t_dtoa *d, int limit);

/*
**  =====** [[[ dtoa ]]] **=====
*/

/*
**  ------ ft_dtoa.c ------
*/

char					*ft_dtoa(double dd, int mode, int ndigits, int *decpt);

/*
**  ------ ft_dtoa_utils.c ------
*/

int						less_than(int a, int b);
int						ft_sbit(uint32_t i, int side);
int						ft_sbit64(uint64_t i, int side);
int						set_strval(t_dtoa *d, const char *s, int decpt);
int						process_special_values(t_dtoa *d, double dd);

/*
**  =====** [[[ float_to_string ]]] **=====
*/

/*
**  ------ ft_convert_float_buf.c ------
*/

int						alloc_cvt_buf(t_cvt_buf *ret, int buflen);
void					fill_scale(char *ret, int decpt);

/*
**  ------ ft_convert_float_f.c ------
*/

char					*ft_convert_f(double d, int prec, int point);

/*
**  ------ ft_convert_float_e.c ------
*/

char					*ft_convert_e(double d, int prec, int upper, int point);

/*
**  ------ ft_convert_float_g.c ------
*/

char					*ft_convert_g(double d, int prec, int upper,
										int optional);

#endif
