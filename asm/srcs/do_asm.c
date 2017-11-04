/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:48:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/04 02:06:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int finalize_asm(t_asm *a)
{
	int		n_write;
	int		fdout;
	int		len;

	//TODO MAGIC REVERT FOR HEADER val
	len = a->file.header.prog_size;
	a->file.header.prog_size = bswap_32(a->file.header.prog_size);
	fdout = open(a->file.filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fdout == -1)
		return (verbose(a, MSG_ERROR, "%s: Permission denied", a->file.filename));
	if (sizeof(t_header) != (n_write = write(fdout, &(a->file.header), sizeof(t_header))))
	{
		close(fdout);
		return (verbose(a, MSG_ERROR, "%s: Header write failed: %d on %u expected", a->file.filename, n_write, sizeof(t_header)));
	}
	if (len != (n_write = write(fdout, a->file.prog, len)))
	{
		close(fdout);
		return (verbose(a, MSG_ERROR, "%s: Program write failed: %d on %u expected", a->file.filename, n_write, len));
	}
	ft_printf("Writing output program to %s\n", a->file.filename);
	close(fdout);
	return (0);
}

static				int (*g_send_line_func[])() =
{
	&check_header,
	&check_header_name,
	&check_header_comment,
	&check_file_content,
};

int					do_asm(t_asm *a, char *filename)
{
	int			(*f)();
	int			ret;
	char		*line;
	int			fdin;

	if (-1 == (fdin = init_asm(a, filename, &f)))
		return (1);
	DG();
	while (0 < (ret = get_next_line(fdin, &line)))
	{
	DG("[%s]", line);
		++a->file.line_number;
		a->file.line = line;
		if (-1 == (ret = f(a, line)))
			break ;
		if (IS_SET(a->file.flag, (HEAD_COMMENT | HEAD_NAME)))
			f = g_send_line_func[3];
		else
			f = g_send_line_func[ret];
		ft_strdel(&line);
	DG();
	}
	DG();
	//TODO ERROR MSG IF RET => ça veut dire qu'on arrive pas à get_next_line sur le fichier
	ft_strdel(&line);
	close(fdin);
	if (!ret)
		ret = check_label(a);
	if (!ret)
		ret = finalize_asm(a);
	free(a->file.filename);
	ft_ld_clear(&a->file.list_know_label, free_label);
	ft_ld_clear(&a->file.list_unknow_label, free_label);
	//TODO FREE ALL (label !) ==> ret error if label unknow not resolve
	return (ret);
}
