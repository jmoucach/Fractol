/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:26:34 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/14 13:26:37 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void			selector(t_data *data)
{
	static void	(*fract[4])(t_data*, int) = {julia_set, mandelbrot_set,
				mandelbar_set, burning_ship_set};
	pthread_t	s;
	int			i;

	i = 0;
	s = pthread_self();
	while (s != data->th[i] && i < THREADS)
		i++;
	fract[data->fract](data, i);
	pthread_exit(NULL);
}

void			threads(t_data *data)
{
	int			i;

	i = 0;
	while (i < THREADS)
	{
		if (pthread_create(&data->th[i], NULL, (void*)selector, data) != 0)
		{
			ft_putendl("Error");
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		}
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(data->th[i], NULL);
		i++;
	}
}
