/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 16:48:44 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define FORMAT pf->format
#define POS pf->pos

void					inc_putchar_byte(t_pf *pf)
{
	ft_putchar(FORMAT[++POS]);
	pf->bytes++;
}

void					putchar_byte(t_pf *pf)
{
	ft_putchar(FORMAT[POS]);
	pf->bytes++;
}

t_bool					nothing_else(t_pf *pf)
{
	int					i;

	i = POS + 2;
	while (!ft_not_conversion_space(FORMAT[i]) || ft_islmod(FORMAT[i]))
		i++;
	if (i == (int)ft_strlen(FORMAT) && !ft_isconversion(FORMAT[i - 1]))
		return (TRUE);
	return (FALSE);
}

void					ft_printf_bis(t_pf *pf, va_list args)
{
	t_bool				fine;

	fine = TRUE;
	while (FORMAT[++POS] && pf->bytes != -1 && fine)
		if (FORMAT[POS] == '%' && !FORMAT[POS + 1])
			;
		else if (FORMAT[POS] == '%' && FORMAT[POS + 1] == ' '
			&& nothing_else(pf))
			fine = FALSE;
		else if (FORMAT[POS] == '%' && FORMAT[POS + 1]
			&& FORMAT[POS + 1] != '%')
		{
			handle_identifier(pf, args);
			if (pf->len_error)
				fine = FALSE;
		}
		else if (FORMAT[POS] == '%' && FORMAT[POS + 1]
			&& FORMAT[POS + 1] == '%')
			inc_putchar_byte(pf);
		else
			putchar_byte(pf);
}

int						ft_printf(const char *format, ...)
{
	t_pf				*pf;
	va_list				args;
	int					b;

	va_start(args, format);
	pf = (t_pf *)malloc(sizeof(t_pf) * 1);
	POS = -1;
	pf->bytes = 0;
	FORMAT = format;
	pf->len_error = FALSE;
	b = 0;
	ft_printf_bis(pf, args);
	va_end(args);
	if (pf->bytes == -1)
	{
		free(pf);
		return (-1);
	}
	b = pf->bytes;
	free(pf);
	return (b);
}
