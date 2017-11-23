/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/09 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_printf(const char *format, ...)
{
	t_pf				*pf;
	va_list			args;
	int				b;

	va_start(args, format);
	pf = (t_pf *)malloc(sizeof(t_pf) * 1);
	pf->pos = -1;
	pf->bytes = 0;
	pf->format = format;
	b = 0;
	// check_format(pf->format);
	while(pf->format[++pf->pos])
	{
		if (pf->format[pf->pos] == '%' && pf->format[pf->pos + 1]
			&& pf->format[pf->pos + 1] != '%')
				handle_identifier(pf, args);
		else if (pf->format[pf->pos] == '%' && pf->format[pf->pos + 1]
			&& pf->format[pf->pos + 1] == '%')
		{
			ft_putchar(pf->format[++pf->pos]);
			pf->bytes++;
		}
		else
		{
			ft_putchar(pf->format[pf->pos]);
			pf->bytes++;
		}
	}
	va_end(args);
	b = pf->bytes;
	ft_putendlnbr("my bytes: ", b);
	free(pf);
	return (b);
}