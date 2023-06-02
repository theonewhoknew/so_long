/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2023/06/02 12:55:34 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void get_col(t_map *map, int fd)
{
	char *line;

	line = get_next_line(fd);
	map->col = ft_strlen(line) - 1;
}

int check_extension(char *path)
{
	int len;
	char *ptr;

	len = ft_strlen(path);
	ptr = &path[len - 4];
	if (ft_strnstr(ptr, ".ber", 4) == NULL)
		return (0);
	else 
		return (1);
}

void fill_struct(t_map *map, char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	get_col(map, fd);
}

void initialize_struct(t_map *map)
{	
	map->col = 0;
	map->row = 0;
	map->exit = 0;
	map->coins = 0;
	map->initial = 0;
}


int	main(int argc, char **argv)
{	
	t_map map;

	if (argc != 2 || check_extension(argv[1]) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	initialize_struct(&map);
	fill_struct(&map, argv[1]);
	
}