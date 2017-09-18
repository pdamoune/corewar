/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:03:55 by tdebarge          #+#    #+#             */
/*   Updated: 2017/09/18 17:20:19 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void ft_check_header(global_t *global)
{
    int i;
    int k;
    char name[128];

    ft_bzero(name, 128);
    i = 0;
    if (ft_strstart(global->s_map->line, NAME_CMD_STRING))
    {
        ft_putendl("NAME PICK UP\n");
        while (global->s_map->line[i])
            i++;
        if (i > 134)
            ft_exit(5, global, NULL);
        else
        {
            k = 0;
            while (k < i - 5)
            {
                name[k] = (ft_strdup(ft_strstart(global->s_map->line, NAME_CMD_STRING)))[k + 1];
                k++;
            }
            printf("NAME === %s\n", name);
            ft_write(global, name, 128);
        }
    }
}

void ft_check_header_bis(global_t *global)
{
    char comment[2048];
    int k;
    int i;

    k = 0;
    i = 0;
    ft_bzero(comment, 2048);
    while (!ft_strcmp(global->s_label->name, "HEADER"))
    {
        if (!ft_strcmp(global->s_label->s_content->line[0], NAME_CMD_STRING))
        {
            ft_putendl(global->s_label->s_content->line[1]);
            global->s_label = global->s_label->next;
        }
        if (!ft_strcmp(global->s_label->s_content->line[0], COMMENT_CMD_STRING))
        {
            global->fdOut = open("42.cor", O_WRONLY | O_APPEND, 0666);
            write(global->fdOut, &(global->total_octet), 4);
            ft_putendl(global->s_label->s_content->line[1]);
            while (global->s_label->s_content->line[1][i])
                i++;
            if (i > 2048)
                ft_exit(6, global, NULL);
            while (k < i)
            {
                comment[k] = global->s_label->s_content->line[1][k];
                k++;
            }
            ft_write(global, comment, 2048);
        }
        global->s_label = global->s_label->next;
    }
}