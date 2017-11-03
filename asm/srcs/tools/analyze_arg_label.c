/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/02 19:07:01 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				analyze_arg_label(t_asm *a, char *arg,
			t_argument *parsed_args, char *end_of_label)
{
	t_ld		**found;
	t_label		*label;

	*end_of_label = 0;
	DG("ARG= %s", arg);
	if ((found = find_label(&a->file.list_know_label, arg)))
	{
		parsed_args->value.dir = ((t_label *)(*found)->content)->pos_label;
		return (0);
	}
	parsed_args->type |= T_LAB;
	if (!(label = (t_label *)malloc(sizeof(t_label))))
		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
	label->label = ft_strdup(arg);
	label->pos_label = -42;
	label->pos_instru = a->file.header.prog_size;
	parsed_args->label = label;
	return(1);
}
