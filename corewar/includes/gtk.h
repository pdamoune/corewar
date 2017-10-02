/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:43:45 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 17:11:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GTK_H
# define GTK_H

# include <libft.h>
# include <gtk/gtk.h>
# include <op.h>

# define BOX_BY_LINE		64
# define N_LINE				(MEM_SIZE / BOX_BY_LINE)
# define NB_LINE			(N_LINE*BOX_BY_LINE==MEM_SIZE?N_LINE:N_LINE+1)
# define SQUARE_WIDTH		16
# define SQUARE_HEIGHT		12
# define SQUARE_SPA			4
# define SQUARE_BORDER		2

# define PX_WIDTH			(SQUARE_SPA + 2 * SQUARE_BORDER + SQUARE_WIDTH)
# define PX_HEIGHT			(SQUARE_SPA + 2 * SQUARE_BORDER + SQUARE_HEIGHT)

# define AREA_WIDTH			(BOX_BY_LINE * (SQUARE_WIDTH + 2 * SQUARE_SPA))
# define AREA_HEIGHT		(NB_LINE * (SQUARE_HEIGHT + 2 * SQUARE_SPA))

# define INIT_SPEED			7

# define GTK_WIDTH			(AREA_WIDTH + 410)
# define GTK_HEIGHT			1300

# define CYCLE_CHANGED		10
/*
** STATUS
*/
# define STATUS_NEW			"FŒTUS"
# define STATUS_ALIVE		"ALIVE"
# define STATUS_GOD			"GOD PLAYER"
# define STATUS_DEAD		"DEAD ?"
# define STATUS_PRO_NEVER	"YOU LOOSE A STILLBORN PROCESS... Condolence."
# define STATUS_PRO_DEAD	"THIS PROCESS IS DEAD. Condolence."
# define STATUS_PRO_NOT		"THIS IS NOT A PROCESS."

/*
** COLOR
*/
# define COLOR_RED			((t_color){1., 0., 0.})
# define COLOR_GREEN		((t_color){0., 1., 0.})
# define COLOR_BLUE			((t_color){0., 0., 1.})
# define COLOR_BLACK		((t_color){0., 0., 0.})
# define COLOR_WHITE		((t_color){1., 1., 1.})
# define COLOR_PC			((t_color){1., .68, .2})

/*
** KEY MANAGEMENT FOR GTK
*/
# ifdef __APPLE__
#  define GTK_ESC			53
#  define GTK_SPA			49
#  define GTK_ADD			69
#  define GTK_SUB			78
#  define GTK_RIGHT			124
#  define GTK_DOWN			125
# endif

# ifdef __linux__
# define GTK_ESC			9
# define GTK_SPA			65
# define GTK_RIGHT			114
# define GTK_DOWN			115
# endif
# define MAX_KEY			1024

/*
** FLAG for px managment
*/
# define USED				(1 << 0)
# define LIVE				(1 << 1)
// # define MOUSE				(1 << 2)

typedef struct		s_vm t_vm;
typedef struct		s_process t_process;

typedef struct		s_ivec2
{
	int				x;
	int				y;
}					t_ivec2;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct	s_px
{
	unsigned long	flag;
	unsigned short	player;
	unsigned int	pc;
	unsigned short	is_new;
}				t_px;

typedef struct	s_gtkplayer
{
	GtkWidget	*status;
	GtkWidget	*last_live;
	GtkWidget	*n_live;
}				t_gtkplayer;

typedef struct	s_process_win
{
	GtkWidget	*btn;
	GtkWidget	*main_label;
	GtkWidget	*reg[REG_NUMBER];
	GtkWidget	*carry;
}				t_process_win;

typedef struct	s_panel
{
	GtkWidget	*step;
	GtkWidget	*pause;
	GtkWidget	*cpt;
	GtkWidget	*next_chk;
	GtkWidget	*cycle_to_die;
	t_gtkplayer	players[MAX_PLAYERS];
	GtkWidget	*repartition;
	GtkWidget	*process_box;
	GtkWidget	*process_status;
	GtkWidget	*process_act;
	GtkWidget	*process_desc_act;
	GtkWidget	*process_owner;
	GtkWidget	*process_owner_id;
	GtkWidget	*process_cycle_wait;
	GtkWidget	*process_pc;
	t_process_win	p_win;
	t_process	*process;
}				t_panel;

typedef struct	s_gtk
{
	gint64				time;
	gint64				oldtime;
	int					speed;
	GtkWidget			*win;
	t_panel				panel;
	GtkWidget			*draw;
	t_px				px[MEM_SIZE];
	cairo_surface_t		*surface;
	int					god_players;
}				t_gtk;

void			calcul_border(GtkWidget *widget, t_vm *vm, int at);
void			draw_border(GtkWidget *widget, t_vm *vm, int at, const t_color color);
int				draw_underline(t_vm *vm, int at, t_color color);
int				do_one_step(t_vm *vm);

/*
** GTK UPDATE
*/
void 			update_process(t_vm *vm, t_process *process, int is_dead);
void			update_players(t_vm *vm, int id);
void			update_process_info(t_vm *vm);
gboolean		update_process_select(t_vm *vm, unsigned int process_id);

/*
** PX MANAGE
*/

int				init_px(t_vm *vm, int at, int player);
t_color			px_calc_color(t_vm *vm, int at);
int				draw_px(t_vm *vm, int at);
int				draw_px_live(t_vm *vm, int at);
int				calcul_px(t_vm *vm, int at);
int				erase_px(t_vm *vm, int at);
void			cairo_pango_draw_text(t_vm *vm, int at, t_ivec2 pos);
void			iter_on_px(t_vm *vm);
void			px_change_owner(t_vm *vm, unsigned int at, int size, short owner);

/*
** PC MANAGE
*/

void			init_pc(t_vm *vm, int at);
int				erase_pc(t_vm *vm, int at);
int				draw_pc(t_vm *vm, int at);

/*
** GTK CONSTRUCT
*/

void			init_gtk_memory(int *ac, char ***av, t_vm *vm);
void			init_gtk_value(t_vm *vm);
void			create_gtk(t_vm *vm);
GtkWidget		*create_info_win(t_vm *vm);
GtkWidget		*create_panel(t_vm *vm);
GtkWidget		*create_players_info(t_vm *vm);
GtkWidget		*create_process_info(t_vm *vm);
GtkMenuBar		*menu_new(t_vm *vm);
GtkWidget		*menu_item_new(GtkMenu *menu, const gchar *title,
								GCallback callback, gpointer data);
GtkWidget		*pack_new_toggle_button(GtkWidget *widget, const gchar *title,
										GCallback callback, gpointer data);
GtkWidget		*pack_new_button(GtkWidget *widget, const gchar *title,
									GCallback callback, gpointer data);
GtkWidget		*create_process_info_display(t_vm *vm);
GtkWidget		*create_players_info_display(t_vm *vm, int i);

/*
** CALLBACK FUNCTION FOR GTK
*/
gboolean		cb_speed(GtkWidget *widget, t_vm *vm);
gboolean		cb_key_event_release(GtkWidget *win, GdkEventKey *event, t_vm *vm);
gboolean		cb_key_event_press(GtkWidget *win, GdkEventKey *event, t_vm *vm);
gboolean		cb_mouse(GtkWidget *win, GdkEventKey *event, t_vm *vm);
gboolean		cb_play(GtkWidget *widget, t_vm *vm);
gboolean		cb_quit(GtkWidget *widget, gpointer data);
gboolean		cb_step(GtkWidget *widget, GdkEvent  *event, t_vm *vm);
gboolean		cb_draw (GtkWidget *widget, cairo_t *cr, t_vm *vm);
gboolean		cb_configure_event(GtkWidget *widget, GdkEventConfigure *event,
									t_vm *vm);
gboolean		cb_process_box(GtkComboBox *widget, t_vm *vm);
gboolean		cb_more_info(GtkWidget *widget, GdkEvent *event, t_vm *vm);
gboolean		cb_reboot(GtkWidget *widget, t_vm *vm);

#endif
