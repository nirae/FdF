/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:45:40 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/08 18:10:38 by ndubouil         ###   ########.fr       */
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

	if ((fd = open(file, O_RDONLY)) < 0)
			errors(ERR_OPEN); // Erreur d'ouverture du fichier
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return(i);
}
