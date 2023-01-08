/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:16:56 by aaouassa          #+#    #+#             */
/*   Updated: 2023/01/08 03:11:32 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_julia(t_var *s_var)
{ 
    s_var->y = -2.0 * s_var->i;
    while(s_var->y <= 2.0 * s_var->i)
    {
        s_var->x = -2.0 * s_var->i;
        s_var->c_y =0.1428;
        while (s_var->x <= 2.0 * s_var->i)
        {
            s_var->z_x = s_var->x / s_var->i;
            s_var->z_y = s_var->y / s_var->i;
            s_var->c_x =  0.45 ;
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
                my_mlx_pixel_put(s_var, s_var->o_x + s_var->x, s_var->o_y - s_var->y, 295 * s_var->iter);
            s_var->x++;
        }
        s_var->y++;
    }
    mlx_put_image_to_window(s_var->mlx, s_var->mlx_win, s_var->img, 0, 0);
}
