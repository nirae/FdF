/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:53:53 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/18 17:02:24 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int				hydrate(t_pixel ***result, int fd, int height, int width)
{
	int		i;
	int		ii;
	char	*line;
	char	**words;

	line = NULL;
	i = -1;
	while (++i < height)
	{
		get_next_line(fd, &line);
		if (ft_count_words(line, ' ') != width)
			return (0); // erreur a gerer
		words = ft_strsplit(line, ' ');
		ii = -1;
		while (++ii < width)
		{
			*result[i][ii] = make_pixel(ii, i, ft_atoi(words[ii]), ft_atoi(words[ii]));
			printf("x : %d, y : %d, z : %d, color : %x\n", result[i][ii]->x, result[i][ii]->y, result[i][ii]->z, result[i][ii]->color);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}*/

t_pixel			**parser(int height, int width, char *file)
{
	int		i;
	int		ii;
	char	*line;
	int		fd;
	char	**tab;
	t_pixel	**result;

	line = NULL;
	result = make_array(height, width);
	if ((fd = open(file, O_RDONLY)) < 0)
			return (NULL); // Erreur d'ouverture du fichier
	i = -1;
	while (++i < height)
	{
		get_next_line(fd, &line);
		ft_putendl(line);
		// Pas la bonne longueur
		if (ft_count_words(line, ' ') != width)
			break; // Erreur a gerer
		tab = ft_strsplit(line, ' ');
		ii = -1;
		while (++ii < width)
		{
			result[i][ii] = create_pixel(ii, i, ft_atoi(tab[ii]), ft_atoi(tab[ii]));
			printf("x : %d, y : %d, z : %d, color : %x\n", result[i][ii].x, result[i][ii].y, result[i][ii].z, result[i][ii].color);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	//hydrate(&result, fd, height, width);
	close(fd);
	return (result);
}
