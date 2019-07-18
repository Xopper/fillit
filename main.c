/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:42 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/18 22:00:32 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
char	**ft_creat_map(int size)
{
	char	**ret;

}
*/
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
	int fd = open(argv[argc - 1], O_RDONLY);
	if (ft_read_tetris(fd) == 0)
	{
		ft_putendl("error");
		return (1);
	}
	return (0);
}