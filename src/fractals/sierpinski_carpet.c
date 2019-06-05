/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:41:18 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/29 11:41:20 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void		draw_square(t_data *data, t_pos p1, t_pos p2)
{
	t_pos p3;

	p3.x = p2.x;
	p3.y = p1.y;
	while (p3.y != p2.y)
	{
		p3.y++;
		p1.y++;
		draw_line(p1, p3, data, 0xffffff);
	}
}

void		divide_carpet(t_data *data, t_pos p1, t_pos p2, int lvl)
{
	if (lvl == 1)
		draw_square(data, p1, p2);
	else
	{
		divide_carpet(data, (t_pos){p1.x, p1.y}, (t_pos)
			{(2 * p1.x + p2.x) / 3.0, (2 * p1.y + p2.y) / 3.0}, lvl - 1);
		divide_carpet(data, (t_pos){(2 * p1.x + p2.x) / 3.0, p1.y}, (t_pos)
			{(p1.x + 2 * p2.x) / 3.0, (2 * p1.y + p2.y) / 3.0}, lvl - 1);
		divide_carpet(data, (t_pos){(p1.x + 2 * p2.x) / 3.0, p1.y}, (t_pos)
			{p2.x, (2 * p1.y + p2.y) / 3.0}, lvl - 1);
		divide_carpet(data, (t_pos){p1.x, (2 * p1.y + p2.y) / 3.0}, (t_pos)
			{(2 * p1.x + p2.x) / 3.0, (p1.y + 2 * p2.y) / 3.0}, lvl - 1);
		divide_carpet(data, (t_pos){(p1.x + 2 * p2.x) / 3.0,
			(2 * p1.y + p2.y) / 3.0}, (t_pos){p2.x,
			(p1.y + 2 * p2.y) / 3.0}, lvl - 1);
		divide_carpet(data, (t_pos){p1.x, (p1.y + 2 * p2.y) / 3.0}, (t_pos)
			{(2 * p1.x + p2.x) / 3.0, p2.y}, lvl - 1);
		divide_carpet(data, (t_pos){(2 * p1.x + p2.x) / 3.0,
			(p1.y + 2 * p2.y) / 3.0}, (t_pos){(p1.x + 2 * p2.x) / 3.0,
			p2.y}, lvl - 1);
		divide_carpet(data, (t_pos){(p1.x + 2 * p2.x) / 3.0,
			(p1.y + 2 * p2.y) / 3.0}, (t_pos){p2.x, p2.y}, lvl - 1);
	}
}

void		sierpinski_carpet(t_data *data)
{
	t_pos	p1;
	t_pos	p2;

	p1.x = 200 + data->xoff;
	p1.y = 200 + data->yoff;
	p2.x = 600 + data->xoff;
	p2.y = 600 + data->yoff;
	divide_carpet(data, p1, p2, data->max_iter);
}