/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:43:19 by yberries          #+#    #+#             */
/*   Updated: 2020/01/16 01:42:55 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file			*ft_startlist(t_file **head, int fd)
{
	t_file	*file;

	if (*head == NULL)
	{
		if (!(file = (t_file *)malloc(sizeof(t_file))))
			return (NULL);
		file->fd = fd;
		file->rest = ft_strnew(0);
		file->next = NULL;
		*head = file;
		return (file);
	}
	else
	{
		file = *head;
		while (file->fd != fd && file->next != NULL)
			file = file->next;
		if (file->fd == fd)
			return (file);
		file->next = malloc(sizeof(t_file));
		file->next->fd = fd;
		file->next->rest = ft_strnew(0);
		file->next->next = NULL;
		return (file->next);
	}
}

char			*ft_check_rest(char *rest, char **line)
{
	int				i;
	char			*nl;

	i = 0;
	while (rest[i] != '\n' && rest[i])
		++i;
	if (rest[i] == '\n')
	{
		*line = ft_strsub(rest, 0, i);
		nl = ft_strdup(&rest[i + 1]);
	}
	if (!rest[i])
	{
		*line = ft_strsub(rest, 0, i);
		nl = ft_strnew(0);
	}
	return (nl);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*head = NULL;
	t_file			*file;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				n;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	file = ft_startlist(&head, fd);
	while ((n = read(fd, buff, BUFF_SIZE)))
	{
		buff[n] = '\0';
		tmp = ft_strjoin(file->rest, buff);
		free(file->rest);
		file->rest = tmp;
		if (ft_strchr(file->rest, '\n'))
			break ;
	}
	if (!ft_strlen(file->rest) && !n)
		return (0);
	tmp = ft_check_rest(file->rest, line);
	free(file->rest);
	file->rest = tmp;
	return (1);
}
