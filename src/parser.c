/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:53:53 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/30 22:20:23 by ndubouil         ###   ########.fr       */
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

int				color(int z)
{
	if (z > 100)
		return (0xF5F4F2);
	else if (z > 90)
		return (0xCAC3B8);
	else if (z > 80)
		return (0xAC9A7C);
	else if (z > 70)
		return (0xB9985A);
	else if (z > 60)
		return (0xCAB982);
	else if (z > 50)
		return (0xDED6A3);
	else if (z > 40)
		return (0xEFEBC0);
	else if (z > 30)
		return (0xD1D7AB);
	else if (z > 20)
		return (0xA8C68F);
	else if (z > 10)
		return (0xACD0A5);
	else if (z > 0)
		return (0xA7DFD2);
	else if (z == 0)
		return (0xD8F2FE);
	else if (z > -10)
		return (0xC6ECFF);
	else if (z > -20)
		return (0xB9E3FF);
	else if (z > -30)
		return (0xACDBFB);
	else if (z > -40)
		return (0xA1D2F7);
	else if (z > -50)
		return (0x96C9F0);
	else if (z > -60)
		return (0x8DC1EA);
	else if (z > -70)
		return (0x84B9E3);
	else if (z > -80)
		return (0x79B2DE);
	//else if (z > -90)
	return (0x71ABD8);
	//return (WHITE);
}

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
			result[i][ii] = create_pixel(ii, i, ft_atoi(tab[ii]), color(ft_atoi(tab[ii])));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	//hydrate(&result, fd, height, width);
	close(fd);
	return (result);
}
