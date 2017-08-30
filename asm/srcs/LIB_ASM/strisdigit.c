#include "../../includes/op.h"

int		ft_isstrdigit(char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (i == ft_strlen(s));
}