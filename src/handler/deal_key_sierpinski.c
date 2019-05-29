/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_sierpinski.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:43:51 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/21 10:43:52 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void	deal_key_sierpinski_ter(t_data *data)
{
	if (data->keyboard[KEY_0] || data->keyboard[KEY_1] || data->keyboard[KEY_2]
		|| data->keyboard[KEY_3])
		init_data(data);
	if (data->keyboard[KEY_0])
		data->fract = 0;
	else if (data->keyboard[KEY_1])
		data->fract = 1;
	else if (data->keyboard[KEY_2])
		data->fract = 2;
	else if (data->keyboard[KEY_3])
		data->fract = 3;
	else if (data->keyboard[KEY_5])
	{
		init_fern(data);
		data->fract = 5;
	}
	deal_key_chooser(data);
}

void	deal_key_sierpinski_bis(t_data *data)
{
	if (data->keyboard[KEY_PAGE_UP])
		data->max_iter += 1;
	if (data->keyboard[KEY_PAGE_DOWN])
		if (data->max_iter > 1)
			data->max_iter -= 1;
	if (data->keyboard[KEY_SPACEBAR])
		init_seirp(data);
	if (data->keyboard[KEY_W])
		data->yoff -= 5;
	if (data->keyboard[KEY_S])
		data->yoff += 5;
	if (data->keyboard[KEY_D])
		data->xoff += 5;
	if (data->keyboard[KEY_A])
		data->xoff -= 5;
	if (data->keyboard[KEY_5])
	{
		data->fract = 5;
		data->max_iter = 512;
	}
	deal_key_sierpinski_ter(data);
}

void	deal_key_sierpinski(t_data *data)
{
	if (data->keyboard[KEY_ESCAPE])
	{
		ft_putendl("Exit");
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (data->keyboard[KEY_C])
	{
		data->ind += 1;
		if (data->ind > 9)
			data->ind = 0;
		data->keyboard[KEY_C] = 0;
	}
	deal_key_sierpinski_bis(data);
}
