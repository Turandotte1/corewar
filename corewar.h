#ifndef COREWAR_H

# define COREWAR_H

#include <libft.h>
#include <vector.h>
#include <op.h>



typedef struct 						s_oper
{
	int								carry;
	int 							live;
	int								waiting;
	size_t							id;
	char							r[REG_NUMBER];
	t_vec							*act; //le vecteur de la struct de Gaspard
}									t_oper;


/*Pour les operation
	on lit l'opcode, on recupere la valeur d'attente (int waiting je l'ai appelle), on decremente la valeur d'attente avec le cycle jusqu'a 0,
	on calcule la nouvelle position de pc, on check ocp

///// on parse les argc

/*
**-------------OPTIONS A GERER-----------------------------
		-n 
		-dump nbr_cycles
		-v (si jamais on le fait);
*/

////on stock les trucs dans le vecteur structure t_act (name, les trois parametres);

////on cree la map et on trouve la position initiale de joueur dans la map;

/////si -v tu boucle dans le ncurses, sinon on boucle dans la vm:
//		- ou on check si memoire doit etre dumper, on break 
//		- on run les operations en verifiant combien de processus on a par cycle
//		- si on doit decrementer CYCLE_DELTA, on sort du boucle
//		- des qu'on a pas de live d'un jouer