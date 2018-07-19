/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:20:45 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 16:18:28 by mrychkov         ###   ########.fr       */
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
		if (!g_vm.v)
		{
		}
		else
			ft_printf("%c", aff);
	}
}
