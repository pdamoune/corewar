#include "../../includes/op.h"

char	*ft_strsubc(char const *s, unsigned int start, char c)
{
	size_t	size_s;
	char	*dest;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	size_s = i;
	if (!(s))
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(*dest) * size_s + 1)))
		return (NULL);
	i = 0;
	while (i < size_s)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}


// char	*ft_strsubc(char **s, char c)
// {
// 	char	*dest;
// 	size_t	i;
//
// 	i = 0;
// 	dest = *s;
// 	while (*s[i] && *s[i] != c)
// 		i++;
// 	*s = (dest + i + 1);
// 	dest[i] = '\0';
// 	return (dest);
// }
