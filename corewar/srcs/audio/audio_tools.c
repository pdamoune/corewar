/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:14:40 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:08:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <audio.h>

int					end_audio(t_private_audio *device)
{
	t_sound			*audio;
	t_sound			*tmp;

	if (!device->audio_enabled)
		return (ERR_SET(1, E_OPEN, "Audio", "Must call init_audio first"));
	pause_audio(device);
	LIST_FOR_EACH_ENTRY_SAFE_0(audio, tmp, &device->sound, lx);
	while (LIST_FOR_EACH_ENTRY_SAFE_1(audio, tmp, &device->sound, lx))
	{
		free_audio(audio);
	}
	SDL_CloseAudioDevice(device->id);
	device->audio_enabled = 0;
	return (0);
}

int					pause_audio(t_private_audio *device)
{
	if (!device->audio_enabled)
		return (ERR_SET(1, E_OPEN, "Audio", "Must call init_audio first"));
	SDL_PauseAudioDevice(device->id, AUDIO_STOP);
	return (0);
}

int					unpause_audio(t_private_audio *device)
{
	if (!device->audio_enabled)
		return (ERR_SET(1, E_OPEN, "Audio", "Must call init_audio first"));
	SDL_PauseAudioDevice(device->id, AUDIO_START);
	return (0);
}

void				free_audio(t_sound *audio)
{
	if (!audio)
		return ;
	if (audio->free_data == 1)
		SDL_FreeWAV(audio->buffer_true);
	list_del(&audio->lx);
	free(audio);
}

t_sound				*create_audio(const char *filename,
						uint8_t loop, int volume)
{
	t_sound		*new_sound;

	if (filename == NULL)
		return (ERR_SET(NULL, E_SYS_NOFILE, filename));
	if (!(new_sound = malloc(sizeof(t_sound))))
		return (ERR_SET(NULL, E_MALLOC, NULL));
	INIT_LIST_HEAD(&(new_sound->lx));
	new_sound->loop = loop;
	new_sound->fade = 0;
	new_sound->free_data = 1;
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
