#include "../../includes/op.h"

int		ft_check_putnbr_base(char *base)
{
	int i;
	int j;
	int count;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		count = 0;
		while (base[j] != '\0')
		{
			if (base[i] == '+' || base[i] == '-')
				return (0);
			if (base[i] == base[j])
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_itoa_base(int nbr, char *base, int base_len, char *tab)
{
	int		display;
	int		k;
	int		i;
	char	*temp;

	while (base[base_len] || (k = 0))
		base_len++;
	if (*base && base_len != 1 && ft_check_putnbr_base(base))
	{
		if (nbr < 0)
			if ((nbr = -nbr))
				tab[k++] = '-';
		display = 0;
		i = 0;
		temp = (char*)malloc(256 * sizeof(char));
		while (nbr != 0)
		{
			temp[i++] = display * base_len + nbr % base_len;
			nbr = nbr / base_len;
		}
		while (i-- > 0)
			tab[k++] = base[0 + temp[i]];
		tab[k] = 0;
	}
	return (tab);
}

int		ft_check_atoi_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int index;
	int display;
	int size_base;

	index = 0;
	display = 0;
	sign = 1;
	while (base[index])
		index++;
	size_base = index;
	index = 0;
	while (str[index] == '\t' || str[index] == '\n' || str[index] == '\v' ||
			str[index] == '\f' || str[index] == '\r' || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			sign = -1;
	while (str[index] && (ft_check_atoi_base(str[index], base) != -1
	|| (sign = 0)))
		display = display * size_base +
		(ft_check_atoi_base(str[index++], base)) * sign;
	return (sign ? display : 0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*tab;
	int		base_len;

	base_len = 0;
	tab = (char*)malloc(256 * sizeof(char));
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to, base_len, tab));
}
