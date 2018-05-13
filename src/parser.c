/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:53:53 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/10 16:47:24 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_result(int height, t_pixel ***result);
static void		free_tab(char ***tab);
static void		set_result(char *line, t_pixel ***result, t_env *env, int i);

/*
**	Parsing the file for put in the result array
**	See make_array for informations about the array
*/

t_pixel			**parser(char *file, t_env *env)
{
	int		i;
	char	*line;
	int		fd;
	t_pixel	**result;

	line = NULL;
	result = make_array(env->height, env->width);
	if ((fd = open(file, O_RDONLY)) < 0)
		errors(ERR_OPEN);
	i = -1;
	env->z_max = 0;
	while (++i < env->height)
	{
		get_next_line(fd, &line);
		set_result(line, &result, env, i);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (result);
}

static void		set_result(char *line, t_pixel ***result, t_env *env, int i)
{
	char	**tab;
	int		ii;
	int		z;

	if (!(tab = ft_strsplit(line, ' ')))
	{
		free_result(env->height, result);
		errors(ERR_MALLOC);
	}
	ii = -1;
	while (++ii < env->width)
	{
		if ((z = ft_atoi(tab[ii])) > env->z_max)
			env->z_max = z;
		(*result)[i][ii] = create_pixel(ii, i, z, z);
	}
	free_tab(&tab);
}

static void		free_tab(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		ft_strdel(&(*tab)[i]);
		i++;
	}
	ft_memdel((void **)tab);
}

static void		free_result(int height, t_pixel ***result)
{
	int		i;

	i = -1;
	while (++i < height)
		ft_memdel((void **)(*result)[i]);
	ft_memdel((void **)result);
}
