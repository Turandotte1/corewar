//
// Created by Minh PHAM on 4/24/18.
//

#ifndef ASM_STRUCT_H
#define ASM_STRUCT_H

#include "asm.h"

/*
** je stocke mes labels dans une liste, address est un flag qui se suivent
*/

typedef struct		s_label
{
	char				*name;
	int					address;
	struct s_label		*next;
}					t_label;

typedef struct		s_param
{
	int					type;
	int					value;
	char 				*init_value;
	int					bytes;
}					t_param;

typedef struct	s_instruct
{
	char 				*name;
	int					opcode;
	int					address;
	t_param				params[MAX_ARGS_NUMBER];
	struct s_instruct	*next;
}				t_instruct;

typedef struct	s_champ
{
	char				*name;
	char				*comment;
	t_label				*labels;
	t_instruct			*instructs;
}								t_champ;

#endif
