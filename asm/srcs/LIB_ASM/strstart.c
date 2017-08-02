#include "../../includes/op.h"

char	*ft_strstart(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (little[i] == '\0')
			return ((char *)big + i);
		if ( big[i] == little[i])
			i++;
		else
			return (NULL);
	}
	if ( big[i] == little[i])
		return ((char *)big + i);
	return (NULL);
}
