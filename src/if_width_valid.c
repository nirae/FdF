/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_width_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:48:20 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/17 12:48:35 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		if_width_valid(char *line, int width)
{
	if (ft_count_words(line, ' ') != width)
		return (0);
	return (1);
}
