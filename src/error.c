//
// Created by pelluro on 23/04/18.
//

#include <stdlib.h>
#include "asm.h"
#include "libft.h"

void	asm_error(const char *str)
{
	ft_putstr_color(str, COL_LIGHT_RED);
	exit(EXIT_FAILURE);
}




void	print_detailed_error(t_champ *champ, const char *av1)
{
	(void)champ;
	ft_putstr("Couldn't convert ", COL_LIGHT_RED);
	ft_putstr_color(av1, COL_LIGHT_YELLOW);
	ft_putstr_color(".\n", COL_LIGHT_RED);
}
