/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:05:35 by rverly            #+#    #+#             */
/*   Updated: 2023/01/21 22:12:24 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	init_img(t_d *d)
{
	d->img.img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img.a = mlx_get_data_addr(d->img.img, &d->img.b, &d->img.len, &d->img.e);
}

void	init_d(t_d *d)
{
	d->zoom = 0.7;
	d->move_x = 0.0;
	d->move_y = 0.0;
	d->max = 100;
	d->i = 0;
	d->coef = 0.6;
	d->window = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Fractol");
	if (!d->window)
		exit (0);
	init_img(d);
}

int	fractol(t_d *d)
{
	int	row;
	int	col;

	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			if (!ft_strcmp(d->fractol, "Mandelbrot"))
				mandelbrot_set(d, row, col);
			else
				julia_set(d, row, col);
			col++;
		}
		row++;
	}
	mlx_clear_window(d->mlx, d->window);
	mlx_put_image_to_window(d->mlx, d->window, d->img.img, 0, 0);
	return (0);
}

void	mandelbrot_set(t_d *d, int row, int col)
{
	double	x_new;

	d->i = 0;
	d->x = 0;
	d->y = 0;
	d->c_re = 1.5 * (col - WIDTH / 2) / (0.5 * d->zoom * WIDTH) + d->move_x;
	d->c_im = (row - HEIGHT / 2) / (0.5 * d->zoom * HEIGHT) + d->move_y;
	while (d->x * d->x + d->y * d->y <= 4 && d->i < d->max)
	{
		x_new = d->x * d->x - d->y * d->y + d->c_re;
		d->y = 2 * d->x * d->y + d->c_im;
		d->x = x_new;
		d->i++;
	}
	if (d->i < d->max)
		px_put(&d->img, col, row, rgb(100, d->i * 1, d->i * 10, d->i * 50));
	else
		px_put(&d->img, col, row, 0);
}

void	julia_set(t_d *d, int row, int col)
{	
	double	x_new;

	d->i = 0;
	d->x = 1.5 * (col - WIDTH / 2) / (0.5 * d->zoom * WIDTH) + d->move_x;
	d->y = (row - HEIGHT / 2) / (0.5 * d->zoom * HEIGHT) + d->move_y;
	julia_options(d, d->fractol);
	while (d->x * d->x + d->y * d->y <= 4 && d->i < d->max)
	{
		x_new = d->x * d->x - d->y * d->y + d->c_re;
		d->y = 2 * d->x * d->y + d->c_im;
		d->x = x_new;
		d->i++;
	}
	if (d->i < d->max)
		px_put(&d->img, col, row, rgb(100, d->i * 10, d->i * 10, d->i * 30));
	else
		px_put(&d->img, col, row, 0);
}
