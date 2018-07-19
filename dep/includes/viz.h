/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:02:33 by mipham            #+#    #+#             */
/*   Updated: 2018/07/18 16:42:48 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZ_H
# define VIZ_H

# include "vm.h"

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_windows
{
	WINDOW				*window;
	t_coord				len;
}						t_windows;

/*
**---------------------------init and game start--------------------------------
*/

void					start_ncurse_mode();
void					start_game(int (*someone_is_alive)(void));
void					windows_init(t_windows win[2]);

/*
**---------------------------drawing functions----------------------------------
*/

void					draw_win(t_windows win[2]);
void					arena_print(t_windows win[2]);

#endif
