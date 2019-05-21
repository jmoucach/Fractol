/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:21:31 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/08 19:21:32 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "fractol.h"


/*
** Parsing
*/

void parser(char *str, t_data *data);

/*
** Init
*/

void	init(t_data *data);
void	init_data(t_data *data);
void	init_seirp(t_data *data);
void	init_img(t_data *data);

/*
** Bressenham
*/

void		draw_line(t_pos a, t_pos b, t_data *data);

/*
** Print_fract
*/

int		is_inside_window(int x, int y);
void	put_pixel(t_data *data, int x, int y, int color);

/*
** Mandelbrot
*/

void	mandelbrot_set(t_data *data, int th);
void	give_value(t_data *data, t_cpx *pt, int x, int y);

/*
** Julia
*/

void	julia_set(t_data *data, int th);

/*
** Mandelbar
*/

void	mandelbar_set(t_data *data, int th);

/*
** Burning ship
*/

void	burning_ship_set(t_data *data, int th);

/*
** Sierpinski triangle
*/

void	sierpinski_triangle(t_data *data);

/*
** Barnsley fern
*/

void	barnsley_fern(t_data *data);

/*
** Key handler
*/

int		key_release(int key, void *param);
int		key_press(int key, void *param);
int		dealer(void *param);
int		mouse_press(int button, int x, int y, void *param);

/*
** Deal-key
*/

int		deal_key(t_data *data);

/*
** Deal-key(Sierpinksi)
*/

void	deal_key_sierpinski(t_data *data);

/*
** Threads
*/

void	threads(t_data *data);
void	selector(t_data *data);

#endif
