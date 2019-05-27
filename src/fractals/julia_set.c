/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:15:05 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/08 20:15:07 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

static int	iterate(t_data *data, double x, double y)
{
	t_cpx	new;
	double	tmp;
	int		i;

	new.x = x;
	new.y = y;
	i = 0;
	while (new.x * new.x + new.y * new.y < 4 && i < data->max_iter)
	{
		tmp = new.x;
		new.x = new.x * new.x - new.y * new.y + data->cst.x;
		new.y = 2.0 * tmp * new.y + data->cst.y;
		i++;
	}
	return (i);
}

void		julia_set(t_data *data, int th)
{
	t_cpx	cur;
	t_cpx	pt;
	int		i;
	int		limit;
	int		color;

	limit = (th + 1) * 50;
	cur.y = th * 50;
	while (cur.y < limit)
	{
		cur.x = 0;
		while (cur.x < WIN_HEIGHT)
		{
			give_value(data, &pt, cur.x, cur.y);
			i = iterate(data, pt.x, pt.y);
			color = data->color[data->ind] / data->max_iter * i;
			if (i == data->max_iter)
				put_pixel(data, cur.x, cur.y, 0);
			else
				put_pixel(data, cur.x, cur.y, color);
			cur.x++;
		}
		cur.y++;
	}
}
