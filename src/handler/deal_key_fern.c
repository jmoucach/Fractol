/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_fern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:32:13 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/27 14:32:14 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void	deal_key_fern_ter(t_data *data)
{
	if (data->keyboard[KEY_6] || data->keyboard[KEY_PAD_6])
	{
		init_seirp(data);
		data->fract = 6;
	}
	else if (data->keyboard[KEY_4] || data->keyboard[KEY_PAD_4])
	{
		init_seirp(data);
		data->fract = 4;
	}
	else if (data->keyboard[KEY_7] || data->keyboard[KEY_PAD_7])
	{
		init_seirp(data);
		data->fract = 7;
	}
	if (data->keyboard[KEY_C])
	{
		data->ind += 1;
		if (data->ind > 9)
			data->ind = 0;
		data->keyboard[KEY_C] = 0;
	}
	deal_key_chooser(data);
}

void	deal_key_fern_bis(t_data *data)
{
	if (data->keyboard[KEY_0] || data->keyboard[KEY_1] || data->keyboard[KEY_2]
		|| data->keyboard[KEY_3] || data->keyboard[KEY_PAD_0]
		|| data->keyboard[KEY_PAD_1] || data->keyboard[KEY_PAD_2]
		|| data->keyboard[KEY_PAD_3])
		init_data(data);
	if (data->keyboard[KEY_0] || data->keyboard[KEY_PAD_0])
		data->fract = 0;
	else if (data->keyboard[KEY_1] || data->keyboard[KEY_PAD_1])
		data->fract = 1;
	else if (data->keyboard[KEY_2] || data->keyboard[KEY_PAD_2])
		data->fract = 2;
	else if (data->keyboard[KEY_3] || data->keyboard[KEY_PAD_3])
		data->fract = 3;
	if (data->keyboard[KEY_PAD_SUB])
		if (data->zoom > 1)
			data->zoom /= 1.1;
	if (data->keyboard[KEY_PAD_ADD])
		data->zoom *= 1.1;
	deal_key_fern_ter(data);
}

void	deal_key_fern(t_data *data)
{
	if (data->keyboard[KEY_ESCAPE])
	{
		ft_putendl("Exit");
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (data->keyboard[KEY_PAGE_UP])
		data->max_iter += 5000;
	if (data->keyboard[KEY_PAGE_DOWN])
		if (data->max_iter >= 10000)
			data->max_iter -= 5000;
	if (data->keyboard[KEY_W])
		data->yoff += 0.05;
	if (data->keyboard[KEY_S])
		data->yoff -= 0.05;
	if (data->keyboard[KEY_D])
		data->xoff += 0.05;
	if (data->keyboard[KEY_A])
		data->xoff -= 0.05;
	if (data->keyboard[KEY_SPACEBAR])
		init_fern(data);
	deal_key_fern_bis(data);
}
