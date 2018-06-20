/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:11:21 by glegendr          #+#    #+#             */
/*   Updated: 2018/06/20 18:11:24 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

char					read_byte(char *addr)
{
	int					overflow;

	if ((overflow = addr - (addr + MEM_SIZE)) >= 0)
		return (addr[overflow]);
	return (*addr);
}
