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
	int					rem;
	int					*address;
	long					s;
	double				dub;
	char* l = setlocale(LC_ALL, "en_US.UTF-8");


	i = 2545;
	address = &i;
	dub = 15.45;
	s = 500;
	
	if (l == NULL) 
		printf("Locale not set\n");
	else
		printf("Locale set to %s\n", l);
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
	// printf("Capital S is: %S!\n", L"漢字");
	// printf("Capital C is: %C!\n", 23588);
	// printf("Capital C is: %C!\n", 1588);
	i = printf("%d", 500);
	ft_printf("%d!\n", i);
	return (0);
}
