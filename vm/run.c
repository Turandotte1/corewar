#include "vm.h"

static void				dump_memory(t_vm *vm)
{
	print_memory(vm->arena, 4096);
	exit(0);
}

static void				count_lives(t_vm *vm, size_t *hm_live, size_t *hm_die)
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
		kill_processes(vm, vm->hm_process - die_count);
	else
	{
		i = vm->hm_process;
		while (--i >= 0)
			vm->ops[i].live = 0;
	}
	i = vm->champs;
	while (--i >= 0)
		vm->champ[i].live_made = 0;
	return (live_count >= NBR_LIVE);
}

static void				showmust_go_on(t_vm *vm)
{
	t_oper 				*current;
	int					cycles;
	int					opcode;
	int					jump;

	cycles = vm->hm_process;
	while (cycles--)
	{
		current = &vm->ops[cycles];
		if (current->waiting < 0)
		{
			opcode = read_byte(current->pc) - 1;
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
		dump_memory(vm);
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
