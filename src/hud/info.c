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

void	generate_info(t_info *i, t_data *data)
{
	sprintf(i->max_iter, "Max iterations    : %d", data->max_iter);
	sprintf(i->x_off, "X-axis offset     : %.2f", data->xoff);
	sprintf(i->y_off, "Y-axis offset     : %f", data->yoff);
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
