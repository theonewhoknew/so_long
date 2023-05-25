/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2023/05/25 18:16:58 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>


void initialize_struct(t_map *map, char *path)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);

}


int	main(int argc, char **argv)
{	
	t_map map;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	initialize_struct(&map, argv[1]);
}