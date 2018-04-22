/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/04/20 17:07:16 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Minh PHAM on 4/20/18.
//

#include "../includes/asm.h"

int main(int ac, char **av)
{
	t_champ		*champ;


	if(!(champ = (t_champ*)ft_memmalloc(sizeof(t_champ))))
		return (EXIT_FAILURE);

	return (0);
}
/*
**check les parametres
*/
