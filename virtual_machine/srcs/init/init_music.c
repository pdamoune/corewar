/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:53:14 by wescande          #+#    #+#             */
/*   Updated: 2017/11/05 16:22:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_music(t_vm *vm)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return (verbose(vm, MSG_ERROR, "Failed to SDL_Init.", NULL));
	if (init_audio(&(vm->audio)))
	{
		return (verbose(vm, MSG_ERROR, "Failed to init_audio: %s",
				ft_strerror(g_errnum)));
	}
	if (play_music(&(vm->audio), MUSIC_FILE_INTRO, SDL_MIX_MAXVOLUME))
	{
		return (verbose(vm, MSG_ERROR, "Failed to init_audio: %s",
				ft_strerror(g_errnum)));
	}
	vm->slash = create_audio(MUSIC_FILE_SLASH, 0, SDL_MIX_MAXVOLUME / 2);
	return (0);
}
