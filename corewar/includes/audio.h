/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:10:12 by wescande          #+#    #+#             */
/*   Updated: 2017/10/04 16:24:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUDIO_H
# define AUDIO_H

# include <SDL.h>

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
	uint8_t			free;
	uint8_t			volume;
	SDL_AudioSpec	audio;
	struct s_sound	*next;
}					t_sound;

t_sound				*create_audio(const char *filename, uint8_t loop, int vol);

void				free_audio(t_sound *audio);

void				play_sound(const char *filename, int volume);

void				play_music(const char *filename, int volume);

void				play_sound_from_memory(t_sound *audio, int volume);

void				play_music_from_memory(t_sound *audio, int volume);

void				end_audio(void);

int					init_audio(void);

void				pause_audio(void);

void				unpause_audio(void);

#endif
