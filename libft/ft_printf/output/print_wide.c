/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/18 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** If the number of significant bits <= 7     OR 0x7F
**    -> normal char
** If the number of significant bits <= 11    OR 0x7FF
**    -> two bytes to be written
** If the number of significant bits <= 16    OR 0xFFFF
**    -> three bytes to be written
** If the number of significant bits <= 21    OR 0x10FFFF
**    -> four bytes to be written
** Anything over that is too big and should return -1
**
** 0x3F = 0000000000111111
**
** Unicode Mask :
** 0xxxxxxx                                  = 0
** 110xxxxx 10xxxxxx                         = 49280        OR 0xC080
** 1110xxxx 10xxxxxx 10xxxxxx                = 14712960     OR 0xE08080
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx       = 4034953344   OR 0xF0808080
*/

void					write_wide(t_pf_item *pfi, char c)
{
	write(1, &c, 1);
	pfi->bytes++;
}

void					print_wide_char(t_pf_item *pfi, wint_t wide)
{
	if (wide <= 0x7F)
		write_wide(pfi, wide);
	else if (wide <= 0x7FF)
	{
		write_wide(pfi, (0xC0 | (wide >> 6)));
		write_wide(pfi, (0x80 | (wide & 0x3F)));
	}
	else if (wide <= 0xFFFF)
	{
		write_wide(pfi, (0xE0 | (wide >> 12)));
		write_wide(pfi, (0x80 | ((wide >> 6) & 0x3F)));
		write_wide(pfi, (0x80 | (wide & 0x3F)));
	}
	else if (wide <= 0x10FFFF)
	{
		write_wide(pfi, (0xF0 | (wide >> 18)));
		write_wide(pfi, (0x80 | ((wide >> 12) & 0x3F)));
		write_wide(pfi, (0x80 | ((wide >> 6) & 0x3F)));
		write_wide(pfi, (0x80 | (wide & 0x3F)));
	}
}

int						get_wide_char_length(wint_t wide)
{
	if (wide <= 0x7F)
		return (1);
	else if (wide <= 0x7FF)
		return (2);
	else if (wide <= 0xFFFF)
		return (3);
	else if (wide <= 0x10FFFF)
		return (4);
	else
		return (0);
}
