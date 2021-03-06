/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:26:34 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/27 10:26:35 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void			color_hud(t_data *data)
{
	int			i;
	int			j;
	int			m_width;

	i = 0;
	m_width = WIN_WIDTH - WIN_HEIGHT;
	while (i < m_width * WIN_HEIGHT)
	{
		data->hud.img_str[i] = 0x808080;
		i++;
	}
	j = WIN_HEIGHT - 399;
	while (j <= WIN_HEIGHT - 11)
	{
		i = 11 + j * m_width;
		while (i < m_width - 10 + j * m_width)
		{
			data->hud.img_str[i] = 0xFF6950;
			i++;
		}
		j++;
	}
}

void			put_pixel_hud(t_data *data, int x, int y, int color)
{
	int			index;

	index = x + y * (WIN_WIDTH - WIN_HEIGHT);
	if (is_inside_window(x, y))
		data->hud.img_str[index] = color;
}

void			draw_line_hud(t_pos a, t_pos b, t_data *data, int color)
{
	t_line		params;
	t_pos		p;

	params = setup_params(a, b);
	p = a;
	while (p.y != b.y || p.x != b.x)
	{
		put_pixel_hud(data, p.x, p.y, color);
		if ((params.error = params.offset * 2) > -params.delta_y)
		{
			params.offset -= params.delta_y;
			p.x += params.sign_x;
		}
		if (params.error < params.delta_x)
		{
			params.offset += params.delta_x;
			p.y += params.sign_y;
		}
	}
	put_pixel_hud(data, p.x, p.y, color);
}

void			box(t_pos p1, t_pos p2, t_data *data)
{
	t_pos		p3;
	t_pos		p4;
	t_pos		p5;
	t_pos		p6;

	p3.x = p1.x;
	p3.y = p2.y;
	p4.x = p2.x;
	p4.y = p1.y;
	draw_line_hud(p1, p3, data, 0xffffff);
	draw_line_hud(p1, p4, data, 0xffffff);
	draw_line_hud(p2, p3, data, 0xffffff);
	draw_line_hud(p2, p4, data, 0xffffff);
	p5.x = 10;
	p5.y = 55;
	p6.x = 390;
	p6.y = 55;
	draw_line_hud(p5, p6, data, 0xffffff);
	p5.y = 190;
	p6.y = 190;
	draw_line_hud(p5, p6, data, 0xffffff);
	p5.y = WIN_HEIGHT - 400;
	p6.y = WIN_HEIGHT - 400;
	draw_line_hud(p5, p6, data, 0xffffff);
	draw_order(data);
}
