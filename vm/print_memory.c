/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:56:02 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/12 18:00:38 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						ft_printhex(int n)
{
	int c;

	if (n >= 16)
		ft_printhex(n / 16);
	c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	ft_putchar(c);
}

void						ft_printchars(unsigned char c)
{
	ft_putchar((c > 31 && c < 127) ? c : '.');
}

void						print_memory(const void *addr, size_t size)
{
	unsigned char 			*t;
	size_t					i;
	int						col;
	size_t					tmp;

	t = (unsigned char *)addr;
	i = 0;
	tmp = 0;
	while (i < size)
	{
		col = -1;
		tmp = i;
		while (++col < 16)
		{
			if (i < size)
			{
				if (t[i] < 16)
					ft_putchar('0');
				ft_printhex(t[i]);
			}
			else
				ft_putstr("  ");
			ft_putchar((i++ & 1) << 6);
		}
		col = -1;
		i = tmp;
		while (++col < 16 && i < size)
			ft_printchars(t[i++]);
		ft_putchar('\n');
	}
}
