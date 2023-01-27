/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:58:28 by rverly            #+#    #+#             */
/*   Updated: 2023/01/26 19:24:31 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./include/fractol.h"

int	closed(int keycode, t_d *d)
{
	if (keycode == 53)
	{
		mlx_destroy_image(d->mlx, d->img.img);
		mlx_destroy_window(d->mlx, d->window);
		exit (0);
	}
	if (keycode == 124)
		d->move_x += (0.6 * 0.7 / d->zoom);
	if (keycode == 123)
		d->move_x -= (0.6 * 0.7 / d->zoom);
	if (keycode == 126)
		d->move_y += (0.6 * 0.7 / d->zoom);
	if (keycode == 125)
		d->move_y -= (0.6 * 0.7 / d->zoom);
	fractol(d);
	return (0);
}

int	scroll_mouse(int keycode, int x, int y, t_d *d)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		d->zoom *= 0.8;
	if (keycode == 5)
		d->zoom *= 1.2;
	fractol(d);
	return (0);
}

int	closed_x(t_d *d)
{
	mlx_destroy_window(d->mlx, d->window);
	exit (0);
	return (0);
}
