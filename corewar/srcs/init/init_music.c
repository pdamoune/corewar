/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:53:14 by wescande          #+#    #+#             */
/*   Updated: 2017/10/04 16:39:20 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
// void my_audio_callback(void *userdata, uint8_t *stream, int len) {
// 	t_vm *vm
	
// 	vm = (t_vm *)userdata;
// 	if (vm->audio.audio_len ==0)
// 	{
// 		if (vm->audio.is_play)
// 		{
// 			vm->audio.is_play = 0;
// 			vm->audio.audio_pos = vm->audio.audio_pos_tmp + vm->audio.audio_len_reset;
// 			vm->audio.audio_len = vm->audio.audio_len_tmp + vm->audio.audio_len_reset;
// 		}
// 		else
// 		{
// 			vm->audio.audio_pos = vm->audio.audio_pos_reset_back;
// 			vm->audio.audio_len = vm->audio.audio_len_reset_back;
// 		}
// 		return;
// 	}
// 	len = ( (Uint32)len > vm->audio.audio_len ? vm->audio.audio_len : len );
// 	SDL_memcpy (stream, vm->audio.audio_pos, len);
// 	vm->audio.audio_pos += len;
// 	vm->audio.audio_len -= len;
// }

int		init_music(t_vm *vm)
{
	if(SDL_Init(SDL_INIT_AUDIO) < 0)
		return (verbose(vm, MSG_ERROR, "Failed to SDL_Init.", NULL));
	if (init_audio())
		return (verbose(vm, MSG_ERROR, "Failed to init_audio.", NULL));
	play_music(MUSIC_FILE_BACK, SDL_MIX_MAXVOLUME);
	vm->sound = create_audio(MUSIC_FILE_SLASH, 0, SDL_MIX_MAXVOLUME / 2);

	// SDL_AudioSpec		wav_spec;

	// if (SDL_Init(SDL_INIT_AUDIO) < 0)
	// 	return (verbose(vm, MSG_ERROR, "SDL_Init as failed", NULL));
	// if (!SDL_LoadWAV(MUSIC_FILE_SLASH, &wav_spec, &(vm->audio.audio_pos_slash), &(vm->audio.audio_len_slash)))
	// 	return (verbose(vm, MSG_ERROR, "%s: SDL_LoadWAV as failed", MUSIC_FILE_SLASH));
	// // set the callback function
	// wav_spec.callback = my_audio_callback;
	// wav_spec.userdata = vm;
	// // set our global static variables
	// // vm->audio.audio_pos = wav_buffer; // copy sound buffer
	// // vm->audio.audio_len = wav_length; // copy file length
	
	// // vm->audio.audio_pos_reset = vm->audio.audio_pos; // copy sound buffer
	// // vm->audio.audio_len_reset = vm->audio.audio_len; // copy file length
	// // DG("%d<<<<<<<<<<", vm->audio.audio_len);
	
	// /* Open the audio device */
	// if (SDL_OpenAudio(&wav_spec, NULL) < 0 )
	// 	return (verbose(vm, MSG_ERROR, "%s: SDL_OpenAudio as failed", MUSIC_FILE_SLASH));
		
	// if (!SDL_LoadWAV(MUSIC_FILE_BACK, &wav_spec, &(vm->audio.audio_pos_reset_back), &(vm->audio.audio_len_reset_back)))
	// 	return (verbose(vm, MSG_ERROR, "%s: SDL_LoadWAV as failed", MUSIC_FILE_BACK));
		
	// vm->audio.audio_pos = vm->audio.audio_pos_reset_back; // copy sound buffer
	// // DG("%d", audio_len);
	
	// vm->audio.audio_len = vm->audio.audio_len_reset_back; // copy file length
	// 	SDL_PauseAudio(0);

	// // set the callback function
	// // wav_spec.callback = my_audio_callback;
	// // wav_spec.userdata = &vm;
	// // set our global static variables
	// // vm->audio.audio_pos = wav_buffer; // copy sound buffer
	// // vm->audio.audio_len = wav_length; // copy file length
	
	// // vm->audio.audio_pos_reset = vm->audio.audio_pos; // copy sound buffer
	// // vm->audio.audio_len_reset = vm->audio.audio_len; // copy file length
	// // DG("%d<<<<<<<<<<", vm->audio.audio_len);
	
	// /* Open the audio device */
	// // if (SDL_OpenAudio(&wav_spec, NULL) < 0 )
	// 	// return (verbose(vm, MSG_ERROR, "%s: SDL_OpenAudio as failed", MUSIC_FILE_BACK));
	// //   fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
	// //   exit(-1);
	// // }
	return (0);
}