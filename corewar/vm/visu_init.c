#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

static int					user_input(int key, t_windows win[3])
{
//	if (key == 'n' || key == 's')
//		g_vm.visu = ACCELERATE;
	if (key == '+')
		wtimeout(win[1].window, ++g_vm.cycle.fast);
//	else if (input == '-')
//		wtimeout(panels[1].win, --g_corewar.cycle_infos.speed);
	else if (key == ' ')
		g_vm.vizu ^= RUN;
//	else if (input == KEY_RESIZE)
//		panels_resize(panels);
	return ((key == '\n') ? 0 : 1);
}


void						start_game(int (someone_is_alive)())
{
	t_windows				win[3];

	windows_init(win);
	someone_is_alive();
	sleep(1);
	while (user_input(wgetch(win[1].window), win))
	{
//		if (g_corewar.state & (STATE_RUNNING | STATE_STEP))
//		{
//			if (cycle_fn(&g_corewar.cycle_infos) <= 0)
//			{
//				g_corewar.state = STATE_DONE;
//				g_corewar.flags &= ~FLAG_FULL;
//				panels_resize(panels);
//				timeout(-1);
//				while (getch() == KEY_RESIZE)
//					panels_resize(panels);
//				break ;
//			}
//		}
//		draw(panels, &g_corewar.cycle_infos);
	}
//	delete_win(panels[0].win);
//	delete_win(panels[1].win);
//	delete_win(panels[2].win);
	endwin();
}

void						colorize_it()
{
	start_color();
	init_pair(1, 89, COLOR_BLACK); //player 1
	init_pair(2, 117, COLOR_BLACK); //player 2
	init_pair(3, 141, COLOR_BLACK); //player 3
	init_pair(4, 161, COLOR_BLACK);//player 4
	init_pair(5, 245, 245); //frame
	init_pair(6, 245, COLOR_BLACK); //main color
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
