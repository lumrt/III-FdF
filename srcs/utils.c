/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:18:04 by lumaret           #+#    #+#             */
/*   Updated: 2024/08/20 14:35:34 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_mlx(t_fdf *fdf)
{
	if (fdf->mlx_ptr != NULL && fdf->win_ptr != NULL)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->img_ptr != NULL)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	if (fdf->mlx_ptr != NULL)
	{
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
	if (fdf->map != NULL)
		free_map(fdf->map);
	if (fdf->map_size != NULL)
		free(fdf->map_size);
	exit(0);
}

void	free_splits(char ***splits, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_freesplit(splits[i]);
		i++;
	}
	free(splits);
}

void	malloc_exit(t_fdf *fdf)
{
	ft_printf("%s     __\n  _ / /\n (_) | \n", RED);
	ft_printf("   | | \n  _| | \n (_) | \n    \\_\\ \n%s", RESET);
	ft_printf("%s[ERROR] At some point a malloc failed.\n%s", RED, RESET);
	free_mlx(fdf);
}
