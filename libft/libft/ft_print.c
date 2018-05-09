
#include "libft.h"

/*
** puttab prints all the strings contained in a char**, followed by a "\n"
*/

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_putstr(char const *s)
{
	ft_putstr_fd(s, 1);
}

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
