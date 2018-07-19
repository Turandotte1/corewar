/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu_arena_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:38:25 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 18:39:56 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

static void				print_byte(WINDOW *win, t_binary *byte, int id, int val)
{
	id = 0;
	if (byte->pc)
		wattron(win, A_STANDOUT);
	if (byte->live)
		wattron(win, COLOR_PAIR(2));
	if (byte->op || byte->live)
		wattron(win, A_BOLD);
	wprintw(win, "%.2x", val);
	if (byte->op || byte->live)
		wattroff(win, A_BOLD);
	if (byte->live)
		wattroff(win, COLOR_PAIR(2));
	if (byte->pc)
		wattroff(win, A_STANDOUT);
}

static void				print_line(WINDOW *win, int width, const char *memory,
										const t_binary *bytemap)
{
	t_binary			*byte;
	int					id;
	int					jump;
	int					i;

	i = 0;
	jump = 2;
	while (i < 64)
	{
		jump += 3;
		if (jump > width)
		{
			wprintw(win, "..");
			break ;
		}
		byte = (t_binary *)&bytemap[i];
		if (!(id = byte->id))
			id = 4;
		wattron(win, COLOR_PAIR(id));
		print_byte(win, byte, id, memory[i] & 0xff);
		wattroff(win, COLOR_PAIR(id));
		waddch(win, ' ');
		i++;
	}
}

void					arena_print(t_windows win[2])
{
	int					i;
	int					height;
	int					offset;

	i = 0;
	height = MEM_SIZE / 64;
	if (height > win->len.y - 4)
	{
		height = win->len.y - 5;
		wmove(win->window, win->len.y - 3, 2);
		waddnstr(win->window,
			"window is small, you cannot see all the magic", win->len.x - 4);
	}
	while (i < height)
	{
		offset = i * 64;
		wmove(win->window, i + 2, 3);
		print_line(win->window, win->len.x - 5,
						&g_vm.arena[offset], &g_vm.cycle.byte[offset]);
		i++;
	}
}
