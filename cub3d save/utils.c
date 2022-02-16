/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:46:53 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/14 12:12:18 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* exit */
int	exit_mlx(t_data	*data)
{
	//free all;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}