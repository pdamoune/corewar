/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:03:55 by tdebarge          #+#    #+#             */
/*   Updated: 2017/09/25 16:13:45 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void ft_check_header(global_t *global)
{
    int     i;
    int     k;
    char    **tmp;
    char    name[PROG_NAME_LENGTH];

    k = 0;
    if (ft_strstart(global->s_map->line, NAME_CMD_STRING))
    {
        tmp = ft_strsplit(global->s_map->line, '"');
        ft_putendl("NAME PICK UP\n");
        i = ft_strlen(tmp[1]);
        if (i > PROG_NAME_LENGTH)
            ft_exit(5, global, NULL);
        else
        {
            while (k < i)
            {
                name[k] = tmp[1][k];
                k++;
            }
            while (k < PROG_NAME_LENGTH)
            {
                name[k] = '\0';
                k++;
            }
            ft_write(global, name, PROG_NAME_LENGTH);
            printf("NAME === %s\n", name);
        }
        /*free(tmp);*/
    }
}

void ft_check_header_bis(global_t *global)
{
    char    comment[COMMENT_LENGTH];
    int     k;
    int     i;
    int     rev;

    k = 0;
    i = 0;
    rev = INTREV32((global->total_octet - 1));
    ft_bzero(comment, COMMENT_LENGTH);
    while (!ft_strcmp(global->s_label->name, "HEADER"))
    {
        if (!ft_strcmp(global->s_label->s_content->line[0], NAME_CMD_STRING))
        {
            ft_putendl(global->s_label->s_content->line[1]);
            global->s_label = global->s_label->next;
        }
        if (!ft_strcmp(global->s_label->s_content->line[0], COMMENT_CMD_STRING))
        {
            ft_write(global, "\0\0\0\0", 4);
            global->fdOut = open("42.cor", O_WRONLY | O_APPEND, 0666);
            write(global->fdOut, &rev, 4);
            while (global->s_label->s_content->line[1][i])
                i++;
            if (i > COMMENT_LENGTH)
                ft_exit(6, global, NULL);
            while (k < i)
            {
                comment[k] = global->s_label->s_content->line[1][k];
                k++;
            }
            ft_write(global, comment, COMMENT_LENGTH);
        }
        global->s_label = global->s_label->next;
    }
}