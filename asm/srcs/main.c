/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:13:39 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/01 15:38:19 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					usage(void)
{
	ft_printf("usage: asm [-vqDc] file ...");
	return (1);
}

static t_cliopts	g_read_opts[] =
{
	{'D', "debug", DEBUG, 0, NULL, 0},
	{'q', "quiet", QUIET, VERBOSE, NULL, 0},
	{'v', "verbose", VERBOSE, QUIET, NULL, 0},
	{'c', "continue", CONTINUE, 0, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

int					main(int ac, char **av)
{
	t_asm		a;
	int			ret;

	if (ac == 1)
		return (usage());
	ft_bzero(&a, sizeof(t_asm));
	if ((cliopts_get(av, g_read_opts, &a)))
		return (ft_perror("asm") && usage());
	if (!a.av_data)
		return (usage());
	ret = 0;
	while (*a.av_data)
	{
		ret += do_asm(&a, *a.av_data++);
		if (ret && IS_UNSET(a.flag, CONTINUE))
			return (ret);
	}
	return (ret);
}
