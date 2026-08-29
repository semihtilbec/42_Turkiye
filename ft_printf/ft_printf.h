#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_print
{
	va_list	args;
	int		idx;
	int		len;
}	t_print;