/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:08:50 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/23 11:08:56 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

void	fractal_name(t_info *i, t_data *data)
{
	if (data->fract == 0)
		sprintf(i->fract, "JULIA");
	else if (data->fract == 1)
		sprintf(i->fract, "MANDELBROT");
	else if (data->fract == 2)
		sprintf(i->fract, "MANDELBAR");
	else if (data->fract == 3)
		sprintf(i->fract, "BURNING SHIP");
	else if (data->fract == 4)
		sprintf(i->fract, "SIERPINKI'S TRIANGLE");
	else if (data->fract == 5)
		sprintf(i->fract, "BARNSLEY'S FERN");
}

void	generate_info(t_info *i, t_data *data)
{
	fractal_name(i, data);
	sprintf(i->max_iter, "Max iterations    : %d", data->max_iter);
	sprintf(i->x_off, "X-axis offset     : %.2f", data->xoff);
	sprintf(i->y_off, "Y-axis offset     : %.2f", data->yoff);
	sprintf(i->zoom, "Zoom              : %.5f", data->zoom);
	if (data->fract == 0)
	{
		sprintf(i->cst_x, "X constant        : %.2f", data->cst.x);
		sprintf(i->cst_y, "Y constant        : %.2f", data->cst.y);
	}
	else
	{
		sprintf(i->cst_x, "X constant        : %d", 0);
		sprintf(i->cst_y, "Y constant        : %d", 0);
	}
}
