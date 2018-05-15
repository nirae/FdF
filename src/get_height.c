/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:45:40 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/15 11:09:56 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Get the height of the grid
**	Call the errors() function if open failed
*/

int		get_height(char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		gnl;

	if ((fd = open(file, O_RDONLY)) < 0)
		errors(ERR_OPEN);
	i = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		i++;
		ft_strdel(&line);
	}
	if (i < 2)
		errors(ERR_FILE);
	ft_strdel(&line);
	close(fd);
	return (i);
}
