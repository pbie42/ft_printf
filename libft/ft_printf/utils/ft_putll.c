/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/24 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						ft_putll(long long int nb)
{
	if (nb == LONG_MIN)
		ft_putstr("-9223372036854775808");
	if (nb < 0 && nb != LONG_MIN)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10 && nb != LONG_MIN)
	{
		ft_putll(nb / 10);
		ft_putll(nb % 10);
	}
	else if (nb != LONG_MIN)
	{
		ft_putll(nb + '0');
	}
}