/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_addr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:52:24 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:40:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		calc_addr(int addr)
{
	addr %= MEM_SIZE;
	if (addr < 0)
		return (addr + MEM_SIZE);
	return (addr);
}
