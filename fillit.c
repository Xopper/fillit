/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:31 by ahaloua           #+#    #+#             */
/*   Updated: 2019/06/30 20:11:16 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int ft_isTetri(const char *str)
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

int check_conn(char *str)
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

static int ft_check_inlines(const char *str, int r)
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

	ret = 21;
	valid_tetris = 0;
	if (read(fd, buf, 0) < 0)
		return (0);
	while (ret == 21 && (ret = read(fd, buf, 21)) > 19)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		printf("\n");
		if (valid_tetris++ == 26 ||!ft_check_inlines(buf, ret) || !ft_isTetri(buf) || !check_conn(buf))
			return (0);
	}
	printf("valid == %d\n", valid_tetris);
	return (ret == 20);
}