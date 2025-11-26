#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_printf(const char *, ...);
char	*ft_itoa_unsd_int(unsigned int i);

int	main(void)
{
	int expeacted = printf("%u\n", UINT_MAX);
	int actual = ft_printf("%u\n", UINT_MAX);
	printf("expected : %d, actual : %d\n", expeacted, actual);
}
