/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/17 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					print_address(va_list args)
{
	int				ptr;
	// int				address;
	const char	*tmp;
	// char string[]="0123456789ABCDEF";

	ptr = va_arg(args, int);                 // store 16-bit address, and then pretend that memory is a character array
	tmp = (const char*) &ptr; // MSB
	ft_putendl(tmp);
}