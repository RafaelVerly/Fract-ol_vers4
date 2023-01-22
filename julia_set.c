/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:57:11 by rverly            #+#    #+#             */
/*   Updated: 2023/01/21 21:26:15 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	julia_options(t_d *d, char *arg)
{
	d->c_re = -0.72;
	d->c_im = 0.27015;
	if (!ft_strcmp(arg, "Julia_1"))
	{
		d->c_re = 0.45;
		d->c_im = 0.1428;
	}
	if (!ft_strcmp(arg, "Julia_2"))
	{
		d->c_re = 0.285;
		d->c_im = 0.01;
	}
	if (!ft_strcmp(arg, "Julia_3"))
	{
		d->c_re = -0.835;
		d->c_im = -0.2321;
	}
	if (!ft_strcmp(arg, "Julia_4"))
	{
		d->c_re = -0.70176;
		d->c_im = -0.3842;
	}
}
