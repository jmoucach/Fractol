/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:21:38 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/08 19:21:42 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fractol.h"

typedef struct	s_cpx
{
	double		x;
	double		y;
}				t_cpx;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_img
{
	void		*img_ptr;
	int			*img_str;
	int			bpp;
	int			endian;
	int			sl;
}				t_img;

typedef struct	s_line
{
	int			error;
	int			offset;
	int			sign_y;
	int			sign_x;
	int			delta_y;
	int			delta_x;
}				t_line;

typedef struct	s_info
{
	char		max_iter[32];
	char		x_off[32];
	char		y_off[32];
	char		zoom[32];
	char		cst_x[32];
	char		cst_y[32];
}				t_info;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fract;
	int			keyboard[512];
	double		zoom;
	int			permit;
	t_cpx		cst;
	int			max_iter;
	int			color[10];
	int			ind;
	double		xoff;
	double		yoff;
	int			slength;
	t_img		img;
	t_img		hud;
	pthread_t	th[THREADS];
}				t_data;

#endif
