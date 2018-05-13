/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:19:02 by mipham            #+#    #+#             */
/*   Updated: 2017/12/18 18:06:32 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include <inttypes.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include "../../libft/includes/libft.h"
typedef struct		s_arg
{
	int				force_prefix : 1;
	int				pad_zero : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				get_width : 1;
	int				get_prec : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}					t_arg;

ssize_t				ft_handle_escape(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_str(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_wstr(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_ptr(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_int(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_long(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_octal(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_unsigned(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_handle_hex(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_char(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_wchar(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_binary(char **format, va_list *args, t_arg *arg);
ssize_t				ft_handle_charswritten(char **format,
		va_list *a, t_arg *arg);
ssize_t				ft_handle_uint(uintmax_t nbr, t_arg *arg, char *b, char *p);
ssize_t				ft_nbrforceprefix(uintmax_t n, char *b, t_arg *a, char *p);
ssize_t				ft_handle_null(char **format,
		va_list *args, t_arg *arg);

uintmax_t			ft_get_unsigned_from_length(va_list *args, t_arg *arg);
intmax_t			ft_get_signed_from_length(va_list *args, t_arg *arg);
void				ft_width_pad(size_t nbrstrlen, int width, char padwith);
unsigned int		ft_nbrlen(uintmax_t nbr, char *base);
size_t				ft_calc_nbrstrlen(uintmax_t nbr, char *base, char *p,
		t_arg *arg);

char				*ft_parse_flags(char **format, t_arg *arg);
char				*ft_parse_width(char **format, va_list *list, t_arg *arg);
char				*ft_parse_precision(char **format,
		va_list *list, t_arg *arg);
char				*ft_parse_length(char **format, t_arg *arg);

typedef ssize_t		(*t_handler)(char**, va_list*, t_arg*);
t_handler			ft_get_handler(char c);

int					ft_printf(const char *format, ...);
#endif
