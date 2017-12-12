/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 16:46:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					inc_putchar_byte(t_pf *pf)
{
	ft_putchar(pf->format[++pf->pos]);
	pf->bytes++;
}

void					putchar_byte(t_pf *pf)
{
	ft_putchar(pf->format[pf->pos]);
	pf->bytes++;
}

int						ft_printf(const char *format, ...)
{
	t_pf				*pf;
	va_list				args;
	int					b;

	va_start(args, format);
	pf = (t_pf *)malloc(sizeof(t_pf) * 1);
	pf->pos = -1;
	pf->bytes = 0;
	pf->format = format;
	b = 0;
	while (pf->format[++pf->pos] && pf->bytes != -1)
		if (pf->format[pf->pos] == '%' && !pf->format[pf->pos + 1])
			;
		else if (pf->format[pf->pos] == '%' && pf->format[pf->pos + 1]
			&& pf->format[pf->pos + 1] != '%')
			handle_identifier(pf, args);
		else if (pf->format[pf->pos] == '%' && pf->format[pf->pos + 1]
			&& pf->format[pf->pos + 1] == '%')
			inc_putchar_byte(pf);
		else
			putchar_byte(pf);
	va_end(args);
	if (pf->bytes == -1)
		return (-1);
	b = pf->bytes;
	free(pf);
	return (b);
}
