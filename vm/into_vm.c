#include "vm.h"

char			*vec_to_char(t_vec *map)
{
	char *arena;
	int i;

	i = 0;
	if ((arena = (char *)malloc(sizeof(char) * (v_size(map) + 1))) == NULL)
		error("Malloc error");
	while (i < v_size(map))
	{
		arena[i] = *(char *)v_get(map, i);
		++i;
	}
	arena[i] = '\0';
	return (arena);
}

static void			complete_vm(t_vm *vm, t_vec *map, t_flag *flag, t_vec *code)
{
	int i;

	i = 0;
	vm->arena = vec_to_char(map);
	vm->n = v_copy(&flag->n);
	vm->v = flag->v;
	vm->dump = flag->dump;
	vm->dump_nb = flag->dump_nb;
	v_del(&flag->n);
	v_del(map);
	while (i < v_size(code))
	{
		v_del((t_vec *)v_get(code, i));
		++i;
	}
	v_del(code);
}

static int			get_next_position(int player, int ci)
{
		return ((MEM_SIZE - player) / player * ci + (ci + 1));
	//	return (MEM_SIZE / player * ci);
}

void				into_vm(t_vm *vm, t_flag *flag, t_vec *code)
{
	int 			i;
	int 			y;
	char 			*lala;
	t_vec 			map;
	t_vec 			tmp;
	
	map = v_new(sizeof(char));
	i = 0;
	while (i < v_size(code))
	{
		tmp = *(t_vec *)v_get(code, i++);
		y = 0;
		while (y < v_size(&tmp))
		{
			v_push_int(&map, *(char *)v_get(&tmp, y));
			++y;
		}
//		vm->champ[i].ch = vec_to_char(&map);
//		map = v_new(sizeof(char));
		while (v_size(&map) < get_next_position(v_size(code), i))
			v_push_int(&map, (char)0);
		//lseek possibly ? 
	}
	complete_vm(vm, &map, flag, code);
}
