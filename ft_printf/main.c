#include <stdio.h>
#include "libftprintf.h"

int main()
{
	printf("%p\n", "g");
	ft_printf("%p", "g");
}
