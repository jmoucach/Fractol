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

typedef struct s_cpx
{
	double		x;
	double		y;
}				t_cpx;

typedef struct s_img
{
	void		*img_ptr;
	int			*img_str;
	int			bpp;
	int			endian;
	int			sl;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fract;
	int			keyboard[512];
	double		zoom;
	int			max_iter;
	int			color[10];
	int			ind;
	double		xoff;
	double		yoff;
	t_img		img;
}				t_data;

# endif
