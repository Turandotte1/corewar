/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:52:52 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/27 19:25:46 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../dep/libft/inc/libft.h"
#include "../dep/libvec/inc/vector.h"
#include "../../get_next_line/get_next_line.h"

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
typedef struct		s_flag
{
	t_vec	n; // l' ID de tout les champs, le 1er etant a l'index 0
	int		v; // == 1 si il a le visu == 0 sinon
	int		dump; // == 1 si il y a dumps == 0 sinon
	int		dump_nb; // nb de dumps max
}					t_flag;

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
