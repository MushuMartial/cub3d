/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:26:09 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/18 13:31:56 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_raycast(t_ray *ray, t_data *data)
{
    ray->start_x = data->x + 0.05;
    ray->start_y = data->y + 0.05;
    ray->dir_x = sin(data->dir_ray * (0.01745329251));//* (PI / 180)
	ray->dir_y = cos(data->dir_ray * (0.01745329251));
    ray->ustep_x = sqrt(1.0 + pow(ray->dir_y / ray->dir_x, 2));
    ray->ustep_y = sqrt(1.0 + pow(ray->dir_x / ray->dir_y, 2));
    ray->map_x = (int)(data->x + 0.05);
    ray->map_y = (int)(data->y + 0.05);
    ray->fish = 0;

    // connaitre la direction et taille   
    if (ray->dir_x < 0) //ray to the left x dimiune else x augmente
    {
        ray->vStep_x = -1;
        ray->lenx = (ray->start_x - (ray->map_x)) * ray->ustep_x;//cb x dedans
    }
    else
    { 
        ray->vStep_x = 1; 
        ray->lenx = ((ray->map_x + 1) - ray->start_x) * ray->ustep_x;//cb x avant de sortir
    }
    if (ray->dir_y < 0) //ray down y dimiune else y augmente
    {
        ray->vStep_y = -1; 
        ray->leny = (ray->start_y - (ray->map_y)) * ray->ustep_y;
    }
    else
    { 
        ray->vStep_y = 1;
        ray->leny = ((ray->map_y + 1) - ray->start_y) * ray->ustep_y;
    }
    
    int bTileFound = 0;
    float fmaxdistance = 8;
    float fdistance = 0;
    while (!bTileFound && fdistance < fmaxdistance)
    {
        //walk
        if (ray->lenx < ray->leny) //marche ds l axe x
        {
            ray->map_x += ray->vStep_x;
            fdistance = ray->lenx;
            ray->lenx += ray->ustep_x;
            ray->fish = 1;//true
        }
        else
        {
            ray->map_y += ray->vStep_y;
            fdistance = ray->leny;
            ray->leny += ray->ustep_y;
            ray->fish = 0;
        }
        //check collision
        if (ray->map_x >= 0 && ray->map_x < 8 && ray->map_y >= 0 && ray->map_y < 8)
        {
            if (data->map[(int)(ray->map_y)][(int)(ray->map_x)] == '1')
            {
                bTileFound = 1;
            }
        }
        
        if(bTileFound == 1)
        {
            ray->intersec_x = ray->start_x + (ray->dir_x * fdistance);
            ray->intersec_y = ray->start_y + (ray->dir_y * fdistance);
            ray->len = sqrt(pow(ray->intersec_x - (data->x + 0.05),2) + pow(ray->intersec_y - (data->y + 0.05),2));
            return ;
        }
    }
    ray->intersec_x = ray->start_x + (ray->dir_x * 1);
    ray->intersec_y = ray->start_y + (ray->dir_y * 1);
    ray->len = sqrt(pow(ray->intersec_x - (data->x + 0.05),2) + pow(ray->intersec_y - (data->y + 0.05),2));
    return ;
}
