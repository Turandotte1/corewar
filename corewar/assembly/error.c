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

#include "../dep/includes/asm.h"

void	close_asm(t_champ *champ, char *str)
{
	free_champ(champ);
	if (str)
		ft_error_v(2, "s", str);
	exit(0);
}

void	free_champ(t_champ *champ)
{
	free(champ->name);
	free(champ->comment);
	free_labels(champ->labels);
	free_instructs(champ->instructs);
	free(champ);
}
