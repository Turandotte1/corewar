#include "../dep/includes/vm.h"
#include "../dep/includes/viz.h"

static void				count_lives(t_vm *vm, 
										size_t *hm_live, size_t *hm_die)
{
	int					i;

	*hm_live = 0;
	*hm_die = 0;
	i = vm->hm_process;
	while (--i >= 0)
	{
		if (vm->ops[i].live)
			*hm_live += vm->ops[i].live;
		else
			(*hm_die)++;
	}
}

static int				i_am_alive(t_vm *vm)
{
	size_t				live_count;
	size_t				die_count;
	int					i;

	count_lives(vm, &live_count, &die_count);
	if (die_count > 0)
		kill_process(vm, vm->hm_process - die_count);
	else
	{
		i = vm->hm_process;
		while (--i >= 0)
			vm->ops[i].live = 0;
	}
	i = vm->champs;
	while (--i >= 0)
		vm->champ[i].cur_live = 0;
	return (live_count >= NBR_LIVE);
}

static void				showmust_go_on(t_vm *vm)
{
	t_oper				*current;
	int					cycles;
	int					opcode;
	int					jump;

	cycles = vm->hm_process;
	while (--cycles >= 0)
	{
		current = &vm->ops[cycles];
		if (current->waiting < 0)
		{
			opcode = (int)read_adress_info(vm, current->pc) - 1;
			if (opcode < OPS && opcode >= 0)
			{
				current->act = &g_tab[opcode];
				current->waiting = g_tab[opcode].cycles;
			}
		}
		if (--current->waiting <= 0)
		{
			jump = which_operation(vm, current);
			move_players(vm, &vm->ops[cycles], jump);
		}
	}
}

int						someone_is_alive(t_vm *vm)
{
	if (vm->dump > 0 && vm->hm_cycles >= vm->dump_nb)
	{
		print_memory(vm->arena, 4096);
		exit(EXIT_SUCCESS);
	}
	vm->hm_cycles++;
	showmust_go_on(vm);
	if (vm->hm_cycles >= vm->cycle.check)
	{
		vm->cycle.cur += (i_am_alive(vm)) ? MAX_CHECKS : 1;
		vm->cycle.check = vm->hm_cycles + vm->cycle.to_die;
	}
	if (vm->cycle.cur >= MAX_CHECKS)
	{
		vm->cycle.cur = 0;
		vm->cycle.to_die -= CYCLE_DELTA;
		vm->cycle.check -= CYCLE_DELTA;
	}
	return (vm->hm_process <= 0 || vm->cycle.to_die <= 0) ? 0 : 1;
}

void					players_are_ready(t_vm *vm)
{
	t_champion			*win;

	vm->cycle.to_die = CYCLE_TO_DIE;
	vm->cycle.check = CYCLE_TO_DIE;
	vm->cycle.cur = 0;
	if (vm->v)
		start_ncurse_mode(vm);
	else
	{
		while (someone_is_alive(vm))
			;
	}
	if ((win = who_is_it(vm, vm->cycle.last_live)))
		ft_printf("Contestant %i, \"%s\", has won !\n", -win->champ_id, win->head.prog_name);
	else
	{
		ft_printf("Contestant %i, \"%s\", has won !\n", -vm->champ->champ_id, vm->champ->head.prog_name);
	}
}