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
	char* l = setlocale(LC_ALL, "");

	// if (l == NULL) 
	// 	printf("Locale not set\n");
	// else
	// 	printf("Locale set to %s\n", l);

	// ft_putendl(setlocale(LC_CTYPE, NULL));

	ft_printf("mine: \n");
	ft_printf("mine: %%\n");
	ft_printf("mine: %d\n", 42);
	ft_printf("mine: %d%d\n", 42, 41);
	ft_printf("mine: %d%d%d\n", 42, 43, 44);
	ft_printf("mine: %ld\n", 2147483647);
	ft_printf("mine: %lld\n", 9223372036854775807);
	ft_printf("mine: %x\n", 505);
	ft_printf("mine: %X\n", 505);
	ft_printf("mine: %p\n", &ft_printf);
	ft_printf("mine: %20.15d\n", 54321);
	ft_printf("mine: %-10d\n", 3);
	ft_printf("mine: % d\n", 3);
	ft_printf("mine: %+d\n", 3);
	ft_printf("mine: %010d\n", 1);
	ft_printf("mine: %hhd\n", 0);
	ft_printf("mine: %jd\n", 9223372036854775807);
	ft_printf("mine: %zd\n", 4294967295);
	ft_printf("mine: %\n");
	ft_printf("mine: %U\n", 4294967295);
	ft_printf("mine: %u\n", 4294967295);
	ft_printf("mine: %o\n", 40);
	ft_printf("mine: %%#08x\n", 42);
	ft_printf("mine: %x\n", 1000);
	ft_printf("mine: %#X\n", 1000);
	ft_printf("mine: %s\n", NULL);
	ft_printf("mine: %S\n", L"ݗݜशব");
	ft_printf("mine: %s%s\n", "test", "test");
	ft_printf("mine: %s%s%s\n", "test", "test", "test");
	ft_printf("mine: %C\n", 15000);

	// printf("real: \n");
	// printf("real: %%\n");
	// printf("real: %d\n", 42);
	// printf("real: %d%d\n", 42, 41);
	// printf("real: %d%d%d\n", 42, 43, 44);
	// printf("real: %ld\n", 2147483647);
	// printf("real: %lld\n", 9223372036854775807);
	// printf("real: %x\n", 505);
	// printf("real: %X\n", 505);
	// printf("real: %p\n", &ft_printf);
	// printf("real: %20.15d\n", 54321);
	// printf("real: %-10d\n", 3);
	// printf("real: % d\n", 3);
	// printf("real: %+d\n", 3);
	// printf("real: %010d\n", 1);
	// printf("real: %hhd\n", 0);
	// printf("real: %jd\n", 9223372036854775807);
	// printf("real: %zd\n", 4294967295);
	// printf("real: %\n");
	// printf("real: %U\n", 4294967295);
	// printf("real: %u\n", 4294967295);
	// printf("real: %o\n", 40);
	// printf("real: %%#08x\n", 42);
	// printf("real: %x\n", 1000);
	// printf("real: %#X\n", 1000);
	// printf("real: %s\n", NULL);
	// printf("real: %S\n", L"ݗݜशব");
	// printf("real: %s%s\n", "test", "test");
	// printf("real: %s%s%s\n", "test", "test", "test");
	// printf("real: %C\n", 15000);
	
	return (0);
}
