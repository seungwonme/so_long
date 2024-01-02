/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:16 by seunan            #+#    #+#             */
/*   Updated: 2023/07/23 23:11:24 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_vars *vars)
{
	if (vars->map[vars->p[1] - 1][vars->p[0]] == 'C')
		--(vars->item);
	else if (vars->map[vars->p[1] - 1][vars->p[0]] == 'E')
	{
		if (vars->item == 0)
			exit_window(vars);
		return ;
	}
	vars->map[vars->p[1]][vars->p[0]] = '0';
	vars->map[vars->p[1] - 1][vars->p[0]] = 'P';
	vars->p[1] -= 1;
	print_map(vars);
	print_num(++vars->cnt);
}

void	down(t_vars *vars)
{
	if (vars->map[vars->p[1] + 1][vars->p[0]] == 'C')
		--(vars->item);
	else if (vars->map[vars->p[1] + 1][vars->p[0]] == 'E')
	{
		if (vars->item == 0)
			exit_window(vars);
		return ;
	}
	vars->map[vars->p[1]][vars->p[0]] = '0';
	vars->map[vars->p[1] + 1][vars->p[0]] = 'P';
	vars->p[1] += 1;
	print_map(vars);
	print_num(++vars->cnt);
}

void	left(t_vars *vars)
{
	if (vars->map[vars->p[1]][vars->p[0] - 1] == 'C')
		--(vars->item);
	else if (vars->map[vars->p[1]][vars->p[0] - 1] == 'E')
	{
		if (vars->item == 0)
			exit_window(vars);
		return ;
	}
	vars->map[vars->p[1]][vars->p[0]] = '0';
	vars->map[vars->p[1]][vars->p[0] - 1] = 'P';
	vars->p[0] -= 1;
	print_map(vars);
	print_num(++vars->cnt);
}

void	right(t_vars *vars)
{
	if (vars->map[vars->p[1]][vars->p[0] + 1] == 'C')
		--(vars->item);
	else if (vars->map[vars->p[1]][vars->p[0] + 1] == 'E')
	{
		if (vars->item == 0)
			exit_window(vars);
		return ;
	}
	vars->map[vars->p[1]][vars->p[0]] = '0';
	vars->map[vars->p[1]][vars->p[0] + 1] = 'P';
	vars->p[0] += 1;
	print_map(vars);
	print_num(++vars->cnt);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_window(vars);
	if (keycode == 13)
		if (vars->map[vars->p[1] - 1][vars->p[0]] != '1')
			up(vars);
	if (keycode == 1)
		if (vars->map[vars->p[1] + 1][vars->p[0]] != '1')
			down(vars);
	if (keycode == 0)
		if (vars->map[vars->p[1]][vars->p[0] - 1] != '1')
			left(vars);
	if (keycode == 2)
		if (vars->map[vars->p[1]][vars->p[0] + 1] != '1')
			right(vars);
	return (0);
}
