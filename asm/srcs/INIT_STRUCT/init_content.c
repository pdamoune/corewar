/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:26:50 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/16 16:48:19 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		ft_initialize_content(content_t **content, char *line)
{
	char **tab1;
	char **tab2;

	tab1 = NULL;
	tab2 = NULL;
	if (!(*content = (content_t*)malloc(sizeof(content_t))))
		return ;
	tab1 = ft_strsplit_cmt(ft_strdup_asm(line));
	if (ft_strlen_tab(tab1) > 1)
		tab2 = ft_strsplit_virg(tab1[0]);
	else
		tab2 = ft_strsplit_virg(ft_strdup_asm(line));
	(*content)->line = ft_split_tab(tab2);
	(*content)->nb_octet = 0;
	(*content)->begin_octet = 0;
	(*content)->next = NULL;
	(*content)->instruction = NULL;
	(*content)->previous = NULL;
}

void		ft_initialize_content_header(content_t **content, char *line)
{
	char	**tmp;

	tmp = ft_strsplit(line, '"');
	if (!(*content = (content_t*)malloc(sizeof(content_t))))
		return ;
	if (!((*content)->line = (char**)malloc(sizeof(char*) * 3)))
		return ;
	(*content)->line[0] = ft_strdup(".comment");
	if (tmp[1] == NULL)
		(*content)->line[1] = NULL;
	else
		(*content)->line[1] = ft_strdup(tmp[1]);
	(*content)->line[2] = NULL;
	(*content)->nb_octet = 0;
	(*content)->begin_octet = 0;
	(*content)->next = NULL;
	(*content)->instruction = NULL;
	(*content)->previous = NULL;
}

void		ft_initialize_content_name(content_t **content, char *line)
{
	char	**tmp;

	tmp = ft_strsplit(line, '"');
	if (!(*content = (content_t*)malloc(sizeof(content_t))))
		return ;
	if (!((*content)->line = (char**)malloc(sizeof(char*) * 3)))
		return ;
	(*content)->line[0] = ft_strdup(".name");
	(*content)->line[1] = ft_strdup(tmp[1]);
	(*content)->line[2] = NULL;
	(*content)->nb_octet = 0;
	(*content)->begin_octet = 0;
	(*content)->next = NULL;
	(*content)->instruction = NULL;
	(*content)->previous = NULL;
}

/*
**  STOCKE CHAQUE LINE DANS LA STRUCT CONTENT
*/

void		ft_stock_content(global_t *global, char *line)
{
	content_t	*new;
	content_t	*previous;

	new = NULL;
	previous = NULL;
	if (!line)
		ft_initialize_content_null(&new, NULL);
	if (!ft_strncmp(line, ".comment", 8))
		ft_initialize_content_header(&new, line);
	else if (!ft_strncmp(line, ".name", 5))
		ft_initialize_content_name(&new, line);
	else
		ft_initialize_content(&new, line);
	if (!global->s_label->begin_content)
		global->s_label->begin_content = new;
	else
	{
		previous = global->s_label->s_content;
		new->previous = previous;
		previous->next = new;
	}
	global->s_label->s_content = new;
}

void		ft_initialize_content_null(content_t **content, char *line)
{
	(*content)->line = &line;
	(*content)->nb_octet = 0;
	(*content)->begin_octet = 0;
	(*content)->next = NULL;
	(*content)->instruction = NULL;
	(*content)->previous = NULL;
}
