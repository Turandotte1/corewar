#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

/*void	mark_bytes(t_cycle_infos *infos)
{
	t_byte_infos	*byte;
	char			*pc;
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		byte = &infos->byte_infos[i];
		byte->pc = 0;
		if (g_corewar.state & (STATE_RUNNING | STATE_STEP))
		{
			byte->live -= (byte->live > 0) ? 1 : 0;
			byte->op -= (byte->op > 0) ? 1 : 0;
		}
		i++;
	}
	i = g_corewar.process_count;
	while (--i >= 0)
	{
		pc = g_corewar.process[i].pc;
		if (pc >= infos->arena + MEM_SIZE)
			infos->byte_infos[0].pc |= 1;
		else
			infos->byte_infos[pc - infos->arena].pc |= 1;
	}
}

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
void					wprint_buf(WINDOW *win, t_coord *position, t_coord *max, char *buf)
{
	if (position->y < max->y)
	{
		wmove(win, position->y, position->x);
		waddnstr(win, buf, max->x);
	}
	position->y += 1;
}

static void				print_commands(WINDOW *win, t_coord *position, t_coord *max)
{
	char				buf[64];

	position->y++;
//	ft_snprintf(buf, 64,  "[n/s]    Next step");
	wprint_buf(win, position, max, buf);
//	ft_snprintf(buf, 64, "[SPACE]  Pause / Run");
	wprint_buf(win, position, max, buf);
//	ft_snprintf(buf, 64, "[ENTER]  End the game");
	wprint_buf(win, position, max, buf);
}

void					help_create(t_windows *win)
{
//	char				buf[64];
	t_coord				max;
	t_coord				position;

	position.y = 2;
	position.x = 3;
	max.y = win->len.y - 2;
	wattron(win->window, A_BOLD);
	printw("DO U NEED SOME HELP");
//	ft_snprintf(buf, 64, "DO U NEED SOME HELP");
	max.x = win->len.x - 5;
//	wprint_buf(win->window, &position, &max, buf);
	print_commands(win->window, &position, &max);
	wattroff(win->window, A_BOLD);
}

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

void				draw_win(t_windows win[3])
{
//	mark_bytes(&g_corewar.cycle_infos);
	arena_print(&win[0]);
	wrefresh(win[0].window);
//	info_print(&panels[1]);
//	wrefresh(win[1].window);
	help_create(&win[2]);
	wrefresh(win[2].window);
//	if (!(g_corewar.state & STATE_RUNNING))
//		g_corewar.state = STATE_PAUSED;
}
