//
// Created by Minh PHAM on 5/13/18.
//

#include "includes/ft_prtl.h"

static void	ft_init_tabm2(t_pm_env *e)
{
	e->tab[11].pt = &prtl_ss;
	e->tab[11].flag = 'S';
	e->tab[12].pt = &prtl_cc;
	e->tab[12].flag = 'C';
	e->tab[13].pt = &prtl_i;
	e->tab[13].flag = 'i';
	e->tab[14].pt = &prtl_tt;
	e->tab[14].flag = 't';
	e->tab[15].pt = &prtl_l;
	e->tab[15].flag = 'l';
	e->tab[NB_ARG - 1].pt = &prtl_error;
	e->tab[NB_ARG - 1].flag = 0;
}

void		ft_init_tabm(t_pm_env *e)
{
	ft_bzero(e->tab, sizeof(t_ptfm) * NB_ARG);
	e->tab[0].pt = &prtl_s;
	e->tab[0].flag = 's';
	e->tab[1].pt = &prtl_f;
	e->tab[1].flag = 'f';
	e->tab[2].pt = &prtl_d;
	e->tab[2].flag = 'd';
	e->tab[3].pt = &prtl_u;
	e->tab[3].flag = 'u';
	e->tab[4].pt = &prtl_c;
	e->tab[4].flag = 'c';
	e->tab[5].pt = &prtl_ee;
	e->tab[5].flag = 'E';
	e->tab[6].pt = &prtl_n;
	e->tab[6].flag = 'n';
	e->tab[7].pt = &prtl_0;
	e->tab[7].flag = '0';
	e->tab[8].pt = &prtl_rr;
	e->tab[8].flag = 'R';
	e->tab[9].pt = &prtl_ff;
	e->tab[9].flag = 'F';
	e->tab[10].pt = &prtl_ll;
	e->tab[10].flag = 'L';
	ft_init_tabm2(e);
}