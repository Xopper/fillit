/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:51:59 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/17 15:54:27 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puttet(t_tetrim *one, int ret)
{
	int count;
	int tmp;
	int a;
	int b;

	count = 0;
	tmp = 0;
	b = 0;
	while (tmp < ret)
	{
		a = -1;
		while (++a < 4 && tmp < ret)
		{
			if (one->hashtab[count].cl == a && one->hashtab[count++].ln == b)
				ft_putchar('#');
			else if (tmp == (ret - 1))
				ft_putchar('\n');
			else
				ft_putchar('.');
			tmp++;
		}
		if (tmp++ != (ret))
			ft_putchar('\n');
		b++;
	}
}
