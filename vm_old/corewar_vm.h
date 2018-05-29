#ifndef COREWAR_H

# define COREWAR_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../dep/libft/inc/libft.h"
#include "../dep/libvec/inc/vector.h"
#include "../../get_next_line/get_next_line.h"

/*
**---------------------------------les structures se cachent ici------------------------------------
*/

typedef struct						s_flag
{
	
}									t_flag;

typedef struct 						s_oper
{
	int								carry;
	int 							live;
	int								waiting;
	size_t							id;
	char							r[REG_NUMBER];
	t_vec							*act; //le vecteur de la struct de Gaspard
}									t_oper;

typedef struct 						s_vm
{
	char							arena[MEM_SIZE];
	t_vec							n;
	int								v;
	int								dump;
	int								dump_nb;
	
}									t_vm;

/*
** Alors mon main return un t_vec *queue, t_vec *names, et un t_flag *flags
**
** t_vec *queue:
**             C'est un vecteur de vecteur qui contient toutes les actions
**    En gros, l'index 0 de queue c'est le 1er champ :D
**
** t_vec *names:
**             C'est un vecteur de header_t (du op.h), avec le nom du champ,
**    et son comment. Pareil qu'avant, index 0 = 1er champ
**
** t_flag *flag:
**             C'est tout simplement les flags, avec un t_vec n qui sont les
**    ID respectifs des champs :D
*/

//op.h
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3
# define MEM_SIZE (4 * 1024)
# define IDX_MOD (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

// les actions
typedef struct		s_act
{
	int				act;
	int				f_p; //first_parameter, if == -1, he is not defined
	int				s_p;
	int				t_p;
}					t_act;

// les differents flags


//header du op.h
typedef struct		header_s
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					header_t;

// ca c'est la verification des differentes actions
int		f_live(t_act *act, t_vec *vec, int i);
int		f_ld(t_act *act, t_vec *vec,int i);
int		f_st(t_act *act, t_vec *vec, int i);
int		f_add(t_act *act, t_vec *vec, int i);
int		f_sub(t_act *act, t_vec *vec, int i);
int		f_and(t_act *act, t_vec *vec, int i);
int		f_zjmp(t_act *act, t_vec *vec, int i);
int		f_ldi(t_act *act, t_vec *vec, int i);
int		f_sti(t_act *act, t_vec *vec, int i);
int		f_fork(t_act *act, t_vec *vec, int i);
int		f_aff(t_act *act, t_vec *vec, int i);
// et ca bah c'est l'erreur
int		error(char *s);

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

#endif 