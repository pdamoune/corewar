/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:13:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/04 16:18:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <errno.h>
# include <stdio.h>
# include <gtk.h>
# include <usage.h>
# include <op.h>
# include <SDL.h>
# include "audio.h"

// # define TITLE ft_printf("===   %s   ===\n", __func__);
// # define E_TITLE ft_printf("=== fin %s ===\n", __func__);

// # define MSG_COR(s) ("{red}corewar: " s "{eoc}\n")
// # define ERR_COR(s, ...) (ft_dprintf(2, MSG_COR(s), ##__VA_ARGS__) * 0 + 1)

// # include <sndfile.h>
// # include <portaudio.h>
// #include <allegro5/allegro.h>
// #include <allegro5/allegro_audio.h>
// #include <allegro5/allegro_acodec.h>
# define MUSIC_FILE_SLASH		"slash.wav"
# define MUSIC_FILE_BACK		"play.wav"

/*
** FLAGS
*/

# define GRAPHIC		(1 << 0)
# define DUMP			(1 << 1)
# define STOP			(1 << 2)
# define END			(1 << 3)
# define PAUSE			(1 << 4)
# define REDRAW			(1 << 5)
# define VERBOSE		(1 << 6)
# define QUIET			(1 << 7)
# define STEP			(1 << 8)
# define WILL_GRAPHIC	(1 << 9)
# define DEBUG			(1 << 10)
# define MUSIC			(1 << 11)
# define SOUND			(1 << 12)
# define NEVER_START	(1 << 12)

# define MSG_STD		0
# define MSG_INFO		1
# define MSG_DEBUG		2
# define MSG_WARNING	3
# define MSG_ERROR		4
# define MSG_SUCESS		5
# define MSG_STD_G		6

# if MAX_PLAYERS < 1
#  error "macro MAX_PLAYERS must be strictly positive"
# endif

typedef struct	s_op		t_op;
typedef struct	s_process	t_process;

struct		s_op
{
	char	*label;
	int		nb_params;
	int		params[MAX_ARGS_NUMBER];
	int		op_code;
	int		cycle;
	char	*description;
	int		ocp;
	int		index;
	int		(*instru)(t_vm *vm, t_process *process, unsigned int *args);
};

struct		s_process
{
	unsigned int	id;
	// char			*name;
	unsigned int	pc;
	unsigned int	r[REG_NUMBER];
	int				carry:1;
	short			id_player;
	long			last_live;
	t_op			op;
	int				nb_cycle_before_exec;
	t_lx			lx;
};

// typedef struct		s_player
// {
// 	int				start_position;
// 	int				live;
// 	long			last_live;
// }					t_player;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
	// unsigned		prog[CHAMP_MAX_SIZE / 4 + 1];// TODO pourquoi unsigned et on divise par 4 ?
}					t_header;

typedef struct		s_file
{
	long			last_live;
	int				start_position;
	int				live;
	t_header		header;
	char			prog[CHAMP_MAX_SIZE + 1];
	int				is_used:1;
}					t_file;

/*
** it's forbidden to change the order of the 2 first params in the following struct
** she is cast in another one after
*/
// typedef struct		s_allegro
// {
// 	ALLEGRO_VOICE				*voice;
// 	ALLEGRO_MIXER				*mixer;
// 	ALLEGRO_SAMPLE_INSTANCE		*sample;
// 	ALLEGRO_SAMPLE				*sample_data;
// }					t_allegro;
typedef struct		s_audio
{
	uint8_t			*audio_pos;
	uint32_t		audio_len;
	uint8_t			*audio_pos_tmp;
	uint32_t		audio_len_tmp;
	uint8_t			*audio_pos_slash;
	uint32_t		audio_len_slash;
	uint8_t			*audio_pos_intro;
	uint32_t		audio_len_intro;
	uint8_t			*audio_pos_play;
	uint32_t		audio_len_play;
	uint8_t			*audio_pos_final;
	uint32_t		audio_len_final;
	int				is_play:1;
}					t_audio;

typedef struct		s_vm
{
	long int		flag;
	char			**av_data;
	t_file			file[MAX_PLAYERS];
	// t_player		players[MAX_PLAYERS];
	t_lx			process;
	t_gtk			gtk;
	t_audio			audio;
	t_sound			*sound;
	// t_allegro		allegro;
	int				nb_player;
	int				livetmp;
	char			area[MEM_SIZE];
	int				cycle;
	int				cycle_to_dump;
	long			cycle_to_die;
	long			last_check;
	long			check_count;
}					t_vm;

/*
** Main functions.
*/

void	display(t_vm *vm);
int		do_one_cycle(t_vm *vm);
void	check_cycle(t_vm *vm);
void	check_live(t_vm *vm);
void	war_end(t_vm *vm);
int		verbose(t_vm *vm, const int level, const char *message, ...);

/*
** Insignifiant func
*/
unsigned int	get_value_at(t_vm *vm, unsigned int pos, char size);
unsigned int	get_process_value_from_area(t_vm *vm, t_process *p, unsigned int type, int *pc_inc);

// unsigned int	get_value_from_area(t_vm *vm, t_process *p, unsigned int type, int *pc_inc);
void			get_type_from_area(t_vm *vm, t_process *p, unsigned int *type);
int				set_value_in_area(t_vm *vm, int at, unsigned int value, unsigned int size);

/*
** Tools functions.
*/

int		usage(char *name);
int		free_vm(t_vm *vm);
// void	destroy_allegro(t_vm *vm);
void	add_process(t_vm *vm, t_process *p);
void	remove_all_process(t_vm *vm);
void	del_process(t_vm *vm, t_process *process, int sound);
int		move_pc(t_vm *vm, int origin, int len);
int		fork_process(t_vm *vm, t_process *p, unsigned int pc);
int		calc_addr(int addr);
void	analyze_value(t_vm *vm, t_process *p, unsigned int *args, int lim);
void	analyze_long_value(t_vm *vm, t_process *p, unsigned int *args, int lim);

/*
** INIT
*/

int		init_vm_memory(t_vm *vm, int *ac, char ***av);
int		init_vm_value(t_vm *vm);
int		init_dump(char **opt_arg, t_vm *vm, int n_args);
int		init_number(char **opt_arg, t_vm *vm, int n_args);
int		init_file(t_vm *vm, int num, char *filename);
int		init_data(t_vm *vm, int fd, t_file *file);
int		init_process_list(t_vm *vm);
int		init_area(t_vm *vm);
// int		init_allegro(t_vm *vm);
int		init_music(t_vm *vm);

/*
** Instructions.
*/

int		op_live(t_vm *vm, t_process *process, unsigned int *args);
int		op_ld(t_vm *vm, t_process *process, unsigned int *args);
int		op_st(t_vm *vm, t_process *process, unsigned int *args);
int		op_add(t_vm *vm, t_process *process, unsigned int *args);
int		op_sub(t_vm *vm, t_process *process, unsigned int *args);
int		op_and(t_vm *vm, t_process *process, unsigned int *args);
int		op_or(t_vm *vm, t_process *process, unsigned int *args);
int		op_xor(t_vm *vm, t_process *process, unsigned int *args);
int		op_zjmp(t_vm *vm, t_process *process, unsigned int *args);
int		op_ldi(t_vm *vm, t_process *process, unsigned int *args);
int		op_sti(t_vm *vm, t_process *process, unsigned int *args);
int		op_fork(t_vm *vm, t_process *process, unsigned int *args);
int		op_lld(t_vm *vm, t_process *process, unsigned int *args);
int		op_lldi(t_vm *vm, t_process *process, unsigned int *args);
int		op_lfork(t_vm *vm, t_process *process, unsigned int *args);
int		op_aff(t_vm *vm, t_process *process, unsigned int *args);

/*
** DISPLAY
*/
int		display_win(t_vm *vm);
int		dump(t_vm *vm);
// void	play_allegro(t_vm *vm);
// void	stop_allegro(t_vm *vm);


#endif
