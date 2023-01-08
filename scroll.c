/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:57:08 by aaouassa          #+#    #+#             */
/*   Updated: 2023/01/08 03:10:26 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int ft_cross(int keycode , t_var *in)
{
    if (keycode == 53)
    {
        mlx_destroy_window(in->mlx, in->mlx_win);
        exit(0);
    }
    return (0);  
}

int    ft_close(t_var *in)
{
    mlx_destroy_window(in->mlx, in->mlx_win);
    exit(0);
    return(0);
}
