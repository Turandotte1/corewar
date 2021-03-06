/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:06:42 by mipham            #+#    #+#             */
/*   Updated: 2018/07/18 15:01:46 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "ft_prtl.h"

# define SUCCESS 1
# define ERROR -1

# define BUFF_SIZE 1000
# define FD_MAX 10240
# define BUFF_SIZE_2_16 65536

# define COL_RESET				"\033[0m"
# define COL_UNDERLINED			"\033[4m"
# define COL_REVERSE			"\033[7m"
# define COL_BLACK				"\033[22;30m"
# define COL_RED				"\033[22;31m"
# define COL_GREEN				"\033[22;32m"
# define COL_YELLOW				"\033[22;33m"
# define COL_BLUE				"\033[22;34m"
# define COL_MAGENTA			"\033[22;35m"
# define COL_CYAN				"\033[22;36m"
# define COL_WHITE				"\033[1;37m"
# define COL_GRAY				"\033[1;30m"
# define COL_LIGHT_GRAY			"\033[22;37m"
# define COL_LIGHT_RED			"\033[1;31m"
# define COL_LIGHT_GREEN		"\033[1;32m"
# define COL_LIGHT_YELLOW		"\033[1;33m"
# define COL_LIGHT_BLUE			"\033[1;34m"
# define COL_LIGHT_MAGENTA		"\033[1;35m"
# define COL_LIGHT_CYAN			"\033[1;36m"
# define COL_BACK_RED			"\033[41m"
# define COL_BACK_GREEN			"\033[42m"
# define COL_BACK_YELLOW		"\033[43m"
# define COL_BACK_BLUE			"\033[44m"
# define COL_BACK_MAGENTA		"\033[45m"
# define COL_BACK_CYAN			"\033[46m"

# define FI_ 	__FILE__
# define FU_ 	__FUNCTION__
# define LI_ 	__LINE__
# define ER 		errno
# define FFL 		FI_, FU_, LI_

# define FAIL 0
# define SUCCESS 1

# define E_MLC		"Could not allocate memory for : "
# define E_OPF		"Could not open file : "
# define E_RDF		"Could not read file or file is empty : "
# define MDI		"more details in : "

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_gnl
{
	char			*str;
	int				fd;
	int				r_stt;
	struct s_gnl	*next;
}					t_gnl;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_create_elem(void *data);
t_list				*fd_select(t_list **list, int fd);

void				*ft_memcpy(void *restrict s1, const void *restrict s2,
		size_t n);
void				*ft_memcpy_rev(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *restrict d, const void *restrict s,
		int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void(*del) (void*, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void				ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd);
void				ft_putnbrbase(uintmax_t nbr, char *base);
void				ft_putnstr_fd(char const *str, size_t len, int fd);
void				ft_putnstr(char const *str, size_t str_len);
void				ft_putnwstr(const wchar_t *str, size_t len);
void				ft_putwchar(wchar_t chr);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putbuf_fd_np(int fd, char *src, char *dst, int *i);
void				ft_putbuf_fd_loop_char_np(int fd_n_x, char c,
			char *dst, int *i);
void				ft_strrev(char *s);
void				ft_sort_integer_table(int *tab, int size);
void				ft_putstr_color(char const *s, const char *color);
void				ft_putstr_color_fd(char const *s, const char *color,
		int fd);
void				ft_color_switch_fd(const char *color, int fd);
void				ft_color_reset_fd(int fd);

char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strcat(char *restrict dest, const char *restrict src);
char				*ft_strncat(char *restrict dest, const char *restrict src,
		size_t n);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find,
		size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(const char *s, char c);
char				**ft_split_whitespaces(char *s);

char				*ft_itoa(int nbr);
char				*ft_utoa(unsigned int nbr, char const *s);
char				*ft_scitoa(double nb, char pre);
char				*ft_ldtoa(long int n);
char				*ft_lutoa(size_t n);

char				*ft_strtrim(char const *s);
char				*ft_strtrim_front(char *s);
char				*ft_strtrim_back(char *s);
char				*ft_strtrim_both(char *s);

char				*ft_strndup(const char *s, size_t n);
char				*gnl_read(char **buff, int fd, char *str);
char				*ft_get_line(char *s, int *i);
char				*ft_cut_first_line(char *str);
char				*ft_point_to_next_line(char *str);
char				*ft_skip_whitespace(char *str);
char				*ft_strjoin_np(char *s1, char *s2);

char				ft_rm(char *path);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_base(char *str, char *base);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_is_prime(int nb);
int					ft_sqrt(int nb);
int					ft_power(int a, int power);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isspace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_max(int x, int y);
int					ft_min(int x, int y);
int					get_next_line(const int fd, char **line);
int					ft_is_sorted(int *tab, int size);
int					ft_haschar(const char *s, int c);
int					*ft_tabnew(size_t size);
int					ft_str_is_digits(char *str);
int					ft_strchr_i(char *s, char c);

int					ft_error_d(int fd, const char *s, ...);
char				ft_error_c(int fd, const char *s, ...);
void				*ft_error_n(int fd, const char *s, ...);
void				ft_error_v(int fd, const char *s, ...);

char				*ft_check_file(char *s, int *len);
size_t				ft_strlcat(char *restrict dest, const char *restrict src,
		size_t len);
size_t				ft_strlen_skip_white(const char *s);
size_t				ft_strlen(const char *s);
size_t				ft_nstrlen(const char *str, size_t maxlen);

unsigned long long	ft_atou(const char *str);
long long			ft_atoll(const char *str);

#endif
