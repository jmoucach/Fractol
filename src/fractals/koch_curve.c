/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_curve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:23:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/29 10:23:45 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void		koch_curve(t_data *data, t_pos p1, t_pos p2, int lvl)
{
	t_pos	p3;
	t_pos	p4;
	t_pos	p5;
	double	angle;

	if (lvl > 1)
	{
		angle = M_PI / 3;
		p3.x = (2 * p1.x + p2.x) / 3;
		p3.y = (2 * p1.y + p2.y) / 3;
		p4.x = (2 * p2.x + p1.x) / 3;
		p4.y = (2 * p2.y + p1.y) / 3;
		p5.x = p3.x + (p4.x - p3.x) * cos(angle) + (p4.y - p3.y) * sin(angle);
		p5.y = p3.y - (p4.x - p3.x) * sin(angle) + (p4.y - p3.y) * cos(angle);
		koch_curve(data, p1, p3, lvl - 1);
		koch_curve(data, p3, p5, lvl - 1);
		koch_curve(data, p5, p4, lvl - 1);
		koch_curve(data, p4, p2, lvl - 1);
	}
	else
	{
		draw_line(p1, p2, data, 0xffffff);
	}
}

void		koch(t_data *data)
{
	t_pos	p1;
	t_pos	p2;
	t_pos	p3;

	p1.x = 100 + data->xoff - 10 * data->zoom;
	p1.y = 140 + data->yoff - 10 * data->zoom;
	p2.x = (WIN_HEIGHT - 100) + data->xoff + 10 * data->zoom;
	p2.y = 140 + data->yoff - 10 * data->zoom;
	p3.x = 400 + data->xoff;
	p3.y = cos(M_PI / 3) * (WIN_HEIGHT + 100) + p1.y + (2 * 10 * data->zoom);
	koch_curve(data, p1, p2, data->max_iter);
	koch_curve(data, p3, p1, data->max_iter);
	koch_curve(data, p2, p3, data->max_iter);
}
