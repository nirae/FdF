/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:32:41 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/19 18:18:11 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "mlx.h"

# include "libft.h"
# include "get_next_line.h"

# define WHITE 0xFFFFFF

# define WIDTH 800
# define HEIGHT 600
# define MARGIN 160


typedef struct		s_seg
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				cumul;
}					t_seg;

/*
**	Structures for Env
*/
typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_pixel
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pixel;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_pixel			**or_tab;
	t_pixel			**curr_tab;
	int				height;
	int				width;
	int				zoom;
	int				start_x;
	int				start_y;
}					t_env;

void				fill_pixel(t_env *env, int x, int y, int color);
void				fill_segment(t_env *env, t_pixel first, t_pixel second);
int					get_height(char *file);
int					get_width(char *file);
int					if_width_valid(char *line, int width);
t_pixel				**make_array(int height, int width);
t_pixel				**parser(int height, int width, char *file);
t_pixel				create_pixel(int x, int y, int z, int color);

#endif
