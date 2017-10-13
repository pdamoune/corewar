/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:03:55 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/13 21:55:37 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_comment_is_done(global_t *global, char *com)
{
	int i;
	int nb_quote;
	size_t k;
	int drift;

	i = 0;
	nb_quote = 0;
	drift = 0;
	while (nb_quote < 2 && drift < COMMENT_LENGTH)
	{
		while (global->s_map->line[i])
		{
			if (global->s_map->line[i] == '"')
				nb_quote++;
			if (nb_quote > 2)
				ft_exit(8, global, NULL);
			i++;
		}
		k = -1;
		while (++k <= ft_strlen(global->s_map->line))
			com[drift + k] = global->s_map->line[k];
		drift = drift + k;
		if (nb_quote == 2)
			return;
		global->s_map = global->s_map->next;
	}
}

static void ft_kind_of_header(global_t *global, char *header, int size, int error)
{
	int k;
	int i;

	i = 0;
	k = 0;
	if (global->s_label->s_content->line[1] == NULL)
		header = NULL;
	else
	{
		while (global->s_label->s_content->line[1][i])
			i++;
		if (i > size)
			ft_exit(error, global, NULL);
		while (k < i)
		{
			header[k] = global->s_label->s_content->line[1][k];
			k++;
		}
	}
}

void ft_parse_header(global_t *global)
{
	unsigned int rev;

	printf("global->total_octet %d\n", global->total_octet);
	printf("CHAMP_MAX_SIZE %d\n", CHAMP_MAX_SIZE);
	global->s_label = global->begin_label;
	if (global->total_octet > CHAMP_MAX_SIZE)
		ft_exit(7, global, NULL);
	rev = INTREV32(global->total_octet);
	ft_bzero(&global->header, sizeof(header_t));
	ft_bzero(global->res, CHAMP_MAX_SIZE + 1);
	global->header.prog_size = rev;
	while (!ft_strcmp(global->s_label->name, "HEADER"))
	{
		if (!ft_strcmp(global->s_label->s_content->line[0], NAME_CMD_STRING))
			ft_kind_of_header(global, global->header.prog_name, PROG_NAME_LENGTH, 5);
		if (!ft_strcmp(global->s_label->s_content->line[0], COMMENT_CMD_STRING))
			ft_kind_of_header(global, global->header.comment, COMMENT_LENGTH, 6);
		global->s_label = global->s_label->next;
	}
}
