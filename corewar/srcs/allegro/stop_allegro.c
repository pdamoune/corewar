/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_allegro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 21:10:52 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 21:11:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		stop_allegro(t_vm *vm)
{
	t_allegro *allegro;

	allegro = &(vm->allegro);
	al_stop_sample_instance(allegro->sample);
}