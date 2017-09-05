/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_calc_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:50:14 by wescande          #+#    #+#             */
/*   Updated: 2017/09/05 22:33:47 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_color			g_player_color[8] = 
{
	{.7, 0., 0.},
	{0., .7, 0.},
	{0., 0., .7},
	{.7, .7, 0.},
	{0., .7, .7},
	{.7, 0., .7},
	{.7, .7, .7},
	{0., 0., 0.}
};

t_color			px_calc_color(t_vm *vm, int at)
{
	t_color		color;

	if (vm->gtk.px[at].player > 8)
		return (COLOR_BLACK);
		DG("%d",vm->gtk.px[at].player);
	color = g_player_color[vm->gtk.px[at].player];
	if (vm->gtk.px[at].is_new)
	{
		DG();
		color.r += .2;
		color.g += .2;
		color.b += .2;
	}
	return (color);
}