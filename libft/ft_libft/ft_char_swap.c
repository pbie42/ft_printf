/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/08 15:02:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void						char_swap(char *p1, char *p2)
{
	char					tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
