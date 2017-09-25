/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:02:23 by wescande          #+#    #+#             */
/*   Updated: 2017/09/25 16:01:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	war_end(t_vm *vm)
{
	SET(vm->flag, PAUSE | END);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		gtk_widget_set_sensitive(vm->gtk.panel.step, FALSE);
		gtk_widget_set_sensitive(vm->gtk.panel.pause, FALSE);
	}
}