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


// void					print_oct_precision(t_pf_item *pfi, int num)
// {
// 	int				i;
// 	int				len;
	
// 	i = pfi->precision;
// 	len = ft_strlen(num);
// 	while (i-- > len)
// 	{
// 		ft_putchar('0');
// 		pfi->bytes++;
// 	}
// 	ft_strrev(num);
// 	pfi->bytes++;
// }

// int					oct_get_width(t_pf_item *pfi, int num)
// {
// 	int				width;

// 	width = 0;
// 	if (pfi->precision >= pfi->field_w)
// 		pfi->precision = 0;
// 	width = pfi->field_w - pfi->precision - 1;
// 	if (!pfi->precision)
// 		width -= ft_strlen(num);
// 	return (width);
// }

// void					print_oct_field_w(t_pf_item *pfi, char *num)
// {
// 	int				i;
// 	int				width;

// 	i = 0;
// 	width = oct_get_width(pfi, num);
// 	if (pfi->flags->minus)
// 	{
// 		print_oct_precision(pfi, num);
// 		while (i++ <= width)
// 		{
// 			ft_putchar(' ');
// 			pfi->bytes++;
// 		}
// 	}
// 	else
// 	{
// 		while (i++ <= width)
// 		{
// 			if (pfi->flags->zero)
// 				ft_putchar('0');
// 			else
// 				ft_putchar(' ');
// 			pfi->bytes++;
// 		}
// 		print_oct_precision(pfi, num);
// 	}
// }

void					print_oct(t_pf_item *pfi, long int n)
{
	int				tmp;
	
	tmp = ft_dec_to_oct(n);
	print_int(pfi, tmp);
	
}

// void					print_oct(t_pf_item *pfi, long int n)
// {
// 	char				*tmp;

// 	tmp = ft_dec_to_oct(n);
// 	if (pfi->cspecs->o)
// 		ft_strrev(ft_strupper(tmp));
// 	else
// 		ft_strrev(ft_strlower(tmp));
// 	free(tmp);
// }