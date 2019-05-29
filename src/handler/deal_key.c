/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:43:45 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/21 10:43:47 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void	deal_key_ter(t_data *data)
{
	if (data->keyboard[KEY_0])
		data->fract = 0;
	else if (data->keyboard[KEY_1])
		data->fract = 1;
	else if (data->keyboard[KEY_2])
		data->fract = 2;
	else if (data->keyboard[KEY_3])
		data->fract = 3;
	else if (data->keyboard[KEY_4])
	{
		init_seirp(data);
		data->fract = 4;
	}
	else if (data->keyboard[KEY_5])
	{
		init_fern(data);
		data->fract = 5;
	}
	deal_key_chooser(data);
}

void	deal_key_bis(t_data *data)
{
	if (data->keyboard[KEY_PAGE_DOWN])
		if (data->max_iter > 10)
			data->max_iter -= 5;
	if (data->keyboard[KEY_W])
		data->yoff += 0.05 / data->zoom;
	if (data->keyboard[KEY_S])
		data->yoff -= 0.05 / data->zoom;
	if (data->keyboard[KEY_D])
		data->xoff -= 0.05 / data->zoom;
	if (data->keyboard[KEY_A])
		data->xoff += 0.05 / data->zoom;
	if (data->keyboard[KEY_TILDE] && data->fract == 0)
	{
		if (data->permit == 0)
			data->permit = 1;
		else
			data->permit = 0;
		data->keyboard[KEY_TILDE] = 0;
	}
	if (data->keyboard[KEY_SPACEBAR])
		init_data(data);
	if (data->keyboard[KEY_PAGE_UP])
		data->max_iter += 5;
	deal_key_ter(data);
}

void	deal_key(t_data *data)
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
	if (data->keyboard[KEY_PAD_SUB] && data->zoom > 0.4)
		data->zoom /= 1.1;
	if (data->keyboard[KEY_PAD_ADD])
		data->zoom *= 1.1;
	deal_key_bis(data);
}
