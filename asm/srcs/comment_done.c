/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment_done.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:13:08 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:40:23 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		ft_line_no_spa(char *line)
{
	int			i;

	i = 0;
	while (ft_isspa(line[i]))
	{
		i++;
	}
	return (i);
}

static int		ft_c3(t_global *global, char *com, char *f_quote, int k)
{
	int			i;
	int			len;
	char		*l_quote;

	i = 0;
	if ((l_quote = ft_strchr(f_quote + 1, '"')))
	{
		len = (int)(l_quote - f_quote);
		if (len > COMMENT_LENGTH + 1)
			ft_exit(6, global, NULL);
		while (i < (int)ft_strlen(global->s_map->line) - k)
		{
			com[i] = global->s_map->line[i + k];
			i++;
		}
		com[i] = '\0';
		return (0);
	}
	return (1);
}

static int		ft_c2(t_global *global, char *com)
{
	int			i;
	int			k;
	int			len;
	char		*f_quote;

	i = 0;
	k = ft_line_no_spa(global->s_map->line);
	f_quote = ft_strchr(global->s_map->line, '"');
	if (!ft_c3(global, com, f_quote, k))
		return (-1);
	len = ft_strlen(f_quote) - 1;
	if (len > COMMENT_LENGTH + 1)
		ft_exit(6, global, NULL);
	while (i < (int)ft_strlen(global->s_map->line) - k)
	{
		com[i] = global->s_map->line[i + k];
		i++;
	}
	com[i] = '\n';
	i++;
	global->s_map = global->s_map->next;
	return (i);
}

static void		ft_c4(t_global *global, char *com, int i)
{
	int			m;
	int			k;
	int			len;

	m = (int)(ft_strchr(global->s_map->line, '"') - global->s_map->line);
	len = i + m;
	k = 0;
	while (k < m && i < len)
	{
		com[i] = global->s_map->line[k];
		i++;
		k++;
	}
	com[i] = '\0';
}

void			ft_comment_is_done(t_global *global, char *com)
{
	int			len;
	int			i;
	int			k;

	i = ft_c2(global, com);
	if (i == -1)
		return ;
	while (!ft_strchr(global->s_map->line, '"'))
	{
		k = 0;
		len = i + ft_strlen(global->s_map->line);
		while (k < (int)ft_strlen(global->s_map->line) && i < len)
		{
			com[i] = global->s_map->line[k];
			i++;
			k++;
		}
		com[i] = '\n';
		i++;
		global->s_map = global->s_map->next;
	}
	ft_c4(global, com, i);
}
