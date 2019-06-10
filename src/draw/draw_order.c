/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:42:09 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/29 14:42:12 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void	order(t_pos pos[15], t_data *data)
{
	draw_line_hud(pos[0], pos[1], data, 0xffffff);
	draw_line_hud(pos[1], pos[3], data, 0xffffff);
	draw_line_hud(pos[3], pos[4], data, 0xffffff);
	draw_line_hud(pos[4], pos[6], data, 0xffffff);
	draw_line_hud(pos[6], pos[7], data, 0xffffff);
	draw_line_hud(pos[7], pos[0], data, 0xffffff);
	draw_line_hud(pos[2], pos[12], data, 0xffffff);
	draw_line_hud(pos[5], pos[14], data, 0xffffff);
	draw_line_hud(pos[8], pos[10], data, 0xffffff);
	draw_line_hud(pos[10], pos[11], data, 0xffffff);
	draw_line_hud(pos[12], pos[13], data, 0xffffff);
	draw_line_hud(pos[9], pos[14], data, 0xffffff);
}

void	draw_order(t_data *data)
{
	t_pos pos[15];

	pos[0] = (t_pos){200 + 0, 600 + -150};
	pos[1] = (t_pos){200 + 130, 600 + -75};
	pos[2] = (t_pos){200 + 130, 600 + 5};
	pos[3] = (t_pos){200 + 130, 600 + 75};
	pos[4] = (t_pos){200 + 0, 600 + 150};
	pos[5] = (t_pos){200 + -75, 600 + 107};
	pos[6] = (t_pos){200 + -130, 600 + 75};
	pos[7] = (t_pos){200 + -130, 600 + -75};
	pos[8] = (t_pos){200 + -56, 600 + -117};
	pos[9] = (t_pos){200 + 0, 600 + -83};
	pos[10] = (t_pos){200 + 75, 600 + -42};
	pos[11] = (t_pos){200 + 75, 600 + 39};
	pos[12] = (t_pos){200 + 0, 600 + 85};
	pos[13] = (t_pos){200 + -75, 600 + 42};
	pos[14] = (t_pos){200 + -75, 600 + -42};
	order(pos, data);
}
