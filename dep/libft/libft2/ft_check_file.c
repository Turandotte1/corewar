/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:00:29 by mipham            #+#    #+#             */
/*   Updated: 2018/07/16 17:00:54 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
	{
		free(buf);
		return (ft_error_n(2, "RFLsnEn", FFL, "read error :", errno));
	}
	*len = ret;
	buf[ret] = '\0';
	close(fd);
	return (buf);
}
