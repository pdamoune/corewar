/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:39:15 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 17:05:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean	cb_quit(GtkWidget *widget, t_vm *vm)
{
	(void)widget;
	verbose(vm, MSG_DEBUG, "%s", __func__);
	SET(vm->flag, STOP);
	return (FALSE);
}
