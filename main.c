#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	char *ptr = "Hello";
	int expeacted = printf("%s, %p\n", ptr, ptr);
	int actual = ft_printf("%s, %p\n", ptr, ptr);
	printf("expected : %d, actual : %d\n", expeacted, actual);
	char	*ft_itoa_p(void *p);
}
