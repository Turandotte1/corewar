/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/04/24 16:40:37 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Minh PHAM on 4/20/18.
//

#include "../includes/asm.h"

int main(int ac, char **av)
{
	t_champ		*champ;
	char 		*content;
	int			fd;

	if(!(champ = (t_champ*)ft_memmalloc(sizeof(t_champ))))
		return (EXIT_FAILURE);
	if (ac = 2 && ft_strcmp(&av[1][ft_strlen(av[1]) - 2], ".s") == 0))
	{
		content = ft_read_file(&av[1], &fd);

	}

	return (0);
}
/*
**check les parametres
*/
