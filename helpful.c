/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:28:37 by aaouassa          #+#    #+#             */
/*   Updated: 2023/01/10 01:50:12 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*f1;
	unsigned char	*f2;
	int				i;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	i = 0;
	while ((f1[i] || f2[i]))
	{
		if (f1[i] != f2[i])
		{
			return (f1[i] - f2[i]);
		}
		i++;
	}
	return (0);
}

void	my_mlx_pixel_put(t_var *data, int x, int y, int color)
{
	char	*dst;

	if (x < 1000 && y < 1000)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	origine(t_var *s_var, int x, int y)
{
	s_var->o_x = x / 2;
	s_var->o_y = y / 2;
}

void	ft_fract(t_var *s_var)
{
	if (s_var->ana == 0)
		ft_mandelbrot(s_var);
	else if (s_var->ana == 1)
		ft_julia(s_var);
}
