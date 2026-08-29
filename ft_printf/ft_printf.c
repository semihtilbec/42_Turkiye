#include "ft_printf.h"

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i;

    if (!str)
        return (write(1, "(null)", 6));
    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
    return (i);
}

int ft_conversion(va_list args, const char format)
{
    if (format == 'c')
        char_printed += ft_putchar(va_arg(args,int));
    else if (format == 's')
        char_printed += ft_putstr(va_arg(args, char *));
    else if (format == 'p')
        char_printed += 
}

