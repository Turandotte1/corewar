/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 20:43:49 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 16:39:19 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tabsize(char const *s, char c)
{
	size_t	i;
	size_t	word_count;
	size_t	j;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (j)
			word_count++;
	}
	return (word_count);
}

static char		**ft_split(char **tab, char c, char const *s)
{
	size_t	word;
	size_t	i;
	size_t	j;

	i = 0;
	word = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j)
		{
			if (!(tab[word] = ft_strsub(s, i, j)))
			{
				ft_memdel((void **)tab);
				return (NULL);
			}
			i = i + j;
			word++;
		}
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_tabsize(s, c);
	if (!(tab = (char **)ft_memalloc(sizeof(*tab) * (word_count + 1))))
		return (NULL);
	ft_split(tab, c, s);
	tab[word_count] = NULL;
	return (tab);
}
