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

size_t			ft_ws_strlen(wchar_t *ws)
{
	size_t		i;

	i = 0;
	while(ws[i])
		i++;
	return (i);
}

void				print_ws_precision(t_pf_item *pfi, wchar_t *ws)
{
	int				i;

	i = -1;
	if (pfi->precision > pfi->field_w && pfi->field_w > 0 && (int)ft_ws_strlen(ws) < pfi->field_w)
		while (ws[++i] && i < pfi->precision)
			print_space_byte(pfi);
	i = 0;
	if (pfi->precision > 0 && (ft_ws_strcmp(ws, L"") != 0))
		while (i < pfi->precision && ws[i])
		{
			print_wide_char(pfi, ws[i++]);
			pfi->bytes++;
		}
	else if (ft_ws_strcmp(ws, L"") != 0)
	{
		if (pfi->lenmods->p && pfi->precision == 0)
			while (ws[i++])
				ft_putchar(' ');
		else
			ft_putwidestr(pfi, ws);
		pfi->bytes += ft_ws_strlen(ws);
	}
	else
		;
}

int					get_ws_width(t_pf_item *pfi, wchar_t *ws)
{
	int				width;
	int				prcsn;

	width = 0;
	prcsn = pfi->precision;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - 1;
	if (ft_ws_strcmp(ws, L"") != 0 || (int)ft_ws_strlen(ws) >= pfi->precision)
		width -= pfi->precision;
	if ((int)ft_ws_strlen(ws) < pfi->precision)
		width += ft_ws_strlen(ws);
	if (!pfi->precision)
		width -= ft_ws_strlen(ws);
	return (width);
}

void				print_ws_field_w(t_pf_item *pfi, wchar_t *ws)
{
	int				i;
	int				width;

	i = 0;
	width = get_ws_width(pfi, ws);
	if (pfi->flags->minus)
	{
		print_ws_precision(pfi, ws);
		while (i++ <= width)
			print_space_byte(pfi);
	}
	else
	{
		while (i++ <= width)
		{
			if (pfi->flags->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			pfi->bytes++;
		}
		print_ws_precision(pfi, ws);
	}
}

// void				print_wide_string(t_pf_item *pfi, wchar_t *ws)
// {
// 	int			width;

// 	width = 0;
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
// 	if (pfi->field_w > 0)
// 	{
// 		if (!pfi->flags->minus)
// 		{
// 			// ft_putendl("in here");
// 			width = pfi->field_w - (ft_ws_strlen(ws) * 3) - 1;
// 			while (width >= 0)
// 			{
// 				ft_putchar(' ');
// 				pfi->bytes++;
// 				width--;
// 			}
// 		}
// 		ft_putwidestr(pfi, ws);
// 		if (pfi->flags->minus)
// 		{
// 			// ft_putendl("in here");
// 			width = pfi->field_w - (ft_ws_strlen(ws) * 3) - 1;
// 			while (width >= 0)
// 			{
// 				ft_putchar(' ');
// 				pfi->bytes++;
// 				width--;
// 			}
// 		}
// 	}
// 	else
// 	{
// 		ft_putwidestr(pfi, ws);
// 		pfi->bytes += ft_ws_strlen(ws);
// 	}
// }

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