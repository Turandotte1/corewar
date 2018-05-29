/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:14:56 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/27 19:26:24 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int						main(int argc, char **argv)
{
	t_vm				vm;

	if (argc == 1)
		usage();
	ft_bzero(&vm, sizeof(t_vm));
	parse_it(&vm, argc, argv);
	run_it(&vm);
	//on n'oublie de rien free !!
	return (0);
}