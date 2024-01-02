/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:11:13 by seunan            #+#    #+#             */
/*   Updated: 2023/07/23 23:11:15 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_escape(t_vars *vars)
{
	char	**visited;
	int		backup[3];

	backup[0] = vars->p[0];
	backup[1] = vars->p[1];
	backup[2] = vars->item;
	visited = dup_map(vars);
	vars->is_escape = 0;
	dfs_find_c(vars, vars->p[0], vars->p[1], visited);
	if (vars->is_escape == 0)
		exit_with_msg("Error\nUnable to escape\n");
	vars->is_escape = 0;
	dfs_find_e(vars, vars->p[0], vars->p[1], visited);
	if (vars->is_escape == 0)
		exit_with_msg("Error\nUnable to escape\n");
	free_map(visited);
	vars->p[0] = backup[0];
	vars->p[1] = backup[1];
	vars->item = backup[2];
}

void	dfs_find_c(t_vars *vars, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= vars->x || y >= vars->y)
		return ;
	if (visited[y][x] == '1' || visited[y][x] == '2' | visited[y][x] == 'E')
		return ;
	if (visited[y][x] == 'C')
	{
		--vars->item;
		vars->p[0] = x;
		vars->p[1] = y;
	}
	visited[y][x] = '2';
	if (vars->item == 0)
	{
		vars->is_escape = 1;
		return ;
	}
	dfs_find_c(vars, x + 1, y, visited);
	dfs_find_c(vars, x - 1, y, visited);
	dfs_find_c(vars, x, y + 1, visited);
	dfs_find_c(vars, x, y - 1, visited);
}

void	dfs_find_e(t_vars *vars, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= vars->x || y >= vars->y)
		return ;
	if (visited[y][x] == '1' || visited[y][x] == '3')
		return ;
	if (visited[y][x] == 'E')
	{
		vars->is_escape = 1;
		return ;
	}
	visited[y][x] = '3';
	dfs_find_e(vars, x + 1, y, visited);
	dfs_find_e(vars, x - 1, y, visited);
	dfs_find_e(vars, x, y + 1, visited);
	dfs_find_e(vars, x, y - 1, visited);
}

char	**dup_map(t_vars *vars)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = protected_calloc(sizeof(char *) * (vars->y + 1));
	while (i < vars->y)
	{
		tmp[i] = ft_strdup(vars->map[i]);
		++i;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		++i;
	}
	free(map);
}
