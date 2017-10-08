/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:03:55 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/08 17:52:40 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void ft_check_header_bis(global_t *global)
{
    int          k;
    int          i;
    unsigned int rev;
    header_t     *header;

    header = NULL;
    k = 0;
    i = 0;
    rev = INTREV32(global->total_octet);
    ft_initialize_header(&header);
    global->header = header;
    global->header->prog_size = rev;
    global->str_till_now = ft_memalloc(global->total_octet);

    while (!ft_strcmp(global->s_label->name, "HEADER"))
    {
        if (!ft_strcmp(global->s_label->s_content->line[0], NAME_CMD_STRING))
        {
            i = 0;
            k = 0;
            while (global->s_label->s_content->line[1][i])
                i++;
            if (i > PROG_NAME_LENGTH)
               ft_exit(5, global, NULL);
            while (k < i)
            {
               global->header->prog_name[k] = global->s_label->s_content->line[1][k];
               k++;
            } 
        }
        if (!ft_strcmp(global->s_label->s_content->line[0], COMMENT_CMD_STRING))
        {
            i = 0;
            k = 0;
            while (global->s_label->s_content->line[1][i])
                i++;
            if (i > COMMENT_LENGTH)
                ft_exit(6, global, NULL);
            while (k < i)
            {
                global->header->comment[k] = global->s_label->s_content->line[1][k];
                k++;
            }
        }
        global->s_label = global->s_label->next;
    }
}

void    ft_str_is_header(global_t *global)
{
    global->str_header = ft_memalloc(2188);
    ft_memcpy(global->str_header, global->header->prog_name, 128);
    ft_memcpy(global->str_header + 128, "\0\0\0\0", 4);
    ft_memcpy(global->str_header + 132, &global->header->prog_size, 4);
    ft_memcpy(global->str_header + 136, global->header->comment, 2048);
    ft_memcpy(global->str_header + 2184, "\0\0\0\0", 4);
}