/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_allegro.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 21:11:47 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 21:12:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		destroy_allegro(t_vm *vm)
{
	t_allegro *allegro;

	allegro = &(vm->allegro);
	al_set_sample(allegro->sample, NULL);
	al_destroy_sample(allegro->sample_data);
	al_destroy_sample_instance(allegro->sample);
	al_destroy_mixer(allegro->mixer);
	al_destroy_voice(allegro->voice);
	al_uninstall_audio();
}