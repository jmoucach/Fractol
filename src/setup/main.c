/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:23:18 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/08 19:23:19 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void	ft_mlx(t_data *data)
{
	mlx_hook(data->win_ptr, KEYPRESS, KEYPRESSMASK, key_press, data);
	mlx_hook(data->win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, data);
	mlx_hook(data->win_ptr, MOUSEPRESS, (1L << 2), mouse_press, data);
	mlx_hook(data->win_ptr, MOUSE_MVT, 0, mouse_move, data);
	mlx_loop_hook(data->mlx_ptr, dealer, data);
	mlx_loop(data->mlx_ptr);
}

void	first_choose(t_data *data)
{
	if (data->fract < 4)
		threads(data);
	else if (data->fract == 7)
	{
		init_seirp(data);
		sierpinski_carpet(data);
	}
	else if (data->fract == 6)
	{
		init_seirp(data);
		koch(data);
	}
	else if (data->fract == 5)
	{
		init_fern(data);
		barnsley_fern(data);
	}
	else if (data->fract == 4)
	{
		init_seirp(data);
		sierpinski_triangle(data);
	}
}

int		main(int ac, char **av)
{
	t_data	data;

	data.fract = 0;
	if (ac == 2)
	{
		parser(av[1], &data);
		init(&data);
		first_choose(&data);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.img.img_ptr, 0, 0);
		call_hud(&data);
		ft_mlx(&data);
	}
	else
		ft_putendl("Wrong number of argument!\nUsage: ./fractol fractal_name");
	return (1);
}
