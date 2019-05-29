/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_koch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:42:33 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/29 10:42:34 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void	deal_key_koch_ter(t_data *data)
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
	else if (data->keyboard[KEY_5] || data->keyboard[KEY_PAD_5])
	{
		init_fern(data);
		data->fract = 5;
	}
	else if (data->keyboard[KEY_6] || data->keyboard[KEY_PAD_6])
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
	deal_key_chooser(data);
}

void	deal_key_koch_bis(t_data *data)
{
	if (data->keyboard[KEY_PAGE_UP])
		if (data->max_iter < 9)
			data->max_iter += 1;
	if (data->keyboard[KEY_PAGE_DOWN])
		if (data->max_iter > 1)
			data->max_iter -= 1;
	if (data->keyboard[KEY_W])
		data->yoff -= 5;
	if (data->keyboard[KEY_S])
		data->yoff += 5;
	if (data->keyboard[KEY_D])
		data->xoff += 5;
	if (data->keyboard[KEY_A])
		data->xoff -= 5;
	deal_key_koch_ter(data);
}

void	deal_key_koch(t_data *data)
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
	deal_key_koch_bis(data);
}
