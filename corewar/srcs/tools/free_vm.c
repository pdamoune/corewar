/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:26:06 by wescande          #+#    #+#             */
/*   Updated: 2017/10/04 16:38:54 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		free_vm(t_vm *vm)
{
	remove_all_process(vm);
	end_audio();
	free_audio(vm->sound);
	SDL_CloseAudio();
	SDL_Quit();

	// SDL_FreeWAV(vm->audio.audio_pos_reset);
	// SDL_FreeWAV(vm->audio.audio_pos_reset_back);
	// stop_allegro(vm);
	// destroy_allegro(vm);
	return (0);
}
