/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 13:23:35 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long int				ft_address_to_hex_ter(char *hex, long int n)
{
	int					temp;
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

long int				ft_address_to_hex_bis(char *hex, long int n)
{
	int					temp;

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

char					*ft_address_to_hex(long int n)
{
	char				*hex;

	hex = (char *)malloc(sizeof(char) * 1 + 1);
	n = ft_address_to_hex_bis(hex, n);
	while (n != 0)
		n = ft_address_to_hex_ter(hex, n);
	return (hex);
}
