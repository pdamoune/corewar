/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 11:53:01 by wescande          #+#    #+#             */
/*   Updated: 2017/08/28 17:50:36 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int	get_empty_file(t_vm *vm)
{
	int i = -1;

	while (++i < 4)
		if (!vm->file[i].is_used)
			return (i);
	return (-1);
}

int		init_file(t_vm *vm, int num, char *filename)
{
	t_file		*file;
	int			fd;

	if (num == -1 && (num = get_empty_file(vm)) == -1)
		return (ERR_COR("max player is 4"));
	file = &(vm->file[num]);
	if (file->is_used++)
		return (ERR_COR("player number already used"));
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror(filename);
		return (1);
	}
	if (!init_data(fd, &(file->header)))
		return (1);
	return (0);
}
