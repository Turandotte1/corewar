/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:20:45 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/12 17:51:58 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						aff(t_oper *p, t_params args[3])
{
	int						aff;

	aff = 0;
	analyze_info(read_info(p->r, args[0].value), (char *)&aff);
	if (!g_vm.error)
	{
		if (g_vm.v)
		{
//			g_vm.cycle.aff[0] = p->id;
//			g_vm.cycle.aff[1] = args[0].value;
//			g_vm.cycle.aff[2] = aff;
//			g_vm.cycle.aff[3] = p->carry;
		}
		else
			ft_printf("%c", aff);
	}
}
