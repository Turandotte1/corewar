#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

static void			binary_align(t_vm *vm)
{
	t_binary		*b;
	char			*pc;
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		b = &vm->cycle.byte[i];
		b->pc = 0;
		if (vm->vizu & (RUN | NEXT))
		{
			b->live -= (b->live > 0) ? 1 : 0;
			b->op -= (b->op > 0) ? 1 : 0;
		}
		i++;
	}
	i = vm->hm_process;
	while (--i >= 0)
	{
		pc =vm->ops[i].pc;
		if (pc >= vm->arena + MEM_SIZE)
			vm->cycle.byte[0].pc |= 1;
		else
			vm->cycle.byte[pc - vm->arena].pc |= 1;
	}
}

void				draw_win(t_windows win[3], t_vm *vm)
{
	binary_align(vm);
	arena_print(&win[0], vm);
	wrefresh(win[0].window);
	info_print(&win[1], vm);
	wrefresh(win[1].window);
	if (!(vm->vizu & RUN))
		vm->vizu = PAUSE;
}