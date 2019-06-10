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

#include "../../hdr/fractol.h"

void	parser(char *str, t_data *data)
{
	if (ft_strequ(str, "julia") || ft_strequ(str, "Julia"))
		data->fract = 0;
	else if (ft_strequ(str, "mandelbrot") || ft_strequ(str, "Mandelbrot"))
		data->fract = 1;
	else if (ft_strequ(str, "mandelbar") || ft_strequ(str, "Mandelbar"))
		data->fract = 2;
	else if (ft_strequ(str, "burning_ship") || ft_strequ(str, "Burning_ship"))
		data->fract = 3;
	else if (ft_strequ(str, "triangle") || ft_strequ(str, "Triangle"))
		data->fract = 4;
	else if (ft_strequ(str, "fern") || ft_strequ(str, "Fern"))
		data->fract = 5;
	else if (ft_strequ(str, "koch") || ft_strequ(str, "Koch"))
		data->fract = 6;
	else if (ft_strequ(str, "carpet") || ft_strequ(str, "Carpet"))
		data->fract = 7;
	else
	{
		ft_putstr("Aviable fractals are: Julia / Mandelbrot / Fern /");
		ft_putendl(" Mandelbar / Burning ship / Sierpinski / Koch / Carpet");
		exit(EXIT_FAILURE);
	}
}
