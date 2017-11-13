/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					handle_conditions(t_pf_item *pfi)
{
	if (pfi->flags->minus && pfi->flags->zero)
		ft_exit("warning: flag '0' is ignored when flag '-' is present");
	if (pfi->flags->hash && pfi->cspecs->d)
		ft_exit("flag '#' results in undefined behavior with 'd' conversion specifier");
}