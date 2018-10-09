/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 22:29:57 by tprak             #+#    #+#             */
/*   Updated: 2017/10/11 05:00:34 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define BUFF_SIZE 9999
# define NULL_CHECK(x) if (!x) return(-1);

typedef struct		s_file
{
	int				fd;
	size_t			len;
	char			*line;

	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
