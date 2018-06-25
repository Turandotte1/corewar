#ifndef VIZ_H
# define VIZ_H

#include "vm.h"

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_windows
{
	WINDOW				*window;
	t_coord				len;
}						t_windows;

typedef struct			s_data
{
	va_list				*ap;
	const char			*format;
	char				*out;
	int					write_size;
}						t_data;



/*
**---------------------------init and game start--------------------------------
*/

void			start_ncurse_mode(t_vm *vm);
void			start_game(int (*someone_is_alive)(t_vm *), t_vm *vm);
void			windows_init(t_windows win[3], t_vm *vm);

/*
**---------------------------drawing functions----------------------------------
*/

void			draw_win(t_windows win[3], t_vm *vm);

#endif