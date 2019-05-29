/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:46:05 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/17 15:46:09 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

t_pos	find_mid(t_pos p1, t_pos p2)
{
	t_pos mid;

	mid.x = (p1.x + p2.x) / 2;
	mid.y = (p1.y + p2.y) / 2;
	return (mid);
}

void	draw_triangle(t_data *data, t_pos pos[3])
{
	draw_line(pos[0], pos[1], data, data->color[data->ind]);
	draw_line(pos[1], pos[2], data, data->color[data->ind]);
	draw_line(pos[2], pos[0], data, data->color[data->ind]);
}

void	divide_triangle(t_data *data, t_pos pos[3], int level)
{
	if (level == 1)
		draw_triangle(data, pos);
	else
	{
		divide_triangle(data, (t_pos[3]){pos[0], find_mid(pos[0], pos[1]),
			find_mid(pos[0], pos[2])}, level - 1);
		divide_triangle(data, (t_pos[3]){find_mid(pos[0], pos[1]),
			pos[1], find_mid(pos[1], pos[2])}, level - 1);
		divide_triangle(data, (t_pos[3]){find_mid(pos[0], pos[2]),
			find_mid(pos[1], pos[2]), pos[2]}, level - 1);
	}
}

void	sierpinski_triangle(t_data *data)
{
	t_pos	pos[3];
	int		len;

	len = data->slength;
	pos[0].x = 200 + data->xoff;
	pos[0].y = 540 + data->yoff;
	pos[1].x = 600 + data->xoff;
	pos[1].y = 540 + data->yoff;
	pos[2].x = 400 + data->xoff;
	pos[2].y = cos(M_PI / 3) * len + data->yoff;
	divide_triangle(data, pos, data->max_iter);
}
