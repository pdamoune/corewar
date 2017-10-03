/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/03 21:41:04 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		gtk_cycle(t_vm *vm)
{
	char	txt[12];

	vm->gtk.time = g_get_monotonic_time();
	if (IS_SETREMOVE(vm->flag, STEP) || (vm->gtk.time - vm->gtk.oldtime) * vm->gtk.speed > 1000000)
	{
		// DG("Start cycle %lu:", vm->cycle);
		iter_on_px(vm);
		if (do_one_cycle(vm))
			return (1);
			//TODO remove next 2 line
		// if (!list_empty(&vm->process))
		// 	del_process(vm, LIST_FIRST_ENTRY(&vm->process, t_process, lx));
		ft_itoa_nomalloc(vm->cycle, txt);
		gtk_label_set_label(GTK_LABEL(vm->gtk.panel.cpt), txt);
		if (vm->gtk.panel.process)
			update_process(vm, vm->gtk.panel.process, 0);
		vm->gtk.oldtime = vm->gtk.time;
	}
	return (0);
}

static gboolean	gtk_loop(void *data)
{
	t_vm	*vm;

	vm = (t_vm *)data;
	vm->gtk.time = g_get_monotonic_time();
	while(IS_UNSET(vm->flag, STOP))
	{
		if (IS_UNSET(vm->flag, END) && (IS_UNSET(vm->flag, PAUSE) || IS_SET(vm->flag, STEP)))
		{
			if (gtk_cycle(vm))
				break;
		}
		while (gtk_events_pending())
			if (gtk_main_iteration())
				return (FALSE);
	}
	gtk_main_quit();
	return (FALSE);
}

static int	gtk_run(t_vm *vm)
{
	g_idle_add(gtk_loop, vm);
	gtk_main();
	if (vm->gtk.surface)
		cairo_surface_destroy(vm->gtk.surface);
	return (free_vm(vm));
}

static int	console_run(t_vm *vm)
{
	int ret;

	ret = 0;
	// DG("START");
	//TODO introducing contestants
	// while (IS_UNSET(vm->flag, STOP))
	while (IS_ONEUNSET(vm->flag, END | STOP | PAUSE)) //TODO check if correct for ending in console
	{
		// display(vm);
		ret = do_one_cycle(vm);
		if (ret)
			break;
	}
	// DG("END at cycle %d", vm->cycle);
	// if (!ret)//retiré car normalement c'est fait dans le check
	// 	ret = display_win(vm);
	return (free_vm(vm) || ret);
}

int		main(int ac, char **av)
{
	t_vm	vm;

	if (init_vm_memory(&vm, &ac, &av))
		return (1);
	if (init_vm_value(&vm))
		return (1);
	if (IS_SET(vm.flag, GRAPHIC))
		return (gtk_run(&vm));
	else
		return (console_run(&vm));
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <gtk/gtk.h>

// int main( int   argc,
//           char *argv[] )
// {
//     GtkWidget *window;

//     gtk_init (&argc, &argv);

//     /* create a new window */
//     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//     gtk_widget_set_size_request (GTK_WIDGET (window), 200, 100);
//     gtk_window_set_title (GTK_WINDOW (window), "GTK Entry");
//     g_signal_connect (window, "destroy",
//                       G_CALLBACK (gtk_main_quit), NULL);
//     g_signal_connect_swapped (window, "delete-event",
//                               G_CALLBACK (gtk_widget_destroy), 
//                               window);

   
//     gtk_widget_show (window);

//     gtk_main();

//     return 0;
// }