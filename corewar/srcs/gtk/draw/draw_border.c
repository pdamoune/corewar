/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_border.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:35:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 19:13:34 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	draw_border(t_vm *vm, t_ivec2 pos, t_color *color)
{
	guchar		*pixels;
	t_ivec2		size[2];
	int			rowstride;

	pixels = gdk_pixbuf_get_pixels(vm->gtk.pixbuf);
	rowstride = gdk_pixbuf_get_rowstride(vm->gtk.pixbuf);
	size[0] = (t_ivec2){SQUARE_SIZE + 2 * SQUARE_BORDER, SQUARE_SIZE + 2 * SQUARE_BORDER};
	size[1] = (t_ivec2){SQUARE_SIZE, SQUARE_SIZE};
	draw_rect_empty(pixels + pos.x * N_CHANNELS + pos.y * rowstride, rowstride, size, color);
}