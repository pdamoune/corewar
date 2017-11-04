/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/04 02:02:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			find_ocp(t_op *cur_instru, char *ocp, uint8_t pos_label)
{
	if (!cur_instru->ocp)
		return(0);
	ocp += 2*pos_label;
	if (*ocp == '1' && ++ocp && *ocp == '1')
		return (T_DIR);
	else if (*ocp == '1' && ++ocp && *ocp == '0')
		return (T_IND);
	else if (*ocp == '0' && ++ocp && *ocp == '1')
		return (T_REG)
	return (0);
}

static t_op			*find_cur_instru(uint8_t pos)
{
	int		i;

	i = -1;
	while (++i < 16)
		if (pos == g_op_tab[i].op_code)
			return ((t_op *)&g_op_tab[i]);
	return (NULL);
}

void			replace_label(t_asm *a, t_label *label, t_ld **target)
{
	td			*unknow_label;
	t_op		*cur_instru;
	t_argument	*arg[1];
	uint16_t	pos;

	unknow_label = ft_ld_front(a->file.list_unknow_label);
	cur_instru = find_cur_instru((uint8_t)(a->file.prog[label->pos_instru]));
	arg->type = find_ocp(cur_instru, a->file.prog[label->pos_instru + 1], label->pos_label);
	arg->value = ((t_label *)(*target)->content)->label;
	arg->label = label;
	//TODO pos = determine la position a laquelle ecrire le label
	while (unknow_label)
	{
		if (ft_strcmp(((t_label *)(*unknow_label)->content)->label,
			((t_label *)(*target)->content)->label))
			pos += stock_argument(a, pos, arg, cur_instru->index);
		unknow_label = (unknow_label)->next;
	}
	/* DG("target ptr is %p", target); */
	/* DG("target *ptr is %p", *target); */
	/* t_label *label = (*target)->content; */
	/* DG("gonna be free %s at pos %d-%d", label->label, label->pos_instru, label->pos_label); */
	remove_label(target);
}
