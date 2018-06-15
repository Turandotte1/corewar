#include "vm.h"

int					f_zjmp(t_act *act, t_vec *vec, int i)
{
	act->f_p = *(int *)v_get(vec, i);
	act->f_p <<= 8;
	++i;
	act->f_p += *(int *)v_get(vec, i);
	return (i + 1);
}

int					f_ldi(t_act *act, t_vec *vec, int i)
{
	int 			id;

	id = *(int *)v_get(vec, i++);
	if ((id & 0xc0) == 0x40)
		act->f_p = *(int *)v_get(vec, i++);
	else if (((id & 0xc0) == 0xc0) || ((id & 0xc0) == 0x80))
	{
		act->f_p = *(int *)v_get(vec, i++);
		act->f_p <<= 8;
		act->f_p += *(int *)v_get(vec, i++);
	}
	else
		error("Bad Action");
	if ((id & 0x30) == 0x10)
		act->f_p = *(int *)v_get(vec, i++);
	else
	{
		act->s_p = *(int *)v_get(vec, i++);
		act->s_p <<= 8;
		act->s_p += *(int *)v_get(vec, i++);
	}
	act->t_p = *(int *)v_get(vec, i);
	return (i + 1);
}

int					f_sti(t_act *act, t_vec *vec, int i)
{
	int 			id;

	id = *(int *)v_get(vec, i++);
	act->f_p = *(int *)v_get(vec, i++);
	if ((id & 0x30) == 0x10)
		act->s_p = *(int *)v_get(vec, i++);
	else if ((id & 0x30) == 0x30 || (id & 0x30) == 0x20)
	{
		act->s_p = *(int *)v_get(vec, i++);
		act->s_p <<= 8;
		act->s_p += *(int *)v_get(vec, i++);
	}
	else
		error("Bad Action");
	if ((id & 0xC) == 0xC || (id & 0xC) == 0x8)
	{
		act->t_p = *(int *)v_get(vec, i++);
		act->t_p <<= 8;
		act->t_p += *(int *)v_get(vec, i);
	}
	else if ((id & 0xC) == 0x4)
		act->t_p = *(int *)v_get(vec, i);
	else
		error("Bad Action");
	return (i + 1);
}

int					f_fork(t_act *act, t_vec *vec, int i)
{
	act->f_p = *(int *)v_get(vec, i++);
	act->f_p <<= 8;
	act->f_p += *(int *)v_get(vec, i);
	return (i + 1);
}

int					f_aff(t_act *act, t_vec *vec, int i)
{
	++i;
	act->f_p = *(int *)v_get(vec, i++);
	return (i);
}