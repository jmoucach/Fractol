/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley_fern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:21:18 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/21 16:21:19 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

static t_pos	map(t_cpx pt, t_data *data)
{
	t_pos		map;

	map.x = WIN_HEIGHT / (2.6558 + 2.1820) * (pt.x + data->xoff + 2.1820)
		* data->zoom;
	map.y = ((-WIN_HEIGHT / 9.9983) * (pt.y + data->yoff) + WIN_HEIGHT)
		* data->zoom;
	return (map);
}

static void		next_point(t_cpx *pt)
{
	int			i;
	t_cpx		next;

	next.x = pt->x;
	next.y = pt->y;
	i = rand() % 100;
	if (i < 1)
		next.x = 0;
	else if (i < 86)
		next.x = 0.85 * pt->x + 0.04 * pt->y;
	else if (i < 93)
		next.x = 0.20 * pt->x - 0.26 * pt->y;
	else
		next.x = -0.15 * pt->x + 0.28 * pt->y;
	if (i < 1)
		next.y = 0.16 * pt->y;
	else if (i < 86)
		next.y = -0.04 * pt->x + 0.85 * pt->y + 1.6;
	else if (i < 93)
		next.y = 0.23 * pt->x + 0.22 * pt->y + 1.6;
	else
		next.y = 0.26 * pt->x + 0.24 * pt->y + 0.44;
	pt->x = next.x;
	pt->y = next.y;
}

void			barnsley_fern(t_data *data)
{
	int			i;
	t_cpx		pt;
	t_pos		out;

	pt.x = 0;
	pt.y = 0;
	i = 0;
	while (i < data->max_iter)
	{
		next_point(&pt);
		out = map(pt, data);
		put_pixel(data, out.x, out.y, data->color[data->ind]);
		i++;
	}
}
