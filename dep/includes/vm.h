#ifndef VM_H

# define VM_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>
# include "../libft/libft.h"
# include "../libft_minh/libft_all.h"
# include "../libvec/inc/vector.h"
# include "../libmem/inc/libmem.h"
# include "op.h"

# define BOLD_RED			"\e[1;31m"
# define CYAN				"\e[38;5;122m"
# define RED				"\e[38;5;124m"
# define BROWN				"\e[0;33m"
# define END				"\033[0m"
# define BOLD_GREEN			"\e[1;32m"
# define BLUE				"\e[34m"
# define LIGHT_GREY			"\e[37m"

# define BUFF_SIZE				1000

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define OPS 16

/*
**----------------------les structures se cachent ici---------------------------
*/

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

typedef char						t_arg_type;
typedef char						t_reg[REG_SIZE];

typedef struct						s_flag
{
	t_vec							n;
	int								v;
	int								dump;
	int								dump_nb;
}									t_flag;

typedef struct						s_parsing
{
	t_vec							queue;
	t_vec							names;
	t_vec							code;
}									t_parsing;

typedef struct						s_act
{
	int								act;
	int								f_p;
	int								s_p;
	int								t_p;
}									t_act;

typedef struct						s_task
{
	const char						*name;
	int								hm_params;
	t_arg_type						args_types[3];
	int								val;
	int								cycles;
	const char						*description;
	int								ocp;
	int								dir_short;
}									t_task;

typedef struct						s_oper
{
	char							*pc;
	int								carry;
	int								live;
	int								waiting;
	size_t							id;
	t_reg							r[REG_NUMBER];
	t_task							*act;
}									t_oper;

typedef struct						s_params
{
	char							*arg;
	size_t							size;
	int								value;
	t_arg_type						type;
}									t_params;

typedef struct 						s_binary
{
	char							id;
	char							live;
	char							pc;
	char							op;
}									t_binary;

typedef struct						s_cycle
{
	int								to_die;
	int								check;
	int								cur;
	int								cycle_nb;
	int 							last_live;
	t_binary						byte[MEM_SIZE];
}									t_cycle;

typedef struct						s_champion
{
	char							*ch;
	char							*complete_ch;
	header_t 						head;
	int								len;
	int								position;
	int								last_live;
	int 							cur_live;
	int								champ_id;
}									t_champion;

typedef struct						s_vm
{
	t_oper							*ops;
	t_cycle							cycle;
	t_champion						*champ;
	int								v;
	int								dump;
	int								dump_nb;
	int								champs;
	int								hm_process;
	int								hm_cycles;
	int								error;
	char							*arena;
}									t_vm;

typedef struct						s_norme
{
	t_vm							*vm;
	t_vec							*code;
	int								player;
}									t_norme;

extern t_task						g_tab[OPS + 1];

/*
**----------------------------------Init functions------------------------------
*/

void								init_flag(t_flag *flag, t_vec *code,
		t_vec *queue, t_vec *names);
t_act								init_struct(void);

/*
**----------------------------------Free helpers--------------------------------
*/

void								del_queue(t_vec *vec, t_vec *names);

/*
**----------------------------------Error handling------------------------------
*/

void								usage(void);
int									error(char *s);

/*
**----------------------------------Args parsing--------------------------------
*/

void								parse_args(t_vm *vm, t_flag flags,
		char **argv);
int									flag_or_champ(t_vm *vm, char **argv,
		t_flag *flags, t_parsing *parsing);
int									f_zjmp(t_act *act, t_vec *vec, int i);
int									f_ldi(t_act *act, t_vec *vec, int i);
int									f_sti(t_act *act, t_vec *vec, int i);
int									f_fork(t_act *act, t_vec *vec, int i);
int									f_aff(t_act *act, t_vec *vec, int i);
int									f_add(t_act *act, t_vec *vec, int i);
int									f_sub(t_act *act, t_vec *vec, int i);
int									f_and_second_part(t_act *act, t_vec *vec,
		int i, int id);
int									f_and(t_act *act, t_vec *vec, int i);
int									f_st(t_act *act, t_vec *vec, int i);
int									f_live(t_act *act, t_vec *vec, int i);
int									f_ld(t_act *act, t_vec *vec, int i);
t_norme								concat(t_vec *vec, t_vm *vm, int player);

/*
**----------------------------------Champion's parsing--------------------------
*/

void								parse_champion(int fd, t_vec *queue,
		t_vec *names, t_norme norme);
void								give_name(t_flag *f, int name);
void								give_magic_number(t_vec *vec,
		header_t *head);
void								give_size(t_vec *vec, int *i,
		header_t *head);
void								give_comment(t_vec *vec, int *i,
		header_t *head);
void								give_actions(t_vec *vec, t_vec *queue);
char								*vec_to_char(t_vec *map);

/*
**-----------------------------------Load players in memory---------------------
*/

void								into_vm(t_vm *vm, t_flag *flag,
		t_vec *code);

/*
**-----------------------------------Play---------------------------------------
*/

void								war_start(t_vm *vm);
void								players_are_ready(t_vm *vm);
int									someone_is_alive(t_vm *vm);
int									which_operation(t_vm *vm, t_oper *p);
size_t								analyze_param(t_oper *p, int opcode,
		t_params args[3]);
int									play(void (*func)(t_vm *, t_oper *,
			t_params[3]),
		t_oper *p, t_vm *vm);
char								*move_players(t_vm *vm, t_oper *p,
		int offset);
int									get_value(t_oper *proc, t_params *arg,
		int idx, int long_op);

/*
**----------------------------------Operations----------------------------------
*/

void								live(t_vm *vm, t_oper *p, t_params args[3]);

void								add(t_vm *vm, t_oper *p, t_params args[3]);
void								aff(t_vm *vm, t_oper *p, t_params args[3]);
void								and(t_vm *vm, t_oper *p, t_params args[3]);
void								fork_o(t_vm *vm, t_oper *p,
		t_params args[3]);
void								ld(t_vm *vm, t_oper *p, t_params args[3]);
void								ldi(t_vm *vm, t_oper *p, t_params args[3]);
void								lfork(t_vm *vm, t_oper *p,
															t_params args[3]);
void								lld(t_vm *vm, t_oper *p, t_params args[3]);
void								lldi(t_vm *vm, t_oper *p, t_params args[3]);
void								or(t_vm *vm, t_oper *p, t_params args[3]);
void								st(t_vm *vm, t_oper *p, t_params args[3]);
void								sti(t_vm *vm, t_oper *p, t_params args[3]);
void								sub(t_vm *vm, t_oper *p, t_params args[3]);
void								xor(t_vm *vm, t_oper *p, t_params args[3]);
void								zjmp(t_vm *vm, t_oper *p, t_params args[3]);

/*
**----------------------------------Process handlers----------------------------
*/

t_oper								*make_process(t_vm *vm,
		char *pc, t_oper *parent_t);
void								kill_process(t_vm *vm, size_t count);
t_champion							*who_is_it(t_vm *vm, int id);

/*
**----------------------------------Memory helpers------------------------------
*/

t_reg								*read_info(t_vm *vm, t_reg r[REG_SIZE], int i);


void					write_range(char *src, char *pc, size_t range, int number);

void								analyze_info(t_reg r[REG_SIZE], char *val);


void								write_info(t_reg r[REG_SIZE], char *pc, 
												int champ_number);
char								read_adress_info(char *address);

void								read_range(char *dst, char *pc,
		size_t range);
void								store(t_reg r[REG_SIZE], char *val);
void								print_memory(const void *addr, size_t size);

void								convert_endian(char *dest, char *src, 
															size_t type_len);



/*
** Pour les operation
**  on lit l'opcode, on recupere la valeur d'attente
** (int waiting je l'ai appelle), on decremente la valeur d'attente
** avec le cycle jusqu'a 0,
**
**  on calcule la nouvelle position de pc, on check ocp
** 		 on parse les argc
**
** ------------------------OPTIONS A GERER-----------------------------
** -n nom
** -dump nbr_cycles
** -v (si jamais on le fait);
**
**
** on stock les trucs dans le vecteur structure t_act
** (name, les trois parametres);
**
** on cree la map et on trouve la position initiale de joueur dans la map;
**
** si -v tu boucle dans le ncurses, sinon on boucle dans la vm:
** 		- ou on check si memoire doit etre dumper, on break
** 		- on run les operations en verifiant combien de processus on a par cycle
** 		- si on doit decrementer CYCLE_DELTA, on sort du boucle
** 		- des qu'on a pas de live d'un jouer
*/

#endif
