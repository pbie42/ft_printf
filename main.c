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
	long					s;


	printf("% -5i!\n", 1);
	if (__builtin_types_compatible_p(__typeof__(s), long)) {
		puts("long");
	} else if (__builtin_types_compatible_p(__typeof__(s), char*)) {
			puts("str");
	}
	ft_printf("%5d\n", 500);
	return (0);
}
