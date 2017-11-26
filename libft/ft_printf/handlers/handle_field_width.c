/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_field_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					handle_field_width(t_pf *pf, t_pf_item *pfi)
{
	int				len;
	int				i;
	char				*anum;

	len = pf->pos;
	anum = NULL;
	i = 0;
	while (ft_isdigit(pf->format[pf->pos]))
		pf->pos++;
	if (!(anum = (char*)malloc(sizeof(char) * (pf->pos - len) + 1)))
		ft_exit("malloc problem handle_field_width");
	while (len < pf->pos)
	{
		anum[i] = pf->format[len];
		i++;
		len++;
	}
	// ft_putendl(anum);
	anum[i] = '\0';
	pfi->field_w = ft_atoi(anum);
	// ft_putendlnbr("field_w is: ", pfi->field_w);
	free(anum);
}