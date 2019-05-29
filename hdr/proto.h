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
** Barnsley fern
*/

void	barnsley_fern(t_data *data);

/*
** Bressenham
*/

t_line	setup_params(t_pos a, t_pos b);
void	draw_line(t_pos a, t_pos b, t_data *data, int color);


/*
** Burning ship
*/

void	burning_ship_set(t_data *data, int th);

/*
** Deal-key
*/

void	deal_key_bis(t_data *data);
void	deal_key(t_data *data);

/*
** Deal-key(Fern)
*/

void	deal_key_fern_bis(t_data *data);
void	deal_key_fern(t_data *data);

/*
** Deal-key(Sierpinksi)
*/

void	deal_key_ter(t_data *data);
void	deal_key_sierpinski_bis(t_data *data);
void	deal_key_sierpinski(t_data *data);

/*
** Draw (HUD)
*/

void	box(t_pos	p1, t_pos p2, t_data *data);
void	color_hud(t_data *data);

/*
** Hud
*/

void	create_hud_img(t_data *data);
void	call_hud(t_data *data);

/*
** Info
*/

void	fractal_name(t_info *i, t_data *data);
void	generate_info(t_info *i, t_data *data);

/*
** Init
*/

void	init(t_data *data);
void	init_fern(t_data *data);
void	init_data(t_data *data);
void	init_seirp(t_data *data);
void	init_img(t_data *data);

/*
** Julia
*/

void	julia_set(t_data *data, int th);

/*
** Key handler
*/

void	deal_key_chooser(t_data *data);
int		key_release(int key, void *param);
int		key_press(int key, void *param);
int		dealer(void *param);
int		mouse_press(int button, int x, int y, void *param);

/*
** Main
*/

void	first_choose(t_data *data);
void	ft_mlx(t_data *data);

/*
** Mandelbar
*/

void	mandelbar_set(t_data *data, int th);

/*
** Mandelbrot
*/

void	mandelbrot_set(t_data *data, int th);
void	give_value(t_data *data, t_cpx *pt, int x, int y);

/*
** Mouse move
*/

int		mouse_move(int x, int y, void *param);

/*
** Parsing
*/

void	parser(char *str, t_data *data);

/*
** Print_fract
*/

int		is_inside_window(int x, int y);
void	put_pixel(t_data *data, int x, int y, int color);


/*
** Sierpinski triangle
*/

void	sierpinski_triangle(t_data *data);

/*
** Threads
*/

void	threads(t_data *data);
void	selector(t_data *data);

#endif
