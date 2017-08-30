#include "../../includes/op.h"

char	*ft_free_strjoin(char **s1, char **s2)
{
	char	*sptr;
	int		index;

	if (!*s1 || !*s2)
		return (NULL);
	if (!(sptr = (char*)malloc(sizeof(char)
		* (ft_strlen(*s1) + ft_strlen(*s2) + 1))))
		return (NULL);
	index = 0;
	while (**s1)
	{
		sptr[index] = **s1;
		++(*s1);
		++index;
	}
	while (**s2)
	{
		sptr[index] = **s2;
		++(*s2);
		++index;
	}
	sptr[index] = '\0';
	return (sptr);
}
