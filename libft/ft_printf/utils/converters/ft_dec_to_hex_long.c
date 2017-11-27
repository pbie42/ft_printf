/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/11/27 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long int					ft_dec_to_hex_long_ter(char *hex, unsigned long long int n)
{
	unsigned long long int				temp;
	char				*tmp;

	temp = 0;
	temp = n % 16;
	if (!(tmp = (char *)malloc(sizeof(char) * 1 + 1)))
		ft_exit("malloc problem dec_to_hex_long");
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

unsigned long long int					ft_dec_to_hex_long_bis(char *hex, unsigned long long int n)
{
	unsigned long long int				temp;

	temp = 0;
	temp = n % 16;
	if (temp < 10)
	{
		hex[0] = temp + 48;
		hex[1] = '\0';
	}
	else
	{
		hex[0] = temp + 55;
		hex[1] = '\0';
	}
	n = n / 16;
	return (n);
}

char					*ft_dec_to_hex_long(unsigned long long int n)
{
	char				*hex;

	hex = (char *)malloc(sizeof(char) * 1 + 1);
	n = ft_dec_to_hex_long_bis(hex, n);
	while (n != 0)
		n = ft_dec_to_hex_long_ter(hex, n);
	return (hex);
}