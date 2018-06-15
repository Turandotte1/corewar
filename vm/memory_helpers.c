#include "vm.h"

char					read_byte(char *addr)
{
	int					overflow;

	if ((overflow = addr - (addr + MEM_SIZE)) >= 0)
		return (addr[overflow]);
	return (*addr);
}