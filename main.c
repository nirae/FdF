/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:27:19 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/12 17:40:11 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/

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
void	horizontal(int *first, int *second, t_img *img, int color)
{
	int x;
	int y;
	int tmp;

	if (first[0] > second[0])
	{
		tmp = first[0];
		first[0] = second[0];
		second[0] = tmp;
		tmp = first[1];
		first[1] = second[1];
		second[1] = tmp;
	}
	x = first[0];
	while (x <= second[0])
	{
		y = first[1] + ((second[1] - first[1]) * (x - first[0])) / (second[0] - first[0]);
		fill_pixel(img, x, y, color);
		x++;
	}
}

void	vertical(int *first, int *second, t_img *img, int color)
{
	int x;
	int y;
	int tmp;

	if (first[1] > second[1])
	{
		tmp = first[0];
		first[0] = second[0];
		second[0] = tmp;
		tmp = first[1];
		first[1] = second[1];
		second[1] = tmp;
	}
	y = first[1];
	while (y <= second[1])
	{
		x = first[0] + ((second[0] - first[0]) * (y - first[1])) / (second[1] - first[1]);
		printf("x : %d, y : %d\n", x, y);
		fill_pixel(img, x, y, color);
		y++;
	}
}

/*
**	tab[0] = x
**	tab[1] = y
**	tab[2] = color
*/
void	print_segment(int *first, int *second, t_img *img)
{
	if ((second[0] - first[0]) >= abs(second[1] - first[1]))
		horizontal(first, second, img, WHITE);
	else
		vertical(first, second, img, WHITE);
}


/*void	fill_pixel(t_img *img, int x, int y, int color)
{
	int pos;

	//pos = (4 * x) + (4 * WIDTH * y);
	pos = y * WIDTH + x;
	img->data[pos] = color;
}*/

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

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-666); // Erreur d'ouverture du fichier
	i = 0;
	if (get_next_line(fd, &line) <= 0)
		return (-555); // Erreur du gnl
	i = ft_count_words(line, ' ');
	close(fd);
	return(i);
}

int		if_width_valid(char *line, int width)
{
	if (ft_count_words(line, ' ') != width)
		return (0);
	return (1);
}

int		taballoc(int ****tab, int height, int width)
{
	int		i;
	int 	y;

	if (!(*tab = ft_memalloc(height * sizeof(int **))))
		return (0);
	i = -1;
	y = -1;
	while (++i < height)
	{
		if (!(*tab[i] = ft_memalloc(width * sizeof(int *))))
			return (0);
		while (++y < width)
		{
			if (!(*tab[i][y] = ft_memalloc(3 * sizeof(int))))
				return (0);
		}
		y = -1;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		height;
	int		width;
	t_env	env;
	//int		ref;

	if (argc == 2)
	{
		height = get_height(argv[1]);
		width = get_width(argv[1]);
		printf("height : %d\n", height);
		printf("width : %d\n", width);
		// a verifier
		taballoc(&env.tab, height, width);
		env.tab[0][0][0] = 666;
		//printf("contenu de tab[%d][%d][0] : %d\n", 0, 0, env.tab[0][0][0]);
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (0); // Erreur d'ouverture du fichier
		while (get_next_line(fd, &line) > 0)
		{
			//ft_putendl(line);
			
		}
		close(fd);
	}
	return (0); // Sortie du main
}
