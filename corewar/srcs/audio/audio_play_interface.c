/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_play_interface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:27:07 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:07:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <audio.h>

int					play_sound(t_private_audio *device,
								const char *filename, int volume)
{
	return (play_audio(device, filename, 0, volume));
}

int					play_music(t_private_audio *device,
								const char *filename, int volume)
{
	return (play_audio(device, filename, 1, volume));
}

int					play_sound_from_memory(t_private_audio *device,
								t_sound *audio, int volume)
{
	return (play_audio_from_memory(device, audio, 0, volume));
}

int					play_music_from_memory(t_private_audio *device,
								t_sound *audio, int volume)
{
	return (play_audio_from_memory(device, audio, 1, volume));
}
