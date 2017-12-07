/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umaxitoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_umaxitoa(uintmax_t n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if ((unsigned long long)n == -9223372036854775808U)
		return (ft_strcpy(str, "9223372036854775808"));
	if ((uintmax_t)n == 9223372036854775807)
		return (ft_strcpy(str, "9223372036854775807"));
	if (n >= 10)
		str = ft_strjoin(ft_llitoa(n / 10), ft_llitoa(n % 10));
	else if (n < 10)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
