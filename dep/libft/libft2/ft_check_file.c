
#include "includes/libft.h"
/*
**	ft_check_file
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


