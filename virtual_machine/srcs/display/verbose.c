/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:26:12 by wescande          #+#    #+#             */
/*   Updated: 2017/10/09 11:21:48 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void			corewar_verbose(const int level, const char *str)
{
	if (level == MSG_ERROR)
		ft_dprintf(2, "{pur}Corewar:{red} %s{eoc}\n", str);
	else if (level == MSG_SUCESS)
		ft_printf("{gre}%s{eoc}\n", str);
	else if (level == MSG_WARNING)
		ft_printf("{pur}Corewar: {yel}WARNING:{eoc} %s{eoc}\n", str);
	else if (level == MSG_INFO)
		ft_printf("{pur}Corewar: {blu}INFO:{eoc} %s{eoc}\n", str);
	else if (level == MSG_STD)
		ft_printf("{pur}Corewar: {eoc}%s{eoc}\n", str);
	else if (level == MSG_DEBUG)
		ft_printf("{pur}Corewar: {YEL}{bla}DEBUG:{eoc} {yel}%s{eoc}\n", str);
}

static void			gtk_verbose(t_vm *vm, const int level, const char *str)
{
	GtkWidget	*dialog;
	int			msg_type;

	if (level == MSG_ERROR)
		msg_type = GTK_MESSAGE_ERROR;
	else if (level == MSG_INFO)
		msg_type = GTK_MESSAGE_INFO;
	else if (level == MSG_WARNING)
		msg_type = GTK_MESSAGE_WARNING;
	else
		msg_type = GTK_MESSAGE_INFO;
	dialog = gtk_message_dialog_new(GTK_WINDOW(vm->gtk.win), GTK_DIALOG_MODAL,
				msg_type, GTK_BUTTONS_CLOSE, str, NULL);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

int					verbose(t_vm *vm, const int level, const char *message, ...)
{
	va_list		va;
	char		*str;

	if ((IS_SET(vm->flag, QUIET) && level < MSG_DEBUG) || (IS_UNSET(vm->flag,
		DEBUG) && level == MSG_DEBUG) || (IS_UNSET(vm->flag, VERBOSE)
		&& (level == MSG_INFO || level == MSG_WARNING)))
		return (0);
	va_start(va, message);
	ft_vasprintf(&str, message, va);
	if (IS_SET(vm->flag, GRAPHIC) && level >= MSG_ERROR && level != MSG_SUCESS)
		gtk_verbose(vm, level, str);
	else if (IS_UNSET(vm->flag, ZAZ) || level == MSG_ERROR)
		corewar_verbose(level, str);
	else if (level != MSG_WARNING)
		ft_printf("%s\n", str);
	free(str);
	return (level == MSG_ERROR);
}
