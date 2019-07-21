/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:42 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/21 16:37:17 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char		**map;
	t_tetris	*tab;

	map = NULL;
	int size;
	int fd;

	size = 0;

	tab = (t_tetris *)ft_memalloc(sizeof(t_tetris));
	fd = open(argv[argc - 1], O_RDONLY);
	if ((size = ft_read_tetris(fd, tab)) == 0)
	{
		ft_putendl("error");
		return (1);
	}
	ft_creat_map(&map, size);
	while (ft_solve(map, &tab->multi_tab[0], size) == 0)
	{
		size += 1;
		ft_creat_map(&map, size);
	}
	//ft_solve(map, &tab->multi_tab[0], size);
	//ft_putmap(map);
	//ft_creat_map(&map, id + 1);
	ft_putmap(map);
	ft_free_map(map); // free the map
	ft_memdel((void **)&tab); // free the *tab
	return (0);
}
