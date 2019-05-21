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

void	deal_key_sierpinski(t_data *data)
{
	if (data->keyboard[KEY_PAD_SUB])
		if (data->zoom > 0.4)
			data->zoom /= 1.1;
		if (data->keyboard[KEY_PAD_ADD])
			data->zoom *= 1.1;
		if (data->keyboard[KEY_PAGE_UP])
			data->max_iter += 1;
		if (data->keyboard[KEY_PAGE_DOWN])
			if (data->max_iter > 1)
				data->max_iter -= 1;
		if (data->keyboard[KEY_W])
			data->yoff += 5;
		if (data->keyboard[KEY_S])
			data->yoff -= 5;
		if (data->keyboard[KEY_D])
			data->xoff -= 5;
		if (data->keyboard[KEY_A])
			data->xoff += 5;
		if (data->keyboard[KEY_SPACEBAR])
		{
			init_seirp(data);
		}
	sierpinski_triangle(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
}