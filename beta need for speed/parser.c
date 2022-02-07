/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:37:38 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/07 17:06:59 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Init Variables */
void make_map(t_data *data)
{
	data->map = malloc(sizeof(char *) * 8);
	data->map[0] = ft_strdup("11111111");
    data->map[1] = ft_strdup("10010001");
    data->map[2] = ft_strdup("10010001");
    data->map[3] = ft_strdup("10010001");
    data->map[4] = ft_strdup("10000001");
    data->map[5] = ft_strdup("10000001");
    data->map[6] = ft_strdup("100P0101");
    data->map[7] = ft_strdup("11111111");
    data->map_h = 8;
    data->map_l = 8;
	data->x = 3.45;
	data->add_x = 0;
	data->add_y = 0;
	data->y = 6.45;
	data->press = 0;
	data->direction = 0.003;
}
