#include "../../includes/op.h"

char	*ft_strsubc(char **s, char c)
{
	char	*dest;

	dest = *s;
	while (**s && **s != c)
		++*s;
	**s = '\0';
	++*s;
	return (dest);
}
