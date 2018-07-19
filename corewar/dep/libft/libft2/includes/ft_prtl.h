/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:55:48 by mipham            #+#    #+#             */
/*   Updated: 2018/07/18 14:55:52 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRTL_H
# define FT_PRTL_H

# include <stdarg.h>
# include "libft.h"

# define NB_ARG	17

struct s_pm_env;

typedef struct			s_ptfm
{
	int					(*pt)(struct s_pm_env*, int);
	char				flag;
}						t_ptfm;

typedef struct			s_pm_env
{
	va_list				*ap;
	int					fd;
	t_ptfm				*tab;
	const char			*s;
}						t_pm_env;

/*
**	convertion correspondant aux flags citée en haut
*/
int						prtl_s(t_pm_env *e, int i);
int						prtl_f(t_pm_env *e, int i);
int						prtl_d(t_pm_env *e, int i);
int						prtl_u(t_pm_env *e, int i);
int						prtl_ee(t_pm_env *e, int i);
int						prtl_c(t_pm_env *e, int i);
int						prtl_n(t_pm_env *e, int i);
int						prtl_0(t_pm_env *e, int i);
int						prtl_rr(t_pm_env *e, int i);
int						prtl_ff(t_pm_env *e, int i);
int						prtl_ll(t_pm_env *e, int i);
int						prtl_cc(t_pm_env *e, int i);
int						prtl_i(t_pm_env *e, int i);
int						prtl_ss(t_pm_env *e, int i);
int						prtl_error(t_pm_env *e, int i);
int						prtl_tt(t_pm_env *e, int i);
int						prtl_l(t_pm_env *e, int i);

/*
**	créer un tableau de pointeur sur les fonction ci dessus
*/
void					ft_init_tabm(t_pm_env *e);

/*
**	ft_prtl 	->	ft_prtl/ft_prtl.c
**		write dans un fd une liste de variable suivant un format contenu dans s
**		S -> ptrm en cours de dévelopement
**		s -> char*
**		f -> double
**		d -> long int
**		u -> size_t
**		c -> char
**		E -> errno
**		n -> \n
**		t -> \t
**		0 -> exit
**		R -> __FILE__
**		F -> __FUNCTION__
**		L -> __LINE__
**		i -> écrit Error !!! : en rouge plus du texte
**		C + r,g,y,b,m,c,w,0 -> couleur
*/
void					ft_prtl(const char *s, va_list *ap, int fd);

#endif
