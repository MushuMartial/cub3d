/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:50:59 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/02 16:46:53 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fillnorth(t_data *data, t_img *north, char *file)
{
	north->img = mlx_xpm_file_to_image(data->mlx, file, &north->w, &north->h);
	north->addr = mlx_get_data_addr(north->img, &north->bpp, &north->l_l,
			&north->endian);
}

void	ft_fillsouth(t_data *data, t_img *south, char *file)
{
	south->img = mlx_xpm_file_to_image(data->mlx, file, &south->w, &south->h);
	south->addr = mlx_get_data_addr(south->img, &south->bpp, &south->l_l,
			&south->endian);
}

void	ft_filleast(t_data *data, t_img *east, char *file)
{
	east->img = mlx_xpm_file_to_image(data->mlx, file, &east->w, &east->h);
	east->addr = mlx_get_data_addr(east->img, &east->bpp, &east->l_l,
			&east->endian);
}

void	ft_fillwest(t_data *data, t_img *west, char *file)
{
	west->img = mlx_xpm_file_to_image(data->mlx, file, &west->w, &west->h);
	west->addr = mlx_get_data_addr(west->img, &west->bpp, &west->l_l,
			&west->endian);
}
