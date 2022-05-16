/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacegain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:01:38 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/05 21:49:30 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_enroule(int counter, int commas)
{
	if (counter != 3 || commas != 2)
	{
		printf("RGB error, missing something?\n");
		exit(1);
	}
}

void	ft_afou(int *commas, int *k)
{
	*commas += 1;
	*k += 1;
}

void	ft_losstime(int *counter, int *k)
{
	*counter += 1;
	*k += 1;
}

void	ft_boring(t_data *data, int i, t_rev *r)
{
	while ((data->map[i][r->k] == '\n' || data->map[i][r->k] == 0) && r->k > 0)
		r->k--;
	while (r->k >= 0 && r->k >= r->max)
	{
		r->c = data->map[i][r->k];
		data->map[i][r->k] = data->map[i][++r->m];
		data->map[i][r->m] = r->c;
		r->k--;
	}
}
