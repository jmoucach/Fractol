/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:46:24 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/23 08:46:26 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

static t_cpx	map(int x, int y)
{
	t_cpx		pt;

	pt.x = (-1.0 - 1.0) / (-WIN_HEIGHT) * (x - 0) - 1.0;
	pt.y = (-1.0 - 1.0) / (-WIN_HEIGHT) * (y - 0) - 1.0;
	return (pt);
}

int				mouse_move(int x, int y, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (data->permit == 1)
		data->cst = map(x, y);
	return (1);
}
