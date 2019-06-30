/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:31 by ahaloua           #+#    #+#             */
/*   Updated: 2019/06/30 19:31:32 by aazeroua         ###   ########.fr       */
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
	while (str[i])
	{
		if (str[i] == '#')
			hashs += 1;
		else if (str[i] == '.')
			dots += 1;
		i += 1;
	}
	if (hashs == 4 && dots == 12)
		return (0x1);
	return (0x0);
}

int		check_conn(char *str)
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
				count ++;
		}
		i++;
	}
	if (count == 3 || count == 4)
		return (1);
	return (0);
}

static int	ft_check_inlines(const char *str)
{
	if (ft_strlen(str) == 21)
	{
		if (str[4] == '\n' && str[9] == '\n' && str[14] == '\n' && str[19] == '\n' && str[20] == '\n')
			return (0x1);
	}
	else if (ft_strlen(str) == 20)
	{
		if (str[4] == '\n' && str[9] == '\n' && str[14] == '\n' && str[19] == '\n' && str[20] == '\0')
			return (0x1);
	}
	return (0x0);
}
int		ft_read_tetris(int fd)
{
	char		buf[22];
	int			ret;
	int			ret2;
	int 		valid_tertis;
	ret2 = 0;
	valid_tertis = 0;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ret2++;
		if (ft_isTetri(buf) && ft_check_inlines(buf) && check_conn(buf))
				valid_tertis++;
		else
			return (0);
	}
	if (ret2 == valid_tertis)
		return (1);
	return (0);
}
