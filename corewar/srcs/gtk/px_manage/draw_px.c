/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:31:49 by wescande          #+#    #+#             */
/*   Updated: 2017/10/07 01:07:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#include <math.h>

static void		draw_px_text(t_vm *vm, cairo_t *cr, int at, t_ivec2 pos)
{
	char					*txt;
	cairo_text_extents_t	extents;

	cairo_set_source_rgb(cr, 0., 0., 0.);
	cairo_set_font_size(cr, 10.0);
	cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL,
			CAIRO_FONT_WEIGHT_NORMAL);
	ft_asprintf(&txt, "%02hhx", vm->area[at]);
	cairo_text_extents(cr, txt, &extents);
	pos.x += SQUARE_WIDTH / 2;
	pos.x -= ((int)extents.width / 2 + extents.x_bearing);
	pos.y += SQUARE_HEIGHT / 2;
	pos.y -= (((int)extents.height / 2 + (int)extents.y_bearing));
	cairo_move_to(cr, pos.x, pos.y);
	cairo_show_text(cr, txt);
	free(txt);
}

int				draw_px_live(t_vm *vm, int at)
{
	t_ivec2		pos;
	cairo_t		*cr;
	t_color		color;

	erase_px(vm, at);
	color = px_calc_color(vm, at);
	cr = vm->gtk.cr;
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	pos.x += SQUARE_BORDER;
	pos.y += SQUARE_BORDER;
	cairo_set_source_rgb(cr, color.r, color.g, color.b);
	cairo_arc(cr, pos.x + SQUARE_WIDTH / 2, pos.y + SQUARE_HEIGHT / 2,
			(SQUARE_HEIGHT > SQUARE_WIDTH ? SQUARE_WIDTH : SQUARE_HEIGHT) / 2,
			0, 2 * M_PI);
	cairo_fill(cr);
	draw_px_text(vm, cr, at, pos);
	DG();
	gtk_widget_queue_draw_area(vm->gtk.draw, pos.x, pos.y,
								SQUARE_WIDTH * 2, SQUARE_HEIGHT * 2);
	DG();
	return (0);
}

int				draw_px(t_vm *vm, int at)
{
	t_ivec2		pos;
	cairo_t		*cr;
	t_color		color;

	color = px_calc_color(vm, at);
	cr = vm->gtk.cr;
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	pos.x += SQUARE_BORDER;
	pos.y += SQUARE_BORDER;
	cairo_set_source_rgb(cr, color.r, color.g, color.b);
	cairo_rectangle(cr, pos.x, pos.y,
						SQUARE_WIDTH, SQUARE_HEIGHT);
	cairo_fill(cr);
	draw_px_text(vm, cr, at, pos);
	DG();
	gtk_widget_queue_draw_area(vm->gtk.draw, pos.x, pos.y,
								SQUARE_WIDTH, SQUARE_HEIGHT);
	DG();

	return (0);
}
