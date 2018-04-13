/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:27:19 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/13 19:15:12 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	carre(int x, int y, int size_x, int size_y, t_env *env)
{
	int a;
	int b;

	a = x;
	b = y;
	while (a < (x + size_x))
	{
		fill_pixel(&env->img, a, b, WHITE);
		a++;
		if (a == (x + size_x) && b < (y + size_y))
		{
			b++;
			a = x;
		}
	}
}
/*
int		agrandir_carre(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == 126)
		env->curr_y -= 1;
	else if (key == 125)
		env->curr_y += 1;
	else if (key == 123)
		env->curr_x -= 1;
	else if (key == 124)
		env->curr_x += 1;
	else
		return (0);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	carre(env->curr_x, env->curr_y, env->size_x, env->size_y, env);
	return (0);
}
*/
/*int		deal_key(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == 126)
		env->curr_y -= 1;
	else if (key == 125)
		env->curr_y += 1;
	else if (key == 123)
		env->curr_x -= 1;
	else if (key == 124)
		env->curr_x += 1;
	else
		return (0);
	mlx_pixel_put(env->mlx_ptr, env->win_ptr, env->curr_x, env->curr_y, WHITE);
	return (0);
}*/
/*
int		gere_mouse(int key, int x, int y, t_env *env)
{
	if (key == 1)
	{
		env->curr_x = x;
		env->curr_y = y;
	}
	else
		return (0);
	printf("x : %d, y : %d\n", x, y);
	mlx_pixel_put(env->mlx_ptr, env->win_ptr, env->curr_x, env->curr_y, WHITE);
	return (0);
}
*/

#define X1 100
#define Y1 800

#define X2 400
#define Y2 100

/* int		main(void)
{
	t_env	env;
	int first[3];
	int second[3];

	printf("nombre : %d\n", ft_count_words("0 0  0  0 0     0 ", ' '));

	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT, "Ma fenetre de ouf");
	//mlx_key_hook(env.win_ptr, deal_key, &env);
	//mlx_hook(env.win_ptr, 2, (1L<<0), deal_key, &env);
	//carre(env.curr_x, env.curr_y, env.size_x, env.size_y, &env);
	//mlx_hook(env.win_ptr, 2, (1L<<0), agrandir_carre, &env);
	//mlx_hook(env.win_ptr, 4, (1L<<2), gere_mouse, &env);

	//segment(X1, Y1, X2, Y2, &env);
	//mlx_string_put(env.mlx_ptr, env.win_ptr, X1, Y1, WHITE, "1");
	//mlx_string_put(env.mlx_ptr, env.win_ptr, X2, Y2, WHITE, "2");
	//mlx_loop(env.mlx_ptr);

	env.img.img_ptr = mlx_new_image(env.mlx_ptr, WIDTH, HEIGHT);
	env.img.data = (unsigned int *)mlx_get_data_addr(env.img.img_ptr, &env.img.bpp, &env.img.size_l, &env.img.endian);

	fill_pixel(&env.img, 200, 200, WHITE);
	//carre(300, 300, 50, 50, &env);
	first[0] = X1;
	first[1] = Y1;
	second[0] = X2;
	second[1] = Y2;
	print_segment(first, second, &env.img);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 10, WHITE, "coucou");
	mlx_loop(env.mlx_ptr);
	return (0);
}*/

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

int		if_width_valid(char *line, int width)
{
	if (ft_count_words(line, ' ') != width)
		return (0);
	return (1);
}


/*
**	Params : height, width
**	Return : 3 dimensional array or NULL if malloc failed
**	Example of an array that will be returned : 
** 		height (Y) : 3
**		width (X) : 4
**														 X
**			0 _____________________________________________
**			| {x, y, z} | {x, y, z} | {x, y, z} | {x, y, z}
**			| ---------------------------------------------
**			| {x, y, z} | {x, y, z} | {x, y, z} | {x, y, z}
**			| --------------------------------------------
**		 Y	| {x, y, z} | {x, y, z} | {x, y, z} | {x, y, z}
**
*/
int		***make_array(int height, int width)
{
	int		i;
	int 	y;
	int		***tab;

	if (!(tab = (int ***)ft_memalloc(height * sizeof(int **))))
		return (NULL);
	i = -1;
	y = -1;
	while (++i < height)
	{
		if (!(tab[i] = (int **)ft_memalloc(width * sizeof(int *))))
			return (NULL);
		while (++y < width)
		{
			if (!(tab[i][y] = (int *)ft_memalloc(3 * sizeof(int))))
				return (NULL);
		}
		y = -1;
	}
	return (tab);
}

#define COEFF 1
#define XY 20
#define DEPARTX 100
#define DEPARTY 50


int		***parser(int height, int width, char *file)
{
	int		i;
	int		y;
	char	*line;
	int		fd;
	char	**tab;
	int		***result;

	line = NULL;
	result = make_array(height, width);
	if ((fd = open(file, O_RDONLY)) < 0)
			return (0); // Erreur d'ouverture du fichier
	i = 0;
	while (i < height)
	{
		get_next_line(fd, &line);
		if (ft_count_words(line, ' ') != width)
			break; // Erreur a gerer
		tab = ft_strsplit(line, ' ');
		y = -1;
		while (++y < width)
		{
			//printf("TOUR NUMERO : %d\n", i);
			// Remplissage du X
			result[i][y][0] = (y * (XY * COEFF)) + DEPARTX;
			result[i][y][1] = (i * (XY * COEFF)) + DEPARTY;
			result[i][y][2] = ft_atoi(tab[y]);
			printf("x : %d, y : %d, z : %d\n", result[i][y][0], result[i][y][1], result[i][y][2]);
		}	
		//ft_strclr(line);
		i++;
	}
	close(fd);
	return (result);
}

#define CTE1 1
#define CTE2 1

int		***parser_iso(int height, int width, char *file)
{
	int		i;
	int		y;
	char	*line;
	int		fd;
	char	**tab;
	int		***result;

	line = NULL;
	result = make_array(height, width);
	if ((fd = open(file, O_RDONLY)) < 0)
			return (0); // Erreur d'ouverture du fichier
	i = 0;
	while (i < height)
	{
		get_next_line(fd, &line);
		if (ft_count_words(line, ' ') != width)
			break; // Erreur a gerer
		tab = ft_strsplit(line, ' ');
		y = -1;
		while (++y < width)
		{
			//printf("TOUR NUMERO : %d\n", i);
			// Remplissage du X
			int xx = (y * (XY * COEFF)) + DEPARTX;
			int yy = (i * (XY * COEFF)) + DEPARTY;
			int zz = ft_atoi(tab[y]);
			printf("xx : %d, yy : %d, zz : %d\n", xx, yy, zz);
			result[i][y][2] = zz;
			result[i][y][0] = CTE1 * xx - CTE2 * yy;
			//result[i][y][0] = xx - yy;
			result[i][y][1] = (-zz + ((CTE1 / 2 + CTE1 % 2) * xx) + ((CTE2 / 2 + CTE2 % 2) * yy));
			//result[i][y][1] = (xx + yy) / 2;
			printf("x : %d, y : %d, z : %d\n", result[i][y][0], result[i][y][1], result[i][y][2]);
		}	
		//ft_strclr(line);
		i++;
	}
	close(fd);
	return (result);
}

int		main(int argc, char **argv)
{
	int		height;
	int		width;
	t_env	env;
	
	if (argc == 2)
	{
		height = get_height(argv[1]);
		width = get_width(argv[1]);
		//printf("height : %d\n", height);
	//	printf("width : %d\n", width);
		// malloc a proteger
		env.tab = parser_iso(height, width, argv[1]);
		//env.tab[10][18][0] = 666;
		// printf("contenu de tab[%d][%d][0] : %d\n", 10, 18, env.tab[10][18][0]);
		

		env.mlx_ptr = mlx_init();
		env.win_ptr = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT, "Ma fenetre de ouf");
		env.img.img_ptr = mlx_new_image(env.mlx_ptr, WIDTH, HEIGHT);
		env.img.data = (unsigned int *)mlx_get_data_addr(env.img.img_ptr, &env.img.bpp, 
				&env.img.size_l, &env.img.endian);
		//fill_pixel(&env.img, 200, 200, WHITE);
		//fill_segment(first, second, &env.img);
		
	
		int i = -1;
		int y = -1;
		while (++i < height)
		{
			while (++y < width)
			{
				if (i != height - 1)
					fill_segment(&env.img, env.tab[i][y], env.tab[i + 1][y]);
				if (y != width - 1)
					fill_segment(&env.img, env.tab[i][y], env.tab[i][y + 1]);
				//fill_pixel(&env.img, env.tab[i][y][0], env.tab[i][y][1], WHITE);
			}
			y = -1;
		}

		

		mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
		mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 10, WHITE, "coucou");
		mlx_loop(env.mlx_ptr);

	}
	return (0); // Sortie du main
}
