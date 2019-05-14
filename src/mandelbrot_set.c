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

void	mandelbrot_set(t_data *data, int th)
{
	t_cpx	start;
	int y;
	int x;
	t_cpx	pt;
	t_cpx	new;
	t_cpx	old;
	int i;
	int limit;

	start.x = -0.75;
	start.y = 0.0;
	limit = (th + 1) * 50;

	y = th * 50;
	while (y < limit)
	{
		pt.y = (y - WIN_HEIGHT / 2.0) / (0.5 * data->zoom * WIN_HEIGHT) + data->yoff;
		x = 0;
		while (x < WIN_HEIGHT)
		{
			pt.x = 1.5 * (x - WIN_HEIGHT / 2.0) / (0.5 * data->zoom * WIN_HEIGHT) + data->xoff;
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
	pthread_exit(NULL);
}

