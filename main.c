/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:55:15 by rverly            #+#    #+#             */
/*   Updated: 2023/01/21 21:26:35 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

int	main(int argc, char **argv)
{
	t_d	d;

	check_args(argc, argv, &d);
	d.mlx = mlx_init();
	if (d.mlx == NULL)
		return (1);
	init_d(&d);
	fractol(&d);
	mlx_key_hook(d.window, closed, &d);
	mlx_hook(d.window, 17, 0L, closed_x, &d);
	mlx_mouse_hook(d.window, scroll_mouse, &d);
	mlx_loop(d.mlx);
	mlx_destroy_window(d.mlx, d.window);
	return (0);
}
