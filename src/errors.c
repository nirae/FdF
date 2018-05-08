/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:17:18 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/08 18:01:17 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors(int error)
{
	//free_env(env);
	ft_putendl("error :");
	if (error == ERR_OPEN)
		ft_putendl("open failed");
	else if (error == ERR_MALLOC)
		ft_putendl("malloc failed");
	else if (error == ERR_FILE)
		ft_putendl("file not valid, please try again or see the usage");
	exit(0);
}
