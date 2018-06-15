/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:17:11 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 03:35:34 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_LEN 1

# include "libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int						get_next_line(int const fd, char **line);

typedef struct			s_reader
{
	char				*buf;
	int					fd;
}						t_reader;
#endif
