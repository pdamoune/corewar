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
		if (big[i] == little[i])
			i++;
		else
			return (NULL);
	}
	if (big[i] == little[i] && (size_t)i == ft_strlen(little))
		return ((char *)big + i);
	return (NULL);
}

char	*ft_strstart_modif(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (little[0] == '\0')
		return (ft_big_till_space((char *)big));
	while (big[i])
	{
		if (little[i] == '\0')
			return (ft_big_till_space((char *)big + i));
		if (big[i] == little[i])
			i++;
		else
			return (NULL);
	}
	if (big[i] == little[i] && (size_t)i == ft_strlen(little))
		return (ft_big_till_space((char *)big + i));
	return (NULL);
}

char	*ft_big_till_space(char *big)
{
	int		i;
	int		k;

	k = ft_strlen(big);
	i = 0;
	while (big[i] != '\0' && big[i] != ' ' && big[i] != '\t')
	{
		i++;
	}
	while (i < k)
	{
		big[i] = '\0';
		i++;
	}
	return ((char*)big);
}