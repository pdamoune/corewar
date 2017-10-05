/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_speech.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:57:11 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:22:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			text_to_speech(t_vm *vm, char *str)
{
	pid_t		pid;
	char		*tab[5];
	int			ret;

	if ((pid = fork()) == -1)
		return (verbose(vm, MSG_ERROR, "fork: %s", strerror(errno)));
	else if (!pid)
	{
		tab[0] = (char*)("/usr/bin/say");
		tab[1] = (char*)("-v");
		tab[2] = (char*)("Victoria");
		tab[3] = str;
		tab[4] = NULL;
		execv(tab[0], tab);
		verbose(vm, MSG_ERROR, "execve: %s", strerror(errno));
		exit(1);
	}
	waitpid(pid, &ret, WUNTRACED);
	if (ret)
		verbose(vm, MSG_ERROR, "Check that /usr/bin/say exist & works.", NULL);
	usleep(500000);
	return (ret);
}
