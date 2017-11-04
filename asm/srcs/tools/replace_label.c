/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/04 16:33:18 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

extern t_op		g_op_tab[];

static t_op			*find_cur_instru(uint8_t pos)
{
	if (!pos  || pos > 16)
		return (NULL); //error on sait pas coder
	return (&g_op_tab[pos - 1]);
	// i = -1;
	// while (++i < 16)
	// 	if (pos == g_op_tab[i].op_code)
	// 		return ((t_op *)&g_op_tab[i]);
	// return (NULL);
}

void			replace_label(t_asm *a, t_label *label, t_ld **target)
{
	t_label		*unknown_label;
	t_op		*cur_instru;
	t_argument	arg;
	int			pos;

	unknown_label = (t_label*)(*target)->content;
	cur_instru = find_cur_instru((uint8_t)(a->file.prog[unknown_label->pos_instru]));
	arg.type = T_DIR;
	if (cur_instru->ocp)
		arg.type = calcul_type_from_ocp(a->file.prog[unknown_label->pos_instru + 1], unknown_label->pos_label);
	pos = unknown_label->pos_instru + calcul_instruction_len(cur_instru->ocp, a->file.prog[unknown_label->pos_instru + 1], unknown_label->pos_label, cur_instru->index);
	arg.value.dir = label->pos_label - unknown_label->pos_instru;
	DG("replacing [%s], with value : %d | %hd", unknown_label->label, arg.value.dir, arg.value.dir);
	stock_argument(a, pos, &arg, cur_instru->index);
	
	remove_label(target);
	// t_ld		*unknow_label;
	// t_op		*cur_instru;
	// t_argument	*arg;
	// uint16_t	pos;

	// unknow_label = ft_ld_front(a->file.list_unknow_label);
	// arg->type = find_ocp(cur_instru, &a->file.prog[label->pos_instru + 1], label->pos_label);
	// arg->value.dir = ((t_label *)(*target)->content)->pos_label;
	// arg->label = label;
	//TODO pos = determine la position a laquelle ecrire le label
	// while (unknow_label)
	// {
	// 	if (ft_strcmp(((t_label *)(*unknow_label).content)->label,
	// 		((t_label *)(*target)->content)->label))
	// 	unknow_label = (unknow_label)->next;
	// }
	/* DG("target ptr is %p", target); */
	/* DG("target *ptr is %p", *target); */
	/* t_label *label = (*target)->content; */
	/* DG("gonna be free %s at pos %d-%d", label->label, label->pos_instru, label->pos_label); */
}
