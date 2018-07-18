#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

/*static void	print_aff(WINDOW *win, t_vec2 *pos, t_vec2 *max, char buf[64])
{
	int		*aff;

	pos->x = 3;
	pos->y++;
	aff = g_corewar.cycle_infos.aff;
	ft_snprintf(buf, 64, STR_AFF);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_AFF_L1, aff[0]);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_AFF_L2, aff[1], ((char *)&aff[2])[3] & 0xff,
											((char *)&aff[2])[2] & 0xff,
											((char *)&aff[2])[1] & 0xff,
											((char *)&aff[2])[0] & 0xff);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_AFF_L3);
	wprint_buf(win, pos, max, buf);
	if (pos->y - 1 < max->y && (int)ft_strlen(buf) < max->x)
	{
		wattroff(win, A_BOLD);
		wattron(win, COLOR_PAIR((aff[3]) ? 1 : 2) | A_STANDOUT);
		waddnstr(win, (aff[3]) ? STR_TRUE : STR_FALSE, max->x - 11);
		wattroff(win, COLOR_PAIR((aff[3]) ? 1 : 2) | A_STANDOUT);
		wattron(win, A_BOLD);
	}
}



static void	print_infos(WINDOW *win, t_vec2 *pos, t_vec2 *max, char buf[64])
{
	t_cycle_infos	*infos;

	infos = &g_corewar.cycle_infos;
	pos->x = 3;
	pos->y++;
	ft_snprintf(buf, 64, STR_CYCLE_TO_DIE, infos->cycle_to_die);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_CYCLE_DELTA, CYCLE_DELTA);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_NBR_LIVE, NBR_LIVE);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_MAX_CHECKS, MAX_CHECKS);
	wprint_buf(win, pos, max, buf);
	pos->y++;
	ft_snprintf(buf, 64, STR_CYCLE, infos->count);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_CYCLE_DURATION, infos->speed);
	wprint_buf(win, pos, max, buf);
	pos->y++;
	ft_snprintf(buf, 64, STR_PROCESS_COUNT, g_corewar.process_count);
	wprint_buf(win, pos, max, buf);
}

static void	print_players(WINDOW *win, t_vec2 *pos, t_vec2 *max, char buf[64])
{
	t_player	*player;
	int			i;

	i = g_corewar.player_count;
	while (--i >= 0)
	{
		player = &g_corewar.players[i];
		ft_snprintf(buf, 64, STR_PLAYER_NAME, player->number);
		wprint_buf(win, pos, max, buf);
		if (pos->y - 1 < max->y && (int)ft_strlen(buf) < max->x)
		{
			wattron(win, COLOR_PAIR(player->id));
			waddnstr(win, player->name, max->x - 11);
			wattroff(win, COLOR_PAIR(player->id));
		}
		ft_snprintf(buf, 64, STR_PLAYER_LAST_LIVE, player->last_live);
		pos->x = 5;
		max->x -= 2;
		wprint_buf(win, pos, max, buf);
		ft_snprintf(buf, 64, STR_PLAYER_LIVE_COUNT, player->current_lives);
		wprint_buf(win, pos, max, buf);
		max->x += 2;
		pos->y++;
	}
}

static void	print_winner(WINDOW *win, t_vec2 *pos, t_vec2 *max, char buf[64])
{
	t_player	*winner;

	if (!(winner = find_player(g_corewar.cycle_infos.last_live)))
		return ;
	pos->x = 3;
	pos->y += 2;
	ft_snprintf(buf, 64, STR_WINNER);
	wprint_buf(win, pos, max, buf);
	if (pos->y - 1 < max->y && (int)ft_strlen(buf) < max->x)
	{
		wattron(win, COLOR_PAIR(winner->id));
		waddnstr(win, winner->name, max->x - 14);
		wattroff(win, COLOR_PAIR(winner->id));
	}
	ft_snprintf(buf, 64, STR_PRESS_ANY);
	wprint_buf(win, pos, max, buf);
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

void					info_print(t_windows win[3], t_vm *vm)
{
	char				buf[64];
	t_coord				max;
	t_coord				pos;

	pos.y = 2;
	pos.x = 3;
	max.y = win->len.y - 2;
	max.x = win->len.x;
	wattron(win->window, A_BOLD);
	snprintf(buf, 64,
			(vm->vizu & RUN) ? 
			"VM IS RUNNING" : 
			"VM IS PAUSED");
	max.x = win->len.x - 5;
	wprint_buf(win->window, &pos, &max, buf);
	max.x = win->len.x - 7;
//	print_infos(panel->win, &pos, &max, buf);
//	max.x = panel->size.x - 5;
//	pos.x = 3;
//	pos.y += 2;
//	print_players(panel->win, &pos, &max, buf);
//	if (!(g_corewar.flags & FLAG_HIDE))
//		print_aff(panel->win, &pos, &max, buf);
//	if (g_corewar.state == STATE_DONE)
//		print_winner(panel->win, &pos, &max, buf);
	wattroff(win->window, A_BOLD);
}