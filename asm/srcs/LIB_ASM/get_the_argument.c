#include "../../includes/op.h"

char	*ft_modif_arg(char *arg, int cell1, int cell2, int type)
{
	if (type == REG_CODE)
	{
		arg[cell1] = '0';
		arg[cell2] = '1';
	}
	else if (type == DIR_CODE)
	{
		arg[cell1] = '1';
		arg[cell2] = '0';
	}
	else if (type == IND_CODE)
	{
		arg[cell1] = '1';
		arg[cell2] = '1';
	}
	return (arg);
}

char	*ft_arg(char *arg, int param, int type)
{
	if (param == 1)
		ft_modif_arg(arg, 0, 1, type);
	else if (param == 2)
		ft_modif_arg(arg, 2, 3, type);
	else if (param == 3)
		ft_modif_arg(arg, 4, 5, type);
	return (arg);
}
