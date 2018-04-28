/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:04:55 by mipham            #+#    #+#             */
/*   Updated: 2018/04/23 12:05:01 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by pelluro on 23/04/18.
//

#include "../libft.h"

void	ft_putstr_color(char const *s, const char *color)
{
	ft_putstr_color_fd(s, color, 1);
}

void	ft_putstr_color_fd(char const *s, const char *color, int fd)
{
	ft_color_switch_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_color_reset_fd(fd);
}

void	ft_color_switch_fd(const char *color, int fd)
{
	ft_putstr_fd(color, fd);
}

void	ft_color_reset_fd(int fd)
{
	ft_putstr_fd(COL_RESET, fd);
}
