#include "vm.h"

char					read_byte(char *addr)
{
	int					overflow;

	if ((overflow = addr - (addr + MEM_SIZE)) >= 0)
		return (addr[overflow]);
//	printf("ADDR = %c\n", *addr);
	return (*addr);
}

t_oper				*make_process(t_vm *vm, char *pc)
{
	t_oper			*new_process;
	int 			now;

	vm->hm_process++;
	now = vm->hm_process;
	vm->ops = realloc(vm->ops, sizeof(t_oper) * now);
	new_process = &vm->ops[now - 1];
	ft_bzero(new_process, sizeof(t_oper));
	new_process->waiting = -1;
	new_process->act = 0;
	new_process->pc = pc;
	printf("%s\n", new_process->pc);
	printf("%d\n", new_process->waiting);
	return (new_process);
}

static void						get_type_of_arg(t_params *arg, char ocp, int opcode)
{
	if (ocp == REG_CODE)
	{
		arg->type = T_REG;
		arg->size = 1;
	}
	else if (ocp == IND_CODE)
	{
		arg->type = T_IND;
		arg->size = IND_SIZE;
	}
	else if (ocp == DIR_CODE)
	{
		arg->type = T_DIR;
		if (g_tab[opcode].dir_short)
			arg->size = IND_SIZE;
		else
			arg->size = DIR_SIZE;
	}
}

static size_t					check_args(t_params args[3], char ocp, int opcode, int count)
{
	if (!g_tab[opcode].ocp)
	{
		if (g_tab[opcode].dir_short)
		{
			args[0].size = IND_SIZE;
			args[0].type = T_IND;
		}
		else
		{
			args[0].size = DIR_SIZE;
			args[0].type = T_DIR;
		}
		return (1);
	}
	args[1].type = 0;
	args[1].size = 0;
	args[2].type = 0;
	args[2].size = 0;
	get_type_of_arg(&args[0], (ocp & 0b11000000) >> 6, opcode);
	if (count > 1)
		get_type_of_arg(&args[1], (ocp & 0b00110000) >> 4, opcode);
	if (count > 2)
		get_type_of_arg(&args[2], (ocp & 0b00001100) >> 2, opcode);
	return (2);
}

static void						get_arguments(char *pc, t_params args[3], int args_count)
{
	char						*value_ptr;
	int							offset;
	int							size;
	int							i;
	int							j;

	i = 0;
	offset = 0;
	while (i < args_count)
	{
		j = 0;
		size = args[i].size;
		value_ptr = (char *)&args[i].value;
		while (j < size)
		{
			value_ptr[size - (j + 1)] = read_byte(pc + offset + j);
			j++;
		}
		offset += args[i].size;
		i++;
	}
}

size_t							get_argument_op(t_oper *proc, int opcode, t_params args[3])
{
	size_t						offset;
	int							args_count;
	int							args_sizes;

	ft_bzero(args, sizeof(t_params) * 3);
	args_count = g_tab[opcode - 1].hm_params;
	offset = check_args(args, read_byte(proc->pc + 1), opcode - 1, args_count);
	args_sizes = args[0].size + args[1].size + args[2].size;
	if (args_sizes > 0)
		get_arguments((char *)&proc->pc[offset], args, args_count);
	return (offset + args_sizes);
}

static int				check_ocp(t_oper *p, t_params args[3])
{
	int		i;

	i = 0;
	while (i < p->act->hm_params)
	{
		if (!(args[i].type & p->act->args_types[i]))
			return (0);
		i++;
	}
	return (1);
}

static int				do_op(void (*op_fn)(t_oper *, t_params[3]), t_oper *p)
{
	t_params			args[3];
	int					offset;

	p->waiting = -1;
//	g_corewar.reg_error = 0;
	offset = get_argument_op(p, p->act->val, args);
	printf("%d\n", offset);
	(void)(op_fn);
	if (op_fn == &zjmp)
	{
		op_fn(p, args);
		return (0);
	}
	if (!p->act->ocp || check_ocp(p, args))
		op_fn(p, args);
	return (offset);
}



int						process_op(t_oper *p)
{
	static void	(*opcode_fns[OP_COUNT])(t_oper *, t_params[3]) = {
		&live,
		&ld,
		&st,
		&add,
		&sub,
		&and,
		&or,
		&xor,
		&zjmp,
		&ldi,
		&sti,
		&fork_o,
		&lld,
		&lldi,
		&lfork,
		&aff,
	};
	return (p->act == NULL ? 1 : do_op(opcode_fns[p->act->val - 1], p));
}

char				*process_move(t_vm *vm, t_oper *p, int offset)
{
	char			*pc;
	char			*mem;
	int 			opcode;

	p->act = NULL;
	p->waiting = -1;
	pc = p->pc + offset;
	if ((mem = vm->arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	p->pc = pc;
	opcode = read_byte(pc);
	printf("NEW OPCODE = %d\n", opcode);
	printf("%s\n", pc);
	return (pc);
}

void					showmust_go_on(t_vm *vm)
{
	int					cycles;
	t_oper 				*current;
	int					opcode;
	int					jump;

	cycles = vm->hm_process;
	while (cycles--)
	{
		current = &vm->ops[cycles];
		if (current->waiting < 0)
		{
			opcode = read_byte(current->pc) - 1;
			printf("OPCODE = %d\n", opcode);
			if (opcode < OP_COUNT && opcode >= 0)
			{
				current->act = &g_tab[opcode];
				current->waiting = 0;
//				g_tab[opcode].cycles
			}
		}
		if (--current->waiting <= 0)
		{
			jump = process_op(current);
			printf("JUMP = %d\n", jump);
			process_move(vm, &vm->ops[cycles], jump);
		}
	}
}
static void	resize_array(t_oper *new, t_oper *old, size_t old_size)
{
	int		from;
	size_t	idx;
	size_t	i;

	i = 0;
	idx = 0;
	from = -1;
	while (i < old_size)
	{
		if (old[i].live)
		{
			old[i].live = 0;
			if (from < 0)
				from = i;
		}
		else if (from >= 0)
		{
			ft_memcpy(&new[idx], &old[from], sizeof(t_oper) * (i - from));
			idx += i - from;
			from = -1;
		}
		i++;
	}
	if (from >= 0)
		ft_memcpy(&new[idx], &old[from], sizeof(t_oper) * (i - from));
}

void			kill_processes(t_vm *vm, size_t count)
{
	t_oper	*old;

	old = vm->ops;
	if (!(vm->ops = (t_oper *)malloc(sizeof(t_oper) * count)))
		error("malloc error");
	resize_array(vm->ops, old, vm->hm_process);
	vm->hm_process = count;
	free(old);
}

static void	get_live_die_count(t_vm *vm, size_t *live_count, size_t *die_count)
{
	int			i;

	*live_count = 0;
	*die_count = 0;
	i = vm->hm_process;
	while (--i >= 0)
	{
		if (vm->ops[i].live)
			*live_count += vm->ops[i].live;
		else
			(*die_count)++;
	}
}

static int			i_am_alive_msg(t_vm *vm)
{
	size_t			live_count;
	size_t			die_count;
	int				i;

	get_live_die_count(vm, &live_count, &die_count);
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

int					someone_is_alive(t_vm *vm)
{
	if (vm->dump && vm->hm_cycles >= vm->dump_nb)
		printf("dumping memory here\n");
	vm->hm_cycles++;
	showmust_go_on(vm);
	if (vm->hm_cycles >= vm->cycle.check)
	{
		vm->cycle.cur += (i_am_alive_msg(vm)) ? MAX_CHECKS : 1;
		vm->cycle.check = vm->hm_cycles + vm->cycle.to_die;
	}
	if (vm->cycle.cur >= MAX_CHECKS)
	{
		vm->cycle.cur = 0;
		vm->cycle.to_die -= CYCLE_DELTA;
		vm->cycle.check -= CYCLE_DELTA;
	}
	if (vm->hm_process <= 0 || vm->cycle.to_die <= 0)
		return (0);
	return (1);
}

void				war_start(t_vm *vm)
{
	int 			how_many_players;
	int				position;
	int 			i;

	how_many_players = vm->champs;
	printf("STARTING COREWAR\n");
	i = 0;
	while (how_many_players)
	{
		position = vm->champ[i++].position;
		make_process(vm, &vm->arena[position]);
		--how_many_players;
	}
	vm->cycle.to_die = CYCLE_TO_DIE;
	vm->cycle.check = CYCLE_TO_DIE;
	vm->cycle.cur = 0;
	while (someone_is_alive(vm))
		;
}

