//
// Created by Minh PHAM on 4/19/18.
//

#ifndef ASM_H
#define ASM_H
# include "../libft/inc/libft.h"
# include "op.h"

# define FC(x, y)			ft_putstr_color(x , y );

# define RET(x, y)	{FC("ERR: ",COL_RED);FC( x ,COL_LIGHT_RED);return( y );}
/*
 * je stocke mes labels dans une liste, address est un flag qui se suivent
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
	t_param				params;
	struct s_instruct	*next;
}				t_instruct;

typedef struct	s_champ
{
	char				*name;
	char				*comment;
	t_label				labels;
	t_instruct			instructs;

}				t_champ;

#endif
