/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:39:15 by wescande          #+#    #+#             */
/*   Updated: 2017/09/19 19:45:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean	cb_quit(GtkWidget *widget, gpointer data)
{
	(void)widget;
	(void)data;
	
	gtk_main_quit();
	return (FALSE);
}