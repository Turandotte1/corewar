/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 21:21:26 by mrychkov          #+#    #+#             */
/*   Updated: 2017/10/31 21:22:03 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_wclen(wchar_t wc)
{
	if ((unsigned int)wc < 128)
		return (1);
	else if ((unsigned int)wc < 2048)
		return (2);
	else if ((unsigned int)wc < 65536)
		return (3);
	else
		return (4);
}
