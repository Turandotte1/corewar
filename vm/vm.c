#include "corewar_vm.h"

int						main(int ac, char **av)
{
	t_vm				vm;
	if (ac < 2)
		printf("not good man\n");
	ft_bzero(&vm, sizeof(t_vm));
	//parser argc
	//parser le fichier .cor notamment pour verifier tous les erreurs possibles (.cor est-il valide,
	//magic est correct, la taille de champion corresponds bien a celui declaré, parser les commentaires)
	//initialiser les champions dans la map
	//<-------------------------------Gaspard fait tout ca---------------------------------------

	run_vm(&vm);
	//on n'oublie de rien free
	return (0);
}