/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:48:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/01 11:47:23 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

// int					usage(void)
// {
// 	ft_printf("usage: asm [-vqDc] file ...");
// 	return (1);
// }

// static int			check_filename(t_asm *a, char *filename)
// {
// 	size_t		len;

// 	if (!(len = ft_strlen(filename)))
// 		return (verbose(a, MSG_ERROR, "%s: len is 0", filename));
// 	if (!ft_strcmp(filename + (len - 2), ".s"))
// 	// {
// 		len -= 2;
// 	// 	if (!(a->file.filename = (char *)malloc(len + 3)))
// 	// 		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
// 	// 	ft_memcpy(a->file.filename, filename, len - 2);
// 	// 	ft_memcpy(a->file.filename + len - 2, ".cor", 5);
// 	// }
// 	// else
// 	// {
// 		if (!(a->file.filename = (char *)malloc(len + 5)))
// 			return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
// 		ft_memcpy(a->file.filename, filename, len);
// 		ft_memcpy(a->file.filename + len, ".cor", 5);
// 	// }
// 	if ((a->file.fdin = open(filename, O_RDONLY)) < 0)
// 	{
// 		return (verbose(a, MSG_ERROR,
// 					"%s: No such file or directory", filename));
// 	}
// 	return (0);
// }

// static int			launch_asm(t_asm *a)
// {
// 	t_global	*global;

// 	global = &a->file.global;
// 	global->header = a->file.header;
// 	global->fdin = a->file.fdin;
// 	ft_read(global);
// 	ft_open(global, a->file.filename);
// 	if (!global->header.prog_size)
// 		verbose(a, MSG_WARNING, "Champion is empty", NULL);
// 	write(global->fdout, global->res, global->total_octet);
// 	close(global->fdin);
// 	ft_printf("Writing output program to %s\n", a->file.filename);
// 	ft_free_map(global);
// 	ft_free_global(global);
// 	free(a->file.filename);
// 	return (0);
// }

int finalize_asm(t_asm *a)
{
	int		n_write;
	int		fdout;

	//TODO MAGIC REVERT FOR HEADER val
	fdout = open(a->file.filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fdout == -1)
		return (verbose(a, MSG_ERROR, "%s: Permission denied", a->file.filename));
	if (sizeof(t_header) != (n_write = write(fdout, a->file.header, sizeof(t_header))))
	{
		close(fdout);
		return (verbose(a, MSG_ERROR, "%s: Header write failed: %d on %u expected", a->file.filename, n_write, sizeof(t_header)));
	}
	if (a->file.header.prog_size != (n_write = write(fdout, a->file.prog, a->file.header.prog_size)))
	{
		close(fdout);
		return (verbose(a, MSG_ERROR, "%s: Program write failed: %d on %u expected", a->file.filename, n_write, a->file.header.prog_size));
	}
	ft_printf("Writing output program to %s\n", a->file.filename);
	close(fdout);
	return (0);
}

// int					dispatch_line(t_asm *a, int (*f)(), char *line)
// {
// 	int ret;

// 	if (-1 == (ret = f(a, line)))
// 		return (ret);
// }


static const int (*g_send_line_func[])() =
{
	&check_header,
	&check_header_name,
	&check_header_comment},
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
