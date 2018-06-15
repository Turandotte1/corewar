/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:00:47 by mrychkov          #+#    #+#             */
/*   Updated: 2017/11/06 02:24:53 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define NB_ARGS 16
# define BUFF_SIZE 1000

typedef struct		s_printf
{
	unsigned int	hash:1;
	unsigned int	left:1;
	unsigned int	space:1;
	unsigned int	plus:1;
	unsigned int	zero:1;
	unsigned int	minus:1;
	size_t			width;
	size_t			prec;
	unsigned int	is_shortshort:1;
	unsigned int	is_longlong:1;
	unsigned int	intmax:1;
	unsigned int	is_sizet:1;
	unsigned int	is_short:1;
	unsigned int	is_long:1;
	char			spec;
	int				index;
	size_t			ret;
	int				count;
	int				point;
	char			error;
	size_t			buff_index;
	char			buffer[BUFF_SIZE + 1];
	char			*full_buff;
}					t_printf;

typedef struct		s_funct_ptr
{
	char			flag;
	int				(*ptr)(t_printf *, va_list);
}					t_funct_ptr;

t_printf			*init_flags(t_printf *flags);
t_printf			set_flags(const char *format, t_printf *flags);
t_printf			set_width(const char *format, t_printf *flags);
t_printf			set_prec(const char *format, t_printf *flags);
t_printf			set_long_length(const char *format, t_printf *flags);
t_printf			set_length(const char *format, t_printf *flags);

int					ft_printf(const char *format, ...);
int					start_parsing(const char *f, t_printf *flags, va_list ap);
int					set_args(const char *format, t_printf *flags, va_list ap);
int					arg_s(t_printf *flags, va_list ap);
int					arg_c(t_printf *flags, va_list ap);
int					arg_ws(t_printf *flags, va_list ap);
int					arg_wc(t_printf *flags, va_list ap);
int					str_null(t_printf *flags);
int					arg_d_i(t_printf *flags, va_list ap);
int					arg_o(t_printf *flags, va_list ap);
int					arg_u(t_printf *flags, va_list ap);
int					arg_x(t_printf *flags, va_list ap);
int					arg_big_x(t_printf *flags, va_list ap);
int					arg_p(t_printf *flags, va_list ap);
int					print_perc(t_printf *flags, va_list ap);
int					print_str(t_printf *flags, char *str);
int					print_char(t_printf *flags, char c);
int					print_wstr(t_printf *flags, wchar_t *ws);
int					print_wchar(t_printf *flags, wchar_t wc);
int					print_num(t_printf *flags, char *str);
int					print_zero(t_printf *flags);
int					print_zero2(t_printf *flags);
int					width_prec_print(t_printf *flags, char *str);
int					width_print(t_printf *flags);
int					prec_print(t_printf *flags, char *str);
int					ft_putbuff(t_printf *flags, char c);
int					ft_putstrbuff(t_printf *flags, char *str);
int					ft_putwstrbuff(t_printf *flags, wchar_t *ws);
int					ft_putwbuff(t_printf *flags, wchar_t wc);
int					error_managment(const char *format, t_printf *flags);
int					str_nullprec(t_printf *flags);

char				*ft_itoa_unbase(uintmax_t nb1, size_t base);
char				*ft_itoa_neg(intmax_t nb);

intmax_t			check_size_signed(intmax_t num, t_printf *flags);
uintmax_t			check_size(long long unsigned int i, t_printf *flags);

void				suffix_print(t_printf *flags);
void				sign_print(t_printf *flags);

size_t				wstrlen_prec(wchar_t *ws, size_t prec, size_t len);

#endif
