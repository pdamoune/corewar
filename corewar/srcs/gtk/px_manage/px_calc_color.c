/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_calc_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:50:14 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 19:18:17 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_color			g_player_color[7] =
{
	{.8, .4, .4},
	{.2, .8, .2},
	{.8, .8, .2},
	{.2, .8, .8},
	{.8, .2, .8},
	{.8, .8, .8},
	{0., 0., 0.}
};

t_color			px_calc_color(t_vm *vm, int at)
{
	t_color		color;

	if (vm->gtk.px[at].player > 7)
		return (COLOR_BLACK);
	color = g_player_color[vm->gtk.px[at].player];
	if (vm->gtk.px[at].is_new)
	{
		color.r += .2;
		color.g += .2;
		color.b += .2;
	}
	return (color);
}
