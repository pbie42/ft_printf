/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/12/12 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_ws_strcmp(const wchar_t *s1, const wchar_t *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((wchar_t)s1[i] - (wchar_t)s2[i]);
}

void				ft_putwidestr(t_pf_item *pfi, wchar_t *ws)
{
	int			i;

	i = -1;
	while (ws[++i])
		print_wide_char(pfi, ws[i]);
}

int					get_ws_width(wchar_t *ws)
{
	int				width;
	int				i;

	i = -1;
	width = 0;
	while (ws[++i])
		width += get_wide_char_length(ws[i]);
	return (width);
}

void				print_wide_string(t_pf_item *pfi, wchar_t *ws)
{
	int			width;

	width = 0;
	if (MB_CUR_MAX == 1)
	{
		pfi->bytes = -1;
		return ;
	}
	if (!ws)
	{
		ft_putstr("(null)");
		pfi->bytes += ft_strlen("(null)");
		return ;
	}
	if (pfi->field_w > 0)
	{
		if (!pfi->flags->minus)
		{
			width = pfi->field_w - get_ws_width(ws) - 1;
			while (width >= 0)
			{
				if (pfi->flags->zero)
					ft_putchar('0');
				else
					ft_putchar(' ');
				pfi->bytes++;
				width--;
			}
		}
		ft_putwidestr(pfi, ws);
		if (pfi->flags->minus)
		{
			width = pfi->field_w - get_ws_width(ws) - 1;
			while (width >= 0)
			{
				if (pfi->flags->zero)
					ft_putchar('0');
				else
					ft_putchar(' ');
				pfi->bytes++;
				width--;
			}
		}
	}
	else
		ft_putwidestr(pfi, ws);
}

// void				print_string(t_pf_item *pfi, char *s)
// {
// 	t_bool		sull;

// 	sull = FALSE;
// 	if (!s)
// 	{
// 		s = ft_strdup("(null)");
// 		sull = TRUE;
// 	}
// 	if (pfi->field_w > 0)
// 	{
// 		if (pfi->precision > pfi->field_w)
// 			print_precision(pfi, s);
// 		else
// 			print_field_w(pfi, s);
// 	}
// 	else if (pfi->precision > 0)
// 		print_precision(pfi, s);
// 	else if (ft_strcmp(s, "") != 0)
// 	{
// 		ft_putstr(s);
// 		pfi->bytes += ft_strlen(s);
// 	}
// 	else
// 		;
// 	if (sull)
// 		free(s);
// }

// void					print_wide_string(t_pf_item *pfi, wchar_t *ws)
// {
// 	int				i;

// 	if (MB_CUR_MAX == 1)
// 	{
// 		pfi->bytes = -1;
// 		return ;
// 	}
// 	if (!ws)
// 	{
// 		ft_putstr("(null)");
// 		pfi->bytes += ft_strlen("(null)");
// 		return ;
// 	}
// 	i = -1;
// 	while (ws[++i])
// 		print_wide_char(pfi, ws[i]);
// }