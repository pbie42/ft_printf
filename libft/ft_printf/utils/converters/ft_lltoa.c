/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/03 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_llitoa(intmax_t n) {
    char buf[sizeof(int)*CHAR_BIT/3 + 3];
    char *s;
    intmax_t v;

		if ((unsigned long long)n == -9223372036854775808U)
			return ("9223372036854775808");
		if ((uintmax_t)n == 9223372036854775807)
			return ("9223372036854775807");
    v = n;
    if (n < 0) {
        v = -v;
    }
    s = buf + sizeof(buf);
    *--s = '\0';
    while (v >= 10) {
        *--s = '0' + v % 10;
        v /= 10;
    }
    *--s = '0' + v;
    if (n < 0)
        *--s = '-';
    return ft_strdup(s);
}

// char		*ft_llitoa(intmax_t n)
// {
// 	char	*str;

// 	if (!(str = (char *)malloc(sizeof(char) * 2)))
// 		return (NULL);
// 	if ((unsigned long long)n == -9223372036854775808U)
// 		return (ft_strcpy(str, "9223372036854775808"));
// 	if ((uintmax_t)n == 9223372036854775807)
// 		return (ft_strcpy(str, "9223372036854775807"));
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		str[1] = '\0';
// 		str = ft_strjoin(str, ft_llitoa(-n));
// 	}
// 	else if (n >= 10)
// 		str = ft_strjoin(ft_llitoa(n / 10), ft_llitoa(n % 10));
// 	else if (n < 10 && n >= 0)
// 	{
// 		str[0] = n + '0';
// 		str[1] = '\0';
// 	}
// 	return (str);
// }
