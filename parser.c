/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:37:38 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/18 15:55:49 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Init Variables */
/* int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},*/
void make_map(t_data *data)
{
	data->map = malloc(sizeof(char *) * 8);
	data->map[0] = ft_strdup("11111111");
    data->map[1] = ft_strdup("10000011");
    data->map[2] = ft_strdup("10000001");
    data->map[3] = ft_strdup("10010011");
    data->map[4] = ft_strdup("10010001");
    data->map[5] = ft_strdup("10000001");
    data->map[6] = ft_strdup("100P0101");
    data->map[7] = ft_strdup("11111111");
    data->map_h = 8;
    data->map_l = 8;
	data->x = 3.45;
    data->y = 6.45;
	data->add_x = 0;
	data->add_y = 0;
	data->press = 0;
    data->press_turn = 0;
	data->direction = 180.000;
    
	//data->posX = 3.5, data->posY = 6.5;  //x and y start position
    //data->dirX = -1, data->dirY = 0; //initial direction vector
    //data->planeX = 0, data->planeY = 0.66; //the 2d raycaster version of camera plane
	//data->time = 0; //time of current frame
    //data->oldTime = 0; //time of previous frame
}
