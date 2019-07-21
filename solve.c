/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:55:27 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/21 16:15:35 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_safe(char **map, t_tetrim *one, int *x ,int *y, int size)
{
	int i = 0;
	int m = 0;
	int n = 0;

	int		minx;
	int		miny;

	minx = one->hashtab[0].cl;
	miny = one->hashtab[0].ln;
	while (i < 4)
	{
		if (one->hashtab[i].cl < minx)
			minx = one->hashtab[i].cl;
		if (one->hashtab[i].ln < miny)
			miny = one->hashtab[i].ln;	
		i += 1;
	}
	i = 0;
	while (i < 4)
	{
		m = one->hashtab[i].cl + *y - minx;
		n = one->hashtab[i].ln + *x - miny;
		//printf("the {m,n} == {%d, %d}\n", m, n);
		if (m >= size || m < 0)
			return (0);
		if (n >= size || n < 0)
			return (0);
		if (map[n][m] != '.')
			return (0);
		i += 1;
	}
	i = 0;
	while (i < 4)
	{
		m = one->hashtab[i].cl + *y - minx;
		n = one->hashtab[i].ln + *x - miny;
		map[n][m] = one->id;
		i++;
	}
	return (1);
}

int		ft_set_tetri(t_tetrim *one, char ***map, int *x, int *y, int size)
{
	int i;

	i = 0;

	while (i < 4 && *x <= size && *y<= size )
	{
		*x = one->hashtab[i].ln;
		*y = one->hashtab[i].cl; 
		if ((*map)[*x][*y] == '.')
			(*map)[*x][*y] = one->id;
		else
			return (0);
		i++;
	}
	if (*x <= size && *y<= size)
		return (0);
	return (1);
}

void	ft_rm_tetri(char **map, char c, int size)
{
	int i = 0;
	int j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j += 1;
		}
	i += 1;
	}
}

int		ft_solve(char **map, t_tetrim *one, int size)
{
	int		x;
	int		y;

	x = 0;
	if (one->id == 0)
		return (1);
	while (x < size)
	{
		y = 0;
		while (y < size)
		{	
			if (ft_is_safe(map, one, &x, &y, size))
			{
				//printf (">> %c\n", one->id);
				//system("clear");
				//ft_putmap(map);
				//sleep(1);
				if (ft_solve(map, ++one, size))
					return (1);
				else
				{
					ft_rm_tetri(map, one->id, size);
				}
			}	
			y++;
		}
		x++;
	}
	return (0);
}