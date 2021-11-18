
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*get_split_string(const char *s, char c);

int main()
{
	printf("%s", get_split_string("hola, pepe", ','));
	return (0);
}

