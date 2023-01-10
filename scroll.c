/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:57:08 by aaouassa          #+#    #+#             */
/*   Updated: 2023/01/10 01:00:40 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_cross(int keycode, t_var *in)
{
	if (keycode == 53)
	{
		mlx_destroy_window(in->mlx, in->mlx_win);
		exit(0);
	}
	return (0);
}

int	ft_close(t_var *in)
{
	mlx_destroy_window(in->mlx, in->mlx_win);
	exit(0);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_var *s_var)
{
	if (keycode == 5)
	{
		x = s_var->o_x;
		y = s_var->o_y;
		s_var->max_iter = 200;
		s_var->i *= 1.5;
		ft_fract(s_var);
	}
	else if (keycode == 4)
	{
		x = s_var->o_x;
		y = s_var->o_y;
		s_var->max_iter = 200;
		s_var->i *= 0.8;
		ft_fract(s_var);
	}
	return (0);
}
