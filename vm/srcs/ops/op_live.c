/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:42:01 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/27 17:46:37 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Instruction live 
** opcode 0x01.
** The only argument is on 4 bytes.
**
** ex : 01 | ff ff ff ff
**
** Allows a process to stay alive.
** It can also record that the player whose number is the argument is alive.
** No argument’s coding byte,
*/
