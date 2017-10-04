/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/04 15:25:03 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#define MAX_CHANNELS 2
#define BUFFER_LEN 1024
// typedef struct
// {
//     float left_phase;
//     float right_phase;
// }   
// paTestData;
// /* This routine will be called by the PortAudio engine when audio is needed.
//    It may called at interrupt level on some machines so don't do anything
//    that could mess up the system like calling malloc() or free().
// */ 
// static int patestCallback( const void *inputBuffer, void *outputBuffer,
//                            unsigned long framesPerBuffer,
//                            const PaStreamCallbackTimeInfo* timeInfo,
//                            PaStreamCallbackFlags statusFlags,
//                            void *userData )
// {
//     /* Cast data passed through stream to our structure. */
//     paTestData *data = (paTestData*)userData; 
//     float *out = (float*)outputBuffer;
//     unsigned int i;
//     (void) inputBuffer; /* Prevent unused variable warning. */
// 	(void)timeInfo;
// 	(void)statusFlags;
    
//     for( i=0; i<framesPerBuffer; i++ )
//     {
//         *out++ = data->left_phase;  /* left */
//         *out++ = data->right_phase;  /* right */
//         /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
//         data->left_phase += 0.01f;
//         /* When signal reaches top, drop back down. */
//         if( data->left_phase >= 1.0f ) data->left_phase -= 2.0f;
//         /* higher pitch so we can distinguish left and right. */
//         data->right_phase += 0.03f;
//         if( data->right_phase >= 1.0f ) data->right_phase -= 2.0f;
//     }
//     return 0;
// }

static int		gtk_cycle(t_vm *vm)
{
	char	txt[12];

	vm->gtk.time = g_get_monotonic_time();
	if (IS_SETREMOVE(vm->flag, STEP) || (vm->gtk.time - vm->gtk.oldtime) * vm->gtk.speed > 1000000)
	{
		iter_on_px(vm);
		if (do_one_cycle(vm))
			return (1);
		ft_itoa_nomalloc(vm->cycle, txt);
		gtk_label_set_label(GTK_LABEL(vm->gtk.panel.cpt), txt);
		if (vm->gtk.panel.process)
			update_process(vm, vm->gtk.panel.process, 0);
		vm->gtk.oldtime = vm->gtk.time;
	}
	return (0);
}

static gboolean	gtk_loop(void *data)
{
	t_vm	*vm;

	vm = (t_vm *)data;
	vm->gtk.time = g_get_monotonic_time();
	while(IS_UNSET(vm->flag, STOP))
	{
		if (IS_UNSET(vm->flag, END) && (IS_UNSET(vm->flag, PAUSE) || IS_SET(vm->flag, STEP)))
		{
			if (gtk_cycle(vm))
				break;
		}
		while (gtk_events_pending())
			if (gtk_main_iteration())
				return (FALSE);
	}
	vm->gtk.time = g_get_monotonic_time();
	while (g_get_monotonic_time() - vm->gtk.time < 100000)
		;
	gtk_main_quit();
	return (FALSE);
}

static int	gtk_run(t_vm *vm)
{
	g_idle_add(gtk_loop, vm);
	gtk_main();
	vm->gtk.time = g_get_monotonic_time();
	while (g_get_monotonic_time() - vm->gtk.time < 100000)
		;
	if (vm->gtk.surface)
		cairo_surface_destroy(vm->gtk.surface);
	return (free_vm(vm));
}

static int	console_run(t_vm *vm)
{
	int ret;

	ret = 0;
	// DG("START");
	//TODO introducing contestants
	// while (IS_UNSET(vm->flag, STOP))
	while (IS_ONEUNSET(vm->flag, END | STOP | PAUSE)) //TODO check if correct for ending in console
	{
		// display(vm);
		ret = do_one_cycle(vm);
		if (ret)
			break;
	}
	// DG("END at cycle %d", vm->cycle);
	// if (!ret)//retiré car normalement c'est fait dans le check
	// 	ret = display_win(vm);
	return (free_vm(vm) || ret);
}
		// #define SAMPLE_RATE (44100)
// static paTestData data;
// #define MUS_PATH "slash.wav"

// Uint8 *audio_pos; // global pointer to the audio buffer to be played
// Uint32 audio_len; // remaining length of the sample we have to play

// audio callback function
// here you have to copy the data of your audio buffer into the
// requesting audio buffer (stream)
// you should only copy as much as the requested length (len)



int		main(int ac, char **av)
{
	t_vm		vm;
		// ft_bzero(&vm, sizeof(t_vm));

	// PaError		err;
	// DG("%p<<<", &vm);



	// local variables
	
	
	/* Start playing */
	// SDL_PauseAudio(0);

// DG();
// init_allegro(&vm);
// DG();
// play_allegro(&vm);
// DG();
// sleep(3);
// DG();
// stop_allegro(&vm);
// DG();
// destroy_allegro(&vm);
// DG();
// return (0);
// printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
	// if ((err = Pa_Initialize()) != paNoError )
	// 	return (verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err)));
	// SNDFILE* sndFile = NULL;
	// SF_INFO sfInfo;
	// ft_bzero(&sfInfo, sizeof(SF_INFO));
	// sndFile = sf_open(MUSIC_FILE, SFM_READ, &sfInfo);
	
    // if (! sndFile)
    // {
	// 	Pa_Terminate();
	// 	return (verbose(&vm, MSG_ERROR, "Sndf error: %s\n", "error_sf_open_failed"));
    // }
    // if (sfInfo.channels > MAX_CHANNELS)
    // {
    //     Pa_Terminate();
	// 	return (verbose(&vm, MSG_ERROR, "Sndf error: %s: %d\n", "error_too_many_channels", sfInfo.channels));
    // }
    // PaStream *stream = NULL;
	
    // PaStreamParameters paStreamParameters;
    // paStreamParameters.device = Pa_GetDefaultOutputDevice();
    // paStreamParameters.channelCount = sfInfo.channels;
    // paStreamParameters.sampleFormat = paInt32;
    // paStreamParameters.suggestedLatency = Pa_GetDeviceInfo(paStreamParameters.device)->defaultLowOutputLatency;
    // paStreamParameters.hostApiSpecificStreamInfo = NULL;
	
    // err = Pa_OpenStream(
    //     &stream, NULL, &paStreamParameters,
    //     sfInfo.samplerate, paFramesPerBufferUnspecified, paClipOff,
    //     NULL, NULL);
    // /* Open an audio I/O stream. */
    // // err = Pa_OpenDefaultStream( &stream,
    // //                             0,          /* no input channels */
    // //                             2,          /* stereo output */
    // //                             paFloat32,  /* 32 bit floating point output */
    // //                             SAMPLE_RATE,
    // //                             256,        /* frames per buffer, i.e. the number
    // //                                                of sample frames that PortAudio will
    // //                                                request from the callback. Many apps
    // //                                                may want to use
    // //                                                paFramesPerBufferUnspecified, which
    // //                                                tells PortAudio to pick the best,
    // //                                                possibly changing, buffer size.*/
    // //                             patestCallback, /* this is your callback function */
    // //                             &data ); /*This is a pointer that will be passed to
    // //                                                your callback*/
	// if (err != paNoError)
	// 	return (verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err)));
	// if ((err = Pa_StartStream(stream)) != paNoError)
	// 	return (verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err)));
		
		
    // int subFormat = sfInfo.format & SF_FORMAT_SUBMASK;
    // double scale = 1.0;
    // if (subFormat == SF_FORMAT_FLOAT || subFormat == SF_FORMAT_DOUBLE)
    // {
    //     sf_command(sndFile, SFC_CALC_SIGNAL_MAX, &scale, sizeof(scale));
    //     if (scale < 1e-10)
    //     {
    //         scale = 1.0;
    //     }
    //     else
    //     {
    //         scale = 32700.0 / scale;
    //     }
    // }
	
    // sf_count_t readCount = 0;
    // float data[BUFFER_LEN];
	// ft_bzero(data, BUFFER_LEN);
	
	//  while ((readCount = sf_read_float(sndFile, data, BUFFER_LEN)))
    // {
    //     if (subFormat == SF_FORMAT_FLOAT || subFormat == SF_FORMAT_DOUBLE)
    //     {
    //         int m = 0;
    //         for (m = 0 ; m < readCount ; ++m)
    //         {
    //             data[m] *= scale;
    //         }
    //     }
    //     err = Pa_WriteStream(stream, data, BUFFER_LEN);
    //     if (err != paNoError)
    //     {
	// 		verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err));
    //         // message = str(format(playSoundStrings[error_pa_write_stream_failed]) % Pa_GetErrorText(paError));
    //         // SoundWarning(message);
    //         break;
    //     }
	// 	// Pa_Sleep(35);
	// ft_bzero(data, BUFFER_LEN);
    //     // ::memset(data, 0, sizeof(data));
    // }
	// 	if ((err = Pa_CloseStream(stream)) != paNoError)
	// 	return (verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err)));
	// if ((err = Pa_Terminate()) != paNoError)
	// 	return (verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err)));
	// return (0);
	// Pa_Sleep(5*1000);
	if (init_vm_memory(&vm, &ac, &av))
		return (1);
	if (init_vm_value(&vm))
		return (1);
	if (IS_SET(vm.flag, GRAPHIC))
		return (gtk_run(&vm));
		// gtk_run(&vm);
	else
		return (console_run(&vm));
		// console_run(&vm);
		
	// shut everything down

// 	if ((err = Pa_AbortStream(stream)) != paNoError)
// 		return (verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err)));
// 	if ((err = Pa_CloseStream(stream)) != paNoError)
// 		return (verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err)));
// 	if ((err = Pa_Terminate()) != paNoError)
// 		return (verbose(&vm, MSG_ERROR, "PortAudio error: %s\n", Pa_GetErrorText(err)));
	return (0);
}
		
// #include <stdio.h>
// #include <stdlib.h>
// #include <gtk/gtk.h>

// int main( int   argc,
//           char *argv[] )
// {
//     GtkWidget *window;

//     gtk_init (&argc, &argv);

//     /* create a new window */
//     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//     gtk_widget_set_size_request (GTK_WIDGET (window), 200, 100);
//     gtk_window_set_title (GTK_WINDOW (window), "GTK Entry");
//     g_signal_connect (window, "destroy",
//                       G_CALLBACK (gtk_main_quit), NULL);
//     g_signal_connect_swapped (window, "delete-event",
//                               G_CALLBACK (gtk_widget_destroy), 
//                               window);

   
//     gtk_widget_show (window);

//     gtk_main();

//     return 0;
// }