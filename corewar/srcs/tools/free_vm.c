/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:26:06 by wescande          #+#    #+#             */
/*   Updated: 2017/09/05 17:21:17 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		free_vm(t_vm *vm)
{
	remove_process(vm);	
	return (DG("not yet implemented"));
}
