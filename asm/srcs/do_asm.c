/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:48:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/26 14:07:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					usage(void)
{
	ft_printf("usage: asm [-vqD] file ...");
	return (1);
}

static int			check_filename(t_asm *a, char *filename)
{
	size_t		len;

	if (!(len = ft_strlen(filename)))
		return (verbose(a, MSG_ERROR, "%s: len is 0", filename));
	if (!ft_strcmp(filename + (len - 2), ".s"))
	{
		if (!(a->file.filename = (char *)malloc(len + 3)))
			return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
		ft_memcpy(a->file.filename, filename, len - 2);
		ft_memcpy(a->file.filename + len - 2, ".cor", 5);
	}
	else
	{
		if (!(a->file.filename = (char *)malloc(len + 5)))
			return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
		ft_memcpy(a->file.filename, filename, len);
		ft_memcpy(a->file.filename + len, ".cor", 5);
	}
	if ((a->file.fdin = open(filename, O_RDONLY)) < 0)
	{
		return (verbose(a, MSG_ERROR,
					"%s: No such file or directory", filename));
	}
	return (0);
}

const static t_itof g_send_line_func[] =
{
	{1, &check_header},
	{2, &check_header_name},
	{3, &check_header_comment},
};

static int			launch_asm(t_asm *a)
{
	t_global	*global;

	global = &a->file.global;
	global->header = a->file.header;
	global->fdin = a->file.fdin;
	ft_read(global);
	ft_open(global, a->file.filename);
	if (!global->header.prog_size)
		verbose(a, MSG_WARNING, "Champion is empty", NULL);
	write(global->fdout, global->res, global->total_octet);
	close(global->fdin);
	ft_printf("Writing output program to %s\n", a->file.filename);
	ft_free_map(global);
	ft_free_global(global);
	free(a->file.filename);
	return (0);
}

static int			do_asm_norme(t_asm *a, char *line)
{
	ft_strdel(&line);
	verbose(a, MSG_ERROR, "Invalid header", NULL);
	return (1);
}

int					do_asm(t_asm *a, char *filename)
{
	int			(*f)();
	int			ret;
	char		*line;

	ft_bzero(&a->file, sizeof(t_file));
	if (check_filename(a, filename))
		return (1);
	f = &check_header;
	while (get_next_line(a->file.fdin, &line) > 0)
	{
		if ((ret = f(a, line)) == -1)
			return (do_asm_norme(a, line));
		ft_strdel(&line);
		if (!ret && IS_SET(a->file.flag, (HEAD_COMMENT | HEAD_NAME)))
			break ;
		if (ret)
			f = g_send_line_func[ret - 1].f;
		else
			f = &check_header;
	}
	ft_strdel(&line);
	if (IS_UNSET(a->file.flag, (HEAD_COMMENT | HEAD_NAME)))
		return (verbose(a, MSG_ERROR, "%s: Invalid file", filename));
	return (launch_asm(a));
}
