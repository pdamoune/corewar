/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_step.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:31:24 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 23:46:49 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	cb_step(GtkWidget *widget, GdkEvent  *event, t_vm *vm)
{
	(void)widget;
	(void)event;
	DG();
	SET(vm->flag, STEP);
}