/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2023/06/05 13:34:51 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{	
	t_map map;
	
	
	initialize_struct(&map);
	fill_struct(&map, argv[1]);
	
	if (check_map(argc, argv[1], &map) == ERROR)
	{	
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_printf("no error\n");
	game(&map);
}