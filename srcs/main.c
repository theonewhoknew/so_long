/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2023/06/05 16:28:05 by theonewhokn      ###   ########.fr       */
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
	t_game game;
	
	
	initialize_struct(&game);
	fill_struct(&game, argv[1]);
	
	if (check_map(argc, argv[1], &game) == ERROR)
	{	
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	run_game(&game);
	return (0);
}