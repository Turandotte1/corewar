#include "../dep/includes/vm.h"

void				init_flag(t_flag *flag, t_vec *code, t_vec *queue, 
													t_vec *names)
{
	flag->v = 0;
	flag->dump = -1;
	flag->dump_nb = -1;
	flag->n = v_new(sizeof(int));
	*code = v_new(sizeof(t_vec));
	*queue = v_new(sizeof(t_vec));
	*names = v_new(sizeof(header_t));
}

t_act				init_struct(void)
{
	t_act act;

	act.act = 0;
	act.f_p = -1;
	act.s_p = -1;
	act.t_p = -1;
	return (act);
}