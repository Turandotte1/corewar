/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_into_raw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 23:13:48 by glegendr          #+#    #+#             */
/*   Updated: 2017/12/18 23:14:00 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		*v_raw(t_vec *vec)
{
	return (vec->private_content);
}
