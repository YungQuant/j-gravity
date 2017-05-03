/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:28:26 by mkok              #+#    #+#             */
/*   Updated: 2017/03/14 16:49:45 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contrast.h"

int		find_width(char *line)
{
	int		width;
	char	*cline;

	cline = line;
	width = 0;
	while (*cline)
	{
		if (!ft_isdigit(*cline) && *cline != '-' && *cline != ' ')
			return (0);
		while (*cline == ' ')
			cline++;
		if (*cline == '-')
			cline++;
		if (!ft_isdigit(*cline))
			return (0);
		while (ft_isdigit(*cline))
			cline++;
		width++;
		while (*cline == ' ')
			cline++;
		if (*cline == '\n')
			break;
	}
	return (width);
}

int		*to_int_map(char *line)
{
	char	*cline;
	int		*map;
	int		*maphead;

	cline = line;
	if (!(map = (int *)malloc(sizeof(int) * validate(cline))))
		return (NULL);
	maphead = map;
	while (*cline)
	{
		*map = ft_atoi(cline);
		while (*cline == ' ')
			cline++;
		if (*cline == '-')
			cline++;
		while (ft_isdigit(*cline))
			cline++;
		while (*cline == ' ' || *cline == '\n')
			cline++;
		map++;
	}
	return (maphead);
}
