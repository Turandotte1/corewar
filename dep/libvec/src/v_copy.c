/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:20:25 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/29 23:09:54 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec		v_copy(t_vec *cpy, t_vec *vec)
{
	cpy = malloc(sizeof(*vec));//v_new(vec->private_elem_size);
	memcpy(vec, cpy, sizeof(*vec));
	/*printf("%p\n", &cpy);
	cpy.private_elem_nb = vec->private_elem_nb;
	cpy.private_elem_cap = vec->private_elem_cap;
	ft_memcpy(cpy.private_content, vec->private_content,
			vec->private_elem_nb * vec->private_elem_size);
	return (cpy);*/
}
