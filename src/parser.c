/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:53:53 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/02 14:18:37 by ndubouil         ###   ########.fr       */
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

int				color(int z, int coeff)
{
	if (z > 10 * coeff)
		return (0xF5F4F2);
	else if (z > 9 * coeff)
		return (0xCAC3B8);
	else if (z > 8 * coeff)
		return (0xAC9A7C);
	else if (z > 7 * coeff)
		return (0xAA8753);
	else if (z > 6 * coeff)
		return (0xC3A76B);
	else if (z > 5 * coeff / 2)
		return (0xCAB982);
	else if (z > 4 * coeff / 2)
		return (0xE8E1B6);
	else if (z > 3 * coeff / 2)
		return (0xE1E4B5);
	else if (z > 2 * coeff / 2)
		return (0xBDCC96);
	else if (z > 1 * coeff / 2)
		return (0xA8C68F);
	else if (z > 0 * coeff)
		return (0xACD0A5);
	else if (z == 0)
		return (0xD8F2FE);
	else if (z > -1 * coeff)
		return (0xC6ECFF);
	else if (z > -2 * coeff)
		return (0xB9E3FF);
	else if (z > -3 * coeff)
		return (0xACDBFB);
	else if (z > -4 * coeff)
		return (0xA1D2F7);
	else if (z > -5 * coeff)
		return (0x96C9F0);
	else if (z > -6 * coeff)
		return (0x8DC1EA);
	else if (z > -7 * coeff)
		return (0x84B9E3);
	else if (z > -8 * coeff)
		return (0x79B2DE);
	//else if (z > -90)
	return (0x71ABD8);
	//return (WHITE);
}

void			manage_color(t_env *env)
{
	int		coeff;
	int		i;
	int		ii;

	coeff = env->z_max / 10;
	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->curr_tab[i][ii] = create_pixel(
									env->curr_tab[i][ii].x,
									env->curr_tab[i][ii].y,
									env->curr_tab[i][ii].z,
									color(env->curr_tab[i][ii].z, coeff)
									);
			env->or_tab[i][ii] = create_pixel(
									env->or_tab[i][ii].x,
									env->or_tab[i][ii].y,
									env->or_tab[i][ii].z,
									color(env->or_tab[i][ii].z, coeff)
									);
		}
	}
}

t_pixel			**parser(int height, int width, char *file, t_env *env)
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
	env->z_max = 0;
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
			if (ft_atoi(tab[ii]) > env->z_max)
				env->z_max = ft_atoi(tab[ii]);
			result[i][ii] = create_pixel(ii, i, ft_atoi(tab[ii]), ft_atoi(tab[ii]));
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	//hydrate(&result, fd, height, width);
	close(fd);
	return (result);
}
