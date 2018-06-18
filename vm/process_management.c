#include "../dep/includes/vm.h"

static void					resize(t_oper *new, t_oper *old, size_t old_size)
{
	int						from;
	size_t					idx;
	size_t					i;

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

char					*move_players(t_vm *vm, t_oper *p, int offset)
{
	char				*pc;
	char				*mem;
	int 				opcode;

	p->act = NULL;
	p->waiting = -1;
	pc = p->pc + offset;
	if ((mem = vm->arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	p->pc = pc;
	opcode = read_byte(pc);
	opcode = opcode;
	return (pc);
}

void					kill_processes(t_vm *vm, size_t count)
{
	t_oper				*old;

	old = vm->ops;
	if (!(vm->ops = (t_oper *)malloc(sizeof(t_oper) * count)))
		error("malloc error");
	resize(vm->ops, old, vm->hm_process);
	vm->hm_process = count;
	free(old);
}

t_oper					*make_process(t_vm *vm, char *pc, t_oper *parent_p)
{
	t_oper				*new_p;
	t_oper				*temp;
	int 				now;

	if (parent_p)
		ft_memcpy(&temp, parent_p, sizeof(t_oper));
	vm->hm_process++;
	now = vm->hm_process;
	vm->ops = realloc(vm->ops, sizeof(t_oper) * now);
	new_p = &vm->ops[now - 1];
	ft_bzero(new_p, sizeof(t_oper));
	if (parent_p)
		ft_memcpy(new_p, &temp, sizeof(t_oper));
	new_p->waiting = -1;
	new_p->act = 0;
	new_p->pc = pc;
	return (new_p);
}