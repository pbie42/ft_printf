/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 13:31:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					check_format(const char *format)
{
	int					count;
	int					i;
	t_bool				correct;

	count = 0;
	i = -1;
	correct = FALSE;
	while (format[++i])
		if (format[i] == '%')
			count++;
	if (count == 0)
		return ;
	if (count == 1)
		return ;
	if (count % 2 == 0)
		ft_exit("Incorrect format with % signs");
	i = -1;
	while (format[++i])
		if (format[i] == '%' && format[i + 1] && format[i + 1] == '%')
			correct = TRUE;
	if (!correct)
		ft_exit("Incorrect format with % signs 2");
}
