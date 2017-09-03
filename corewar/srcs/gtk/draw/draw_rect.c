/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:33:21 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 09:51:30 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	draw_rect(guchar *pixels, int rowstride, t_ivec2 size, const t_color color)
{
	t_ivec2		pos;
	
	pos.y = -1;
	while (++pos.y < size.y && (pos.x = -1))
		while (++pos.x < size.x)
			draw_pix(pixels + (pos.x * N_CHANNELS + pos.y * rowstride), color);
}

void	draw_rect_border(guchar *pixels, int rowstride, t_ivec2 *size, const t_color color)
{
	t_ivec2		limit;

	limit.x = (size[0].x - size[1].x) / 2;
	limit.y = (size[0].y - size[1].y) / 2;
	draw_rect(pixels, rowstride, (t_ivec2){size[0].x, limit.y}, color);
	draw_rect(pixels + (limit.y + size[1].y) * rowstride,
			rowstride, (t_ivec2){size[0].x, limit.y}, color);
	draw_rect(pixels, rowstride, (t_ivec2){limit.x, size[0].y}, color);
	draw_rect(pixels + (limit.x + size[1].x) * N_CHANNELS,
			rowstride, (t_ivec2){limit.x, size[0].y}, color);
}