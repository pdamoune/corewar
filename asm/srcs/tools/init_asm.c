/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 01:17:21 by wescande          #+#    #+#             */
/*   Updated: 2017/11/01 18:40:58 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int			check_filename(t_asm *a, char *filename)
{
	size_t		len;

	if (!(len = ft_strlen(filename)))
		return (verbose(a, MSG_ERROR, "%s: len is 0", filename));
	if (!ft_strcmp(filename + (len - 2), ".s"))
		len -= 2;
	if (!(a->file.filename = (char *)malloc(len + 5)))
		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
	ft_memcpy(a->file.filename, filename, len);
	ft_memcpy(a->file.filename + len, ".cor", 5);
	if ((a->file.fdin = open(filename, O_RDONLY)) < 0)
	{
		return (verbose(a, MSG_ERROR,
					"%s: No such file or directory, or permission denied", filename));
	}
	return (0);
}

int		init_asm(t_asm *a, char *filename, int (**f)())
{
	ft_bzero(&a->file, sizeof(t_file));
	if (check_filename(a, filename))
		return (1);
	*f = &check_header;
	
	// INIT_LIST_HEAD(&(a->file.list_know_label));
	// INIT_LIST_HEAD(&(a->file.list_unknow_label));
	return (0);
}