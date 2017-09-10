/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:18:33 by wescande          #+#    #+#             */
/*   Updated: 2017/09/10 10:23:05 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		add_process(t_vm *vm, t_process *p)
{
	static unsigned int id = 0;

	p->id_process = ++id;
	list_add(&(p->lx), &(vm->process));
}