/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:10:45 by glegendr          #+#    #+#             */
/*   Updated: 2018/06/20 18:10:47 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void				usage(void)
{
	write(1, RED, ft_strlen(RED));
	ft_putstr_fd("Usage: ./corewar [-v | -n N | -dump N] ", 2);
	ft_putstr_fd("<champion1.cor> <...>\n", 2);
	write(1, CYAN, ft_strlen(CYAN));
	ft_putstr_fd("----------------------------flags", 2);
	ft_putstr_fd("---------------------------\n", 2);
	ft_putstr_fd("    -v		Met en place le visualisateur\n", 2);
	ft_putstr_fd("    -n N	Fixe le numero du prochain joueur\n", 2);
	ft_putstr_fd("    -dump N	Raccourcie la partie a N cycles\n", 2);
	ft_putstr_fd("---------------------------------", 2);
	ft_putstr_fd("---------------------------\n", 2);
	write(1, END, ft_strlen(END));
	exit(EXIT_FAILURE);
}

int					error(char *s)
{
	if (!ft_strcmp(s, ""))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
