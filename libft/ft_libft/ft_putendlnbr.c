/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendlnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/M/ 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/M/ 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					ft_putendlnbr(char *s, int num)
{
	ft_putstr(s);
	ft_putnbr(num);
	ft_putchar('\n');
}
