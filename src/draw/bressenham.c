/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:00:58 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/23 15:01:02 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"
#include <stdio.h>

static t_line	setup_params(t_pos a, t_pos b)
{
	t_line	params;

	params.sign_y = (a.y < b.y ? 1 : -1);
	params.sign_x = (a.x < b.x ? 1 : -1);
	params.delta_y = ft_abs(b.y - a.y);
	params.delta_x = ft_abs(b.x - a.x);
	params.offset = params.delta_x - params.delta_y;
	params.error = 0;
	return (params);
}

void		draw_line(t_pos a, t_pos b, t_data *data)
{
	t_line	params;
	t_pos	p;

	params = setup_params(a, b);
	p = a;
	while (p.y != b.y || p.x != b.x)
	{
		put_pixel(data, p.x, p.y, data->color[data->ind]);
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
	put_pixel(data, p.x, p.y, data->color[data->ind]);
}
