/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:14 by seunan            #+#    #+#             */
/*   Updated: 2023/08/08 21:52:14 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	is_valid_arg(ac, av[1]);
	init_vars(&vars, av[1]);
	parse_map(&vars);
	is_valid_map(&vars);
	open_window(&vars);
	mlx_hook(vars.win, 3, 1L << 1, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	is_valid_arg(int ac, char *av)
{
	int	i;
	int	slash;

	if (ac != 2)
		exit_with_msg("Error\nEnter 2 arguments\n");
	i = 0;
	slash = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '/')
			slash = i + 1;
		++i;
	}
	if (i - slash < 5 || av[i - 1] != 'r' || av[i - 2] != 'e'
		|| av[i - 3] != 'b' || av[i - 4] != '.')
		exit_with_msg("Error\nThe file must end with a \'.ber\'\n");
}

void	init_vars(t_vars *vars, char *file)
{
	vars->fd = protected_open(file);
	vars->map = NULL;
	vars->x = 0;
	vars->y = 0;
	vars->p[0] = 0;
	vars->p[1] = 0;
	vars->item = 0;
	vars->is_escape = 0;
	vars->cnt = 0;
}

int	exit_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}
