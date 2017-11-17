/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					print_identifier(t_pf_item *pfi, va_list args)
{
	t_types			*types;

	if(!(types = (t_types *)malloc(sizeof(t_types) * 1)))
		ft_exit("malloc error handle_identifier");
	if (pfi->cspecs->c)
	{
		types->c = (unsigned char)va_arg(args, int);
		ft_putchar(types->c);
	}
	else if (pfi->cspecs->d || pfi->cspecs->i)
		print_int(pfi, va_arg(args, int));
	else if (pfi->cspecs->s)
		print_string(pfi, va_arg(args, char *));
	else if (pfi->cspecs->o)
		print_oct(pfi, va_arg(args, long int));
	else if (pfi->cspecs->x || pfi->cspecs->lg_x)
		print_hex(pfi, va_arg(args, long int));
	else if (pfi->cspecs->p)
		print_address(pfi, va_arg(args, long int));
	free(types);
}

void					handle_identifier(t_pf *pf, va_list args)
{
	t_pf_item		*pfi;

	++pf->pos;
	if(!(pfi = (t_pf_item *)malloc(sizeof(t_pf_item) * 1)))
		ft_exit("malloc error handle_identifier");
	pfi->field_w = 0;
	pfi->precision = 0;
	init_pfi(pfi);
	ft_putendl("before handle_identifier while");
	ft_putstr("the current letter is: ");
	ft_putchar(pf->format[pf->pos]);
	ft_putchar('!');
	ft_putchar('\n');
	while (ft_isflag(pf->format[pf->pos]))
	{
		ft_putendl("isflag");
		ft_putchar(pf->format[pf->pos]);
		handle_flag(pf, pfi);
	}
	if (ft_isdigit(pf->format[pf->pos]))
	{
		ft_putendl("isdigit");
		ft_putchar(pf->format[pf->pos]);
		handle_field_width(pf, pfi);
	}
	if (pf->format[pf->pos] == '.')
	{
		ft_putendl("isprecision");
		ft_putchar(pf->format[pf->pos]);
		handle_precision(pf, pfi);
	}
	if (ft_islmod(pf->format[pf->pos]))
	{
		ft_putendl("islmod");
		ft_putchar(pf->format[pf->pos]);
		handle_len_mod(pf, pfi);
	}
	if (ft_isconversion(pf->format[pf->pos]))
	{
		ft_putendl("isconversion");
		ft_putstr("the current letter is: ");
		ft_putchar(pf->format[pf->pos]);
		ft_putchar('!');
		ft_putchar('\n');
		ft_putchar(pf->format[pf->pos]);
		handle_conversion(pf, pfi);
	}
	else
		pfi->c_error = pf->format[pf->pos];
	print_pfi(pfi);
	handle_conditions(pfi);
	print_identifier(pfi, args);
	free(pfi);
}