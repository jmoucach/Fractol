/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:14:51 by jmoucach          #+#    #+#             */
/*   Updated: 2019/06/05 09:14:52 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/fractol.h"

static void	give_rgb_values2(t_rgb *rgb, t_hsv hsv, t_conv conv)
{
	if (conv.i == 3)
	{
		rgb->r = conv.p;
		rgb->g = conv.q;
		rgb->b = hsv.v;
	}
	else if (conv.i == 4)
	{
		rgb->r = conv.t;
		rgb->g = conv.p;
		rgb->b = hsv.v;
	}
	else
	{
		rgb->r = hsv.v;
		rgb->g = conv.p;
		rgb->b = conv.q;
	}
}

static void	give_rgb_values(t_rgb *rgb, t_hsv hsv, t_conv conv)
{
	if (conv.i == 0)
	{
		rgb->r = hsv.v;
		rgb->g = conv.t;
		rgb->b = conv.p;
	}
	else if (conv.i == 1)
	{
		rgb->r = conv.q;
		rgb->g = hsv.v;
		rgb->b = conv.p;
	}
	else if (conv.i == 2)
	{
		rgb->r = conv.p;
		rgb->g = hsv.v;
		rgb->b = conv.t;
	}
	else
		give_rgb_values2(rgb, hsv, conv);
}

static void	fill_conv(t_conv *conv, t_hsv hsv)
{
	conv->i = (int)floor(hsv.h);
	conv->f = hsv.h - conv->i;
	conv->p = hsv.v * (1.0 - hsv.s);
	conv->q = hsv.v * (1.0 - (hsv.s * conv->f));
	conv->t = hsv.v * (1.0 - (hsv.s * (1.0 - conv->f)));
}

int			hsv_to_rgb(t_hsv hsv)
{
	t_rgb	rgb;
	t_conv	conv;

	if (hsv.s == 0)
	{
		rgb.r = hsv.v;
		rgb.g = hsv.v;
		rgb.b = hsv.v;
	}
	else
	{
		if (hsv.h == 360)
			hsv.h = 0;
		else
			hsv.h /= 60;
		fill_conv(&conv, hsv);
		give_rgb_values(&rgb, hsv, conv);
	}
	rgb.r *= 255;
	rgb.g *= 255;
	rgb.b *= 255;
	return ((int)rgb.r << 16 | (int)rgb.g << 8 | (int)rgb.b);
}
