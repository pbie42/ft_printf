/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/17 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					ft_dec_to_oct(long int decimal_number)
{
	int				octal_number;
	int				i;

	octal_number = 0;
	i = 1;
	while (decimal_number != 0)
	{
		octal_number += (decimal_number % 8) * i;
		decimal_number /= 8;
		i *= 10;
	}
	return (octal_number);
}
