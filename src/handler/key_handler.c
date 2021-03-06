/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:17:00 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/10 12:17:02 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

int			mouse_press(int button, int x, int y, void *param)
{
	t_data	*data;
	double	old_zoom;

	data = (t_data *)param;
	if (data->fract < 4)
	{
		if (button == SCROLL_UP)
		{
			old_zoom = data->zoom;
			data->zoom += 0.15;
			data->xoff -= (0.05 / data->zoom) * ((WIN_HEIGHT / 2 - x) / 64);
			data->yoff -= (0.05 / data->zoom) * ((WIN_HEIGHT / 2 - y) / 64);
		}
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_bzero(data->img.img_str, 4 * WIN_HEIGHT * WIN_WIDTH);
		threads(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img_ptr, 0, 0);
		call_hud(data);
	}
	return (1);
}

void		deal_key_chooser(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->img.img_str, 4 * WIN_HEIGHT * WIN_WIDTH);
	if (data->fract < 4)
		threads(data);
	else if (data->fract == 4)
		sierpinski_triangle(data);
	else if (data->fract == 5)
		barnsley_fern(data);
	else if (data->fract == 6)
		koch(data);
	else if (data->fract == 7)
		sierpinski_carpet(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	call_hud(data);
}

int			key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->keyboard[key] = 1;
	return (0);
}

int			key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key != KEY_C && key != KEY_TILDE && key != KEY_UP && key != KEY_DOWN)
		data->keyboard[key] = 0;
	return (0);
}

int			dealer(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->fract < 4)
		deal_key(data);
	else if (data->fract == 4 || data->fract == 7)
		deal_key_sierpinski(data);
	else if (data->fract == 5)
		deal_key_fern(data);
	else if (data->fract == 6)
		deal_key_koch(data);
	return (1);
}
