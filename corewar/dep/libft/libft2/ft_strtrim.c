/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:54:45 by mipham            #+#    #+#             */
/*   Updated: 2018/07/14 16:52:55 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtrim(char const *s)
{
	int			i;
	int			j;
	size_t		size;
	char		*dest;

	i = 0;
	j = 0;
	size = ft_strlen_skip_white(s) + 1;
	if (!s || !(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (size--)
	{
		dest[j] = s[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

/*
**	ft_strtrim_front -> libft/string/ft_strtrim.c
**		suprime les espaces devant une str et renvoie la str
*/

char		*ft_strtrim_front(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t')
		{
			s[i] = '\0';
			++i;
		}
		return (s + i);
	}
	return (ft_error_n(2, "RFLsn", FI_, FU_, LI_,
					"input string should not be NULL..."));
}

/*
**	ft_strtrim_back	-> libft/string/ft_strtrim.c
**		suprime les espaces derriere une str et renvoie la str
*/

char		*ft_strtrim_back(char *s)
{
	int i;

	if (s)
	{
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t')
		{
			s[i] = '\0';
			--i;
			if (i < 0)
				break ;
		}
		return (s);
	}
	return (ft_error_n(2, "RFLsn", FI_, FU_, LI_,
					"input string should not be NULL..."));
}

/*
**	ft_strtrim_both	-> libft/string/ft_strtrim.c
**		suprime les espaces devant et derriere une str et renvoie la str
**	ft_strtrim_back	-> libft/string/ft_strtrim.c
**		suprime les espaces derriere une str et renvoie la str
**	ft_strtrim_front -> libft/string/ft_strtrim.c
**		suprime les espaces devant une str et renvoie la str
*/

char		*ft_strtrim_both(char *s)
{
	if (s)
	{
		s = ft_strtrim_back(s);
		return (ft_strtrim_front(s));
	}
	return (NULL);
}
