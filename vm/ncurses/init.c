#include "bonus.h"

void						colorize_it()
{
	start_color();
	init_pair(1, 89, COLOR_BLACK); //player 1
	init_pair(2, 117, COLOR_BLACK); //player 2
	init_pair(3, 141, COLOR_BLACK); //player 3
	init_pair(4, , COLOR_BLACK);//player 4
	init_pair(5, 245, 245); //frame
	init_pair(6, 245, COLOR_BLACK); //fond
}

static int	get_input(int input, t_panel panels[3])
{
	if (input == 'n' || input == 's')
		g_corewar.state = STATE_STEP;
	else if (input == '+')
		wtimeout(panels[1].win, ++g_corewar.cycle_infos.speed);
	else if (input == '-')
		wtimeout(panels[1].win, --g_corewar.cycle_infos.speed);
	else if (input == ' ')
		g_corewar.state ^= STATE_RUNNING;
	else if (input == 'f')
	{
		g_corewar.flags ^= FLAG_FULL;
		panels_resize(panels);
	}
	else if (input == 'h')
	{
		g_corewar.flags ^= FLAG_HELP;
		panels_resize(panels);
	}
	else if (input == KEY_RESIZE)
		panels_resize(panels);
	else if (input == '\n')
		return (0);
	return (1);
}

void		start_game(int (*cycle)(t_cycle_infos *))
{
	t_panel	panels[3];

	panels_init(panels);
	while (get_input(wgetch(panels[1].win), panels))
	{
		if (g_corewar.state & (STATE_RUNNING | STATE_STEP))
		{
			if (cycle_fn(&g_corewar.cycle_infos) <= 0)
			{
				g_corewar.state = STATE_DONE;
				g_corewar.flags &= ~FLAG_FULL;
				panels_resize(panels);
				timeout(-1);
				while (getch() == KEY_RESIZE)
					panels_resize(panels);
				break ;
			}
		}
		draw(panels, &g_corewar.cycle_infos);
	}
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	window_destroy(panels[2].win);
	endwin();
}

void						start_ncurse_mode(t_vm *vm)
{
			initscr();
			cbreak();
			raw();
			noecho();
			curs_set(0);
			colorize_it();
			//	load_players(vm->);
			//	start_game();
}