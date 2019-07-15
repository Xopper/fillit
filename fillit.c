/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:31 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/15 17:56:40 by ahaloua          ###   ########.fr       */
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
	int id;
	int x;
	int y;
	int hid;
	int count;
	t_tetris mtabs;

	ret = 21;
	id = 0;
	if (read(fd, buf, 0))
		return (0);
	while (ret == 21 && (ret = read(fd, buf, 21)) > 19)
	{
		buf[ret] = '\0';
		if (id == 26 || !ft_check_inlines(buf, ret) || !ft_isTetri(buf)
		|| !check_conn(buf))
			return (0);
		else
		{
			//printf("the len of the buff is %zu\n", ft_strlen(buf));
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
							//printf("tet[%d] hashid[%d](%d , %d)\n", id, hid, x, y);
							hid += 1;
						}
					}
					x++;
					count++;
				}
				y++;
			}
			count = 0;
			hid = 0;
			int mincl;
			int minln;
			mincl = 0;
			minln = 0;
			mincl = mtabs.multi_tab[id].hashtab[hid].cl;
			minln = mtabs.multi_tab[id].hashtab[hid].ln;
			while (++hid < 3)
			{
				if (mincl >= mtabs.multi_tab[id].hashtab[hid].cl)
					mincl = mtabs.multi_tab[id].hashtab[hid].cl;
				if (minln >= mtabs.multi_tab[id].hashtab[hid].ln)
					minln = mtabs.multi_tab[id].hashtab[hid].ln;
			}
			//printf("[%d(mincl) , %d(minln)\n", mincl, minln);
			//printf("the new cords !!\n");
			while (count < 4)
			{
				mtabs.multi_tab[id].hashtab[count].cl -= mincl;
				mtabs.multi_tab[id].hashtab[count].ln -= minln;
				//printf("tet[%d] hashid[%d](%d , %d)\n", id, hid, mtabs.multi_tab[id].hashtab[count].cl, mtabs.multi_tab[id].hashtab[count].ln);
				count++;
			}
			// print the new tetris ;
			hid = 0;
			count = 0;
			int tmp = 0;
			int b = 0;
			while (tmp != ret)
			{
				int a = 0;
				while (a < 4 && tmp != ret)
				{
					if (mtabs.multi_tab[id].hashtab[count].cl == a && mtabs.multi_tab[id].hashtab[count].ln == b)
					{
						ft_putchar('#');
						count++;
					}
					else if (tmp == (ret - 1) && ret == 21)
					{
						ft_putchar('\n');
					}
					else
						ft_putchar('.');
					a++;
					tmp++;
				}
				if (tmp != (ret - 1))
					ft_putchar('\n');
				b++;
			}
			id++;
		}
	}
	return (ret == 20);
}