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

#include "../includes/asm.h"

void	asm_error(const char *str)
{
	ft_putstr_color(str, COL_LIGHT_RED);
	exit(EXIT_FAILURE);
}

void	print_detailed_error(const char *av1)
{
	ft_putstr_color("Couldn't convert ", COL_LIGHT_RED);
	ft_putstr_color(av1, COL_LIGHT_YELLOW);
	ft_putstr_color(".\n", COL_LIGHT_RED);
}

void	free_champ(t_champ *champ)
{
	free(champ->name);
	free(champ->comment);
	free_labels(champ->labels);
	free_instructs(champ->instructs);
	free(champ);
}

void	close_asm(t_champ *champ, char *str)
{
	free_champ(champ);
	if (str)
		ft_error_v(2, "s", str);
	exit(0);
}