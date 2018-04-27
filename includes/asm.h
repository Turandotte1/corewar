//
// Created by Minh PHAM on 4/19/18.
//

#ifndef ASM_H
#define ASM_H
# include "../libft/inc/libft.h"
# include "op.h"

# define FC(x, y)			ft_putstr_color(x , y );

# define RET(x, y)	{FC("ERR: ",COL_RED);FC( x ,COL_LIGHT_RED);return( y );}


#endif
