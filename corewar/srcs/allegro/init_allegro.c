/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_allegro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:30:19 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 21:40:26 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int init_allegro(t_vm *vm)
{
	t_allegro *allegro;
	
	allegro = &vm->allegro;
	// float longest_sample;

	if (!al_init())
		return (verbose(vm, MSG_ERROR, "Could not init Allegro.", NULL));
	al_init_acodec_addon();
	if (!al_install_audio())
		return (verbose(vm, MSG_ERROR, "Could not init sound.", NULL));
	if (!(allegro->voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_INT16,
		ALLEGRO_CHANNEL_CONF_2)))
		return (verbose(vm, MSG_ERROR, "Could not create ALLEGRO_VOICE from sample.", NULL));
	if (!(allegro->mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32,
		ALLEGRO_CHANNEL_CONF_2)))
		return (verbose(vm, MSG_ERROR, "al_create_mixer failed.", NULL));
	if (!al_attach_mixer_to_voice(allegro->mixer, allegro->voice))
		return (verbose(vm, MSG_ERROR, "al_attach_mixer_to_voice failed.", NULL));
	if (!(allegro->sample = al_create_sample_instance(NULL)))
		return (verbose(vm, MSG_ERROR, "al_create_sample failed.", NULL));
	if (!(allegro->sample_data = al_load_sample(MUSIC_FILE)))
		return (verbose(vm, MSG_ERROR, "Could not load sample from '%s'!", MUSIC_FILE));
	if (!al_set_sample(allegro->sample, allegro->sample_data))
		return (verbose(vm, MSG_ERROR, "al_set_sample_instance_ptr failed.", NULL));
	if (!al_attach_sample_instance_to_mixer(allegro->sample, allegro->mixer))
		return (verbose(vm, MSG_ERROR, "al_attach_sample_instance_to_mixer failed.", NULL));
	return (0);
}