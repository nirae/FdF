/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:45:40 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/17 12:46:54 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(file, O_RDONLY)) < 0)
			return (-666); // Erreur d'ouverture du fichier
	i = 0;
	while (get_next_line(fd, &line) > 0)
		i++;
	close(fd);
	return(i);
}
