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
	int					*address;
	long					s;
	double				dub;


	i = 2545;
	address = &i;
	dub = 15.45;
	s = 500;
	// ft_putstr(ft_itoa(dub));
	// ft_putchar('\n');
	// if (__builtin_types_compatible_p(__typeof__(s), long)) {
	// 	puts("long");
	// } else if (__builtin_types_compatible_p(__typeof__(s), char*)) {
	// 	puts("str");
	// }
	printf("%10s!\n", "Hello");
	ft_printf("%10s!\n", "Hello");
	return (0);
}
