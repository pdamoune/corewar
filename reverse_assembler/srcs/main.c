/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:26:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/11/05 02:28:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_r.h>

static t_cliopts	g_read_opts[] =
{
	{'D', "debug", DEBUG, 0, NULL, 0},
	{'q', "quiet", QUIET, VERBOSE, NULL, 0},
	{'v', "verbose", VERBOSE, QUIET, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

int					usage(void)
{
	ft_printf("asm_r -[vqD] file ...");
	return (1);
}

static int			de_asm(t_asm_r *asm_r, char ***av)
{
	if ((cliopts_get(*av, g_read_opts, asm_r)))
		return (ft_perror("asm-r") && usage());
	if (asm_r->av_data)
	{
		while (*asm_r->av_data)
		{
			asm_r->file.filename = *asm_r->av_data;
			if (init_file(asm_r, &asm_r->file, *asm_r->av_data++))
				continue ;
			if (create_file(asm_r, &asm_r->file))
				continue ;
		}
	}
	return (0);
}

int					main(int ac, char **av)
{
	t_asm_r		asm_r;

	if (ac == 1)
		return (usage());
	ft_bzero(&asm_r, sizeof(t_asm_r));
	return (de_asm(&asm_r, &av));
}
