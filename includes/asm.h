//
// Created by Minh PHAM on 4/19/18.
//

#ifndef ASM_H
#define ASM_H

/*
 * je stocke mes labels dans une liste, address est un flag qui se suivent
 */

typedef struct		s_label
{
	char			*name;
	int				address;
	struct s_label	*next;
}					t_label;

typedef struct		s_param
{
	int				type;
	int				value;
	char 			*raw_value;
	int				bytes;
}					t_param;

typedef struct	s_instruct
{
	char 			*name;
	int				opcode;
	int				address;
//	t_param			params;
	struct s_instruct	*next;
}				t_instruct;


#endif //COREWAR_ASM_H
