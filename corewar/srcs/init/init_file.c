/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 11:53:01 by wescande          #+#    #+#             */
/*   Updated: 2017/10/24 11:31:51 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		get_empty_file(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
		if (!vm->file[i].is_used)
			return (i);
	return (-1);
}

int				init_file(t_vm *vm, int num, char *filename)
{
	t_file		*file;
	int			fd;

	if (num == -1 && (num = get_empty_file(vm)) == -1)
		return (verbose(vm, MSG_ERROR, "max player is %d", MAX_PLAYERS));
	file = &(vm->file[num]);
	if (file->is_used++)
	{
		return (verbose(vm, MSG_ERROR, "player number already used: %d",
				num + 1));
	}
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		return (verbose(vm, MSG_ERROR, "{yel}%s:{red} %s",
				filename, strerror(errno)));
	}
	if (init_data(vm, fd, file))
	{
		close(fd);
		return (verbose(vm, MSG_ERROR, "{yel}%s:{red} Invalid champion file",
				filename));
	}
	close(fd);
	vm->nb_player++;
	return (0);
}
