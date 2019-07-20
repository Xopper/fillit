/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:42 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/20 20:25:17 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <string.h>

void	ft_free_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		printf("&(map)[i] = [%p] {%s}\n", &(map)[i] , map[i]);
		ft_memdel((void **)&(map)[i]);
		i++;
	}
	ft_memdel((void **)&map);
}
void	ft_putmap(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
void	ft_creat_map(char ***map, int size)
{
	int		i;

	i = 0;
	if (*map != NULL)
		ft_free_map(*map);
	if (!(*map = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return ;
	else
	{
		while (i < size)
		{
			(*map)[i] = ft_strnew(size);
			(*map)[i] = ft_memset((*map)[i], '.', size);
			i += 1;
		}
	}
}

int		ft_map_size(int nb)
{
	nb *= 4;
	while (ft_sqrt(nb) == 0 || ft_sqrt(nb) < 4)
		nb++;
	return (ft_sqrt(nb));
}

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb > 0)
	{
		while ((i*i) <= nb)
		{
			if ((i*i) == nb)
				return (i);
			i++;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	char **map;

	map = NULL;
	int id;
	int fd;

	id = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	if ((id = ft_read_tetris(fd)) == 0)
	{
		ft_putendl("error");
		return (1);
	}
	ft_creat_map(&map, id);
	ft_putmap(map);
	//ft_creat_map(&map, id + 1);
	//ft_putmap(map);
	ft_free_map(map);

	return (0);
}