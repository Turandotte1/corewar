/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:12:11 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/12 17:12:17 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						print_arena(char *arena)
{
	int i;
	int y;

	y = 0;
	i = 0;
	ft_printf("0x0000 : ");
	while (i < 4096)
	{
		y = arena[i++] & 0xff;
		if (y < 16)
			ft_putchar('0');
		ft_printf("%x", y);
		ft_putchar(' ');
		if (i % 64 == 0 && i != 4096)
			ft_printf("\n%#.4x : ", i);
		if (i == 4096)
			ft_putchar('\n');
	}
}
