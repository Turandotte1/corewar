/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 20:17:33 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 16:51:34 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strdel(char **tab)
{
	if (tab)
	{
		ft_memdel((void **)tab);
		*tab = NULL;
	}
	return (1);
}