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

void init(t_data *data);
void	init_data(t_data *data);
void init_img(t_data *data);

/*
** Print_fract
*/

void	put_pixel(t_data *data, int x, int y, int color);
void	print_fract(t_data *data);

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
** Newton
*/

void	newton_fractal(t_data *data, int th);

/*
** Key handler
*/

int		key_release(int key, void *param);
int		deal_key(void *param);
int		key_press(int key, void *param);
int mouse_press(int button, int x, int y, void *param);

/*
** Threads
*/

void	threads(t_data *data);
void	selector(t_data *data);

#endif
