/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_key_event_press.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:46:51 by wescande          #+#    #+#             */
/*   Updated: 2017/09/26 19:43:29 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		one_step(t_vm *vm)
{
	return (do_one_step(vm));
}

static t_itof	g_action[] =
{
	{GTK_RIGHT, one_step},
	{0, 0},
};

gboolean			cb_key_event_press(GtkWidget *win, GdkEventKey *event, t_vm *vm)
{
	int i;

	(void)win;
	i = -1;
	DG("press %s of val %u", gdk_keyval_name(event->keyval),
						event->hardware_keycode);
	while (g_action[++i].id)
		if (g_action[i].id == event->hardware_keycode)
		{
			g_action[i].f(vm);
			return (FALSE);
		}
	return (FALSE);
}