/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:57:43 by seunan            #+#    #+#             */
/*   Updated: 2023/07/23 23:11:27 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_map(t_vars *vars)
{
	is_valid_char(vars);
	is_dup_char(vars);
	is_map_surrounded_one(vars);
	is_rectangular(vars);
	is_escape(vars);
}

void	is_valid_char(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] != '0' && vars->map[y][x] != '1'
				&& vars->map[y][x] != 'E' && vars->map[y][x] != 'P'
				&& vars->map[y][x] != 'C')
				exit_with_msg("Error\nContains unrecognized character\n");
			if (vars->map[y][x] == 'C')
				++(vars->item);
			++x;
		}
		++y;
	}
}

void	is_dup_char(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == 'P')
			{
				vars->p[0] = x;
				vars->p[1] = y;
				++(vars->cnt);
			}
			else if (vars->map[y][x] == 'E')
				++(vars->is_escape);
			++x;
		}
		++y;
	}
	if (vars->cnt != 1 || vars->is_escape != 1)
		exit_with_msg("Error\nMaps should only have 1 escape and 1 character\n");
}

void	is_map_surrounded_one(t_vars *vars)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	tmp = vars->map;
	while (tmp[y] != NULL)
	{
		x = 0;
		while (tmp[y][x] != '\0')
		{
			if (x == 0 || y == 0 || x == vars->x - 1 || y == vars->y - 1)
				if (tmp[y][x] != '1')
					exit_with_msg("Error\nMap is not surrounded by \'1\'\n");
			++x;
		}
		++y;
	}
}

void	is_rectangular(t_vars *vars)
{
	int	i;

	i = 1;
	while (vars->map[i] != NULL)
	{
		if (vars->x != (int)ft_strlen(vars->map[i]))
			exit_with_msg("Error\nMap is not rectangular\n");
		++i;
	}
}
