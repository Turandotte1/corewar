#ifndef VIZ_H
# define VIZ_H

#include "vm.h"

typedef struct	s_vec2
{
	int		x;
	int		y;
}				t_vec2;

typedef struct	s_windows
{
	WINDOW	*win;
	t_vec2	size;
}				t_windows;



/*
**---------------------------init and game start--------------------------------
*/

void			start_ncurse_mode(t_vm *vm);
void			start_game(int (*someone_is_alive)(t_vm *), t_vm *vm);

#endif