/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:47:05 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/17 12:47:25 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_width(char *file)
{
	int		fd;
	char	*line;
	int		i;
	char	*firstline;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-666); // Erreur d'ouverture du fichier
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
			firstline = line;
		i++;
	}
	i = ft_count_words(firstline, ' ');
	close(fd);
	return(i);
}
