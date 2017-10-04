/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:14:40 by wescande          #+#    #+#             */
/*   Updated: 2017/10/04 17:31:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#include <libft.h>

/*
** Definition for the game global sound device
*/

typedef struct		s_private_audio_device
{
	SDL_AudioDeviceID		device;
	SDL_AudioSpec			want;
	uint8_t					audio_enabled;
}					t_private_audio_device;

static t_private_audio_device	*g_device;
static uint32_t					g_sound_count;

/*
** Add a sound to the end of the queue
**
** @param root      Root of queue
** @param new       New Audio to add
*/

static void					add_audio(t_sound *root, t_sound *new)
{
	if (!root)
		return ;
	while (root->next != NULL)
		root = root->next;
	root->next = new;
}

/*
** Add a music to the queue, add_audio wrapper for music due to fade
**
** @param new       New Audio to add
*/

static void					add_music(t_sound *root, t_sound *new)
{
	uint8_t		music_found;
	t_sound		*root_next;

	music_found = 0;
	root_next = root->next;
	while (root_next)
	{
		if (root_next->loop == 1 && root_next->fade == 0)
		{
			if (music_found)
			{
				root_next->length = 0;
				root_next->volume = 0;
			}
			root_next->fade = 1;
		}
		else if (root_next->loop == 1 && root_next->fade == 1)
			music_found = 1;
		root_next = root_next->next;
	}
	add_audio(root, new);
}

/*
** Wrapper function for play_music, play_sound, play_music_from_memory,
** play_sound_from_memory
**
** @param filename      Provide a filename to load WAV from,
** or NULL if using FromMemory
** @param audio         Provide an Audio object if copying from memory,
** or NULL if using a filename
** @param sound         1 if looping (music), 0 otherwise (sound)
** @param volume        See play_sound for explanation
*/

static inline int			common_check(uint8_t loop)
{
	if (!g_device->audio_enabled)
		return (ERR_SET(1, E_CUSTOM_ERR, "Warning", "Audio not enable"));
	if (!loop)
	{
		if (g_sound_count >= AUDIO_MAX_SOUNDS)
			return (ERR_SET(1, E_CUSTOM_ERR, "Warning", "Two many sound"));
		else
			g_sound_count++;
	}
}

static inline int			common_add(uint8_t loop, t_sound *new_sound)
{
	SDL_LockAudioDevice(g_device->device);
	if (loop == 1)
		add_music((t_sound *)(g_device->want).userdata, new_sound);
	else
		add_audio((t_sound *)(g_device->want).userdata, new_sound);
	SDL_UnlockAudioDevice(g_device->device);
	return (0);
}

static inline int			play_audio(const char *filename,
										uint8_t loop, int volume)
{
	t_sound		*new_sound;

	if (common_check(loop))
		return (1);
	if (!filename)
		return (ERR_SET(1, E_CUSTOM_ERR, "Warning", "Filename is NULL"));
	new_sound = create_audio(filename, loop, volume);
	return (common_add(loop, new_sound));
}

static inline int			play_audio_from_memory(t_sound *audio,
										uint8_t loop, int volume)
{
	t_sound *new_sound;

	if (common_check(loop))
		return (1);
	if (!audio)
		return (ERR_SET(1, E_CUSTOM_ERR, "Warning", "Audio is NULL"));
	if (!(new_sound = malloc(sizeof(t_sound))))
		return (ERR_SET(1, E_MALLOC, NULL));
	memcpy(new_sound, audio, sizeof(t_sound));
	new_sound->volume = volume;
	new_sound->loop = loop;
	new_sound->free = 0;
	return (common_add(loop, new_sound));
}

/*
** Audio callback function for OpenAudioDevice
**
** @param userdata      Points to linked list of sounds to play,
** first being a placeholder
** @param stream        Stream to mix sound into
** @param len           Length of sound to play
*/

static inline void			audio_callback(void *userdata,
										uint8_t *stream, int len)
{
	t_sound		*audio;
	t_sound		*previous;
	int			temp_length;
	uint8_t		music;

	audio = (t_sound *)userdata;
	previous = audio;
	music = 0;
	SDL_memset(stream, 0, len);
	audio = audio->next;
	while (audio)
	{
		if (audio->length > 0)
		{
			if (audio->fade == 1 && audio->loop == 1)
			{
				music = 1;
				if (!--audio->volume)
					audio->length = 0;
			}
			if (music && audio->loop == 1 && audio->fade == 0)
				temp_length = 0;
			else
				temp_length =
				((uint32_t)len > audio->length) ? audio->length : (uint32_t)len;
			SDL_MixAudioFormat(stream, audio->buffer, AUDIO_FORMAT,
								temp_length, audio->volume);
			audio->buffer += temp_length;
			audio->length -= temp_length;
			previous = audio;
			audio = audio->next;
		}
		else if (audio->loop == 1 && audio->fade == 0)
		{
			audio->buffer = audio->buffer_true;
			audio->length = audio->length_true;
		}
		else
		{
			previous->next = audio->next;
			if (!audio->loop)
				g_sound_count--;
			audio->next = NULL;
			free_audio(audio);
			audio = previous->next;
		}
	}
}

int		play_sound(const char *filename, int volume)
{
	return (play_audio(filename, 0, volume));
}

int		play_music(const char *filename, int volume)
{
	return (play_audio(filename, 1, volume));
}

int		play_sound_from_memory(t_sound *audio, int volume)
{
	return (play_audio_from_memory(audio, 0, volume));
}

int		play_music_from_memory(t_sound *audio, int volume)
{
	return (play_audio_from_memory(audio, 1, volume));
}

int		init_audio(void)
{
	t_sound *global;

	g_sound_count = 0;
	if (!(g_device = malloc(sizeof(t_private_audio_device))))
		return (ERR_SET(1, E_MALLOC, NULL));
	g_device->audio_enabled = 0;
	if (!(SDL_WasInit(SDL_INIT_AUDIO) & SDL_INIT_AUDIO))
		return (ERR_SET(1, E_CUSTOM_ERR, "Error", "Init failed"));
	SDL_memset(&(g_device->want), 0, sizeof(g_device->want));
	(g_device->want).freq = AUDIO_FREQUENCY;
	(g_device->want).format = AUDIO_FORMAT;
	(g_device->want).channels = AUDIO_CHANNELS;
	(g_device->want).samples = AUDIO_SAMPLES;
	(g_device->want).callback = audio_callback;
	(g_device->want).userdata = malloc(sizeof(t_sound));
	if (!(global = (g_device->want).userdata))
		return (ERR_SET(1, E_MALLOC, NULL));
	global->buffer = NULL;
	global->next = NULL;
	if (!(g_device->device = SDL_OpenAudioDevice(NULL, 0, &(g_device->want),
							NULL, SDL_AUDIO_ALLOW_CHANGES)))
		return (ERR_SET(1, E_OPEN, "Audio device", SDL_GetError()));
	g_device->audio_enabled = 1;
	unpause_audio();
	return (0);
}

void					end_audio(void)
{
	if (g_device->audio_enabled)
	{
		pause_audio();
		free_audio((t_sound *)(g_device->want).userdata);
		SDL_CloseAudioDevice(g_device->device);
	}
	free(g_device);
}

void					pause_audio(void)
{
	if (g_device->audio_enabled)
		SDL_PauseAudioDevice(g_device->device, 1);
}

void					unpause_audio(void)
{
	if (g_device->audio_enabled)
		SDL_PauseAudioDevice(g_device->device, 0);
}

void					free_audio(t_sound *audio)
{
	t_sound *temp;

	while (audio)
	{
		if (audio->free == 1)
			SDL_FreeWAV(audio->buffer_true);
		temp = audio;
		audio = audio->next;
		free(temp);
	}
}

t_sound					*create_audio(const char *filename,
						uint8_t loop, int volume)
{
	t_sound *new_sound;

	if (filename == NULL)
		return (ERR_SET(NULL, E_SYS_NOFILE, filename));
	if (!(new_sound = malloc(sizeof(t_sound))))
		return (ERR_SET(NULL, E_MALLOC, NULL));
	new_sound->next = NULL;
	new_sound->loop = loop;
	new_sound->fade = 0;
	new_sound->free = 1;
	new_sound->volume = volume;
	if (!SDL_LoadWAV(filename, &(new_sound->audio), &(new_sound->buffer_true),
					&(new_sound->length_true)))
	{
		free(new_sound);
		return (ERR_SET(NULL, E_OPEN, filename, SDL_GetError()));
	}
	new_sound->buffer = new_sound->buffer_true;
	new_sound->length = new_sound->length_true;
	(new_sound->audio).callback = NULL;
	(new_sound->audio).userdata = NULL;
	return (new_sound);
}
