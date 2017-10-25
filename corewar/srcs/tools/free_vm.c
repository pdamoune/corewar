/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:26:06 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:41:18 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		free_vm(t_vm *vm)
{
	remove_all_process(vm);
	end_audio(&(vm->audio));
	SDL_CloseAudio();
	SDL_Quit();
	return (0);
}
