#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_printf(const char *, ...);
char	*ft_itoa_unsd_int(unsigned int i);

int	main(void)
{
	char *ptr = "Hello";
	int expeacted = printf("%p\n", ptr);
	int actual = ft_printf("%p\n", ptr);
	printf("expected : %d, actual : %d\n", expeacted, actual);
}
