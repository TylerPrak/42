/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 21:31:00 by tprak             #+#    #+#             */
/*   Updated: 2017/10/08 21:01:39 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*ft_new_lst(int fd)
{
	t_file	*current;

	if (!(current = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	current->line = NULL;
	current->fd = fd;
	current->len = 0;
	current->next = NULL;
	return (current);
}

t_file	*ft_get_file(t_file **file, int fd)
{
	t_file *head;

	head = *file;
	while (head != NULL)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	if (head == NULL)
	{
		head = ft_new_lst(fd);
		head->next = *file;
		*file = head;
	}
	return (head);
}

int		ft_findnl(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\n')
		i++;
	return (i);
}

int		ft_parse(char **line, t_file *cur, char *tmp, int nl)
{
	if (ft_strchr(cur->line, '\n'))
	{
		nl = ft_findnl(cur->line);
		*line = ft_strsub(cur->line, 0, nl);
		cur->line = ft_strsub(cur->line, nl + 1, ((cur->len - nl) + 1));
		return (1);
	}
	else if (ft_strlen(cur->line) > 0)
	{
		*line = ft_strdup(cur->line);
		ft_strclr(cur->line);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	if (!ft_strlen(cur->line))
	{
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*file;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;
	t_file			*current;

	current = ft_get_file(&file, fd);
	if (fd == -1 || line == NULL || read(fd, buf, 0) < 0 || fd > 4864)
		return (-1);
	while (((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		if (current->line == NULL)
			current->line = ft_strnew(1);
		tmp = ft_strjoin(current->line, buf);
		free(current->line);
		current->line = tmp;
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	tmp = current->line;
	current->len = ft_strlen(current->line);
	return (ft_parse(line, current, tmp, 0));
}
