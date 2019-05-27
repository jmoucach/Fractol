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

void	deal_key_sierpinski_bis(t_data *data)
{
	if (data->keyboard[KEY_PAGE_UP])
		data->max_iter += 1;
	if (data->keyboard[KEY_PAGE_DOWN])
		if (data->max_iter > 1)
			data->max_iter -= 1;
	if (data->keyboard[KEY_SPACEBAR])
		init_seirp(data);
}

void	deal_key_sierpinski(t_data *data)
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
	deal_key_sierpinski_bis(data);
	sierpinski_triangle(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	call_hud(data);
}
