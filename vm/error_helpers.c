#include "vm.h"

void				usage(void)
{
	write(1, RED, ft_strlen(RED));
	ft_putstr_fd("Usage: ./corewar [-v | -n N | -dump N] ", 2);
	ft_putstr_fd("<champion1.cor> <...>\n", 2);
	write(1, CYAN, ft_strlen(CYAN));
	ft_putstr_fd("----------------------------flags", 2);
	ft_putstr_fd("---------------------------\n", 2);
	ft_putstr_fd("    -v		Met en place le visualisateur\n", 2);
	ft_putstr_fd("    -n N	Fixe le numero du prochain joueur\n", 2);
	ft_putstr_fd("    -dump N	Raccourcie la partie a N cycles\n", 2);
	ft_putstr_fd("---------------------------------", 2);
	ft_putstr_fd("---------------------------\n", 2);
	write(1, END, ft_strlen(END));
	exit(EXIT_FAILURE);
}

int			error(char *s)
{
	if (!ft_strcmp(s, ""))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
/*
**void		print(int i, t_vec queue, t_vec names, t_flag flags)
**{
**	t_vec	tmp;
**	int y;
**
**	while (i < v_size(&queue))
**	{
**		header_t tmp2;
**		tmp2 = *(header_t *)v_get(&names, i);
**		printf("\n---------------%i---------------\n", i + 1);
**		printf("name: %s   ID: %i\n", tmp2.prog_name,\
**(int *)v_get(&flags.n, i));
**		printf("Comment: %s\n", tmp2.comment);
**		printf("size: %i   magic number: %x\n", tmp2.prog_size, tmp2.magic);
**		tmp = *(t_vec *)v_get(&queue, i++);
**		printf("actions:\n");
**		y = 0;
**		while (y < v_size(&tmp))
**		{
**			t_act act = *(t_act *)v_get(&tmp, y++);
**			printf("act %x: %i %i %i\n", act.act, act.f_p, act.s_p, act.t_p);
**		}
**	}
**	printf("Flags: ");
**	if (flags.v == 1)
**		printf("-v ");
**	if (flags.dump == 1)
**		printf("-dump (%i)", flags.dump_nb);
**	if (flags.v == 0 && flags.dump == 0)
**		printf("Null\n");
**}
*/