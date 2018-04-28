/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:05:11 by mipham            #+#    #+#             */
/*   Updated: 2018/04/23 12:05:36 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by pelluro on 23/04/18.
//

#include "../includes/asm.h"
/*
**ft_error a coder avec la sortie d'erreur
*/

void	asm_error(const char *str)
{
	ft_putstr_color(str, COL_LIGHT_RED);
	exit(EXIT_FAILURE);
}

void	print_detailed_error(t_champ *champ, const char *av1)
{
	(void)champ;
	ft_putstr("Couldn't convert ", COL_LIGHT_RED);
	ft_putstr_color(av1, COL_LIGHT_YELLOW);
	ft_putstr_color(".\n", COL_LIGHT_RED);
}

void	close_asm(t_champ *champ, char *s)
{
	free_champ(champ);
	if (s)
		asm_error(s);
}

void	free_champ(t_champ *champ)
{
	free(champ->name);
	free(champ->comment);

}
