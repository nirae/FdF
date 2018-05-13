/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:34:11 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/13 23:21:04 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Free the 2 arrays malloced in the env struct
*/

void	free_env(t_env *env)
{
	ft_memdel((void **)env->or_tab);
	ft_memdel((void **)env->curr_tab);
}
