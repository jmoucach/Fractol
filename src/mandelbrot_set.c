/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:51:00 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/10 10:28:09 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"

void	mandelbrot_set(t_data *data)
{
	t_cpx	start;
	unsigned int y;
	unsigned int x;
	t_cpx	pt;
	t_cpx	new;
	t_cpx	old;
	int i;

	start.x = -0.75;
	start.y = 0.0;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		pt.y = (y - WIN_HEIGHT / 2.0) / (0.5 * data->zoom * WIN_HEIGHT) + data->yoff;
		x = 0;
		while (x < WIN_WIDTH)
		{
			pt.x = 1.5 * (x - WIN_WIDTH / 2.0) / (0.5 * data->zoom * WIN_WIDTH) + data->xoff;
			new.x = 0;
			new.y = 0;
			old.y = 0;
			old.x = 0;
			i = 0;
			while (new.x * new.x + new.y * new.y < 4 && i < data->max_iter)
			{
				old.x = new.x;
				old.y = new.y;
				new.x = old.x * old.x - old.y * old.y + pt.x;
				new.y = 2.0 * old.x * old.y + pt.y;
				i++;
			}
			if (i == data->max_iter)
				put_pixel(data, x, y, 0);
			else
				put_pixel(data, x, y, data->color[data->ind] / i);
			x++;
		}
		y++;
	}
}

