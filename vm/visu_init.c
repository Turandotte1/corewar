#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

static int					user_input(int key, t_windows win[3])
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
//	delete_windows(win[1].window);
//	delete_windows(win[2].window);
	endwin();
}

void						colorize_it()
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
//	memory_handler_here;
	start_game(&someone_is_alive);
}
