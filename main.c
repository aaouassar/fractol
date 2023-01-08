/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:19:03 by aaouassa          #+#    #+#             */
/*   Updated: 2023/01/08 16:15:10 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_minilbx(t_var *s_var, char **argv)
{
    s_var->mlx = mlx_init();
    s_var->img = mlx_new_image(s_var->mlx, 1000, 1000);
    s_var->addr = mlx_get_data_addr(s_var->img, &s_var->bits_per_pixel, &s_var->line_length, &s_var->endian);
    s_var->mlx_win = mlx_new_window(s_var->mlx, 1000, 1000, "Hello world!");
    origine(s_var, 1000, 1000);

    if (ft_strcmp(argv[1], "Mandelbrot") == 0)
        {
            // ft_minilbx(img);
            s_var->max_iter = 200;
            s_var->i = 250;
            ft_mandelbrot(s_var);
        }
        else if (!ft_strcmp(argv[1], "Julia"))
        {
            s_var->max_iter = 200;
            s_var->i = 250;
            ft_julia(s_var);
        }

    
}
int main(int argc, char **argv)
{
    t_var s_var;
    if (argc > 2 || argc == 1)
        printf("you should chose between Mandelbrot or Julia please");
        // exit(1);
    if(argc == 2)
    {
        if(ft_strcmp(argv[1], "Mandelbrot") == 0)
        {
            ft_minilbx(&s_var, argv);
        }
        else if (ft_strcmp(argv[1], "Julia") == 0)
            ft_minilbx(&s_var, argv);
        else
        {
            printf("you should chose between Mandelbrot or Julia please");
            // exit(1);
        }
        mlx_hook(s_var.mlx_win, 17, 0, ft_close, &s_var);
        mlx_hook(s_var.mlx_win, 2, 0, ft_cross, &s_var);
        mlx_loop(s_var.mlx);
    }
}

// The Mandelbrot set is the set of complex numbers c for which the function f(z)=z^2+c 
// does not diverge when iterated from z=0.
