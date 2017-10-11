/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:03:55 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/11 13:57:29 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static void	ft_kind_of_header(global_t *global, char *header, int size, int error)
{
	int          k;
	int          i;

	i = 0;
	k = 0;
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

void	ft_parse_header(global_t *global)
{
    unsigned int rev;

	printf("global->total_octet %d\n", global->total_octet);
	printf("CHAMP_MAX_SIZE %d\n", CHAMP_MAX_SIZE);
	global->s_label = global->begin_label;
    if (global->total_octet > CHAMP_MAX_SIZE)
        printf(" WARNING your champ size (%d) > CHAMP_MAX_SIZE(%d)\n", global->total_octet, CHAMP_MAX_SIZE);
    rev = INTREV32(global->total_octet);
    ft_bzero(&global->header, sizeof(header_t));
    ft_bzero(global->res, CHAMP_MAX_SIZE + 1);
    global->header.prog_size = rev;
    while (!ft_strcmp(global->s_label->name, "HEADER"))
    {
		if (!ft_strcmp(global->s_label->s_content->line[0], NAME_CMD_STRING))
			ft_kind_of_header(global, global->header.prog_name,PROG_NAME_LENGTH, 5);
        if (!ft_strcmp(global->s_label->s_content->line[0], COMMENT_CMD_STRING))
			ft_kind_of_header(global, global->header.comment,COMMENT_LENGTH, 6);
        global->s_label = global->s_label->next;
    }
}
