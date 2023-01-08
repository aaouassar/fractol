/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:24:34 by aaouassa          #+#    #+#             */
/*   Updated: 2023/01/08 15:45:17 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_mandelbrot(t_var *s_var)
{
    s_var->y = -2.0 * (1000 / 4);
    while(s_var->y <= 2.0 * (1000 / 4))
    {
        s_var->x = -2.0 * (1000 / 4);
        s_var->c_y = s_var->y / s_var->i;
        while (s_var->x <= 2.0 * (1000 / 4))
        {
            s_var->z_x = s_var->x / s_var->i;
            s_var->z_y = s_var->y / s_var->i;
            s_var->c_x = s_var->x / s_var->i;
            s_var->iter = 0;
            while ((s_var->z_x * s_var->z_x) + (s_var->z_y * s_var->z_y) < 4.0  && s_var->iter < s_var->max_iter)
            {
                s_var->save = s_var->z_x;
                s_var->z_x = (s_var->z_x * s_var->z_x) - (s_var->z_y * s_var->z_y) + s_var->c_x;
                s_var->z_y = 2 * s_var->save * s_var->z_y + s_var->c_y;
                s_var->iter++;
            }
            if (s_var->iter == s_var->max_iter)
                my_mlx_pixel_put(s_var, s_var->o_x + s_var->x, s_var->o_y - s_var->y, 0);
            else 
                my_mlx_pixel_put(s_var, s_var->o_x + s_var->x, s_var->o_y - s_var->y, 51581515 * s_var->iter);
            s_var->x++;
        }
        s_var->y++;
    }
    mlx_put_image_to_window(s_var->mlx, s_var->mlx_win, s_var->img, 0, 0);
}
