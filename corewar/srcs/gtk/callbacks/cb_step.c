/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_step.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:31:24 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 11:23:47 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean	cb_step(GtkWidget *widget, GdkEvent *event, t_vm *vm)
{
	(void)widget;
	(void)event;
	do_one_step(vm);
	return (FALSE);
}
