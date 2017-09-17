/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/09/17 22:46:57 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		gtk_cycle(t_vm *vm)
{
	char	txt[12];

	vm->gtk.time = g_get_monotonic_time();
	if (IS_SETREMOVE(vm->flag, STEP) || (vm->gtk.time - vm->gtk.oldtime) * vm->gtk.speed > 1000000)
	{
		DG("Start cycle %lu:", vm->cycle);
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
		if (IS_UNSET(vm->flag, PAUSE) || IS_SET(vm->flag, STEP))
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

	if (!vm)
		return (ERR_COR("WHAT THE FUCK IS NULL??"));
	ret = 0;
	DG("START");
	while (IS_UNSET(vm->flag, STOP))
	{
		display(vm);
		ret = do_one_cycle(vm);
		if (ret)
			break;
	}
	DG("END at cycle %d", vm->cycle);
	if (!ret)
		ret = display_win(vm);
	return (free_vm(vm) || ret);
}

int		main(int ac, char **av)
{
	t_vm	vm;

	if (init_vm(&vm, &ac, &av))
		return (1);
	if (IS_SET(vm.flag, GRAPHIC))
		return (gtk_run(&vm));
	else
		return (console_run(&vm));
}
