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

void					ft_printf(const char *format)
{
	t_pf				*pf;

	printf("%-100d !\n", 999);
	pf = (t_pf *)malloc(sizeof(t_pf) * 1);
	pf->pos = -1;
	pf->format = format;
	check_format(pf->format);
	while(pf->format[++pf->pos])
	{
		if (pf->format[pf->pos] == '%' && pf->format[pf->pos + 1]
			&& pf->format[pf->pos + 1] != '%')
				handle_identifier(pf);
		else if (pf->format[pf->pos] == '%' && pf->format[pf->pos + 1]
			&& pf->format[pf->pos + 1] == '%')
			ft_putchar(pf->format[++pf->pos]);
		else
			ft_putchar(pf->format[pf->pos]);
	}
}