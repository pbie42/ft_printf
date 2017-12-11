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
	char			c;
	// char* l = setlocale(LC_ALL, "");

	// if (l == NULL) 
	// 	printf("Locale not set\n");
	// else
	// 	printf("Locale set to %s\n", l);

	// ft_putendl(setlocale(LC_CTYPE, NULL));

	if ((i = printf("real: %15.4u", 424242)))
		perror("printf");
	ft_putchar('\n');
	x = ft_printf("mine: %15.4u", 424242);
	ft_putchar('\n');

	ft_putendlnbr("real is ", i);
	ft_putendlnbr("mine is ", x);
	
	return (0);
}
