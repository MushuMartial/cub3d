/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:26:09 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/24 14:14:06 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_ray *ray, t_data *data)
{
	ray->start_x = data->x;
	ray->start_y = data->y;
	ray->dir_x = sin(data->dir_ray * RAD);
	ray->dir_y = cos(data->dir_ray * RAD);
	ray->ustep_x = sqrt(1.0 + pow(ray->dir_y / ray->dir_x, 2));
	ray->ustep_y = sqrt(1.0 + pow(ray->dir_x / ray->dir_y, 2));
	ray->map_x = (int)(data->x);
	ray->map_y = (int)(data->y);
	ray->vertical = 0;
	ray->bTileFound = 0;
	if (data->map_h > data->map_l)
		ray->fmaxdistance = data->map_h;
	else
		ray->fmaxdistance = data->map_l;
	ray->fdistance = 0;
	raycast2(ray, data);
}

void	raycast2(t_ray *ray, t_data *data)
{
	if (ray->dir_x < 0)
	{
		ray->vStep_x = -1;
		ray->lenx = (ray->start_x - (ray->map_x)) * ray->ustep_x;
	}
	else
	{
		ray->vStep_x = 1;
		ray->lenx = ((ray->map_x + 1) - ray->start_x) * ray->ustep_x;
	}
	if (ray->dir_y < 0)
	{
		ray->vStep_y = -1;
		ray->leny = (ray->start_y - (ray->map_y)) * ray->ustep_y;
	}
	else
	{
		ray->vStep_y = 1;
		ray->leny = ((ray->map_y + 1) - ray->start_y) * ray->ustep_y;
	}
	raycast3(ray, data);
}

void	raycast4(t_ray *ray, t_data *data)
{
	if (ray->lenx < ray->leny)
	{
		ray->map_x += ray->vStep_x;
		ray->fdistance = ray->lenx;
		ray->lenx += ray->ustep_x;
		ray->vertical = 1;
	}
	else
	{
		ray->map_y += ray->vStep_y;
		ray->fdistance = ray->leny;
		ray->leny += ray->ustep_y;
		ray->vertical = 0;
	}
	if (ray->map_x >= 0 && ray->map_x < data->map_l
		&& ray->map_y >= 0 && ray->map_y < data->map_h)
	{
		if (data->map[(int)(ray->map_y)][(int)(ray->map_x)] == '1')
			ray->bTileFound = 1;
	}
}

void	raycast3(t_ray *ray, t_data *data)
{
	while (ray->bTileFound == 0 && ray->fdistance < ray->fmaxdistance)
	{
		raycast4(ray, data);
		if (ray->bTileFound == 1)
		{
			ray->intersec_x = ray->start_x + (ray->dir_x * ray->fdistance);
			ray->intersec_y = ray->start_y + (ray->dir_y * ray->fdistance);
			ray->len = sqrt(pow(ray->intersec_x - (data->x), 2)
					+ pow(ray->intersec_y - (data->y), 2));
			return ;
		}
	}
	return ;
}
