/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:03:55 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/19 19:22:54 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static int		ft_c_i_d_2(t_global *global, char *com)
{
	int			i;
	int			len;
	char		*f_quote;
	char		*l_quote;

	DG("%s", global->s_map->line);
	i = 0;
	f_quote = ft_strchr(global->s_map->line, '"');
	if ((l_quote = ft_strchr(f_quote + 1, '"')))
	{
		len = (int)(l_quote - f_quote);
		if (len > COMMENT_LENGTH)
			ft_exit(6, global, NULL);
		while (i++ < len - 1)
			com[i] = f_quote[i];
		com[i] = '\0';
		return (-1);
	}
	len = ft_strlen(f_quote);
	if (len > COMMENT_LENGTH)
		ft_exit(6, global, NULL);
	while (i++ < len)
		com[i] = f_quote[i];
	global->s_map = global->s_map->next;
	return (len);
}

void			ft_comment_is_done(t_global *global, char *com)
{
	int			len;
	int			i;
	int			k;

	i = ft_c_i_d_2(global, com);
	DG("%s", com);
	if (i == -1)
		return ;
	while (!ft_strchr(global->s_map->line, '"'))
	{
		k = 0;
		len = i + ft_strlen(global->s_map->line);
		if (len > COMMENT_LENGTH)
			ft_exit(6, global, NULL);
		while (i++ < len)
			com[i] = global->s_map->line[k++];
		global->s_map = global->s_map->next;
		DG("%s", com);
	}
	DG("%s", global->s_map->line);
	k = 0;
	len = i + (int)(ft_strchr(global->s_map->line, '"') - global->s_map->line);
	if (len > COMMENT_LENGTH)
		ft_exit(6, global, NULL);
	while (i++ < len)
		com[i] = global->s_map->line[k++];
	com[i] = '\0';
	DG("%s", com);
}
/*	int		i;
	int		nb_quote;
	size_t	k;
	int		drift;

	nb_quote = 0;
	drift = 0;
	while (nb_quote < 2 && drift < COMMENT_LENGTH)
	{
		i = 0;
		while (global->s_map->line[i++])
		{
			if (global->s_map->line[i] == '"')
				nb_quote++;
			if (nb_quote > 2)
				ft_exit(8, global, NULL);
		}
		k = -1;
		while (++k <= ft_strlen(global->s_map->line))
			com[drift + k] = global->s_map->line[k];
		drift = drift + k;
		if (nb_quote == 2)
			return ;
		global->s_map = global->s_map->next;
	}
}
*/
static void		ft_kind_of_header(t_global *global,
			char *header, int size, int error)
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

void			ft_parse_header(t_global *global)
{
	unsigned int	rev;

	global->s_label = global->begin_label;
	if (global->total_octet > (MEM_SIZE / 3))
		ft_exit(7, global, NULL);
	if (global->total_octet > CHAMP_MAX_SIZE)
		ft_putendl("Warning, champion too heavy to fit in the arena.");
	rev = INTREV32(global->total_octet);
	ft_bzero(&global->header, sizeof(t_header));
	ft_bzero(global->res, CHAMP_MAX_SIZE + CHAMP_MAX_SIZE + 1);
	global->header.prog_size = rev;
	while (!ft_strcmp(global->s_label->name, "HEADER"))
	{
		if (!ft_strcmp(global->s_label->s_content->line[0],
			NAME_CMD_STRING))
			ft_kind_of_header(global, global->header.prog_name,
				PROG_NAME_LENGTH, 5);
		if (!ft_strcmp(global->s_label->s_content->line[0],
			COMMENT_CMD_STRING))
			ft_kind_of_header(global, global->header.comment,
				COMMENT_LENGTH, 6);
		global->s_label = global->s_label->next;
	}
}
