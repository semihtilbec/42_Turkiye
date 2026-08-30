#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
    ft_printf("merhaba %s, sayi: %d, hex: %x\n", "dunya", 42, 255);
    printf("merhaba %s, sayi: %d, hex: %x\n", "dunya", 42, 255);
    return (0);
}