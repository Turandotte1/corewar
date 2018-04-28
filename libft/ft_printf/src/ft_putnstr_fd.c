/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:09:27 by mipham            #+#    #+#             */
/*   Updated: 2017/12/13 16:09:33 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "../include/ft_printf.h"

void	ft_putnstr_fd(char const *str, size_t len, int fd)
{
	write(fd, str, len);
}
