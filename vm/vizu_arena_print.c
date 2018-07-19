#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

/*
static void				print_byte(WINDOW *win, t_byte_infos *byte, int player_id, int val)
{
	if (byte->pc)
		wattron(win, A_STANDOUT);
	if (byte->live)
		wattron(win, COLOR_PAIR(player_id + 4));
	if (byte->op || byte->live)
		wattron(win, A_BOLD);
	wprintw(win, "%.2x", val);
	if (byte->op || byte->live)
		wattroff(win, A_BOLD);
	if (byte->live)
		wattroff(win, COLOR_PAIR(player_id + 4));
	if (byte->pc)
		wattroff(win, A_STANDOUT);
}

static void				print_line(WINDOW *win, int width, const char *memory,
										const t_byte_infos *bytemap)
{
	t_byte_infos	*byte;
	int				player_id;
	int				offset;
	int				i;

	i = 0;
	offset = 2;
	while (i < BYTES_PER_LINE)
	{
		offset += 3;
		if (offset > width)
		{
			wprintw(win, "..");
			break ;
		}
		byte = (t_byte_infos *)&bytemap[i];
		if (!(player_id = byte->number))
			player_id = PAIR_GREY;
		wattron(win, COLOR_PAIR(player_id));
		print_byte(win, byte, player_id, memory[i] & 0xff);
		wattroff(win, COLOR_PAIR(player_id));
		waddch(win, ' ');
		i++;
	}
}*/

void					arena_print(t_windows win[3])
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
		g_vm.error = 0;
	//	print_line(win->window, window->len.x - 5,
//						&g_vm.arena[offset], &g_vm.cycle[offset]);
		i++;
	}
}