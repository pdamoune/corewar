/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/05 11:08:19 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			replace_label(t_asm *a, t_label *label, t_ld **target)
{
	t_label		*unknown_label;
	const t_op	*cur_instru;
	t_argument	arg;
	int			pos;

	unknown_label = (t_label*)(*target)->content;
	cur_instru = find_cur_instru(
		(uint8_t)(a->file.prog[unknown_label->pos_instru]));
	arg.type = T_DIR;
	if (cur_instru->ocp)
		arg.type = calcul_type_from_ocp(
		a->file.prog[unknown_label->pos_instru + 1], unknown_label->pos_label);
	pos = unknown_label->pos_instru +
	calcul_instruction_len(cur_instru->ocp,
		a->file.prog[unknown_label->pos_instru + 1],
		unknown_label->pos_label, cur_instru->index);
	arg.value.dir = label->pos_label - unknown_label->pos_instru;
	stock_argument(a, pos, &arg, cur_instru->index);
	remove_label(target);
}
