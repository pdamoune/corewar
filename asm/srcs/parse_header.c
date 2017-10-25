/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:03:55 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:55:46 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void		ft_kind_of_header(t_global *global,
			char *header, int size, int error)
{
	int k;
	int i;

	i = 0;
	k = 0;
	if (G_L_C->line[1] == NULL)
		header = NULL;
	else
	{
		while (G_L_C->line[1][i])
			i++;
		if (i > size)
			ft_exit(error, global, NULL);
		while (k < i)
		{
			header[k] = G_L_C->line[1][k];
			k++;
		}
	}
}

void			ft_parse_header(t_global *global)
{
	unsigned int	rev;

	global->s_label = global->begin_label;
	if (global->total_octet > (MEM_SIZE / 3))
		ft_exit(7, global, NULL);
	if (global->total_octet > CHAMP_MAX_SIZE)
		ft_putendl("Warning, champion too heavy to fit in the arena.");
	rev = bswap_32(global->total_octet);
	ft_bzero(global->res, CHAMP_MAX_SIZE + CHAMP_MAX_SIZE + 1);
	global->header.prog_size = rev;
	while (!ft_strcmp(global->s_label->name, "HEADER"))
	{
		if (!ft_strcmp(G_L_C->line[0],
			NAME_CMD_STRING))
			ft_kind_of_header(global, global->header.prog_name,
				PROG_NAME_LENGTH, 5);
		if (!ft_strcmp(G_L_C->line[0],
			COMMENT_CMD_STRING))
			ft_kind_of_header(global, global->header.comment,
				COMMENT_LENGTH, 6);
		global->s_label = global->s_label->next;
	}
}
