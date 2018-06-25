#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

static void			help_win_create(t_windows *win, t_coord len)
{
	t_coord			position;

	position.y = len.y - 12;
	position.x = len.x - (len.x * 0.2) - 1;
	len.y = 12;
	if (len.y > LINES)
		len.y = LINES;
	len.y = 0;
	len.x = 0;
	position.x = 0;
	position.y = 0;
	win->len.y = len.y;
	win->len.x = len.x;
	win->window = newwin(len.y, len.x, position.y, position.x);
	wattron(win->window, COLOR_PAIR(5));
	wborder(win->window, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(win->window, COLOR_PAIR(5));
}

static void			info_win_create(t_windows *win, t_coord len)
{
	t_coord			position;

	position.y = 0;
	position.x = len.x - (len.x * 0.2) - 1;
//	len.y -= PANEL_HELP_HEIGHT - 1;
	if (len.y < 0)
		len.y = 0;
	len.y = 0;
	len.x = 0;
	position.x = 0;
	position.y = 0;
	win->len.y = len.y;
	win->len.x = len.x;
	win->window = newwin(len.y, len.x, position.y, position.x);
	wattron(win->window, COLOR_PAIR(5));
	wborder(win->window, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(win->window, COLOR_PAIR(5));
//	wtimeout(panel->win, g_corewar.cycle_infos.speed);
}

static void			arena_win_create(t_windows *win, t_coord len)
{
	t_coord			position;

	position.y = 0;
	position.x = 0;
	win->len.y = len.y;
	win->len.x = len.x;
	win->window = newwin(len.y, len.x, position.y, position.x);
	wattron(win->window, COLOR_PAIR(5));
	wborder(win->window, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(win->window, COLOR_PAIR(5));
}

void				windows_init(t_windows win[3], t_vm *vm)
{
	t_coord			len;

	getmaxyx(stdscr, len.y, len.x);
	arena_win_create(&win[0], len);
	info_win_create(&win[1], len);
	help_win_create(&win[2], len);
	refresh();
	draw_win(win, vm);
}