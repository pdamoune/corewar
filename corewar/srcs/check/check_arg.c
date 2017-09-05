/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 19:00:21 by pdamoune          #+#    #+#             */
/*   Updated: 2017/09/05 17:18:59 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		check_arg(vm, t_op *op, int *args)
{
	ft_printf("args[0] %d\n", arg[0]);
	ft_printf("args[1] %d\n", arg[1]);
	ft_printf("args[2] %d\n", arg[2]);
	ft_printf("args[3] %d\n", arg[3]);

	ft_printf("op.label %s\n", op.label);
	ft_printf("op.nb_params %d\n", op.nb_params);
	ft_printf("op.params[0] %d\n", op.params[0]);
	ft_printf("op.params[1] %d\n", op.params[1]);
	ft_printf("op.params[2] %d\n", op.params[2]);
	ft_printf("op.op_code %d\n", op.op_code);
	ft_printf("op.cycle %d\n", op.cycle);
	ft_printf("op.description %s\n", op.description);
	ft_printf("op.ocp %d\n", op.ocp);
	ft_printf("op.index %d\n", op.index);
	ft_printf("op.instru %p\n", op.instru);

	return (0);
}
