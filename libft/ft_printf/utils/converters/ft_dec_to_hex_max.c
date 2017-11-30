/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/11/29 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t					ft_dec_to_hex_max_ter(char *hex, intmax_t n)
{
	intmax_t				temp;
	char				*tmp;

	temp = 0;
	temp = n % 16;
	if (!(tmp = (char *)malloc(sizeof(char) * 1 + 1)))
		ft_exit("malloc problem dec_to_hex_max");
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

intmax_t					ft_dec_to_hex_max_bis(char *hex, intmax_t n)
{
	intmax_t				temp;

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

char					*ft_dec_to_hex_max(intmax_t n)
{
	char				*hex;

	hex = (char *)malloc(sizeof(char) * 1 + 1);
	n = ft_dec_to_hex_max_bis(hex, n);
	while (n != 0)
		n = ft_dec_to_hex_max_ter(hex, n);
	return (hex);
}