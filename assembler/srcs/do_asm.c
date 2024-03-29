/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:48:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/05 13:30:07 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				write_file(t_asm *a)
{
	int		fdout;
	int		len;
	int		res;
	int		n_write;

	if (!(len = a->file.header.prog_size))
		verbose(a, MSG_WARNING, "%s: No instruction in file", a->file.filename);
	a->file.header.prog_size = bswap_32(a->file.header.prog_size);
	fdout = open(a->file.filename, O_CREAT | O_TRUNC | O_WRONLY,
		S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	res = 0;
	if (fdout == -1)
		res = (verbose(a, 4, "%s: Permission denied", a->file.filename));
	else if (sizeof(t_header) != (n_write = write(fdout,
		&(a->file.header), sizeof(t_header))))
		res = (verbose(a, 4, "%s: Header write failed: %d on %u expected",
			a->file.filename, n_write, sizeof(t_header)));
	else if (len != (n_write = write(fdout, a->file.prog, len)))
		res = (verbose(a, 4, "%s: Program write failed: %d on %u expected",
			a->file.filename, n_write, len));
	else
		ft_printf("Writing output program to %s\n", a->file.filename);
	close(fdout);
	return (res);
}

int				check_if_file_valid(t_asm *a)
{
	t_ld	*cur;

	if (!(IS_SET(a->file.flag, (HEAD_COMMENT | HEAD_NAME))))
		return (verbose(a, MSG_ERROR, "%s: Invalid header", a->file.filename));
	if (!a->file.line_number)
		return (verbose(a, MSG_ERROR, "%s: file is empty", a->file.filename));
	if ((cur = a->file.list_unknow_label))
	{
		verbose(a, MSG_ERROR, cur->next ?
				"%s: Unknown labels left:" : "%s: Unknown label left:",
				a->file.filename);
		while (cur)
		{
			ft_printf("\t{red}%s{eoc}\n", ((t_label *)cur->content)->label);
			cur = cur->next;
		}
		return (-1);
	}
	return (0);
}

static int		(*g_send_line_func[])() =
{
	&check_header,
	&check_header_name,
	&check_header_comment,
	&check_file_content,
};

int				parse_asm(t_asm *a, char *filename)
{
	int			(*f)();
	int			ret;
	char		*line;
	int			fdin;

	if (-1 == (fdin = init_asm(a, filename, &f)))
		return (1);
	while (0 < (ret = get_next_line(fdin, &line)))
	{
		verbose(a, MSG_DEBUG, "Parsing %s-L%d:\n[%s]",
		a->file.filename, a->file.line_number, line);
		++a->file.line_number;
		a->file.line = line;
		if (-1 == (ret = f(a, line)) && (!--a->file.nb_error
					|| a->file.flag & LEN_ERROR || f != check_file_content))
			break ;
		if (IS_SET(a->file.flag, (HEAD_COMMENT | HEAD_NAME)))
			f = g_send_line_func[3];
		else
			f = g_send_line_func[ret];
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fdin);
	return (ret || a->file.nb_error != a->nb_error);
}
