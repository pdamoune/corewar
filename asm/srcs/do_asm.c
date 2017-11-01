/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:48:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/01 17:54:28 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int finalize_asm(t_asm *a)
{
	int		n_write;
	int		fdout;

	//TODO MAGIC REVERT FOR HEADER val
	fdout = open(a->file.filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fdout == -1)
		return (verbose(a, MSG_ERROR, "%s: Permission denied", a->file.filename));
	if (sizeof(t_header) != (n_write = write(fdout, &(a->file.header), sizeof(t_header))))
	{
		close(fdout);
		return (verbose(a, MSG_ERROR, "%s: Header write failed: %d on %u expected", a->file.filename, n_write, sizeof(t_header)));
	}
	if ((int)a->file.header.prog_size != (n_write = write(fdout, a->file.prog, a->file.header.prog_size)))
	{
		close(fdout);
		return (verbose(a, MSG_ERROR, "%s: Program write failed: %d on %u expected", a->file.filename, n_write, a->file.header.prog_size));
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

	if (init_asm(a, filename, &f))
		return (1);
	while (0 < (ret = get_next_line(a->file.fdin, &line)))
	{
		++a->file.line_number;
		a->file.line = line;
		if (-1 == (ret = f(a, line)))
			break ;
		if (IS_SET(a->file.flag, (HEAD_COMMENT | HEAD_NAME)))
			f = g_send_line_func[3];
		else
			f = g_send_line_func[ret];
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(a->file.fdin);
	if (!ret)
		ret = check_label(a);
	if (!ret)
		ret = finalize_asm(a);
	free(a->file.filename);
	//TODO FREE ALL (label !) ==> ret error if label unknow not resolve
	return (ret);

	// if (IS_UNSET(a->file.flag, (HEAD_COMMENT | HEAD_NAME)))
	// 	return (verbose(a, MSG_ERROR, "%s: Invalid file", filename));
	// return (launch_asm(a));
}
