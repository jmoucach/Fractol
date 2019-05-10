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
		data->fract = 1;
	else if (ft_strequ(str, "mandelbrot") || ft_strequ(str, "Mandelbrot"))
		data->fract = 2;
	else
		ft_putendl("Aviable fractals are: Julia / Mandelbrot");
}
