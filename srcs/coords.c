/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:16:30 by lumaret           #+#    #+#             */
/*   Updated: 2024/09/25 15:31:22 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_x(t_fdf *fdf, int x)
{
	return (fdf->start_x + fdf->x + (x * (BASE_SCALE + fdf->scale)));
}

int	get_y(t_fdf *fdf, int y, int scale)
{
	if (scale == 1)
		return (fdf->start_y + fdf->y + ((y + 1) * (BASE_SCALE + fdf->scale)));
	else
		return (fdf->start_y + y + fdf->y);
}

int	*iso_proj(t_fdf *fdf, int x, int y, int z)
{
	int	*coord;

	coord = malloc(sizeof(int) * 2);
	if (!coord)
		malloc_exit(fdf);
	coord[0] = (x - y) * 0.866025;
	coord[1] = -z + (x + y) * 0.5;
	return (coord);
}
