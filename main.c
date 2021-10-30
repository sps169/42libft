
#include <stdio.h>
#include <string.h>
#include "ft_strtrim.c"

int main()
{
	char *	s = ft_strtrim("   xxx   xxx", " x");
	printf("%s\n", s);
	return (0);
}

