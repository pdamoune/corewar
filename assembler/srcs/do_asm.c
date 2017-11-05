/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:48:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/05 11:46:20 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		finalize_asm_2(t_asm *a, int fdout, int len)
{
	int			n_write;
	int			res;

	res = 0;
	if (fdout == -1)
		res = (verbose(a, MSG_ERROR, "%s: Permission denied",
		a->file.filename));
	else if (sizeof(t_header) != (n_write = write(fdout,
		&(a->file.header), sizeof(t_header))))
		res = (verbose(a, MSG_ERROR,
			"%s: Header write failed: %d on %u expected",
			a->file.filename, n_write, sizeof(t_header)));
	else if (len != (n_write = write(fdout, a->file.prog, len)))
		res = (verbose(a, MSG_ERROR,
			"%s: Program write failed: %d on %u expected",
			a->file.filename, n_write, len));
	else
		ft_printf("Writing output program to %s\n", a->file.filename);
	close(fdout);
	return (res);
}

int				finalize_asm(t_asm *a)
{
	int		fdout;
	int		len;

	len = a->file.header.prog_size;
	if (len == 0)
	{
		return (verbose(a, MSG_ERROR, "%s: No instruction in file",
		a->file.filename));
	}
	a->file.header.prog_size = bswap_32(a->file.header.prog_size);
	fdout = open(a->file.filename, O_CREAT | O_TRUNC | O_WRONLY,
		S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	return (finalize_asm_2(a, fdout, len));
}

static int		(*g_send_line_func[])() =
{
	&check_header,
	&check_header_name,
	&check_header_comment,
	&check_file_content,
};

static int		do_asm_next(t_asm *a, int ret)
{
	if (!a->file.line_number)
	{
		ret = -1;
		verbose(a, MSG_ERROR, "Le fichier %s est vide-L%d",
		a->file.filename, a->file.line_number);
	}
	if (a->file.list_unknow_label)
	{
		ret = -1;// TODO Faire la liste des labels introuves
		verbose(a, MSG_ERROR,
		"%s: Unknown label left at Line %d:", a->file.filename,
		((t_label *)a->file.list_unknow_label->content)->pos_instru);
	}
	if (!ret)
		ret = finalize_asm(a);
	free(a->file.filename);
	ft_ld_clear(&a->file.list_know_label, free_label);
	ft_ld_clear(&a->file.list_unknow_label, free_label);
	return (ret);
}

int				do_asm(t_asm *a, char *filename)
{
	int			(*f)();
	int			ret;
	char		*line;
	int			fdin;

	if (-1 == (fdin = init_asm(a, filename, &f)))
		return (1);
	while (0 < (ret = get_next_line(fdin, &line)))
	{
		verbose(a, MSG_DEBUG, "Parsing %s-L%d: [%s]",
		a->file.filename, a->file.line_number, line);
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
	close(fdin);
	return (do_asm_next(a, ret));
}
