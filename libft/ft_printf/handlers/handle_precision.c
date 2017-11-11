/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					handle_precision(t_pf *pf, t_pf_item *pfi)
{
	int				len;
	int				i;
	char				*anum;

	anum = NULL;
	i = 0;
	++pf->pos;
	len = pf->pos;
	while (ft_isdigit(pf->format[pf->pos]))
		pf->pos++;
	if (!(anum = (char*)malloc(sizeof(char) * (pf->pos - len) + 1)))
		ft_exit("malloc problem handle_field_width");
	while (len < pf->pos)
	{
		ft_putchar(pf->format[len]);
		ft_putchar('\n');
		anum[i] = pf->format[len];
		i++;
		len++;
	}
	anum[i] = '\0';
	pfi->precision = ft_atoi(anum);
	free(anum);
}