void    ft_mlx(v_data *var, char **av)
{
    var->mlx = mlx_init();
    var->img = mlx_new_image(var->mlx, W, H);
    var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length, &var->endian);
    var->mlx_win = mlx_new_window(var->mlx, W, H, av[1]);
    origine(var, W, H);

    if(ft_strncmp(av[1], "Mandelbrot", 11) == 0)
    {
        var->max_iter = 100;
        var->i = W / 4;
        ft_mandelbrot(var);
    }
    else if(ft_strncmp(av[1], "Julia", 6) == 0)
    {
        var->max_iter = 200;
        var->i = W / 4;
        ft_julia(var, av);
    }
}
int main(int ac, char **av)
{
    v_data    var;

    if(ac >= 2 && ac <= 3)
    {
        if(ft_strncmp(av[1], "Mandelbrot", 11) != 0 && ft_strncmp(av[1], "Julia", 6) != 0)
        {
            printf("you have to choose between" "Mandelbrot" or "Julia"\n"");
            printf("if you choose "Julia" you can defin your julia set as folow : c = 0.285 + 0.01i\n");
            return (0);
        }
        ft_mlx(&var, av);

        mlx_hook(var.mlx_win, 17, 0, close, &var);
        mlx_hook(var.mlx_win, 2, 0, key_esc, &var);
        mlx_loop(var.mlx);
    }
