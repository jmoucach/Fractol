/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:27:05 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/17 13:27:09 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"

t_cpx	derivative(double x, double y)
{
	t_cpx pt;

	pt.x = 3 * x * x - 3 * y * y;
	pt.y = 6 * x * y;
	return (pt);
}

t_cpx	newton(double x, double y)
{
	t_cpx pt;

	pt.x = x * x * x + 3 * x * y * y + 1;
	pt.y = 3 * x * x * y - y * y * y;
	return (pt);
}

static void iterate(t_data *data, double x, double y)
{
	int iter;
	int index;
	t_cpx r[2];
	t_cpx new;
	t_cpx newt;
	t_cpx der;
	double tolerance;
	t_cpx	dif;

	tolerance = 0.000001;
	new.x = x;
	new.y = y;
	r[1].x = 1;
	r[1].y = 0;
	r[2].x = -0.5;
	r[2].y = sqrt(3) / 2;
	r[3].x = -0.5;
	r[3].y = - sqrt(3) / 2;
	iter = 0;
	index = 0;
	while (iter < data->max_iter)
	{
		der = derivative(new.x, new.y);
		newt = newton(new.x, new.y);
		new.x -= newt.x / der.x;
		new.y -= newt.y / der.y;
		while (index < 3)
		{
			dif.x = new.x - r[index].x;
			dif.y = new.y - r[index].y;
			if (ft_abs(dif.x) < tolerance && ft_abs(dif.y) < tolerance)
				put_pixel(data, x, y, data->color[index]);
			index++;
		}
		iter++;
	}
}

void	newton_fractal(t_data *data, int th)
{
	int limit;
	t_cpx	pt;
	t_cpx cur;

	cur.y = th * 50;
	limit = (th + 1 ) * 50;
	while (cur.y < limit)
	{
		cur.x = 0;
		while (cur.x < WIN_HEIGHT)
		{
			give_value(data, &pt, cur.x, cur.y);
			iterate(data, pt.x, pt.y);
			cur.x++;
		}
		cur.y++;
	}
}
