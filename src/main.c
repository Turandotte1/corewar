/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/04/24 16:40:37 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Minh PHAM on 4/20/18.
//

#include "../includes/asm.h"

char	*ft_check_file(char *s, int *len)
{
	char		*buf;
	struct stat	fstat;
	int			fd;
	int			ret;

	if (!s || !len)
		return (ft_error(2, "missing path or adress for len"));
	*len = 0;
	if (stat(s, &fstat) < 0)
		return (ft_error(2, "stat error on : "));
	if (!(buf = (char*)malloc(fstat.st_size + 1)))
		return (ft_error(2, "malloc error :"));
	if ((fd = open(s, O_RDONLY)) < 0)
		return (ft_error(2, "open error :"));
	if ((ret = read(fd, buf, fstat.st_size)) <= 0)
		return (ft_error(2, "read error :"));
	*len = ret;
	buf[ret] = '\0';
	close(fd);
	return (buf);
}


int main(int ac, char **av)
{
	t_champ		*champ;
	char 		*content;
	int			fd;

	if(!(champ = (t_champ*)ft_memmalloc(sizeof(t_champ))))
		return (EXIT_FAILURE);
	if (ac = 2 && ft_strcmp(&av[1][ft_strlen(av[1]) - 2], ".s") == 0))
	{
		content = ft_check_file(champ);
		if (!content)
			close_asm(champ, "Exiting: can't read file\n");
		parse_file(content, champ);
		if (!(compile(champ, av[1])))
		{
			free(content);
			close_asm(champ, "Error creating .cor file\n");
		}
		free(content);
		close_asm(champ, "");
	}
	else
		close_asm(champ, "Usage: ./asm <file.s>\n");
	return (0);
}
/*
**check les parametres
*/
