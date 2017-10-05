/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:10:12 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:45:17 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUDIO_H
# define AUDIO_H

# include <SDL.h>
# include <libft.h>

# define AUDIO_START		0
# define AUDIO_STOP			1
# define AUDIO_FORMAT		AUDIO_S16LSB
# define AUDIO_FREQUENCY	48000
# define AUDIO_CHANNELS		2
# define AUDIO_SAMPLES		4096
# define AUDIO_MAX_SOUNDS	25

/*
** Flags OR'd together, which specify how SDL should behave when a device
** cannot offer a specific feature
** If flag is set, SDL will change the format in the actual audio file structure
** (as opposed to gDevice->want)
**
** Note: If you're having issues with Emscripten / EMCC
** play around with these flags
**
** 0                                    Allow no changes
** SDL_AUDIO_ALLOW_FREQUENCY_CHANGE     Allow frequency changes
** (e.g. AUDIO_FREQUENCY is 48k, but allow files to play at 44.1k
** SDL_AUDIO_ALLOW_FORMAT_CHANGE        Allow Format change
** (e.g. AUDIO_FORMAT may be S32LSB, but allow wave files of S16LSB to play)
** SDL_AUDIO_ALLOW_CHANNELS_CHANGE      Allow any number of channels
** (e.g. AUDIO_CHANNELS being 2, allow actual 1)
** SDL_AUDIO_ALLOW_ANY_CHANGE           Allow all changes above
*/
# define SDL_AUDIO_ALLOW_CHANGES SDL_AUDIO_ALLOW_ANY_CHANGE

typedef struct		s_sound
{
	uint32_t		length;
	uint32_t		length_true;
	uint8_t			*buffer_true;
	uint8_t			*buffer;
	uint8_t			loop;
	uint8_t			fade;
	uint8_t			free_data;
	uint8_t			volume;
	SDL_AudioSpec	audio;
	t_lx			lx;
}					t_sound;

typedef struct		s_private_audio
{
	SDL_AudioDeviceID		id;
	SDL_AudioSpec			spec;
	uint8_t					audio_enabled;
	uint32_t				sound_count;
	t_lx					sound;
}					t_private_audio;

t_sound				*create_audio(const char *filename, uint8_t loop, int vol);

void				free_audio(t_sound *audio);

int					play_sound(t_private_audio *device,
								const char *filename, int volume);

int					play_music(t_private_audio *device,
								const char *filename, int volume);

int					play_sound_from_memory(t_private_audio *device,
								t_sound *audio, int volume);

int					play_music_from_memory(t_private_audio *device,
								t_sound *audio, int volume);

int					end_audio(t_private_audio *device);

int					init_audio(t_private_audio *device);

int					pause_audio(t_private_audio *device);

int					unpause_audio(t_private_audio *device);

/*
** Internal functions
*/
extern int			play_audio(t_private_audio *device, const char *filename,
								uint8_t loop, int volume);
extern int			play_audio_from_memory(t_private_audio *device,
								t_sound *audio,
								uint8_t loop, int volume);

#endif
