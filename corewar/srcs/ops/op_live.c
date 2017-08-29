/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:42:01 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/29 19:26:01 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_live(t_op param)
{
	(void)&param;
	DG("");
	return (0);
}


// live : L’instruction qui permet à un processus de rester vivant.
// A également pour effet de rapporter que le joueur dont le numéro est
// en paramètre est en vie. Pas d’octet de codage des paramètres, opcode 0x01.
// Oh, et son seul paramètre est sur 4 octets.
//
// Suivie de 4 octets qui représente le numéro du joueur.
// Cette instruction indique que ce joueur est en vie.
// Pas d’octet de codage des paramètres.
//
// Live
// 0x01
// Usage : live S(D4)
// Durée : 10
// Octet de codage des parametres : Non
// Modifie le carry : Non
// Rapporte le joueur designé par le premier parametre comme etant en vie.
// L'instruction ecrit sur la sortie standard un message du type
// "Le joueur $player_name ( $player_id ), a été raporter comme étant en vie".
// Libre a vous de 'pimper' le message comme bon vous semble, du moment que
// l'idée passe et qu'il contienne les variables sus nommée. Un joueur ne vie
// que tant qu'au moins un processus effectue un live avec sont id, et ce au
// minimun une fois tout les CYCLE_TO_DIE. Si le parametre passé ne correspond
// a l'id d'aucun joueurs, le comportement est indefinit. A vous de decider si
// c'est une erreur et que le processus crash, ou si osef, l'instruction ne fait
// rien et on passe a la suite, avec eventuelement en supplément un petit message
// sur la sortie standard, message incohérent ou message d'avertissement, votre
// seul limite est celle de votre creativité.

/*
** Instruction live
**
** Opcode 0x01.
** The only argument is on 4 bytes.
** Cycles : 10
** Carry : No
**
** ex : 01 | ff ff ff ff
**
** Allows a process to stay alive.
** It can also record that the player whose number is the argument is alive.
** No argument’s coding byte,
*/
