/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:43:45 by wescande          #+#    #+#             */
/*   Updated: 2017/09/01 16:45:30 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GTK_H
# define GTK_H

# include <corewar.h>
# define COR				((t_cor *)singleton(NULL))

/*
** VM FLAGS
*/
# define STOP				(1 << 0)
# define PAUSE				(STOP << 1)
# define PLAY				(PAUSE << 1)
# define END				(PLAY << 1)
# define GRAPHIC			(END << 1)

#endif