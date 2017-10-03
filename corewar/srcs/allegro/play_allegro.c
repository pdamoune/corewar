/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_allegro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 21:08:12 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 21:57:40 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		play_allegro(t_vm *vm)
{
	t_allegro *allegro;

DG();
	allegro = &(vm->allegro);
	al_set_sample_instance_playmode(allegro->sample, ALLEGRO_PLAYMODE_ONCE);
	al_play_sample_instance(allegro->sample);
}