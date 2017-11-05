/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:13:39 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/05 12:57:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int			usage(void)
{
	ft_printf("usage: asm [-vqDc] [-e nb_error] file ...");
	return (1);
}

static int			get_error(char **opt_arg, t_asm *a, int n_args)
{
	char	**args;
	int		nb_error;

	if (!opt_arg || !a)
		return (1);
	args = opt_arg;
	if (ft_tablen(args) < n_args)
		return (verbose(a, MSG_ERROR, "Option needs more arguments", NULL));
	if (!ft_strisnumeral(args[0]))
		return (verbose(a, MSG_ERROR, "Argument must be numeral value", NULL));
	nb_error = ft_atoi(args[0]);
	if (nb_error < 0)
		return (verbose(a, MSG_ERROR, "Argument must be positive", NULL));
	a->nb_error = nb_error;
	return (0);
}

static t_cliopts	g_read_opts[] =
{
	{'D', "debug", DEBUG, 0, NULL, 0},
	{'q', "quiet", QUIET, VERBOSE, NULL, 0},
	{'v', "verbose", VERBOSE, QUIET, NULL, 0},
	{'c', "continue", CONTINUE, 0, NULL, 0},
	{'e', "error", 0, 0, get_error, 1},
	{0, 0, 0, 0, 0, 0},
};

int					main(int ac, char **av)
{
	t_asm		a;
	int			ret;
	int			ret_cumul;

	if (ac == 1)
		return (usage());
	ft_bzero(&a, sizeof(t_asm));
	a.nb_error = NB_ERROR_BY_FILE;
	if ((cliopts_get(av, g_read_opts, &a)))
		return (ft_perror("asm") && usage());
	if (!a.av_data)
		return (usage());
	ret_cumul = 0;
	while (*a.av_data)
	{
		if (!(ret = parse_asm(&a, *a.av_data++)))
			ret = check_if_file_valid(&a);
		if (!ret)
			write_file(&a);
		free_file(&a);
		ret_cumul += !(!ret);
		if (ret && IS_UNSET(a.flag, CONTINUE))
			return (ret_cumul);
	}
	return (ret_cumul);
}
