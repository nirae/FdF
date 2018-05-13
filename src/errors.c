/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:17:18 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/13 23:24:07 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Managing the errors with the error code
*/

void	errors(int error)
{
	ft_putendl("Error :");
	if (error == ERR_OPEN)
		ft_putendl("This file can't be opened");
	else if (error == ERR_MALLOC)
		ft_putendl("Malloc failed");
	else if (error == ERR_FILE)
		ft_putendl("File not valid, please try again or see the usage");
	else if (error == ERR_WIDTH)
		ft_putendl("The file width is not equal on all lines");
	exit(1);
}

/*
** Print the usage
*/

void	usage(void)
{
	ft_putendl("usage: ./fdf file");
	ft_putendl("    The file need to have the same width on each lines");
	ft_putendl("    Exemples:\n");
	ft_putendl("         0 0  0  0");
	ft_putendl("         0 10 10 0");
	ft_putendl("         0 0  0  0");
	ft_putendl("         Valid\n");
	ft_putendl("         0 0  0  0");
	ft_putendl("         0 10 10");
	ft_putendl("         0 0  0  0");
	ft_putendl("         Not valid\n");
	exit(0);
}
