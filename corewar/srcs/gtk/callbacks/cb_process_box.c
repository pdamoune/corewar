/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_process_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 19:46:47 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 13:32:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean		cb_process_box(GtkComboBox *widget, t_vm *vm)
{
	unsigned int	process_id;
	char			*text;

	verbose(vm, MSG_DEBUG, "%s", __func__);
	if (IS_SET(vm->flag, STOP))
		return (FALSE);
	text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
	if (!text)
		return (FALSE);
	process_id = ft_atoui(text);
	free(text);
	if (update_process_select(vm, process_id))
		return (FALSE);
	vm->gtk.panel.process = NULL;
	update_process(vm, NULL, 0);
	return (FALSE);
}
