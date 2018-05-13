/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:32:41 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/14 00:05:11 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "mlx.h"

# include "mlx_keycode.h"

# include "libft.h"
# include "get_next_line.h"

# define WHITE		0xFFFFFF
/*
** Window dimensions
*/

# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000

/*
** Top Menu dimensions
*/

# define T_M_WIDTH	WIN_WIDTH
# define T_M_HEIGHT	100
# define T_M_COLOR	0x34495E

/*
**	Down Menu dimensions
*/

# define D_M_WIDTH WIN_WIDTH
# define D_M_HEIGHT	50
# define D_M_COLOR	T_M_COLOR

/*
**	Borders
*/

# define B_HEIGHT 5
# define B_COLOR 0xECF0F1

/*
** Text Menu
*/

# define COL1	5
# define COL2	T_M_WIDTH / 3
# define COL3	COL2 * 2

# define ROW1	25
# define ROW2	42
# define ROW3	59

# define D_COL2 D_M_WIDTH / 3
# define D_CENTER WIN_HEIGHT - 40

# define TEXT_COLOR	0xECF0F1
# define TEXT_ACTIVE 0xF1C40F


/*
** Workspace dimensions
*/

# define MARGIN		100
# define WS_WIDTH	WIN_WIDTH - MARGIN
# define WS_HEIGHT	WIN_HEIGHT - (T_M_HEIGHT + D_M_HEIGHT)

/*
**	Projections
*/

# define BASIC		999
# define ISO		998
# define PARA		997
# define CTE1		1
# define CTE2		1

/*
**	Errors
*/

# define ERR_OPEN	-665
# define ERR_MALLOC	-666
# define ERR_FILE	-664
# define ERR_WIDTH	-663

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

/*
**	Put in the image
*/

void				fill_pixel(t_env *env, int x, int y, int color);
void				fill_segment(t_env *env, t_pixel first, t_pixel second);
void				fill_square(t_pixel start, int width, int height, t_env *env);
void				fill_img(t_env * env);

/*
**	Managing images and windows
*/

void				create_img(t_env *env);
void				put_to_window(t_env *env);

/*
**	Starts points (src/start_points.c) 
*/
void				add_start(t_env *env);
void				move_start(t_env *env, int x, int y);
void				set_default_start(t_env *env);

/*
** Parsing (src/parser.c, etc)
*/
t_pixel				**parser(char *file, t_env *env);
int					get_height(char *file);
int					get_width(char *file);
int					if_width_valid(char *line, int width);
t_pixel				**make_array(int height, int width);
t_pixel				create_pixel(int x, int y, int z, int color);
void				set_or_to_curr(t_env *env);

/*
** Color (src/set_color.c)
*/
void				set_color(t_env *env);

/*
**	Menu (src/menu.c)
*/

void				fill_menu_bars(t_env *env);
void				print_keybinds(t_env *env);

/*
**	Events
*/
int					deal_key(int key, t_env *env);

/*
** Cleaning (src/free_env.c)
*/
void				free_env(t_env *env);

/*
** Quit (src/quit.c)
*/
void				quit_fdf(t_env *env);

/*
** Errors management (src/errors.c)
*/
void				errors(int error);
void				usage(void);

/*
**	Zoom (src/zoom.c)
*/
void				add_zoom(t_env *env);
void				set_default_zoom(t_env *env);
void				set_zoom(t_env *env, int zoom);

/*
**	Projections (src/projections.c)
*/
void				apply_proj(t_env *env, int proj);
void				change_proj(t_env *env, int proj);

#endif
