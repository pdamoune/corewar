#include "../../includes/op.h"

char	*ft_modif_arg(char *arg, int cell1, int cell2, char *val, int type)
{
	if (type == REG_CODE)
	{
		arg[cell1] = val[0];
		if (val[1])
			arg[cell2] = val[1];
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

char	*ft_arg(char *arg, int param, int type, char *val)
{
	if (param == 1)
		ft_modif_arg(arg, 0, 1, val, type);
	else if (param == 2)
		ft_modif_arg(arg, 2, 3, val, type);
	else if (param == 3)
		ft_modif_arg(arg, 4, 5, val, type);
	return (arg);
}
