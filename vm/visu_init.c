/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:36:44 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 18:37:46 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

static int					user_input(int key, t_windows win[2])
{
	if (key == 'n')
		g_vm.vizu = NEXT;
	if (key == '+')
		wtimeout(win[1].window, ++g_vm.cycle.fast);
	else if (key == '-')
		wtimeout(win[1].window, --g_vm.cycle.fast);
	else if (key == ' ')
		g_vm.vizu ^= RUN;
	return ((key == '\n') ? 0 : 1);
}

void						start_game(int (someone_is_alive)())
{
	t_windows				win[2];

	windows_init(win);
	while (user_input(wgetch(win[1].window), win))
	{
		if (g_vm.vizu & (RUN | NEXT))
		{
			if (someone_is_alive() <= 0)
			{
				g_vm.vizu = FINISH;
				timeout(-1);
				break ;
			}
		}
		draw_win(win);
	}
	endwin();
}

void						colorize_it(void)
{
	start_color();
	init_pair(1, 89, COLOR_BLACK);
	init_pair(2, 117, COLOR_BLACK);
	init_pair(3, 141, COLOR_BLACK);
	init_pair(4, 161, COLOR_BLACK);
	init_pair(5, 245, 245);
	init_pair(6, 245, COLOR_BLACK);
}

void						start_ncurse_mode(void)
{
	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);
	colorize_it();
	start_game(&someone_is_alive);
}
