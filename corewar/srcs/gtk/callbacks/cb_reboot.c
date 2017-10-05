/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_reboot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:45:41 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 13:19:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void	panel_reboot(t_vm *vm)
{
	int		i;
	char	txt[12];

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (vm->file[i].is_used)
		{
			vm->file[i].live = 0;
			vm->file[i].last_live = 0;
			if (IS_SET(vm->flag, GRAPHIC))
				update_players(vm, i);
		}
	}
	ft_itoa_nomalloc(vm->cycle, txt);
	gtk_label_set_label(GTK_LABEL(vm->gtk.panel.cpt), txt);
	ft_itoa_nomalloc(vm->cycle_to_die, txt);
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.cycle_to_die), txt);
	ft_itoa_nomalloc((vm->last_check + vm->cycle_to_die), txt);
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.next_chk), txt);
}

static void	erase_draw_area(t_vm *vm)
{
	cairo_t		*cr;

	cr = cairo_create(vm->gtk.surface);
	cairo_set_source_rgb(cr, 1., 1., 1.);
	cairo_rectangle(cr, 0, 0, AREA_WIDTH, AREA_HEIGHT);
	cairo_fill(cr);
	cairo_destroy(cr);
	gtk_widget_queue_draw_area(vm->gtk.draw, 0, 0, AREA_WIDTH, AREA_HEIGHT);
}

gboolean	cb_reboot(GtkWidget *widget, t_vm *vm)
{
	int		tmp;

	(void)widget;
	verbose(vm, MSG_DEBUG, "%s", __func__);
	verbose(vm, MSG_INFO, "Reinitialisation of vm", NULL);
	UNSET(vm->flag, END);
	if (IS_UNSET(vm->flag, PAUSE))
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause),
									IS_SET(vm->flag, PAUSE));
	gtk_widget_set_sensitive(vm->gtk.panel.step, TRUE);
	gtk_widget_set_sensitive(vm->gtk.panel.pause, TRUE);
	remove_all_process(vm);
	erase_draw_area(vm);
	tmp = vm->gtk.speed;
	init_gtk_value(vm);
	if (IS_SET(vm->flag, MUSIC))
		play_music(&(vm->audio), MUSIC_FILE_INTRO, SDL_MIX_MAXVOLUME);
	if (init_vm_value(vm))
		SET(vm->flag, STOP);
	vm->gtk.speed = tmp;
	panel_reboot(vm);
	return (FALSE);
}
