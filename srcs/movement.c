/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:18:22 by lumaret           #+#    #+#             */
/*   Updated: 2024/08/20 15:35:44 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	iso_movement(t_fdf *fdf, int direction)
{
	if (direction == RIGHT)
	{
		fdf->x -= 10;
		fdf->y += 10;
	}
	else if (direction == LEFT)
	{
		fdf->x += 10;
		fdf->y -= 10;
	}
	else if (direction == DOWN)
	{
		fdf->y -= 10;
		fdf->x -= 10;
	}
	else if (direction == UP)
	{
		fdf->y += 10;
		fdf->x += 10;
	}
}

void	zoom_handler(t_fdf *fdf, int direction)
{
	if (direction == ZOOM)
		fdf->scale += 1;
	else if (direction == DEZOOM)
		fdf->scale -= 1;
}

void	change_z(t_fdf *fdf, int key)
{
	if (key == PAGE_UP)
		fdf->z += 1;
	else if (key == PAGE_DOWN)
		fdf->z -= 1;
}
