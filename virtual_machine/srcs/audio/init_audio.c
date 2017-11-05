/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_audio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:25:59 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 17:14:24 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <audio.h>

/*
** Audio callback function for OpenAudioDevice
**
** @param userdata      Points to linked list of sounds to play,
** first being a placeholder
** @param stream        Stream to mix sound into
** @param len           Length of sound to play
*/

static inline void			audio_callback_mix(t_sound *audio, uint8_t *music,
												uint8_t *stream, int len)
{
	int				temp_length;

	if (audio->fade == 1 && audio->loop == 1)
	{
		*music = 1;
		if (!--audio->volume)
			audio->length = 0;
	}
	if (*music && audio->loop == 1 && audio->fade == 0)
		temp_length = 0;
	else
		temp_length =
		((uint32_t)len > audio->length) ? audio->length : (uint32_t)len;
	SDL_MixAudioFormat(stream, audio->buffer, AUDIO_FORMAT,
						temp_length, audio->volume);
	audio->buffer += temp_length;
	audio->length -= temp_length;
}

static inline void			audio_callback(void *userdata,
										uint8_t *stream, int len)
{
	t_private_audio	*device;
	t_sound			*audio;
	t_sound			*tmp;
	uint8_t			music;

	device = (t_private_audio *)userdata;
	music = 0;
	SDL_memset(stream, 0, len);
	LIST_FOR_EACH_ENTRY_SAFE_0(audio, tmp, &device->sound, lx);
	while (LIST_FOR_EACH_ENTRY_SAFE_1(audio, tmp, &device->sound, lx))
	{
		if (audio->length > 0)
			audio_callback_mix(audio, &music, stream, len);
		else if (audio->loop == 1 && audio->fade == 0)
		{
			audio->buffer = audio->buffer_true;
			audio->length = audio->length_true;
		}
		else
		{
			if (!audio->loop)
				--(device->sound_count);
			free_audio(audio);
		}
	}
}

int							init_audio(t_private_audio *device)
{
	ft_bzero(device, sizeof(t_private_audio));
	INIT_LIST_HEAD(&(device->sound));
	if (SDL_WasInit(SDL_INIT_AUDIO) != SDL_INIT_AUDIO)
		return (ERR_SET(1, E_CUSTOM_ERR, "SDL AUDIO", "Must be init first"));
	device->spec.freq = AUDIO_FREQUENCY;
	device->spec.format = AUDIO_FORMAT;
	device->spec.channels = AUDIO_CHANNELS;
	device->spec.samples = AUDIO_SAMPLES;
	device->spec.callback = audio_callback;
	device->spec.userdata = device;
	if (!(device->id = SDL_OpenAudioDevice(NULL, 0, &(device->spec),
							NULL, SDL_AUDIO_ALLOW_CHANGES)))
		return (ERR_SET(1, E_OPEN, "Audio device", SDL_GetError()));
	device->audio_enabled = 1;
	unpause_audio(device);
	return (0);
}
