/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:31 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/14 16:49:38 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int ft_isTetri(const char *str)
{
	size_t hashs;
	size_t dots;
	int i;
	
	hashs = 0;
	dots = 0;
	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '#')
			hashs += 1;
		else if (str[i] == '.')
			dots += 1;
		i += 1;
	}
	if (hashs == 4 && dots == 12)
		return (1);
	return (0);
}

int check_conn(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				count++;
			if (str[i + 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 3 || count == 4)
		return (1);
	return (0);
}

int ft_check_inlines(const char *str, int r)
{
	int i = 4;
		while (i < 20)
		{
			if (str[i] != '\n')
				return (0);
			i += 5;
		}
		return ((r == 21 && str[20] == '\n') || r == 20);
}

/*
void	ft_get_hashs(t_tetrim tet, int col, int ln)
{
	int i;
	int j;

	i = 0;
	while (1)
	{
		j = 0;
		while(j < 4)
		{
			if (tet.tab[i][j] == '#')
			{
				col = j;
				ln = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
*/

int ft_read_tetris(int fd)
{
	char buf[22];
	int ret;
	int id;
	int x;
	int y;
	int hid;
	int count;
	//int valid_tet;
	t_tetris mtabs;

	ret = 21;
	id = 0;
	//valid_tet = 0;
	if (read(fd, buf, 0))
		return (0);
	while (ret == 21 && (ret = read(fd, buf, 21)) > 19)
	{
		//printf("this is for check in id[valid_tet == %d]\n",valid_tet);
		buf[ret] = '\0';
		if (id == 26 || !ft_check_inlines(buf, ret) || !ft_isTetri(buf)
		|| !check_conn(buf))
			return (0);
		else
		{
			printf("the len of the buff is %zu\n", ft_strlen(buf));
			count = 0;
			y = 0;
			hid = 0;
			while (buf[count] != '\0')
			{
				x = 0;
				while (x < 5 && buf[count])
				{
					if (buf[count] != '\n')
					{
						if (buf[count] == '#')
						{
							mtabs.multi_tab[id].hashtab[hid].cl = x;
							mtabs.multi_tab[id].hashtab[hid].ln = y;
							printf("tet[%d] hashid[%d](%d , %d)\n", id, hid, x, y);
							hid += 1;
						}
					}
					x++;
					count++;
				}
				y++;
			}
			//printf("this is for check out id[id == %d]\n",id);
			id++;
		}
	}
	return (ret == 20);
}