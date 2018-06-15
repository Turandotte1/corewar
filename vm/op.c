#include "vm.h"

t_task				g_tab[OPS + 1] =
{
	{ "live", 1, { T_DIR }, 1, 10, "alive", 0, 0 },
	{ "ld", 2, { T_DIR | T_IND, T_REG }, 2, 5, "load", 1, 0 },
	{ "st", 2, { T_REG, T_IND | T_REG }, 3, 5, "store", 1, 0 },
	{ "add", 3, { T_REG, T_REG, T_REG }, 4, 10, "addition", 1, 0 },
	{ "sub", 3, { T_REG, T_REG, T_REG }, 5, 10, "soustraction", 1, 0 },
	{ "and", 3, { T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG }, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0 },
	{ "or", 3, { T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG }, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0 },
	{ "xor", 3, { T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG }, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0 },
	{ "zjmp", 1, { T_DIR}, 9, 20, "jump if zero", 0, 1 },
	{ "ldi", 3, { T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG }, 10, 25,
		"load index", 1, 1 },
	{ "sti", 3, { T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG }, 11, 25,
		"store index", 1, 1 },
	{ "fork", 1, { T_DIR }, 12, 800, "fork", 0, 1 },
	{ "lld", 2, { T_DIR | T_IND, T_REG }, 13, 10, "long load", 1, 0 },
	{ "lldi", 3, { T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG }, 14, 50,
		"long load index", 1, 1 },
	{ "lfork", 1, { T_DIR }, 15, 1000, "long fork", 0, 1 },
	{ "aff", 1, { T_REG }, 16, 2, "aff", 1, 0 },
	{ 0, 0, { 0 }, 0, 0, 0, 0, 0 }
};

static int						check_ocp(t_oper *p, t_params args[3])
{
	int							i;

	i = 0;
	while (i < p->act->hm_params)
	{
		if (!(args[i].type & p->act->args_types[i]))
			return (0);
		i++;
	}
	return (1);
}

int								play(void (*func)(t_vm *, t_oper *, t_params[3]), 
																	t_oper *p, t_vm *vm)
{
	t_params					args[3];
	int							jump;

	p->waiting = -1;
	vm->error = 0;
	jump = analyze_param(p, p->act->val, args);
	if (func == &zjmp)
	{
		func(vm, p, args);
		return (0);
	}
	if (!p->act->ocp || check_ocp(p, args))
		func(vm, p, args);
	return (jump);
}

int								which_operation(t_vm *vm, t_oper *p)
{
	static void	(*func[OPS])(t_vm *, t_oper *, t_params[3]) = {
		&live, &ld, &st, &add, &sub, &and,
		&or, &xor, &zjmp, &ldi, &sti, &fork_o,
		&lld, &lldi, &lfork, &aff,
	};
	return (p->act == NULL ? 1 : play(func[p->act->val - 1], p, vm));
}

