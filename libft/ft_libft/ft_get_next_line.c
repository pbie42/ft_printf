/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:02:39 by pbie              #+#    #+#             */
/*   Updated: 2017/08/24 14:48:39 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void				free_gnl_list(t_list *list)
{
	t_list			*curr;

	while ((curr = list) != NULL)
	{
		list = list->next;
		free(curr->content);
		free(curr);
	}
}

static t_list		*ft_findfd(t_list **begin, int fd)
{
	t_list			*tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char			*ft_freejoin(char *tmp, char *buf, int ret)
{
	char			*l;

	l = tmp;
	tmp = ft_strnjoin(tmp, buf, ret);
	free(l);
	return (tmp);
}

int					ft_get_next_line(int const fd, char **line)
{
	t_gnl			gnl;

	gnl.list = NULL;
	if (fd < 0 || line == NULL || read(fd, gnl.buf, 0) < 0)
		return (-1);
	gnl.begin = gnl.list ? gnl.list : NULL;
	gnl.list = ft_findfd(&gnl.begin, fd);
	while (!ft_strchr(gnl.list->content, '\n')
		&& (gnl.ret = read(fd, gnl.buf, BUFF_SIZE)))
		gnl.list->content = ft_freejoin(gnl.list->content, gnl.buf, gnl.ret);
	gnl.ret = 0;
	while (((char *)gnl.list->content)[gnl.ret]
		&& ((char *)gnl.list->content)[gnl.ret] != '\n')
		++gnl.ret;
	*line = ft_strndup(gnl.list->content, gnl.ret);
	if (((char *)gnl.list->content)[gnl.ret] == '\n')
		++gnl.ret;
	gnl.l = gnl.list->content;
	gnl.list->content = ft_strdup(gnl.list->content + gnl.ret);
	free(gnl.l);
	gnl.list = gnl.begin;
	free_gnl_list(gnl.list);
	if (gnl.ret > 0)
		return (1);
	return (0);
}
