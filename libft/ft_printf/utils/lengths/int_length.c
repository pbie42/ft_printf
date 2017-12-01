/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/16 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					int_length(long long int num)
{
	int				counter;
	long long int	anum;

	anum = llabs(num);
	if (anum == 0)
		return (1);
	counter = 0;
	while (anum > 0)
	{
		anum = anum / 10;
		counter ++;
	}
	return (counter);
}