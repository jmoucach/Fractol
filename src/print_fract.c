/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:11:54 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/08 20:11:58 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"

int		is_inside_window(int x, int y)
{
		if (x > (WIN_WIDTH) - 1 || x < 0
		 || y <= 0 || y >= WIN_HEIGHT)
		return (0);
		return (1);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int index;

	index = x + y * WIN_WIDTH;
	if (is_inside_window(x, y))
	{
		data->img.img_str[index] = color;
	}
}

void	print_fract(t_data *data)
{
	if (data->fract == 2)
		mandelbrot_set(data);
	else
		ft_putendl("wut");
}
