/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:09:14 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/23 11:09:20 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void		create_hud_img(t_data *data)
{
	int		m_width;
	t_pos	p1;
	t_pos	p2;

	m_width = WIN_WIDTH - WIN_HEIGHT;
	data->hud.img_ptr = mlx_new_image(data->mlx_ptr,
		m_width, WIN_HEIGHT);
	data->hud.img_str = (int*)mlx_get_data_addr(data->hud.img_ptr,
		&(data->img.bpp), &(data->img.sl), &(data->img.endian));
	color_hud(data);
	p1.x = 10;
	p1.y = 10;
	p2.x = m_width - 10;
	p2.y = WIN_HEIGHT - 10;
	box(p1, p2, data);
}

void		call_hud_bis(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 245, 0xffffff,
		"C         : Change color palette");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 265, 0xffffff,
		"W A S D   : Directionnal movement");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 285, 0xffffff,
		"PG UP     : Max iteration increase");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 305, 0xffffff,
		"PG DWN    : Max iteration decrease");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 325, 0xffffff,
		"0 to 7    : Change fractal");
	if (data->fract < 4)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 345, 0xffffff,
			"+ & -     : Zoom IN & OUT");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 365, 0xffffff,
			"Scroll UP & DWN : Zoom IN & OUT");
	}
}

void		call_hud(t_data *data)
{
	t_info	i;

	generate_info(&i, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->hud.img_ptr, 800, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 930, 25, 0xffffff, i.fract);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 65, 0xffffff, i.max_iter);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 85, 0xffffff, i.zoom);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 105, 0xffffff, i.x_off);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 125, 0xffffff, i.y_off);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 145, 0xffffff, i.cst_x);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 165, 0xffffff, i.cst_y);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 970, 200, 0xffffff,
		"KEYS:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 830, 225, 0xffffff,
		"Space     : Reset changes");
	call_hud_bis(data);
}
