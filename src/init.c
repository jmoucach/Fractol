/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:43:40 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/08 19:43:41 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"

void	init_img(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH,
		WIN_HEIGHT);
	data->img.img_str = (int*)mlx_get_data_addr(data->img.img_ptr,
		&(data->img.bpp), &(data->img.sl), &(data->img.endian));
}

void	init_data(t_data *data)
{
	data->zoom = 1;
	data->max_iter = 16;
	data->xoff = 0;
	data->yoff = 0;
	data->ind = 0;
	data->color[0] = 0xffffff;
	data->color[1] = 0xE6E6FA;
	data->color[2] = 0xff0000;
	data->color[3] = 0xFFFAFA;
	data->color[4] = 0x808000;
	data->color[5] = 0xD2691E;
	data->color[6] = 0x696969;
	data->color[7] = 0x708090;
	data->color[8] = 0xFFDAB9;
	data->color[9] = 0xF4A460;
}

void	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
	init_data(data);
	init_img(data);
}
