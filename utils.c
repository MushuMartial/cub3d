/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:46:53 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/29 17:11:14 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* exit */
int	exit_mlx(t_data	*data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	sprites_init(t_data *data)
{
	data->north.img = mlx_xpm_file_to_image(data->mlx,
			data->txtr[0], &data->north.w, &data->north.h);
	data->north.addr = mlx_get_data_addr(data->north.img,
			&data->north.bpp, &data->north.l_l, &data->north.endian);
	data->south.img = mlx_xpm_file_to_image(data->mlx,
			data->txtr[1], &data->south.w, &data->south.h);
	data->south.addr = mlx_get_data_addr(data->south.img,
			&data->south.bpp, &data->south.l_l, &data->south.endian);
	data->west.img = mlx_xpm_file_to_image(data->mlx,
			data->txtr[2], &data->west.w, &data->west.h);
	data->west.addr = mlx_get_data_addr(data->west.img,
			&data->west.bpp, &data->west.l_l, &data->west.endian);
	data->east.img = mlx_xpm_file_to_image(data->mlx,
			data->txtr[3], &data->east.w, &data->east.h);
	data->east.addr = mlx_get_data_addr(data->east.img,
			&data->east.bpp, &data->east.l_l, &data->east.endian);
}
