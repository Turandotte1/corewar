/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/05/15 13:10:46 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	ft_open_file -> libft/main/ft_open_file.c
**		renvoit le contenu d'un fichier dont le path est passé en param
**		enregistre dan len la size de la chaine renvoyé
**	stat -> sys/stat.h
**		stat - get file status
**	ft_error_n  -->  libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	malloc	--> stdlib.h
**		allocation dynamic de memoire
**	open  -->  fcntl.h
**		creates a new open file description
**	read  -->  unistd.h
**		Lire depuis un descripteur de fichier
**	close  -->  unistd.h
**		Fermer un descripteur de fichier
*/

 char	*ft_check_file(char *s, int *len)
{
	char		*buf;
	struct stat	fstat;
	int			fd;
	int			ret;

	if (!s || !len)
		return (ft_error_n(2, "RFLsn", FFL, "missing path or adress for len"));
	*len = 0;
	errno = 0;
	if (stat(s, &fstat) < 0)
		return (ft_error_n(2, "RFLssnEn", FFL, "stat error on : ", s, errno));
	errno = 0;
	if (!(buf = (char*)malloc(fstat.st_size + 1)))
		return (ft_error_n(2, "RFLsnEn", FFL, "malloc error :", errno));
	errno = 0;
	if ((fd = open(s, O_RDONLY)) < 0)
		return (ft_error_n(2, "RFLsnEn", FFL, "open error :", errno));
	if ((ret = read(fd, buf, fstat.st_size)) <= 0)
		return (ft_error_n(2, "RFLsnEn", FFL, "read error :", errno));
	*len = ret;
	buf[ret] = '\0';
	close(fd);
	return (buf);
}

int	main(int ac, char **argv)
{
	char	*content;
	int		len;
	t_champ	*champ;

	content = NULL;
	if (!(champ = (t_champ*)ft_memalloc(sizeof(t_champ))))
		return (ft_error_d(2, "RFLsn", FFL, E_MLC));
	if (ac == 2 && (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 2], ".s") == 0))
	{
		content = ft_check_file(argv[1], &len);
		if (!content)
			close_asm(champ, "Exiting: can't read file\n");
		parse_file(content, champ);
		if (!(compile(champ, argv[1])))
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
