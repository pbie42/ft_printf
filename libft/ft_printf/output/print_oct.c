/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/17 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					print_oct(t_pf_item *pfi, long int n)
{
	char				*tmp;

	tmp = ft_dec_to_oct(n);
	if (pfi->cspecs->o)
		ft_strrev(ft_strupper(tmp));
	else
		ft_strrev(ft_strlower(tmp));
	free(tmp);
}