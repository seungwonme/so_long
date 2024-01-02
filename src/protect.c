/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:06 by seunan            #+#    #+#             */
/*   Updated: 2023/07/23 23:11:37 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	protected_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_msg("Error\nFailed to open\n");
	return (fd);
}

void	*protected_calloc(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (ptr == NULL)
		exit_with_msg("Error\nFailed to malloc\n");
	i = 0;
	while (i < size)
		ptr[i++] = 0;
	return (ptr);
}

char	**protected_realloc(char **ptr, size_t size, size_t len)
{
	char	**new_ptr;
	size_t	i;

	if (ptr == NULL)
		return (protected_calloc(size));
	new_ptr = protected_calloc(size);
	i = 0;
	while (i < len)
	{
		new_ptr[i] = ptr[i];
		++i;
	}
	free(ptr);
	return (new_ptr);
}

void	write_num(unsigned long long num, int size)
{
	char	c;

	if (num == 0)
		return ;
	write_num(num / 10, size - 1);
	c = num % 10 + '0';
	write(1, &c, 1);
}

void	print_num(unsigned long long num)
{
	int					size;
	unsigned long long	tmp;

	tmp = num;
	size = 0;
	while (tmp)
	{
		tmp /= 10;
		++size;
	}
	write_num(num, size);
	write(1, "\n", 1);
}
