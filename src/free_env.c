/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:34:11 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/08 18:45:45 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_env(t_env *env)
{
	/*int		i;

	i = -1;
	while (++i < env->height)
	{
		ft_memdel((void **)env->or_tab[i][0]);
		ft_memdel((void **)env->curr_tab[i][0]);
	}*/
	ft_memdel((void **)env->or_tab);
	ft_memdel((void **)env->curr_tab);
}
