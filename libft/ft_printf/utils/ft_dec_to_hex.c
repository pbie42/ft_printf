/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/17 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int					ft_dec_to_hex_bis(char *hex, long int n)
{
	int				temp;
	char				*tmp;

	temp = 0;
	temp = n % 16;
	tmp = (char *)malloc(sizeof(char) * 1 + 1);
	if (temp < 10)
	{
		tmp[0] = temp + 48;
		tmp[1] = '\0';
		hex = ft_strcat(hex, tmp);
	}
	else
	{
		tmp[0] = temp + 55;
		tmp[1] = '\0';
		hex = ft_strcat(hex, tmp);
	}
	free(tmp);
	n = n / 16;
	return (n);
}

char					*ft_dec_to_hex(long int n)
{
	char				*hex;

	hex = (char *)malloc(sizeof(char) * 1 + 1);
	n = ft_dec_to_hex_bis(hex, n);
	while (n != 0)
		n = ft_dec_to_hex_bis(hex, n);
	return (hex);
}