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

#include "../hdr/fractol.h"

int		deal_key(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->keyboard[KEY_ESCAPE])
	{
		ft_putendl("Exit");
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (data->keyboard[KEY_PAD_SUB])
		if (data->zoom > 0.1)
			data->zoom -= 0.1;
	if (data->keyboard[KEY_PAD_ADD])
		data->zoom += 0.1;
	if (data->keyboard[KEY_PAGE_UP])
		data->max_iter += 1;
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
	if (data->keyboard[KEY_C])
	{
		data->ind += 1;
		if (data->ind > 9)
			data->ind = 0;
		data->keyboard[KEY_C] = 0;
	}
	if (data->keyboard[KEY_SPACEBAR])
	{
		init_data(data);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_bzero(data->img.img_str, 4 * WIN_HEIGHT * WIN_WIDTH);
		print_fract(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (1);
}

int mouse_press(int button, int x, int y, void *param)
{
	t_data	*data;
	double	old_zoom;

	data = (t_data *)param;
	if (button == SCROLL_UP)
	{
		old_zoom = data->zoom;
		data->zoom += 0.15;
		data->xoff -= (0.05 / data->zoom) * ((WIN_WIDTH / 2 - x) / 64);
		data->yoff -= (0.05 / data->zoom) * ((WIN_HEIGHT / 2 - y) / 64);
	}
	if (button == SCROLL_DOWN)
	{
		old_zoom = data->zoom;
		data->zoom -= 0.1;
		data->xoff += (0.05 / data->zoom) * ((WIN_WIDTH / 2 - x) / 64);
		data->yoff += (0.05 / data->zoom) * ((WIN_HEIGHT / 2 - y) / 64);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_bzero(data->img.img_str, 4 * WIN_HEIGHT * WIN_WIDTH);
		print_fract(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
		return (1);
}

int		key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->keyboard[key] = 1;
	return (0);
}

int		key_release(int key, void *param)
{
	t_data	*data;
		data = (t_data *)param;
	if (key != KEY_C)
		data->keyboard[key] = 0;
	return (0);
}
