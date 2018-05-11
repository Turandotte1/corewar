//
// Created by Minh PHAM on 5/10/18.
//

#include "includes/ft_prtl.h"


int		ft_pars_argm(t_pm_env *e, int i, const char *s)
{
	int j;

	j = 0;
	while (j < NB_ARG)
	{
		if (e->tab[j].flag == s[i])
		{
			return ((*(e->tab[j].pt))(e, i));
		}
		++j;
	}
	prtl_error(e, 0);
	return (-1);
}

/*
**	ft_prtl 	->	ft_prtl/ft_prtl.c
**		write dans un fd une liste de variable suivant un format contenu dans s
**		S -> ptrm en cours de dévelopement
**		s -> char*
**		f -> double
**		d -> int
**		l -> long int
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
**		C + r,g,y,b,m,c,w,1,0 -> couleur
*/

void	ft_prtl(const char *s, va_list *ap, int fd)
{
	static t_ptfm		tab[NB_ARG] = {NULL, '\0'};
	int					i;
	t_pm_env			e;

	if (s && ap)
	{
		e.tab = tab;
		e.fd = fd;
		e.ap = ap;
		e.s = s;
		if (tab[0].pt == NULL)
			ft_init_tabm(&e);
		i = 0;
		while (s[i])
		{
			i = ft_pars_argm(&e, i, s);
			if (i == -1)
			{
				write(2, "format faux!\nft_prtl.c ou lib_ft_prtl.h\n", 44);
				return ;
			}
		}
	}
}