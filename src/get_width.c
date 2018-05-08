/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:47:05 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/08 18:10:57 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Get the width of the file for the grid
**	Call the errors() function if open failed
*/

int		get_width(char *file)
{
	int		fd;
	char	*line;
	int		i;
	char	*firstline;

	if ((fd = open(file, O_RDONLY)) < 0)
		errors(ERR_OPEN); // Erreur d'ouverture du fichier
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
			firstline = line;
		else
			ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	i = ft_count_words(firstline, ' ');
	ft_strdel(&firstline);
	close(fd);
	return(i);
}
