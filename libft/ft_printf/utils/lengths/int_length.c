/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 13:20:58 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					int_length(intmax_t num)
{
	int				counter;
	intmax_t		anum;

	if ((unsigned long long)num == -9223372036854775808U)
		return (19);
	if (num < 0)
		anum = num * -1;
	else
		anum = num;
	if (anum == 0)
		return (1);
	counter = 0;
	while (anum > 0)
	{
		anum = anum / 10;
		counter++;
	}
	return (counter);
}
