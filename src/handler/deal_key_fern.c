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

void	deal_key_fern(t_data *data)
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
	if (data->keyboard[KEY_PAGE_UP])
		data->max_iter *= 2;
	if (data->keyboard[KEY_PAGE_DOWN])
		if (data->max_iter >= 2)
			data->max_iter /= 2;
	barnsley_fern(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	call_hud(data);
}
