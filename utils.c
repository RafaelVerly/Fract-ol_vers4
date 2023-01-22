/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:36:47 by rverly            #+#    #+#             */
/*   Updated: 2023/01/21 21:40:27 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], fd);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

void	check_args(int argc, char **argv, t_d *d)
{
	if (argc != 2)
	{
		ft_putstr_fd("fractais:\nMandelbrot\nJulia", 1);
		ft_putstr_fd("Julia_1\nJulia_2\nJulia_3\nJulia_4\n", 1);
		exit(1);
	}
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		d->fractol = "Mandelbrot";
	else if (!ft_strcmp(argv[1], "Julia"))
		d->fractol = "Julia";
	else if (!ft_strcmp(argv[1], "Julia_1"))
		d->fractol = "Julia_1";
	else if (!ft_strcmp(argv[1], "Julia_2"))
		d->fractol = "Julia_2";
	else if (!ft_strcmp(argv[1], "Julia_3"))
		d->fractol = "Julia_3";
	else if (!ft_strcmp(argv[1], "Julia_4"))
		d->fractol = "Julia_4";
	else
	{
		ft_putstr_fd("fractais:\nMandelbrot\nJulia\n", 1);
		ft_putstr_fd("Julia_1\nJulia_2\nJulia_3\nJulia_4\n", 1);
		exit(0);
	}
}

int	rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	px_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->a + (y * img->len + x * (img->b / 8));
	*(unsigned int *)dst = color;
}
