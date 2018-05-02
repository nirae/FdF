/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:32:41 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/02 13:21:36 by ndubouil         ###   ########.fr       */
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

# define WHITE		0xFFFFFF

# define WIDTH		1000
# define HEIGHT		800
# define MARGIN		160

# define BASIC		999
# define ISO		998
# define PARA		997

# define CTE1		1
# define CTE2		1

typedef struct		s_seg
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				cumul;
	int				color;
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
	int				curr_start[2];
	int				or_start[2];
	int				proj;
	int				z_max;
}					t_env;

void				fill_pixel(t_env *env, int x, int y, int color);
void				fill_segment(t_env *env, t_pixel first, t_pixel second);
int					get_height(char *file);
int					get_width(char *file);
int					if_width_valid(char *line, int width);
t_pixel				**make_array(int height, int width);
t_pixel				**parser(int height, int width, char *file, t_env *env);
void				manage_color(t_env *env);
t_pixel				create_pixel(int x, int y, int z, int color);
// start
void				add_start(t_env *env);
void				move_start(t_env *env, int x, int y);
void				set_default_start(t_env *env);

// zoom
void				add_zoom(t_env *env);
void				set_default_zoom(t_env *env);
void				reset_zoom(t_env *env);
void				set_zoom(t_env *env, int zoom);

// projections
void				isometry(t_env *env);
void				parallel(t_env *env);
void				apply_proj(t_env *env, int proj);
void				change_proj(t_env *env, int proj);


void				reset_to_or(t_env *env);



#endif
