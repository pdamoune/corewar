/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_arg_and_instru.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:09:59 by wescande          #+#    #+#             */
/*   Updated: 2017/11/04 18:54:00 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			stock_argument(t_asm *a, uint16_t pos,
	t_argument *arg, uint8_t index)
{
	if (IS_SET(arg->type, T_REG))
	{
		a->file.prog[pos] = arg->value.reg;
		return (1);
	}
	if (IS_SET(arg->type, T_DIR))
	{
		if (index)
		{
			*(uint16_t *)&a->file.prog[pos] = bswap_16(arg->value.index_dir);
			return (2);
		}
		*(uint32_t *)&a->file.prog[pos] = bswap_32(arg->value.dir);
		return (4);
	}
	if (IS_SET(arg->type, T_IND))
	{
		*(uint16_t *)&a->file.prog[pos] = bswap_16(arg->value.ind);
		return (2);
	}
	DG("I AM FUCKING BOLOSS BECAUSE THIS IS NOT A POSSIBLE END !!!!!");
	//TODO remove the last if to return him
	return (-2147483645);
}

int			stock_instruction(t_asm *a,
	const t_op *cur_instru, t_argument *parsed_args, uint8_t ocp)
{
	int			i;

	a->file.prog[PROG_SIZE++] = cur_instru->op_code;
	if (cur_instru->ocp)
		a->file.prog[PROG_SIZE++] = ocp;
	i = -1;
	while (++i < cur_instru->nb_params)
	{
		PROG_SIZE += stock_argument(a, PROG_SIZE,
			&parsed_args[i], cur_instru->index);
	}
	return (0);
}
