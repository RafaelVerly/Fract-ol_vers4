/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:49:30 by rverly            #+#    #+#             */
/*   Updated: 2023/01/21 22:07:18 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 960
# define HEIGHT 640

typedef struct s_img
{
	void	*img;
	char	*a;
	int		b;
	int		len;
	int		e;
}	t_img;

typedef struct s_d
{
	void	*mlx;
	void	*window;
	int		max;
	int		i;
	double	coef;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	double	zoom;
	double	move_x;
	double	move_y;
	char	*fractol;
	t_img	img;
}	t_d;
//eventos
int		scroll_mouse(int keycode, int x, int y, t_d *d);
int		closed_x(t_d *d);
int		closed(int keycode, t_d *d);
//outros
void	px_put(t_img *img, int x, int y, int color);
void	init_d(t_d *d);
//fractol calculates
int		fractol(t_d *d);
void	julia_set(t_d *d, int x, int y);
void	mandelbrot_set(t_d *d, int x, int y);
//color
int		rgb(int t, int r, int g, int b);
//libft
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
//utils
void	check_args(int argc, char **argv, t_d *d);
// julia_options
void	julia_options(t_d *d, char *fractol);
#endif
