/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:28:18 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/08 19:28:23 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
void parser(char *str, t_data *data)
{
	if (ft_strequ(str, "julia") || ft_strequ(str, "Julia"))
		data->fract = 0;
	else if (ft_strequ(str, "mandelbrot") || ft_strequ(str, "Mandelbrot"))
		data->fract = 1;
	else if (ft_strequ(str, "mandelbar") || ft_strequ(str, "Mandelbar"))
		data->fract = 2;
	else if (ft_strequ(str, "burning_ship") || ft_strequ(str, "Burning_ship"))
		data->fract = 3;
	else if (ft_strequ(str, "newton") || ft_strequ(str, "Newton"))
		data->fract = 4;
	else
	{
		ft_putendl("Aviable fractals are: Julia / Mandelbrot / Mandelbar / Burning ship");
		exit(EXIT_FAILURE);
	}
}
