/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:32:41 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/12 16:57:54 by ndubouil         ###   ########.fr       */
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

typedef struct		s_img
{
	void			*img_ptr;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	int				***tab;
}					t_env;

void				fill_pixel(t_img *img, int x, int y, int color);

#endif
