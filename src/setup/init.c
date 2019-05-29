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

#include "../../hdr/fractol.h"

void	init_img(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_HEIGHT,
		WIN_HEIGHT);
	data->img.img_str = (int*)mlx_get_data_addr(data->img.img_ptr,
		&(data->img.bpp), &(data->img.sl), &(data->img.endian));
	create_hud_img(data);
}

void	init_data(t_data *data)
{
	data->zoom = 1;
	data->max_iter = 15;
	data->cst.x = -0.8;
	data->cst.y = 0.156;
	data->xoff = 0;
	data->yoff = 0;
	data->ind = 0;
}

void	init_seirp(t_data *data)
{
	data->max_iter = 1;
	data->xoff = 0;
	data->yoff = 0;
	data->permit = 0;
	data->slength = 400;
}

void	init_fern(t_data *data)
{
	data->max_iter = 2048;
	data->xoff = 0;
	data->yoff = 0;
	data->permit = 0;
}

void	init(t_data *data)
{
	data->color[0] = 0xffffff;
	data->color[1] = 0xff0000;
	data->color[2] = 0x00ff00;
	data->color[3] = 0xff0f0f;
	data->color[4] = 0xffff00;
	data->color[5] = 0x00ffff;
	data->color[6] = 0xff00ff;
	data->color[7] = 0x009933;
	data->color[8] = 0xff6600;
	data->color[9] = 0xff66cc;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT, "fractol");
	init_data(data);
	init_img(data);
}
