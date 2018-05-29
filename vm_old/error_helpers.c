#include "corewar_vm.h"

void		usage(void)
{
	printf("Usage: ./corewar [-v | -n N | -dump N] <champion1.cor> <...>\n");
	printf("----------------------------flags---------------------------\n");
	printf("    -v		Met en place le visualisateur\n");
	printf("    -n N	Fixe le numero du prochain joueur\n");
	printf("    -dump N	Raccourcie la partie a N cycles\n");
	printf("------------------------------------------------------------\n");
	exit(1);
}

int			error(char *s)
{
	if (!ft_strcmp(s, ""))
	{
		printf("Error\n");
		exit(1);
		return (0);
	}
	printf("Error: %s\n", s);
	exit(1);
	return (0);
}

void		print(int i, t_vec queue, t_vec names, t_flag flags)
{
	t_vec	tmp;
	int y;

	while (i < v_size(&queue))
	{
		header_t tmp2;
		tmp2 = *(header_t *)v_get(&names, i);
		printf("\n---------------%i---------------\n", i + 1);
		printf("name: %s   ID: %i\n", tmp2.prog_name, *(int *)v_get(&flags.n, i));
		printf("Comment: %s\n", tmp2.comment);
		printf("size: %i   magic number: %x\n", tmp2.prog_size, tmp2.magic);
		tmp = *(t_vec *)v_get(&queue, i++);
		printf("actions:\n");
		y = 0;
		while (y < v_size(&tmp))
		{
			t_act act = *(t_act *)v_get(&tmp, y++);
			printf("act %x: %i %i %i\n", act.act, act.f_p, act.s_p, act.t_p);
		}
	}
	printf("Flags: ");
	if (flags.v == 1)
		printf("-v ");
	if (flags.dump == 1)
		printf("-dump (%i)", flags.dump_nb);
	if (flags.v == 0 && flags.dump == 0)
		printf("Null\n");
}
