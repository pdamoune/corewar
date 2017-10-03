/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:26:06 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 21:37:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		free_vm(t_vm *vm)
{
	remove_all_process(vm);
	stop_allegro(vm);
	destroy_allegro(vm);
	return (0);
}
