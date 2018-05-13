/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:47:05 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/10 17:26:58 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Get the width of the file for the grid
**	Call the errors() function if open failed and if the width is not good
*/

int		get_width(char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		width;

	if ((fd = open(file, O_RDONLY)) < 0)
		errors(ERR_OPEN); // Erreur d'ouverture du fichier
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
			width = ft_count_words(line, ' ');
		else
		{
			if (ft_count_words(line, ' ') != width)
				errors(ERR_WIDTH);
		}
			ft_strdel(&line);
		i++;
	}
	if (i < 1)
		errors(ERR_FILE);
	ft_strdel(&line);
	close(fd);
	return(width);
}
