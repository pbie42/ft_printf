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

// void					*handle_arg(t_pf *pf)
// {

// }

void					ft_printf(const char *format)
{
	t_pf				*pf;

	pf = (t_pf *)malloc(sizeof(t_pf) * 1);
	pf->pos = -1;
	pf->format = format;
	check_format(pf->format);
	while(pf->format[++pf->pos])
	{
		if (pf->format[pf->pos] == '%')
			;
		// printf("hello % %c\n", pf->format[pf->pos]);
	}
}