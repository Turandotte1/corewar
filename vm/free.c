#include "vm.h"

void			del_queue(t_vec *vec, t_vec *names)
{
	int i;

	i = 0;
	while (i < v_size(vec))
	{
		v_del((t_vec *)v_get(vec, i));
		++i;
	}
	v_del(vec);
	v_del(names);
}