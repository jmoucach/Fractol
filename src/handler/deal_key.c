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

void	deal_key_bis(t_data *data)
{
	if (data->keyboard[KEY_PAGE_DOWN])
		if (data->max_iter > 10)
			data->max_iter -= 1;
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
	{
		init_data(data);
	}
	if (data->keyboard[KEY_PAGE_UP])
		data->max_iter += 1;
}

void	deal_key(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->img.img_str, 4 * WIN_HEIGHT * WIN_WIDTH);
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
	threads(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	call_hud(data);
}
