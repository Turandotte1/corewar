/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:14:56 by glegendr          #+#    #+#             */
/*   Updated: 2018/07/18 16:49:01 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						convert_endian(char *dest, char *src,
														size_t type_len)
{
	int						i;

	i = type_len - 1;
	while (i >= 0)
	{
		dest[i] = src[type_len - (i + 1)];
		i--;
	}
}

void						war_start(void)
{
	int						how_many_players;
	int						position;
	int						i;
	t_champion				*champ;

	how_many_players = g_vm.champs;
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < how_many_players)
	{
		champ = &g_vm.champ[i];
		position = champ->position;
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
			champ->champ_id, champ->head.prog_size, champ->head.prog_name,
			champ->head.comment);
		make_process(&g_vm.arena[position], NULL);
		champ->champ_id = -champ->champ_id;
//		champ->id = i;
		convert_endian((char*)&g_vm.ops[i].r[0], (char *)&champ->champ_id,
				REG_SIZE);
		i++;
	}
	players_are_ready();
}

void						del_queue(t_vec *vec, t_vec *names)
{
	int					i;

	i = 0;
	while (i < v_size(vec))
	{
		v_del((t_vec *)v_get(vec, i));
		++i;
	}
	v_del(vec);
	v_del(names);
}

void						parse_args(t_flag flags, char **argv)
{
	int						player;
	t_parsing				parsing;

	ft_bzero(&parsing, sizeof(t_parsing));
	player = flag_or_champ(argv, &flags, &parsing);
	if (player == 0 || v_size(&flags.n) != player)
		usage();
	if (player > 4)
		error("too many champions");
	g_vm.champs = player;
	into_vm(&flags, &parsing.code);
	del_queue(&parsing.queue, &parsing.names);
}

int							main(int argc, char **argv)
{
	t_flag					flag;

	if (argc == 1)
		usage();
	ft_bzero(&g_vm, sizeof(t_vm));
	ft_bzero(&flag, sizeof(t_flag));
	g_vm.champ = malloc(sizeof(t_champion) * argc - 1);
	parse_args(flag, argv);
	war_start();
	free(g_vm.arena);
	free(g_vm.ops);
	while (--g_vm.champs >= -1)
		free(g_vm.champ[g_vm.champs + 1].ch);
	free(g_vm.champ);
	return (0);
}
