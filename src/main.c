/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/05/15 13:10:46 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int ac, char **argv)
{
	char	*content;
	int		len;
	t_champ	*champ;

	content = NULL;
	if (!(champ = (t_champ*)ft_memalloc(sizeof(t_champ))))
		return (ft_error_d(2, "RFLsn", FFL, E_MLC));
	if (ac == 2 && (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 2], ".s") == 0))
	{
		content = ft_check_file(argv[1], &len);
		if (!content)
			close_asm(champ, "Exiting: can't read file\n");
		parse_file(content, champ);
		if (!(compile(champ, argv[1])))
		{
			free(content);
			close_asm(champ, "Error creating .cor file\n");
		}
		free(content);
		close_asm(champ, "");
	}
	else
		close_asm(champ, "Usage: ./asm <file.s>\n");
	return (0);
}
