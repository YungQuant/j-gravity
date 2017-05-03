/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:31:30 by mkok              #+#    #+#             */
/*   Updated: 2017/03/07 18:05:21 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char	*read_all(int fd, char *line)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		amt;

	ret = 0;
	amt = 0;
	tmp = line;
	if (line == NULL || fd < 0 || read(fd, buff, 0) < 0)
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (amt)
			tmp = line;
		amt += ret;
		buff[ret] = '\0';
		line = ft_strjoin(tmp, buff);
		if (!(line))
			return (NULL); 
	}
	return (line);
}
