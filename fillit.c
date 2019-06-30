/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:31 by ahaloua           #+#    #+#             */
/*   Updated: 2019/06/30 15:23:28 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int ft_isTetri(const char *str)
{
	size_t hashs;
	size_t dots;
	int i;
	count = 0x0;
	i = 0x0;
	while (str[i])
	{
		if (str[i] == '#')
			hashs += 0x1;
		else if (str[i] == '.')
			dots += 0x1;
		i += 0x1;
	}
	if (hashs == 12 && dots == 4)
		return (0x1);
	return (0x0);
}

/*
static size_t ft_countDots(const char *str)
{
	size_t count;
	int i;

	count = 0x0;
	i = 0x0;
	while (str[i])
	{
		if (str[i] == '.')
			count += 0x1;
		i += 0x1;
	}
	return (count);
}
*/

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
	int 		valid_tertis;
	t_tetrim t;
	int co;
	int ln;
	int i;

	valid_tertis = 0;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		printf("Dots numbers %zu\n", ft_countDots(buf));
		printf("Hashs numbers %zu\n", ft_countHashs(buf));
		printf("lines is inlines ? %d\n", ft_check_inlines(buf));
		printf("the return is %d\n", ret);
		ft_putstr(buf);
		if (ft_isTetri(buf) && ft_check_inlines(buf))
			{
				valid_tertis++;
			}
		else
			return (0x0);
		printf("%d\n" , valid_tertis);
		if (ret == 20)
			return (0x1);
	}
	return (0x0);
}
/*
int	ft_check_re(t_tetrim t)
{

}


int 		count(char *str)
{
	int points;
	int hashs;
	int i;

	i = 0;
	points = 0;
	hashs = 0;
	while (str[i])
	{
		if (str[i] == '.')
			points += 1;
		else if (str[i] == '#')
			hashs += 1;
		i += 1;
	}
	if ((str[4] == '\n' || str[9] == '\n' || str[14] == '\n'
			|| str[19] == '\n' || str[20] == '\n' )&& str[20])
		return (1);
	return (0);
}
*/
