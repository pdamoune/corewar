/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:43:45 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 19:48:00 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GTK_H
# define GTK_H

# include <libft.h>
# include <gtk/gtk.h>
# include <op.h>


# define N_CHANNELS 		4

# define BOX_BY_LINE		64
# define N_LINE				(MEM_SIZE / BOX_BY_LINE)
# define NB_LINE			(N_LINE*BOX_BY_LINE==MEM_SIZE?N_LINE:N_LINE+1)
# define SQUARE_SIZE		10
# define SQUARE_SPA			4
# define SQUARE_BORDER		2

# define AREA_WIDTH			(BOX_BY_LINE * (SQUARE_SIZE + 2 * SQUARE_SPA))
# define AREA_HEIGHT		(NB_LINE * (SQUARE_SIZE + 2 * SQUARE_SPA))

# define INIT_SPEED			7

# define GTK_WIDTH			(AREA_WIDTH + 410)
# define GTK_HEIGHT			1200

/*
** COLOR
*/
# define G_RED				((t_color){255, 0, 0, 255})
# define G_GREEN			((t_color){0, 255, 0, 255})
# define G_BLUE				((t_color){0, 0, 255, 255})
# define G_BLACK			((t_color){0, 0, 0, 255})
# define G_WHITE			((t_color){255, 255, 255, 255})

/*
** KEY MANAGEMENT FOR GTK
*/
# ifdef __APPLE__
#  define GTK_ESC			53
#  define GTK_SPA			49
#  define GTK_ADD			69
#  define GTK_SUB			78
#  define GTK_RIGHT			124
# endif
# define MAX_KEY			1024

/*
** FLAG for px managment
*/
# define USED				(1 << 0)
# define LIVE				(1 << 1)


typedef struct		s_vm t_vm;

typedef struct		s_ivec2
{
	int				x;
	int				y;
}					t_ivec2;

typedef struct		s_color
{
	unsigned short	r;
	unsigned short	g;
	unsigned short	b;
	unsigned short	a;	
}					t_color;

typedef struct	s_px
{
	long int		flag;
}				t_px;

typedef struct	s_gtk
{
	gint64		time;
	gint64		oldtime;
	int			speed;
	GtkWidget	*win;
	GtkWidget	*pause;
	GtkWidget	*cpt;
	GtkWidget	*img;
	GdkPixbuf	*pixbuf;
	t_px		px[MEM_SIZE];
}				t_gtk;

void			calcul_border(t_vm *vm, t_ivec2 cur);
void			draw_rect(guchar *pixels, int rowstride, t_ivec2 size, t_color *color);
void			draw_rect_empty(guchar *pixels, int rowstride, t_ivec2 *size, t_color *color);
void			draw_border(t_vm *vm, t_ivec2 pos, t_color *color);
void			draw_pix(guchar *p, t_color *color);

/*
** GTK CONSTRUCT
*/

void			create_gtk(t_vm *vm);
GtkMenuBar		*menu_new(gpointer data);
GtkWidget		*menu_item_new(GtkMenu *menu, const gchar *title,
								GCallback callback, gpointer data);
GtkWidget		*pack_new_toggle_button(GtkWidget *widget, const gchar *title,
										GCallback callback, gpointer data);
GtkWidget		*pack_new_button(GtkWidget *widget, const gchar *title,
									GCallback callback, gpointer data);

/*
** CALLBACK FUNCTION FOR GTK
*/
void			cb_speed(GtkWidget *widget, t_vm *vm);
void			cb_key_event_release(GtkWidget *win, GdkEventKey *event, t_vm *vm);
void			cb_mouse(GtkWidget *win, GdkEventKey *event, t_vm *vm);
void			cb_play(GtkWidget *widget, t_vm *vm);
void			cb_quit(GtkWidget *widget, gpointer data);

#endif