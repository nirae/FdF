/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:53:53 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/08 22:45:16 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_result(int height, t_pixel ***result);
static void		free_tab(char ***tab);

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
		errors(ERR_OPEN);
	i = -1;
	env->z_max = 0;
	while (++i < height)
	{
		get_next_line(fd, &line);
		if (ft_count_words(line, ' ') != width)
		{
			free_result(height, &result);
			errors(ERR_FILE);
		}
		if (!(tab = ft_strsplit(line, ' ')))
		{
			free_result(height, &result);
			errors(ERR_FILE);
		}
		ii = -1;
		while (++ii < width)
		{
			if (ft_atoi(tab[ii]) > env->z_max)
				env->z_max = ft_atoi(tab[ii]);
			result[i][ii] = create_pixel(ii, i, ft_atoi(tab[ii]), ft_atoi(tab[ii]));
		}
		ft_strdel(&line);
		free_tab(&tab);
	}
	ft_strdel(&line);
	close(fd);
	return (result);
}

static void		free_tab(char ***tab)
{
	/*int		i;

	i = 0;
	while (*tab[i])
	{
		//ft_strdel(tab[i]);
		printf("%d\n", i);
		i++;
	}*/
	ft_memdel((void **)tab);
}

static void		free_result(int height, t_pixel ***result)
{
	int		i;

	i = -1;
	while (++i < height)
		ft_memdel((void **)result[i]);
	ft_memdel((void **)result);
}
