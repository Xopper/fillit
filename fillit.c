/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:31 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/18 22:00:33 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_istetri(const char *str)
{
	size_t	hashs;
	size_t	dots;
	int		i;

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

int		check_conn(const char *str)
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

int		ft_check_inlines(const char *str, int r)
{
	int i;

	i = 4;
	while (i < 20)
	{
		if (str[i] != '\n')
			return (0);
		i += 5;
	}
	return ((r == 21 && str[20] == '\n') || r == 20);
}

void	ft_shift(t_tetrim *one)
{
	int hid;
	int count;
	int mincl;
	int minln;

	hid = 0;
	count = 0;
	mincl = one->hashtab[hid].cl;
	minln = one->hashtab[hid].ln;
	while (++hid < 3)
	{
		if (mincl >= one->hashtab[hid].cl)
			mincl = one->hashtab[hid].cl;
		if (minln >= one->hashtab[hid].ln)
			minln = (*one).hashtab[hid].ln;
	}
	while (count < 4)
	{
		(*one).hashtab[count].cl -= mincl;
		(*one).hashtab[count].ln -= minln;
		count++;
	}
}

void	ft_stock_hashs(char *buff, t_tetrim *one)
{
	int i;
	int hid;
	int x;
	int y;

	i = 0;
	y = 0;
	hid = 0;
	while (buff[i])
	{
		x = 0;
		while (x < 5 && buff[i])
		{
			if (buff[i] == '#')
			{
				one->hashtab[hid].cl = x;
				one->hashtab[hid].ln = y;
				hid++;
			}
			x++;
			i++;
		}
		y++;
	}
}

int		ft_read_tetris(int fd)
{
	char		buf[22];
	int			ret;
	int			id;
	t_tetris	tab;

	ret = 21;
	id = 0;
	if (read(fd, buf, 0))
		return (0);
	while (ret == 21 && (ret = read(fd, buf, 21)) > 19)
	{
		buf[ret] = '\0';
		if (id == 26 || !ft_check_inlines(buf, ret) || !ft_istetri(buf)
		|| !check_conn(buf))
			return (0);
		else
		{
			tab.multi_tab[id].id = 'A' + id;
			ft_stock_hashs(buf, &tab.multi_tab[id]);
			ft_shift(&tab.multi_tab[id]);
			//ft_putchar(tab.multi_tab[id].id);
			//ft_putchar('\n');
			ft_puttet(tab.multi_tab[id], ret);
			id++;
		}
	}
	printf("the good mini map size is [%d]", ft_map_size(id));
	return (ret == 20);
}
