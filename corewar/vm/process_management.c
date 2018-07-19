/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:03:22 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/18 16:44:22 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

static void					resize(t_oper *new, t_oper *old, size_t old_size)
{
	int						from;
	size_t					idx;
	size_t					i;

	i = 0;
	idx = 0;
	from = -1;
	while (i < old_size)
	{
		if (old[i].live)
		{
			old[i].live = 0;
			if (from < 0)
				from = i;
		}
		else if (from >= 0)
		{
			ft_memcpy(&new[idx], &old[from], sizeof(t_oper) * (i - from));
			idx += i - from;
			from = -1;
		}
		i++;
	}
	if (from >= 0)
		ft_memcpy(&new[idx], &old[from], sizeof(t_oper) * (i - from));
}

char						*move_players(t_oper *p, int offset)
{
	char					*pc;
	char					*mem;

	p->act = NULL;
	p->waiting = -1;
	pc = p->pc + offset;
//	ft_printf("je suis le pc avant %ld\n", p->pc - g_vm.arena);
	if ((mem = g_vm.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (mem + MEM_SIZE < pc)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	p->pc = pc;
	while (p->pc < mem)
		p->pc += MEM_SIZE;
//	ft_printf("je suis le pc %ld\n", (((pc - mem) % MEM_SIZE) + MEM_SIZE) % MEM_SIZE);
	//printf("%d\n", ft_atoi_base(pc, "F"));
	return (pc);
}

void						kill_process(size_t count)
{
	t_oper					*old;

	old = g_vm.ops;
	if (!(g_vm.ops = (t_oper *)malloc(sizeof(t_oper) * count)))
		error("malloc error");
	resize(g_vm.ops, old, g_vm.hm_process);
	g_vm.hm_process = count;
	free(old);
}

t_oper						*make_process(char *pc, t_oper *parent_p)
{
	static unsigned int		uid;
	t_oper					*new_p;
	t_oper					temp;
	int						now;

	uid = 0;
	if (parent_p)
		ft_memcpy(&temp, parent_p, sizeof(t_oper));
	g_vm.hm_process++;
	now = g_vm.hm_process;
	g_vm.ops = realloc(g_vm.ops, sizeof(t_oper) * now);
	new_p = &g_vm.ops[now - 1];
	ft_bzero(new_p, sizeof(t_oper));
	new_p->pc = pc;
	if (parent_p)
		ft_memcpy(new_p, &temp, sizeof(t_oper));
	new_p->id = uid++;
	new_p->waiting = -1;
	new_p->act = NULL;
	return (new_p);
}

t_champion					*who_is_it(int id)
{
	int						i;
	t_champion				*champ;

	i = 0;
	while (i < g_vm.champs)
	{
		champ = &g_vm.champ[i];
		if (champ->champ_id == id)
			return (champ);
		i++;
	}
	return (NULL);
}
