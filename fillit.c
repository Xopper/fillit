/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:31 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/08 19:09:34 by ahaloua          ###   ########.fr       */
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

int ft_read_tetris(int fd)
{
	char buf[22];
	int ret;
	int valid_tetris;
	int i;
	int j;
	int l;
	int k;
	t_tetris mtabs;

	ret = 21;
	valid_tetris = 0;
	i = 0;
	if (read(fd, buf, 0))
		return (0);
	while (ret == 21 && (ret = read(fd, buf, 21)) > 19)
	{
		buf[ret] = '\0';
		if (valid_tetris++ == 26 || !ft_check_inlines(buf, ret) || !ft_isTetri(buf)
		|| !check_conn(buf))
			return (0);
		else
		{
			printf("the len of the buff is %zu\n", ft_strlen(buf));
			j = 0;
			l = 0;
			while (buf[l] != '\0')
			{
				k = 0;
				while (k < 5 && buf[l])
				{
					if (buf[l] != '\n')
						mtabs.multi_tab[i].tab[j][k] = buf[l];
					else
						mtabs.multi_tab[i].tab[j][k] = '0';
					printf("the tetris value is [%c]\n", mtabs.multi_tab[i].tab[j][k]);
					//printf("[k] value is = %d\n", k);
					k++;
					//printf("[l] value is = %d\n", l);
					l++;
					
				}
				ft_putstr("-_-_\n");
				//printf("[j] value is = %d\n", j);
				j++;
				//printf("[l] value is = %d\n", l);
			}
			//printf("[i] value is = %d\n", i);
			i++;
		}
	}
	return (ret == 20);
}