/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 14:55:59 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			print_oct_precision(t_pf_item *pfi, char *num, t_bool field)
{
	int			i;
	int			len;

	i = pfi->precision;
	if (pfi->flags->hash)
		i--;
	len = ft_strlen(num);
	while (i-- > len)
		print_zero_byte(pfi);
	if (pfi->flags->hash && (num != 0) && !field)
		ft_putchar('0');
	if (pfi->lenmods->p && (ft_strcmp(num, "0") == 0) && (pfi->precision == 0))
		ft_putchar(' ');
	else if (pfi->cspecs->lg_o)
		ft_putstr(ft_strupper(num));
	else
		ft_putstr(ft_strlower(num));
	pfi->bytes += len;
}

int				oct_get_width(t_pf_item *pfi, char *num)
{
	int			width;

	width = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - ft_strlen(num) - 1;
	if ((size_t)pfi->precision > ft_strlen(num))
		width -= pfi->precision - ft_strlen(num);
	if (pfi->flags->hash)
		width -= 1;
	return (width);
}

void			print_oct_field_w(t_pf_item *pfi, char *num)
{
	int			i;
	int			width;

	i = 0;
	width = oct_get_width(pfi, num);
	if (pfi->flags->minus)
	{
		print_oct_precision(pfi, num, FALSE);
		while (i++ <= width)
			print_space_byte(pfi);
	}
	else
	{
		if (pfi->flags->hash && pfi->flags->zero && (ft_strcmp(num, "0") != 0))
			ft_putchar('0');
		while (i++ <= width)
			print_zero_space(pfi);
		if (pfi->flags->hash && !pfi->flags->zero && (ft_strcmp(num, "0") != 0))
			ft_putchar('0');
		print_oct_precision(pfi, num, TRUE);
	}
}

void			print_oct_bis(t_pf_item *pfi, char *tmp)
{
	if (pfi->flags->hash && (ft_strcmp(tmp, "0") != 0))
		ft_putchar('0');
	if (pfi->lenmods->p && pfi->flags->hash && (ft_strcmp(tmp, "0") == 0)
		&& (pfi->precision == 0))
		ft_putchar('0');
	else
	{
		if (pfi->lenmods->p && !pfi->flags->hash
			&& (ft_strcmp(tmp, "0") == 0) && (pfi->precision == 0))
			pfi->bytes--;
		else
			print_o_ul(pfi, tmp);
	}
	pfi->bytes += ft_strlen(tmp);
}

void			print_oct(t_pf_item *pfi, intmax_t n)
{
	char		*tmp;
	intmax_t			oct;

	if (n == LONG_MAX && !pfi->cspecs->lg_o)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen("37777777777") + 1);
		tmp = ft_strcpy(tmp, "37777777777");
	}
	else if (n == LONG_MIN && pfi->cspecs->lg_o)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen("1000000000000000000000") + 1);
		tmp = ft_strcpy(tmp, "1000000000000000000000");
	}
	else if ((long)n == LONG_MAX)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen("777777777777777777777") + 1);
		tmp = ft_strcpy(tmp, "777777777777777777777");
	}
	else if ((unsigned long)n == ULONG_MAX && n != 0)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen("1777777777777777777777") + 1);
		tmp = ft_strcpy(tmp, "1777777777777777777777");
	}
	else
	{
		if (!pfi->cspecs->lg_o && pfi->lenmods->hh)
			n = (unsigned char)n;
		if (!pfi->cspecs->lg_o && pfi->lenmods->h)
			n = (unsigned short)n;
		if (!pfi->cspecs->lg_o)
			n = (unsigned int)n;
		oct = ft_dec_to_oct(n);
		tmp = ft_llitoa(oct);
	}
	if (pfi->flags->hash && (ft_strcmp(tmp, "0") != 0))
		pfi->bytes += 1;
	if (pfi->field_w > 0)
	{
		if (pfi->precision >= pfi->field_w)
			print_oct_precision(pfi, tmp, FALSE);
		else
			print_oct_field_w(pfi, tmp);
	}
	else if (pfi->precision > 0)
		print_oct_precision(pfi, tmp, FALSE);
	else
		print_oct_bis(pfi, tmp);
	if (ft_strcmp(tmp, "9223372036854775807") != 0
		&& ft_strcmp(tmp, "9223372036854775808") != 0)
		free(tmp);
}
