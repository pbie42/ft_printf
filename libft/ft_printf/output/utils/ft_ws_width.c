/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ws_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					ft_ws_width(wchar_t *ws)
{
	int				width;
	int				i;

	i = -1;
	width = 0;
	while (ws[++i])
		width += get_wide_char_length(ws[i]);
	return (width);
}
