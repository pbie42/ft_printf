/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*oct_malloc(char *str)
{
	char			*tmp;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	tmp = ft_strcpy(tmp, str);
	return (tmp);
}
