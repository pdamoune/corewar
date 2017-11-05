/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_audio.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:22:49 by wescande          #+#    #+#             */
/*   Updated: 2017/11/05 16:23:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <audio.h>

static inline void		search_and_replace_music(t_private_audio *device)
{
	uint8_t		music_found;
	t_sound		*sound;

	music_found = 0;
	LIST_FOR_EACH_ENTRY_0(sound, &device->sound, lx);
	while (LIST_FOR_EACH_ENTRY_1(sound, &device->sound, lx))
	{
		if (sound->loop == 1 && sound->fade == 0)
		{
			if (music_found)
			{
				sound->length = 0;
				sound->volume = 0;
			}
			sound->fade = 1;
		}
		else if (sound->loop == 1 && sound->fade == 1)
			music_found = 1;
	}
}

static inline int		common_check(t_private_audio *device,
										uint8_t loop)
{
	if (!device->audio_enabled)
		return (ERR_SET(1, E_CUSTOM_ERR, "Warning", "Audio not enable"));
	if (!loop)
	{
		if (device->sound_count >= AUDIO_MAX_SOUNDS)
			return (ERR_SET(1, E_CUSTOM_ERR, "Warning", "Two many sound"));
		else
			++(device->sound_count);
	}
	return (0);
}

static inline int		common_add(t_private_audio *device,
										uint8_t loop, t_sound *new_sound)
{
	SDL_LockAudioDevice(device->id);
	if (loop == 1)
		search_and_replace_music(device);
	list_add(&(new_sound->lx), &(device->sound));
	SDL_UnlockAudioDevice(device->id);
	return (0);
}

inline int				play_audio(t_private_audio *device,
								const char *filename, uint8_t loop, int volume)
{
	t_sound		*new_sound;

	if (common_check(device, loop))
		return (1);
	if (!filename)
		return (ERR_SET(1, E_CUSTOM_ERR, "Warning", "Filename is NULL"));
	if (!(new_sound = create_audio(filename, loop, volume)))
	{
		return (ERR_SET(1, E_CUSTOM_ERR,
					filename, "Unable to load audio file"));
	}
	return (common_add(device, loop, new_sound));
}

inline int				play_audio_from_memory(t_private_audio *device,
									t_sound *audio, uint8_t loop, int volume)
{
	t_sound *new_sound;

	if (common_check(device, loop))
		return (1);
	if (!audio)
		return (ERR_SET(1, E_CUSTOM_ERR, "Warning", "Audio is NULL"));
	if (!(new_sound = malloc(sizeof(t_sound))))
		return (ERR_SET(1, E_MALLOC, NULL));
	ft_memcpy(new_sound, audio, sizeof(t_sound));
	new_sound->volume = volume;
	new_sound->loop = loop;
	new_sound->free_data = 0;
	return (common_add(device, loop, new_sound));
}
