/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:38:27 by mipham            #+#    #+#             */
/*   Updated: 2018/05/07 13:28:44 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft_all.h"
# include "op.h"
# include "asm_struct.h"

# define FC(x, y)			ft_putstr_color(x , y );

char *ft_error(int fd, char *s);

#endif
