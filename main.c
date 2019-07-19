/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:42 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/19 21:32:05 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_free_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
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
		ft_putstr(map[i]);
		i++;
	}
}
void	ft_creat_map(char ***map, int size)
{
	char	*str;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = size + 1;
	if (*map != NULL)
		ft_free_map(*map);
	str = ft_strnew(size);
	while (i < count)
	{
		str[i] = '.';
		i++;
	}
	str[size] = '\n';
	if (*map == NULL)
	{
		*map = (char **)ft_memalloc(sizeof(char *) * (size + 1));
		while (j < size)
		{
			(*map)[j] = ft_strnew(count);
			(*map)[j] = ft_strcpy((*map)[j], str);
			//(*map)[j] = ft_strdup("");
			//(*map)[j] = ft_strjoin((*map)[j], str);
			j++;
		}
	}
	ft_memdel((void **)&str);
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
	int id = 0;
	int fd = open(argv[argc - 1], O_RDONLY);
	if ((id = ft_read_tetris(fd)) == 0)
	{
		ft_putendl("error");
		return (1);
	}
	ft_creat_map(&map, id);
	ft_putmap(map);
	ft_free_map(map);
	return (0);
}