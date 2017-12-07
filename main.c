/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/09 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				main(void){
	int			i;
	int			x;
	unsigned long	ul;

	i = printf("real: %O", LONG_MAX);
	ft_putchar('\n');
	x = ft_printf("mine: %O", LONG_MAX);
	ft_putchar('\n');

	ft_putendlnbr("real is ", i);
	ft_putendlnbr("mine is ", x);
	
	return (0);
}
