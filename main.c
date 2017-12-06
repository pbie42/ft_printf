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

int						main(void){
	int					i;
	int					x;
	int					rem;
	int					*address;
	long					s;
	double				dub;
	char* l = setlocale(LC_ALL, "en_US.UTF-8");


	i = 2545;
	address = &i;
	dub = 15.45;
	s = 500;
	
	// if (l == NULL) 
	// 	printf("Locale not set\n");
	// else
	// 	printf("Locale set to %s\n", l);
	// ft_putnbr(printf("%lc", 945));
	// ft_putstr(ft_itoa(dub));
	// ft_putchar('\n');
	// if (__builtin_types_compatible_p(__typeof__(s), long)) {
	// 	puts("long");
	// } else if (__builtin_types_compatible_p(__typeof__(s), char*)) {
	// 	puts("str");
	// }
	i = 3 / 2;
	rem = 3 % 2;
	x = 15;
	// i = printf("%S!\n", L"漢字");
	// rem = printf("%C!\n", 23588);
	printf("%lu\n", -42);
	// printf("x is: %010x\n", &x);
	// printf("Capital C is: %C!\n", 1588);
	// printf("printf address is: %-020p!\n", &x);
	// ft_printf("%lx\n", 4294967296);
	ft_printf("%lu\n", -42);
	// ft_printf("%010x!\n", &x);
	// ft_printf("%C!\n", 23588);
	return (0);
}

// ft_printf("%+10.5d", 4242);
//   1. (   10) -->+    04242<--
//   2. (   10) -->    +04242<--

// ft_printf("%0+5d", 42);
//   1. (    5) -->00+42<--
//   2. (    5) -->+0042<--