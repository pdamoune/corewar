/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_addr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:52:24 by wescande          #+#    #+#             */
/*   Updated: 2017/10/07 00:21:29 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

unsigned int		calc_addr(int addr)
{
	unsigned int	ret_addr;

	ret_addr = 0;
	while (addr < 0)
		addr += MEM_SIZE;
	ret_addr = addr % MEM_SIZE;
	return (ret_addr);
}
