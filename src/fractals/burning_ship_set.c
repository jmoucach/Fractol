/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:12:58 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/17 13:13:00 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

static int	iterate(t_data *data, double x, double y)
{
	int		i;
	t_cpx	new;
	double	tmp;

	new.x = x;
	new.y = y;
	i = 0;
	while (new.x * new.x + new.y * new.y < 4 && i < data->max_iter)
	{
		tmp = new.x;
		new.x = ft_abs(new.x * new.x - new.y * new.y + x);
		new.y = ft_abs(2.0 * tmp * new.y) + y;
		i++;
	}
	return (i);
}

void		burning_ship_set(t_data *data, int th)
{
	t_cpx	cur;
	int		limit;
	int		i;
	t_cpx	pt;
	int		color;

	cur.y = th * 50;
	limit = (th + 1) * 50;
	while (cur.y < limit)
	{
		cur.x = 0;
		while (cur.x < WIN_HEIGHT)
		{
			give_value(data, &pt, cur.x, cur.y);
			i = iterate(data, pt.x, pt.y);
			color = hsv_to_rgb((t_hsv){(i * data->color[data->ind] / 256)
				% 360, 1, 1});
			if (i == data->max_iter)
				put_pixel(data, cur.x, cur.y, 0);
			else
				put_pixel(data, cur.x, cur.y, color);
			cur.x++;
		}
		cur.y++;
	}
}
