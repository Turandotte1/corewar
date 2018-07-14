#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

static void					print_it_out(const void *format, t_data *data)
{
	int						wcount;

	wcount = ft_strlen(format);
	if (wcount < data->write_size)
		data->bcount += wcount;
	else
		datas->bcount += data->write_size - fdatas->bcount;
	if (!fdatas->out)
		fdatas->out = (char *)malloc(fdatas->bcount + 1);
	fdatas->out[fdatas->bcount] = '\0';
}

static void					*curses_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		((char *)b)[i++] = (unsigned char)c;
	return (b);
}

static int					curses_vsn(char *str, size_t size,
									const char *format, va_list *ap)
{
	t_data					data;

	curses_memset(&data, 0, sizeof(t_data));
	data.ap = ap;
	data.format = format;
	data.out = str;
	data.write_size = size - 1;
	if (fdatas.write_size < 0)
		return (-1);
	print_it_out(format, &fdatas);
	if (fdatas.flag & FLAG_WRITE_ERROR)
		return (-1);
	return (fdatas.bcount);
}

int							curses_printf(char *restrict str, size_t size,
											const char *restrict format, ...)
{
	va_list					ap;
	int						out;

	va_start(ap, format);
	out = ft_vsnprintf(str, size, format, &ap);
	va_end(ap);
	return (out);
}
