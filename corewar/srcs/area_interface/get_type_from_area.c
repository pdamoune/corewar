/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_from_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:01:52 by wescande          #+#    #+#             */
/*   Updated: 2017/09/06 14:03:34 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		get_type_from_area(t_vm *vm, t_process *p, unsigned int *type)
{
	int				i;
	unsigned char	ocp;
	unsigned char	bit;

	ocp = vm->area[(p->pc + 1) % MEM_SIZE];
	i = -1;
	while (++i < p->op.nb_params)
	{
		bit = (ocp >> (6 - 2 * i));
		if (bit & 1)
		{
			if ((bit >> 1) & 1)
				type[i] = T_IND;
			else
				type[i] = T_REG;
		}
		else if (bit & 2)
			type[i] = T_DIR;
		else
			type[i] = 0;
	}
}
